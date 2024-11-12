#include "symbol_table.h"
#include "symbol.h"
#include "gpl_assert.h"
using namespace std;

#include <vector>
#include <algorithm> // for sort algorithm

/* static */ Symbol_table *Symbol_table::m_instance = 0;

/* static */ Symbol_table * Symbol_table::instance()
{
  if (!m_instance)
    m_instance = new Symbol_table();
  return m_instance;
}

Symbol_table::Symbol_table(){}

Symbol_table::~Symbol_table()
{
  cerr << "~Symbol_table()... not implemented..." << endl;
}


bool Symbol_table::insert(Symbol *symbol)
{
    // COMPLETE ME

    //match every symbol?
    if (m_symbols.find(symbol->get_name()) == m_symbols.end()){
       m_symbols.insert({symbol->get_name(), symbol});
      // cout << "inserting " << symbol->get_name() << "\n";
      return true;
    }
      return false;
}

Symbol *Symbol_table::lookup(string name) const
{
    if (m_symbols.find(name) == m_symbols.end()){
      return NULL;
    } else {
      return m_symbols.find(name)->second;
    }
    // cout << "LOOKUP\n";
}

// comparison function for the STL sort algorithm
// returns true if a <= b
bool compare_symbols(Symbol *a, Symbol *b) 
{
    return a->get_name() <= b->get_name();
    // string a_name = a->get_name();
    // string b_name = b->get_name();
    // for (int i = 0; i < a_name.length(); i++){
    //     if (isdigit(a_name[i])) {
    //       if (isdigit(b_name[i])) {
    //         int a_digit = atoi(&a_name[i]);
    //         int b_digit = atoi(&b_name[i]);
    //         if (a_digit < b_digit) {
    //           return true;
    //         }
    //         if (a_digit > b_digit) {
    //           return false;
    //         }
    //       } else {
    //         return false;
    //       }
    //     } else {
    //       if (a_name[i] < b_name[i]) {
    //         return true;
    //       } 
    //       if (a_name[i] > b_name[i]){
    //         return false;
    //       }
    //   }
    // }
    // return true;
}


void Symbol_table::print(ostream &os) const
{
  // COMPLETE ME

  // HINT: What I would do here is ...
  // (1) add all symbols in the table into a vector.
  // (2) sort the vector.
  // (3) print the elements (symbols) in the vector.

  vector<Symbol *> v;

  for (const pair<const string, Symbol*>& keyValue : m_symbols) {
      v.push_back(keyValue.second);
  }
  sort(v.begin(), v.end(), compare_symbols);
  for (Symbol *s : v){
  
    string name = s->get_name();
    switch (s->get_type())
    {
        case INT: {os << "int " << name << " = " << s->get_int_value() << "\n"; break;}
        case DOUBLE: {os << "double " << name << " = " << s->get_double_value() << "\n"; break;}
        case STRING: {os << "string " << name << " = \"" << s->get_string_value() << "\"\n"; break;}
        case ARRAY: {os <<  "array"; break;}
        case INT_ARRAY: {
          for (int i = 0; i < s->size(); i++){
            os << "int " << name << "[" << i << "] = " << s->get_int_value(i) << "\n";
          }
          break;
        }
        case DOUBLE_ARRAY: {
          for (int i = 0; i < s->size(); i++){
            os << "double " << name << "[" << i << "] = " << s->get_double_value(i) << "\n";
          }
          break;
        }
        case STRING_ARRAY: {
          for (int i = 0; i < s->size(); i++){
            os << "string " << name << "[" << i << "] = \"" << s->get_string_value(i) << "\"\n";
          }
          break;
        }
        case GAME_OBJECT: {
          
          Game_object *g = s->get_game_object_value();
          g->print(s->get_name(),os);
          break;
        }
        default: os <<  "error";
      }
    }
}
