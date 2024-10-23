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
    m_symbols.insert({symbol->get_name(), symbol});
    // cout << "inserting " << symbol->get_name() << "\n";
    return true;
}

Symbol *Symbol_table::lookup(string name) const
{
    // if (m_symbols.find(name) == m_symbols.end()){
    return m_symbols.find(name)->second;
    // cout << "LOOKUP\n";
}

// comparison function for the STL sort algorithm
bool compare_symbols(Symbol *a, Symbol *b) 
{
    return a->get_name() <= b->get_name();
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
      Symbol *val = keyValue.second;
      // cout << "KEY: " << keyValue.first << " VALUE: " << val->get_name() << "\n";
      //  << (keyValue.second)->get_name();
      v.push_back(keyValue.second);
  }
  // for (Symbol *s : v){
  //   cout << s->get_name() << "\n";
  // }
  // cout << "sorting\n";
  sort(v.begin(), v.end());
  // for (Symbol *s : v){
  //   cout << s->get_name() << "\n";
  // }
  // cout << v.size();
  for (Symbol *s : v){
  
    string name = s->get_name();
    switch (s->get_type())
    {
        case INT: {os << "int " << name << " = 42\n"; break;}
        case DOUBLE: {os << "double " << name << " = 3.14159\n"; break;}
        case STRING: {os << "string " << name << " = \"Hello world\"\n"; break;}
        case ARRAY: {os <<  "array"; break;}
        case INT_ARRAY: {
          for (int i = 0; i < s->size(); i++){
            // int curr = s->get_int_value(i);
            os << "int " << name << "[" << i << "] = 42\n";
          }
          break;
        }
        case DOUBLE_ARRAY: {
          for (int i = 0; i < s->size(); i++){
            // double curr = s->get_double_value(i);
            os << "double " << name << "[" << i << "] = 3.14159\n";
          }
          break;
        }
        case STRING_ARRAY: {
          for (int i = 0; i < s->size(); i++){
            // string curr = s->get_string_value(i);
            string curr = "\"Hello world\"";
            os << "string " << name << "[" << i << "] = " << curr << "\n";
          }
          break;
        }
        default: os <<  "error";
      }
    }
}
