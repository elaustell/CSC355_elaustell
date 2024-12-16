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
    assert(argument);
    assert(argument->valid());

    // (a) modify the symbol for the formal parameter so it points to argument
    Game_object *old_object = m_parameter_symbol->get_game_object_value();
    assert(old_object);
    assert(old_object->valid());

    m_parameter_symbol->set(argument);

    // (b) call Statement_block::execute()
    Statement_block::execute();

    // (c) undo the modification from step (a)
    m_parameter_symbol->set(old_object);
}

// void Animation_block::execute(Game_object *argument) {
//     static bool executing = false;
//     if (executing) return;
//     executing = true;
//     if (m_parameter_symbol) {
//         Game_object* original = m_parameter_symbol->get_game_object_value();
//         m_parameter_symbol->set(argument);
//         Statement_block::execute();
//         m_parameter_symbol->set(original);
//     } else {
//         Statement_block::execute();
//     }
//     executing = false;
// }