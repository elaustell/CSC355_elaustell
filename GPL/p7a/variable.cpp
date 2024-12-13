#include "variable.h"
#include "symbol.h"
#include "expression.h"
#include "gpl_type.h"
#include "gpl_assert.h"
#include "error.h"
#include <sstream>
using namespace std;

Variable::Variable(Symbol *symbol, string *member_field_name /*= NULL*/)
{
    assert(symbol);

    m_symbol = symbol;
    m_field = member_field_name;

    if (member_field_name) {
        assert(symbol->is_game_object());
        // int index = m_expression->eval_int();
        Game_object *g = m_symbol->get_game_object_value();
        Gpl_type *type = new Gpl_type(NO_TYPE);
        g->get_member_variable_type(*member_field_name, *type);
        m_type = *type;
    } else {
        m_type = symbol->get_type();
    }
    m_expression = NULL;

    // make sure that if a field was specified that it is a legal field
    // check_field_update_type();
}

Variable::Variable(Symbol *symbol, Expression *expression, string *member_field_name /*= NULL*/)
{
    assert(expression != NULL);
    m_symbol = symbol;
    m_type = symbol->get_base_type();
    m_expression = expression;
    m_field = member_field_name;

    // if expression is not an INT expression
    if (expression->get_type() != INT)
    {
        assert(expression->get_type() == DOUBLE
            || expression->get_type() == STRING
            || expression->get_type() == ANIMATION_BLOCK
            );

        //MOVE errors to gpl.y
        if (expression->get_type() == DOUBLE)
        {
        Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,
                    m_symbol->get_name(),"A double expression"
                    );
        }
        else if (expression->get_type() == STRING)
        {
        Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,
                    m_symbol->get_name(),"A string expression"
                    );
        }
        else
        {
        Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,
                    m_symbol->get_name(),"An animation_block expression"
                    );
        }
        // for error recovery
        m_expression = new Expression(0);
    }

    if (member_field_name) {
        assert(symbol->is_game_object());
        // int index = m_expression->eval_int();
        int index = eval_index_with_error_checking();
        Game_object *g = m_symbol->get_game_object_value(index);
        Gpl_type *type = new Gpl_type(NO_TYPE);
        g->get_member_variable_type(*member_field_name, *type);
        m_type = *type;
    } else {
        m_type = symbol->get_base_type();
    }

    assert(m_symbol);

    // it would be nice to evaluate m_expression here and make sure
    // m_expression->eval_int() is w/in the bounds for the array
    // HOWEVER, the current value of m_expression is meaningless
    // it is only at run time that the value has any meaning

    // make sure that if a field was specified that it is a legal field
    // check_field_update_type();
}

string Variable::get_name() const
{
  string name = m_symbol->get_name();
  // Add [] at the end of name string to indicate the variable is an array.
  if (m_expression)
  {
    name += "[]";
  }
  return name;
}

Gpl_type Variable::get_type() const {
    // if (m_field) {
    //     assert(m_symbol->is_game_object());
    //     int index = m_expression->eval_int();
    //     Game_object *g = m_symbol->get_game_object_value(index);
    //     Gpl_type *type = new Gpl_type(NO_TYPE);
    //     g->get_member_variable_type(*m_field, *type);
    //     return *type;
    // } else {
    //     return m_type;
    // }
    return m_type;
}

int Variable::get_int_value() const
{
    // here i think i need to get the value from the field!!
    // the variable has type int, but the symbol has type game object
    if (m_field) {
        if (m_expression == NULL) {
            Game_object *g = m_symbol->get_game_object_value();
            int *ret = new int(0);
            g->get_member_variable(*m_field, *ret);
            return *ret;
        } else {
            Game_object *g = m_symbol->get_game_object_value(eval_index_with_error_checking());
            int *ret = new int(0);
            g->get_member_variable(*m_field, *ret);
            return *ret;
        }
    }
    if (m_expression == NULL){
        return m_symbol->get_int_value();
    } else {
        return m_symbol->get_int_value(eval_index_with_error_checking());
    }
}

double Variable::get_double_value() const
{
    if (m_field) {
        if (m_expression == NULL) {
            Game_object *g = m_symbol->get_game_object_value();
            double *ret = new double(0);
            g->get_member_variable(*m_field, *ret);
            return *ret;
        } else {
            Game_object *g = m_symbol->get_game_object_value(eval_index_with_error_checking());
            double *ret = new double(0.0);
            g->get_member_variable(*m_field, *ret);
            return *ret;
        }
    }
    if (m_expression == NULL){
        return m_symbol->get_double_value();
    } else {
        return m_symbol->get_double_value(eval_index_with_error_checking());
    }
}

string Variable::get_string_value() const
{
    if (m_field) {
        if (m_expression == NULL) {
            Game_object *g = m_symbol->get_game_object_value();
            string *ret = new string("");
            g->get_member_variable(*m_field, *ret);
            return *ret;
        } else {
            Game_object *g = m_symbol->get_game_object_value(eval_index_with_error_checking());
            string *ret = new string("");
            g->get_member_variable(*m_field, *ret);
            return *ret;
        }
    }
    if (m_expression == NULL){
        return m_symbol->get_string_value();
    } else {
        return m_symbol->get_string_value(eval_index_with_error_checking());
    }
}

Animation_block *Variable::get_animation_block_value() const
{
    assert(is_animation_block());
    if (m_expression == NULL){
        return m_symbol->get_animation_block_value();
    } else {
        // todo: error
        return m_symbol->get_animation_block_value();
    }
}

void Variable::set(int value)
{
  if (!m_field)
  {
    if (!m_expression)
      m_symbol->set(value);
    else
      m_symbol->set(value,eval_index_with_error_checking());
  }
  else
  {
    {
      Game_object *cur_game_object;
      if (!m_expression)
        cur_game_object = m_symbol->get_game_object_value();
      else
        cur_game_object=m_symbol->get_game_object_value(eval_index_with_error_checking());

      Status status = cur_game_object->set_member_variable(*m_field,value);
      assert(status == OK);
    }
  }
}

void Variable::set(double value)
{
    if (!m_field)
  {
    if (!m_expression)
      m_symbol->set(value);
    else
      m_symbol->set(value,eval_index_with_error_checking());
  }
  else
  {
    {
      Game_object *cur_game_object;
      if (!m_expression)
        cur_game_object = m_symbol->get_game_object_value();
      else
        cur_game_object=m_symbol->get_game_object_value(eval_index_with_error_checking());

      Status status = cur_game_object->set_member_variable(*m_field,value);
      assert(status == OK);
    }
  }
}

void Variable::set(string value)
{
    if (!m_field)
  {
    if (!m_expression)
      m_symbol->set(value);
    else
      m_symbol->set(value,eval_index_with_error_checking());
  }
  else
  {
    {
      Game_object *cur_game_object;
      if (!m_expression)
        cur_game_object = m_symbol->get_game_object_value();
      else
        cur_game_object=m_symbol->get_game_object_value(eval_index_with_error_checking());

      Status status = cur_game_object->set_member_variable(*m_field,value);
      assert(status == OK);
    }
  }
}

void Variable::set(Animation_block *value)
{
//     if (!m_field)
//   {
//     if (!m_expression)
//       m_symbol->set(value);
//     else
//       m_symbol->set(value,eval_index_with_error_checking());
//   }
//   else
//   {
//     {
//       Game_object *cur_game_object;
//       if (!m_expression)
//         cur_game_object = m_symbol->get_game_object_value();
//       else
//         cur_game_object=m_symbol->get_game_object_value(eval_index_with_error_checking());

//       Status status = cur_game_object->set_member_variable(*m_field,value);
//       assert(status == OK);
//     }
//   }
}

// Evaluate expression if there is one, return index if index is out of bounds, 
// issue error, return 0 (0 is always in bounds)
int Variable::eval_index_with_error_checking() const
{
  assert(m_expression); // should only be called if this is an array

  int index = m_expression->eval_int();

  // an annoying special case
  // if the index is -1 it confuses symbol that uses -1 for 
  //   not an array
  if (m_symbol->index_within_range(index))
  {
    return index;
  }
  else
  {
    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,
                 m_symbol->get_name(),to_string(index));

    return 0; // 0 is always within range
  }
}

Gpl_type Variable::get_base_game_object_type() const
{
    return m_symbol->get_base_type();
}

bool Variable::is_non_member_animation_block() const
{
    return !m_symbol->is_animation_block();
}

int Variable::get_expression() const 
{
    if (m_expression == NULL) {
        return -1;
    }
    return m_expression->eval_int();
}