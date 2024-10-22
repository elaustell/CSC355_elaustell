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
    m_symbols.insert({"int", symbol});
    return true;
}

Symbol *Symbol_table::lookup(string name) const
{
    // if (m_symbols.find(name) == m_symbols.end()){
    return m_symbols.find(name)->second;
}

// comparison function for the STL sort algorithm
bool compare_symbols(Symbol *a, Symbol *b) 
{
    return a->get_name() < b->get_name();
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
  sort(v.begin(), v.end());
  for (Symbol *s : v){
    os << "<" << s->get_type() << "> <" << s->get_name() 
        << "> = <42>";
  }
}
