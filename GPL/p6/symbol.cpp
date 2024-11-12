#include "symbol.h"
#include "gpl_assert.h"

using namespace std;

Symbol::Symbol(string name, int initial_value)
{
  m_name = name;
  m_type = INT;
  m_data_void_ptr = (void *) new int(initial_value);
  m_size = UNDEFINED_SIZE;
  validate();
}

Symbol::Symbol(string name, double initial_value)
{
  m_name = name;
  m_type = DOUBLE;
  m_data_void_ptr = (void *) new double(initial_value);
  m_size = UNDEFINED_SIZE;
  validate();
}

Symbol::Symbol(string name, string initial_value)
{
  m_name = name;
  m_type = STRING;
  m_data_void_ptr = (void *) new string(initial_value);
  m_size = UNDEFINED_SIZE;
  validate();
}


Symbol::Symbol(string name, Gpl_type type, int size)
{
  m_name = name;
  m_type = type;
  if (type == INT_ARRAY) {m_data_void_ptr = (void *) new int[size]();}
  else if (type == DOUBLE_ARRAY) {m_data_void_ptr = (void *) new double[size]();}
  else if (type == STRING_ARRAY) {m_data_void_ptr = (void *) new string[size]();}
  else {
    //error?
  }
  m_size = size;
  validate();
}

Symbol::~Symbol()
{
  // The Symbol "owns" the object it contains, it must delete it
  if (!is_array())
    switch (m_type)
    {
      case INT: delete (int *) m_data_void_ptr; break;
      case DOUBLE: delete (double *) m_data_void_ptr; break;
      case STRING: delete (string *) m_data_void_ptr; break;
      default: assert(0);
    }
  else
    switch (m_type)
    {
      case INT_ARRAY: delete [] (int *) m_data_void_ptr; break;
      case DOUBLE_ARRAY: delete [] (double *) m_data_void_ptr; break;
      case STRING_ARRAY: delete [] (string *) m_data_void_ptr; break;
      default: assert(0);
    }
}

// strip away the ARRAY bit from the type if there is one
Gpl_type Symbol::get_base_type() const 
{

  if (m_type & ARRAY)
      return (Gpl_type) (m_type - ARRAY);
  else
      return m_type;
}

void Symbol::validate_type_and_index(Gpl_type type, int index) const
{
  assert(m_type & type);

  assert((index == UNDEFINED_INDEX && m_size == UNDEFINED_SIZE) 
         || (index >= 0 && m_size >= 1 && index < m_size));
}

int Symbol::get_int_value(int index /* = UNDEFINED_INDEX */) const
{
  validate_type_and_index(INT, index);
  if (is_array())
    return ((int *) m_data_void_ptr)[index];
  else
    return *((int *) m_data_void_ptr);
}

double Symbol::get_double_value(int index /* = UNDEFINED_INDEX */) const
{
  validate_type_and_index(DOUBLE, index);
  if (is_array())
    return ((double *) m_data_void_ptr)[index];
  else
    return *((double *) m_data_void_ptr);
}

string Symbol::get_string_value(int index /* = UNDEFINED_INDEX */) const
{
  validate_type_and_index(STRING, index);
  if (is_array())
    return ((string *) m_data_void_ptr)[index];
  else
    return *((string *) m_data_void_ptr);
}

void Symbol::print(ostream &os) const
{
  os << m_name;
  if (is_array()) {
    os << "[]";
  }
}

void Symbol::validate() const
{
  if (m_type & ARRAY)
    assert(m_size > 0);
  else
    assert(m_size == UNDEFINED_SIZE);

  assert(m_data_void_ptr != NULL);
  assert(m_name != "");
  assert(m_size != 0);
}
