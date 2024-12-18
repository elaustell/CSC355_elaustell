#include <cmath>
using namespace std;

#include "expression.h"

#include "constant.h"
#include "variable.h"
#include "gpl_assert.h"
#include "game_object.h"
#include "error.h"

Expression::Expression(int value)
{
    m_type = INT;
    m_constant = new Constant(value);
}
Expression::Expression(double value)
{
    m_type = DOUBLE;
    m_constant = new Constant(value);
}

Expression::Expression(string *value)
{
    m_type = STRING;
    m_constant = new Constant(*value);
}

Expression::Expression(Variable *variable)
{
    m_type = variable->get_type();
    m_variable = variable;
}

Expression::Expression(Operator_type op,
                       Expression *lhs,
                       Expression *rhs
                       )
{
    m_op = op;
    m_rhs = rhs;
    m_lhs = lhs;
    // Check for boolean operations
    if (op == NOT || op == AND || op == OR || op == EQUAL || 
        op == NOT_EQUAL || op == LESS_THAN || op == LESS_EQUAL || 
        op == GREATER_THAN || op == GREATER_EQUAL || op == NEAR || op == TOUCHES){
            m_type = INT;
    } 
    // Plus goes to string if a string is present, then double, and lastly int
    else if (op == PLUS){
      if (m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
          m_type = STRING;
      } else if (m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE) {
          m_type = DOUBLE;
      } else if (m_lhs->get_type() == INT && m_rhs->get_type() == INT){
          m_type = INT;
      } else {
        // we shouldn't use PLUS or MINUS for other types... 
        // maybe return error?
          m_type = NO_TYPE; 
      }
    }
    // Valid over a mix of ints or doubles. Binary operations
    else if (op == MULTIPLY || op == DIVIDE || op == MINUS) {
        if (m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE) {
          m_type = DOUBLE;
        } else if (m_lhs->get_type() == INT && m_rhs->get_type() == INT){
          m_type = INT;
        } else {
          //TODO: error
        }
    }
    //Unary operations. that always yield floats 
    else if (op == SIN || op == COS || op == TAN || op == ASIN || 
             op == ACOS || op == ATAN || op == SQRT || op == ABS){
        if (m_lhs->get_type() == DOUBLE || m_lhs->get_type() == INT || 
            m_rhs->get_type() == DOUBLE || m_rhs->get_type() == INT){
                m_type = DOUBLE;
        } else {
          //TODO: error
        }      
    }
    else if (op == UNARY_MINUS){
        if (m_lhs->get_type() == DOUBLE || m_lhs->get_type() == INT || 
            m_rhs->get_type() == DOUBLE || m_rhs->get_type() == INT){
                m_type = m_lhs->get_type();
        } else {
          //TODO: error
        }
    } else if (op == FLOOR) {
        if (m_lhs->get_type() == DOUBLE || m_lhs->get_type() == INT || 
            m_rhs->get_type() == DOUBLE || m_rhs->get_type() == INT){
                m_type = INT;
        } else {
          //TODO: error
        }
    } else if (op == RANDOM || op == MOD) {
        m_type = INT;
    } else {
      // error?
    }
}

Expression::Expression(Operator_type op, Expression *operand)
{
    m_lhs = operand;
    m_op = op;

    // Check for boolean operations
    if (op == NOT || op == AND || op == OR || op == EQUAL || 
        op == NOT_EQUAL || op == LESS_THAN || op == LESS_EQUAL || 
        op == GREATER_THAN || op == GREATER_EQUAL || op == NEAR || op == TOUCHES){
            m_type = INT;
    } 
    // Plus goes to string if a string is present, then double, and lastly int
    else if (op == PLUS){
      if (m_lhs->get_type() == STRING || m_rhs->get_type() == STRING){
          m_type = STRING;
      } else if (m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE) {
          m_type = DOUBLE;
      } else if (m_lhs->get_type() == INT && m_rhs->get_type() == INT){
          m_type = INT;
      } else {
        // we shouldn't use PLUS or MINUS for other types... 
        // maybe return error?
          m_type = NO_TYPE; 
      }
    }
    // Valid over a mix of ints or doubles. Binary operations
    else if (op == MULTIPLY || op == DIVIDE) {
        if (m_lhs->get_type() == DOUBLE || m_rhs->get_type() == DOUBLE) {
          m_type = DOUBLE;
        } else if (m_lhs->get_type() == INT && m_rhs->get_type() == INT){
          m_type = INT;
        } else {
          //TODO: error
        }
    }
    //TODO: determine type using lots of case analysis

    //Unary operations. that always yield floats 
    else if (op == SIN || op == COS || op == TAN || op == ASIN || 
             op == ACOS || op == ATAN || op == SQRT ){
        if (m_lhs->get_type() == DOUBLE || m_lhs->get_type() == INT || 
            m_rhs->get_type() == DOUBLE || m_rhs->get_type() == INT){
                m_type = DOUBLE;
        } else {
          //TODO: error
        }      
    }
    else if (op == ABS || op == UNARY_MINUS){
        if (m_lhs->get_type() == DOUBLE || m_lhs->get_type() == INT || 
            m_rhs->get_type() == DOUBLE || m_rhs->get_type() == INT){
                m_type = operand->get_type();
        } else {
          //TODO: error
        }
    } else if (op == FLOOR) {
        if (m_lhs->get_type() == DOUBLE || m_lhs->get_type() == INT || 
            m_rhs->get_type() == DOUBLE || m_rhs->get_type() == INT){
                m_type = INT;
        } else {
          //TODO: error
        }
    } else if (op == RANDOM) {
        m_type = INT;
    } else {
      // error?
    }
}


int Expression::eval_int()
{
  assert(m_type == INT);

  if (m_constant != NULL)
  {
    assert(m_variable == NULL);
    assert(m_lhs == NULL && m_rhs == NULL);

    return m_constant->get_int_value();
  }
  else if (m_variable != NULL)
  {
    assert(m_constant == NULL);
    assert(m_lhs == NULL && m_rhs == NULL);
    return m_variable->get_int_value();
  }

  // must be a binary or unary expression
  //   both binary and unary have m_lhs
  assert(m_lhs);

  if (m_op != NOT
      && m_op != UNARY_MINUS
      && m_op != FLOOR
      && m_op != RANDOM
      && m_op != ABS
     )
    assert(m_rhs);
  else assert(!m_rhs);


  // idea: replace switch with an array of labels and a goto
  switch (m_op)
  {
    case PLUS:
        return m_lhs->eval_int() + m_rhs->eval_int();
    case MINUS:
        return m_lhs->eval_int() - m_rhs->eval_int();
    case MULTIPLY:
        return m_lhs->eval_int() * m_rhs->eval_int();
    case DIVIDE:
    {
        int rhs;
        rhs = m_rhs->eval_int();
        // if this is still compile time, then don't allow
        // a floating point exception
        if (rhs == 0 && !Error::runtime())
        {
          Error::error(Error::DIVIDE_BY_ZERO_AT_PARSE_TIME);
          return 0;
        }
        return m_lhs->eval_int() / rhs;
    }
    case MOD:
    {
        int rhs;
        rhs = m_rhs->eval_int();
        // if this is still compile time, then don't allow
        // a floating point exception
        if (rhs == 0 && !Error::runtime())
        {
          Error::error(Error::MOD_BY_ZERO_AT_PARSE_TIME);
          return 0;
        }
        return m_lhs->eval_int() % rhs;

    }
    case NOT:
        assert(m_rhs == NULL);
        // eval m_lhs as a double in case it is a double
        // INT's can be evaluated as either an INT or DOUBLE
        return !m_lhs->eval_double();
    case UNARY_MINUS:
        assert(m_rhs == NULL);
        return -m_lhs->eval_int();
    case ABS:
        return (int) std::abs(m_lhs->eval_int());
    case FLOOR:
        return (int) floor(m_lhs->eval_double());
    case RANDOM:
    {
        int range = (int) floor(m_lhs->eval_double());
        if (range < 1)
        {
          Error::error(Error::INVALID_ARGUMENT_FOR_RANDOM, 
                       m_lhs->get_type() == INT ?  
                          to_string(m_lhs->eval_int())
                          : to_string(m_lhs->eval_double())
                      );
          range = 2;
        }
        return rand() % range;
    }
    case AND:
        return m_lhs->eval_double() && m_rhs->eval_double();
    case OR:
        return m_lhs->eval_double() || m_rhs->eval_double();
    case EQUAL:
        if (m_lhs->m_type == STRING || m_rhs->m_type == STRING)
          return m_lhs->eval_string() == m_rhs->eval_string();
        else if (m_lhs->m_type == INT && m_rhs->m_type == INT)
          return (m_lhs->eval_int() == m_rhs->eval_int());
        else return (m_lhs->eval_double() == m_rhs->eval_double());
    case NOT_EQUAL:
        if (m_lhs->m_type == STRING || m_rhs->m_type == STRING)
          return m_lhs->eval_string() != m_rhs->eval_string();
        else if (m_lhs->m_type == INT && m_rhs->m_type == INT)
          return m_lhs->eval_int() != m_rhs->eval_int();
        else return m_lhs->eval_double() != m_rhs->eval_double();

    case LESS_THAN:
        if (m_lhs->m_type == STRING || m_rhs->m_type == STRING)
          return m_lhs->eval_string() < m_rhs->eval_string();
        else if (m_lhs->m_type == DOUBLE || m_rhs->m_type == DOUBLE)
          return m_lhs->eval_double() < m_rhs->eval_double();
        else return m_lhs->eval_int() < m_rhs->eval_int();

    case LESS_EQUAL:
        if (m_lhs->m_type == STRING || m_rhs->m_type == STRING)
          return m_lhs->eval_string() <= m_rhs->eval_string();
        else if (m_lhs->m_type == INT && m_rhs->m_type == INT)
          return m_lhs->eval_int() <= m_rhs->eval_int();
        else return m_lhs->eval_double() <= m_rhs->eval_double();
    case GREATER_THAN:
        if (m_lhs->m_type == STRING || m_rhs->m_type == STRING)
          return m_lhs->eval_string() > m_rhs->eval_string();
        else if (m_lhs->m_type == INT && m_rhs->m_type == INT)
          return m_lhs->eval_int() > m_rhs->eval_int();
        else return m_lhs->eval_double() > m_rhs->eval_double();
    case GREATER_EQUAL:
        if (m_lhs->m_type == STRING || m_rhs->m_type == STRING)
          return m_lhs->eval_string() >= m_rhs->eval_string();
        else if (m_lhs->m_type == INT && m_rhs->m_type == INT)
          return m_lhs->eval_int() >= m_rhs->eval_int();
        else return m_lhs->eval_double() >= m_rhs->eval_double();
    case NEAR:
      if (!(m_lhs->m_type & GAME_OBJECT) || !(m_rhs->m_type & GAME_OBJECT)){
        assert(0);
        return 0;
      } else {
          Variable *v1 = m_lhs->eval_variable();
          Variable *v2 = m_rhs->eval_variable();

          assert(v1->is_game_object());
          assert(v2->is_game_object());

          Game_object *g1 = v1->get_game_object_value();
          Game_object *g2 = v2->get_game_object_value();

          return g1->near(g2);
      }
    case TOUCHES:
      if (!(m_lhs->m_type & GAME_OBJECT) || !(m_rhs->m_type & GAME_OBJECT)){
        assert(0);
        return 0;
      } else {
          Variable *v1 = m_lhs->eval_variable();
          Variable *v2 = m_rhs->eval_variable();

          assert(v1->is_game_object());
          assert(v2->is_game_object());

          Game_object *g1 = v1->get_game_object_value();
          Game_object *g2 = v2->get_game_object_value();

          return g1->touches(g2);
      }

    // no other operators are legal for int
    default: assert(0 && "undefined switch value");
  }
  assert(false && "should never reach this");
  return 0; // to prevent a compilation warning
}

double Expression::eval_double()
{
  // INT expressions can be in an expression tree that is double
  // when this happens, evaluate the int as a double
  assert(m_type == INT || m_type == DOUBLE);

  if (m_type == INT)
    return (double) eval_int();
  else if (m_constant != NULL)
  {
    assert(m_constant);
    return m_constant->get_double_value();
  }
  else if (m_variable != NULL)
  {
    assert(m_variable);
    return m_variable->get_double_value();
  }

  // must be a unary or binary expression
  //   both unary and binary expressions have a lhs
  assert(m_lhs);

  // if it is not one of the legal double unary operators
  // there must be a m_rhs
  if (m_op != SIN
      && m_op != COS
      && m_op != TAN
      && m_op != ASIN
      && m_op != ACOS
      && m_op != ATAN
      && m_op != SQRT
      && m_op != ABS
      && m_op != UNARY_MINUS
     )
  {
    assert(m_rhs);
  }
  switch (m_op)
  {
    case PLUS:
      return m_lhs->eval_double() + m_rhs->eval_double();
    case MINUS:
      return m_lhs->eval_double() - m_rhs->eval_double();
    case MULTIPLY:
      return m_lhs->eval_double() * m_rhs->eval_double();
    case DIVIDE:
    {
      double rhs = m_rhs->eval_double();
      // if this is still compile time, then don't allow
      // a floating point exception
      if (rhs == 0 && !Error::runtime())
      {
        Error::error(Error::DIVIDE_BY_ZERO_AT_PARSE_TIME);
        return 0;
      }
      return m_lhs->eval_double() / rhs;
    }
    case UNARY_MINUS:
      return -m_lhs->eval_double();
    case SIN:
      return sin(m_lhs->eval_double() * M_PI / 180.0);
    case COS:
      return cos(m_lhs->eval_double() * M_PI / 180.0);
    case TAN :
      return tan(m_lhs->eval_double() * M_PI / 180.0);
    case ASIN:
      return asin(m_lhs->eval_double()) * 180.0 / M_PI;
    case ACOS:
      return acos(m_lhs->eval_double()) * 180.0 / M_PI;
    case ATAN :
      return atan(m_lhs->eval_double()) * 180.0 / M_PI;
    case SQRT:
      return sqrt(m_lhs->eval_double());
    case ABS:
      // new version of abs handles doubles
      return std::abs(m_lhs->eval_double());
    case FLOOR:
      assert(false && "should never have a double floor");
      return floor(m_lhs->eval_double());
    // no other operators are legal double operators
    default: assert(0);
  }
  assert(false && "should never get here");
  return 0; // to prevent a compiler warning
}

string Expression::eval_string()
{
  // can only call eval_string() on the following types of expressions
  assert(m_type == STRING || m_type == INT || m_type == DOUBLE);

  // INT and DOUBLE expressions are automatically cast into strings
  // for example:  the int 42 is converted into the string "42"
  // this is done because there is no other way to convert numbers into
  // strings.
  if (m_type == INT)
  {
    return to_string(eval_int());
  }
  if (m_type == DOUBLE)
  {
    return to_string(eval_double());
  }
  if (m_constant != NULL)
  {
    assert(m_variable == NULL);
    return m_constant->get_string_value();
  }
  if (m_variable != NULL)
  {
    assert(m_constant == NULL);
    return m_variable->get_string_value();
  }

  // must really be a string expression
  // the only legal string operator is (+)
  // (that is, the only one that produces a string, ==, <, > etc produce INT)
  assert(m_lhs != NULL && m_rhs != NULL);
  assert(m_op == PLUS);
  return m_lhs->eval_string() + m_rhs->eval_string();
}

Animation_block *Expression::eval_animation_block()
{
  assert(m_type == ANIMATION_BLOCK);
  return m_variable->get_animation_block_value();
}
