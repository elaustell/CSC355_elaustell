// updated 2/14/2016

#include <vector>
#include "animation_block.h"
#include "game_object.h"
#include "gpl_assert.h"
#include "symbol.h"
using namespace std;

void Animation_block::initialize(Symbol *parameter_symbol, string name)
{
  m_name = name;
  // during error recovery a NULL parameter_symbol can be passed to Animation_block()
  if (parameter_symbol)
    assert(parameter_symbol->is_game_object());
  m_parameter_symbol = parameter_symbol;
}

void Animation_block::execute(Game_object *argument)
{
    cout << "beginning\n";
    // (a) modify the symbol for the formal parameter so it points to argument
    Symbol *old_symbol = get_parameter_symbol();
    cout << "middle\n";
    // cout << argument->get_type();
  
    Symbol *new_symbol = new Symbol(m_name, CIRCLE);
    cout << "is this the problem\n";
    // new_symbol->set(argument);
    // m_parameter_symbol = new_symbol;

    // // (b) call Statement_block::execute()
    // Statement_block::execute();

    // (c) undo the modification from step (a)
    // m_parameter_symbol = old_symbol;
    cout << "or now\n";
}

