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

Symbol::Symbol(string name, Gpl_type type)
{
    assert(type == CIRCLE
           || type == RECTANGLE
           || type == TRIANGLE
           || type == TEXTBOX
           || type == PIXMAP
           || type == ANIMATION_BLOCK
          );
  
    m_name = name;
    m_type = type;
    m_size = UNDEFINED_SIZE;
  
    switch(type)
    {
      case CIRCLE: m_data_void_ptr  = (void *) new Circle(); break;
      case RECTANGLE: m_data_void_ptr = (void *) new Rectangle(); break;
      case TRIANGLE: m_data_void_ptr  = (void *) new Triangle(); break;
      case TEXTBOX: m_data_void_ptr  = (void *) new Textbox(); break;
      case PIXMAP: m_data_void_ptr  = (void *) new Pixmap(); break;
      default: assert(0);
    }
}


Symbol::Symbol(string name, Gpl_type type, int size)
{
  m_name = name;
  m_type = type;
  switch(type) {
    case INT_ARRAY: m_data_void_ptr = (void *) new int[size](); break;
    case DOUBLE_ARRAY: m_data_void_ptr = (void *) new double[size](); break;
    case STRING_ARRAY: m_data_void_ptr = (void *) new string[size](); break;
    case CIRCLE_ARRAY: m_data_void_ptr  = (void *) new Circle[size]; break;
    case RECTANGLE_ARRAY: m_data_void_ptr = (void *) new Rectangle[size]; break;
    case TRIANGLE_ARRAY: m_data_void_ptr  = (void *) new Triangle[size]; break;
    case TEXTBOX_ARRAY: m_data_void_ptr  = (void *) new Textbox[size]; break;
    case PIXMAP_ARRAY: m_data_void_ptr  = (void *) new Pixmap[size]; break;
    default: assert(0);
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

Game_object *Symbol::get_game_object_value(int index /* = UNDEFINED_INDEX */) const
{
  validate_type_and_index(GAME_OBJECT, index);

  if (is_array())
  {
    // since this is an array of actual object, can't consider it an array of Game_object
    // must consider each type: Rectangle, Triangle, etc...

    switch(m_type)
    {
      case CIRCLE_ARRAY:
      {
        Circle *object_array = (Circle *) m_data_void_ptr;
        return object_array + index;
        break;
      }
      case RECTANGLE_ARRAY:
      {
        Rectangle *object_array = (Rectangle *) m_data_void_ptr;
        return object_array + index;
        break;
      }
      case TRIANGLE_ARRAY:
      {
        Triangle *object_array = (Triangle *) m_data_void_ptr;
        return object_array + index;
        break;
      }
      case TEXTBOX_ARRAY:
      {
        Textbox *object_array = (Textbox *) m_data_void_ptr;
        return object_array + index;
        break;
      }
      case PIXMAP_ARRAY:
      {
        Pixmap *object_array = (Pixmap *) m_data_void_ptr;
        return object_array + index;
        break;
      }
      default: 
      {
        assert(false && "given type is not handled by switch");
        return NULL;
      }
    }
  }
  else
    // m_data_void_ptr is a void pointer, that really points to a Game_object.
    return (Game_object *) m_data_void_ptr;
}

void Symbol::print(ostream &os) const
{
  if (is_game_object()) {
      Game_object *g = get_game_object_value();
      g->print(m_name,os);
  } else {
    os << m_name;
    if (is_array()) {
      os << "[]";
    }
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