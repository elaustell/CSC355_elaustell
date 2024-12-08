#include "variable.h"
#include "symbol.h"
#include "expression.h"
#include "gpl_type.h"
#include "gpl_assert.h"
#include "error.h"
#include <sstream>
using namespace std;

Variable::Variable(Symbol *symbol)
{
    m_symbol = symbol;
    m_type = symbol->get_type();
}

Variable::Variable(Symbol *symbol, Expression *expression)
{
    m_symbol = symbol;
    m_type = symbol->get_base_type(); //maybe get type of expression instead?
    m_expression = expression;
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

int Variable::get_int_value() const
{
    if (m_expression == NULL){
        return m_symbol->get_int_value();
    } else {
        return m_symbol->get_int_value(m_expression->eval_int());
    }
}

double Variable::get_double_value() const
{
    if (m_expression == NULL){
        return m_symbol->get_double_value();
    } else {
        return m_symbol->get_double_value(m_expression->eval_int());
    }
}

string Variable::get_string_value() const
{
    if (m_expression == NULL){
        return m_symbol->get_string_value();
    } else {
        return m_symbol->get_string_value(m_expression->eval_int());
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