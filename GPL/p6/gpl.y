%{

// there is a compatibility problem with my current cygwin environment
// this appears to fix the problem
#undef __GNUC_MINOR__

#include "error.h"
#include "gpl_assert.h"
#include "symbol_table.h"
#include "symbol.h"
#include "expression.h"
#include "variable.h"
#include <iostream>
#include <sstream>
#include <cmath> // for floor()
#include <stack>
#include "event_manager.h"
#include "statement_block.h"
#include "animation_block.h"
#include "game_object.h"
#include "triangle.h"
#include "pixmap.h"
#include "circle.h"
#include "rectangle.h"
#include "textbox.h"
#include "window.h"
using namespace std;

extern int yylex();
extern int yyerror(const char *);
extern int line_count;  // from gpl.l, used for statement blocks

// Global variable to make the construction of object much less complex
// Only one object can ever be under construction at one time
Game_object *cur_object_under_construction = 0;
string cur_object_under_construction_name;
int undeclared = 0;
Symbol_table *table = Symbol_table::instance();

%}

%union {
  int              union_int;
  double           union_double;
  std::string      *union_string;  // MUST be a pointer to a string ARG!
  Gpl_type         union_type;
  Expression       *union_expression;
  Variable         *union_variable;
  Operator_type    union_op;
  Game_object      *union_object;
}

%error-verbose

%token T_INT                 "int"
%token T_DOUBLE              "double"
%token T_STRING              "string"
%token T_TRIANGLE            "triangle"
%token T_PIXMAP              "pixmap"
%token T_CIRCLE              "circle"
%token T_RECTANGLE           "rectangle"
%token T_TEXTBOX             "textbox"
%token <union_int> T_FORWARD "forward" // value is line number
%token T_INITIALIZATION      "initialization" 
%token T_TERMINATION         "termination" 

%token T_TRUE                "true"
%token T_FALSE               "false"

%token T_ON                  "on"
%token T_SPACE               "space"
%token T_LEFTARROW           "leftarrow"
%token T_RIGHTARROW          "rightarrow"
%token T_UPARROW             "uparrow"
%token T_DOWNARROW           "downarrow"
%token T_LEFTMOUSE_DOWN      "leftmouse_down"
%token T_MIDDLEMOUSE_DOWN    "middlemouse_down"
%token T_RIGHTMOUSE_DOWN     "rightmouse_down"
%token T_LEFTMOUSE_UP        "leftmouse_up"
%token T_MIDDLEMOUSE_UP      "middlemouse_up"
%token T_RIGHTMOUSE_UP       "rightmouse_up"
%token T_MOUSE_MOVE          "mouse_move"
%token T_MOUSE_DRAG          "mouse_drag"
%token T_F1                  "f1"
%token T_AKEY                "akey"
%token T_SKEY                "skey"
%token T_DKEY                "dkey"
%token T_FKEY                "fkey"
%token T_HKEY                "hkey"
%token T_JKEY                "jkey"
%token T_KKEY                "kkey"
%token T_LKEY                "lkey"
%token T_WKEY                "wkey"
%token T_ZKEY                "zkey"

%token T_TOUCHES             "touches"
%token T_NEAR                "near"

%token T_ANIMATION           "animation"

%token T_IF                  "if"
%token T_FOR                 "for"
%token T_ELSE                "else"
%token <union_int> T_PRINT   "print" // value is line number
%token <union_int> T_EXIT    "exit" // value is line number

%token T_LPAREN              "("
%token T_RPAREN              ")"
%token T_LBRACE              "{"
%token T_RBRACE              "}"
%token T_LBRACKET            "["
%token T_RBRACKET            "]"
%token T_SEMIC               ";"
%token T_COMMA               ","
%token T_PERIOD              "."

%token T_ASSIGN              "="
%token T_PLUS_ASSIGN         "+="
%token T_MINUS_ASSIGN        "-="
%token T_PLUS_PLUS           "++"
%token T_MINUS_MINUS         "--"

%token T_MULTIPLY            "*"
%token T_DIVIDE              "/"
%token T_MOD                 "%"
%token T_PLUS                "+"
%token T_MINUS               "-"
%token T_SIN                 "sin"
%token T_COS                 "cos"
%token T_TAN                 "tan"
%token T_ASIN                "asin"
%token T_ACOS                "acos"
%token T_ATAN                "atan"
%token T_SQRT                "sqrt"
%token T_FLOOR               "floor"
%token T_ABS                 "abs"
%token T_RANDOM              "random"

%token T_LESS                "<"
%token T_GREATER             ">"
%token T_LESS_EQUAL          "<="
%token T_GREATER_EQUAL       ">="
%token T_EQUAL               "=="
%token T_NOT_EQUAL           "!="

%token T_AND                 "&&"
%token T_OR                  "||"
%token T_NOT                 "!"

%token <union_string> T_ID              "identifier"
%token <union_int> T_INT_CONSTANT       "int constant"
%token <union_double> T_DOUBLE_CONSTANT "double constant"
%token <union_string> T_STRING_CONSTANT "string constant"

%token T_ERROR               "error"

%nonassoc IF_NO_ELSE
%nonassoc T_ELSE

%left T_NEAR T_TOUCHES
%left T_OR 
%left T_AND
%left T_EQUAL T_NOT_EQUAL
%left T_LESS T_GREATER T_LESS_EQUAL T_GREATER_EQUAL 
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE T_MOD
%nonassoc UNARY_OPS

%type <union_type> simple_type
%type <union_expression> expression
%type <union_expression> optional_initializer
%type <union_expression> primary_expression
%type <union_variable> variable
%type <union_op> math_operator
%type <union_type> object_type



%%
//---------------------------------------------------------------------
program:
    declaration_list block_list
    ;

//---------------------------------------------------------------------
declaration_list:
    declaration_list declaration
    | empty
    ;

//---------------------------------------------------------------------
declaration:
    variable_declaration T_SEMIC
    | object_declaration T_SEMIC
    | forward_declaration T_SEMIC
    ;

//---------------------------------------------------------------------
variable_declaration:
    simple_type  T_ID  optional_initializer {
        string *name = $2;
        if ($1 == INT){
            int initial_value = 0;
            if ($3 != NULL)
            {
                if ($3->get_type() != INT && $3->get_type() != INT_ARRAY) {
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,gpl_type_to_string($3->get_type()),*name,"int");
                }
                else {
                    if ($3->get_type() == INT) {
                        initial_value = $3->eval_int();
                    }
                }
            }
            Symbol *s = new Symbol(*name, initial_value);
            bool valid = table->insert(s);
            if (!valid) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
            }
        } else if ($1 == DOUBLE){
            double initial_value = 0.0;
            if ($3 != NULL)
            {
                if (($3->get_type() != DOUBLE) && ($3->get_type() != INT)) {
                    if ($3->get_type() == INT_ARRAY || $3->get_type() == DOUBLE_ARRAY){
                    } else{
                        Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, "string", *name, "double");
                    }
                }
                else initial_value = $3->eval_double();
            }
            Symbol *s = new Symbol(*name, initial_value);
            bool valid = table->insert(s);
            if (!valid) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
            }
        } else {
            string initial_value = "";
            if ($3 != NULL)
            {
                if ($3->get_type() == INT || $3->get_type() == DOUBLE || $3->get_type() == STRING) {
                    initial_value = $3->eval_string();
                } else if ($3->get_type() == INT_ARRAY) {
                    Variable *v = $3->eval_variable();
                    int val = v->get_int_value();
                    initial_value = to_string(val);
                } else if ($3->get_type() == DOUBLE_ARRAY) {
                    Variable *v = $3->eval_variable();
                    double val = v->get_double_value();
                    initial_value = to_string(val);
                } else if ($3->get_type() == STRING_ARRAY) {
                    Variable *v = $3->eval_variable();
                    initial_value = v->get_string_value();
                } else {
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,gpl_type_to_string($3->get_type()), *name, "string");
                }
            }
            Symbol *s = new Symbol(*name, initial_value);
            bool valid = table->insert(s);
            if (!valid) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
            }
        }
    }
    | simple_type  T_ID  T_LBRACKET expression T_RBRACKET {
        string *name = $2;
        if ($4 == NULL) {

        } else if ($4->get_type() != INT) {
            Error::error(Error::ARRAY_SIZE_MUST_BE_AN_INTEGER,gpl_type_to_string($4->get_type()),*name);
        } else {
            int size = $4->eval_int();
            if (size <= 0){
                Error::error(Error::INVALID_ARRAY_SIZE, *name, to_string(size));
            } else {
                if ($1 == INT){
                    Symbol *s = new Symbol(*name, INT_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ($1 == DOUBLE){
                    Symbol *s = new Symbol(*name, DOUBLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else {
                    Symbol *s = new Symbol(*name, STRING_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                }
            }
        }
    }
    ;

//---------------------------------------------------------------------
simple_type:
    T_INT {$$ = INT;}
    | T_DOUBLE {$$ = DOUBLE;}
    | T_STRING {$$ = STRING;}
    ;

//---------------------------------------------------------------------
optional_initializer:
    T_ASSIGN expression {$$ = $2;}
    | empty {$$ = NULL;}
    ;

//---------------------------------------------------------------------
object_declaration:
    object_type T_ID {
        // create a new object and it's symbol
        // (Symbol() creates the new object);
        Symbol *symbol = new Symbol(*$2, $1);

        if (!table->insert(symbol))
        {
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
        }
        // assign to global variable so the parameters can be inserted into
        // this object when each parameter is parsed
        cur_object_under_construction = symbol->get_game_object_value();
        cur_object_under_construction_name = symbol->get_name();
  
    }
    T_LPAREN parameter_list_or_empty T_RPAREN
    {
        cur_object_under_construction = NULL;
        delete $2; // Scanner allocates memory for each T_ID string
    }
    | object_type T_ID T_LBRACKET expression T_RBRACKET {
        string *name = $2;
        if ($4 == NULL) {

        } else if ($4->get_type() != INT) {
            Error::error(Error::ARRAY_SIZE_MUST_BE_AN_INTEGER,gpl_type_to_string($4->get_type()),*name);
        } else {
            int size = $4->eval_int();
            if (size <= 0){
                Error::error(Error::INVALID_ARRAY_SIZE, *name, to_string(size));
            } else {
                if ($1 == TRIANGLE){
                    Symbol *s = new Symbol(*name, TRIANGLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ($1 == CIRCLE){
                    Symbol *s = new Symbol(*name, CIRCLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ($1 == RECTANGLE){
                    Symbol *s = new Symbol(*name, RECTANGLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ($1 == TEXTBOX){
                    Symbol *s = new Symbol(*name, TEXTBOX_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ($1 == PIXMAP){
                    Symbol *s = new Symbol(*name, PIXMAP_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else {
                    //invalid type error?
                }
            }
        }
    }
    ;

//---------------------------------------------------------------------
object_type:
    T_TRIANGLE {$$ = TRIANGLE;}
    | T_PIXMAP {$$ = PIXMAP;}
    | T_CIRCLE {$$ = CIRCLE;}
    | T_RECTANGLE {$$ = RECTANGLE;}
    | T_TEXTBOX {$$ = TEXTBOX;}
    ;

//---------------------------------------------------------------------
parameter_list_or_empty :
    parameter_list
    | empty
    ;

//---------------------------------------------------------------------
parameter_list :
    parameter_list T_COMMA parameter
    | parameter
    ;

//---------------------------------------------------------------------
parameter:
    T_ID T_ASSIGN expression {
        string *name = $1;
        if (!cur_object_under_construction->has_member_variable(*name)) {
            Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER,gpl_type_to_string(cur_object_under_construction->get_type()),*name);
        } else {
            Gpl_type *param_type = new Gpl_type(NO_TYPE);
            cur_object_under_construction->get_member_variable_type(*name,*param_type);

            Gpl_type exp_type = $3->get_type();

            if (*param_type == INT) {
                if (exp_type != INT) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE,cur_object_under_construction_name, *$1);
                } else {
                    int val = $3->eval_int();
                    Status status = cur_object_under_construction->set_member_variable(*name,val);
                }
            } else if (*param_type == DOUBLE) {
                if (exp_type != INT && exp_type != DOUBLE) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_under_construction_name, *$1);
                } else {
                    double val = $3->eval_double();
                    Status status = cur_object_under_construction->set_member_variable(*name,val);
                }
            } else if (*param_type == STRING) {
                if (exp_type != INT && exp_type != DOUBLE && exp_type != STRING) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_under_construction_name, *$1);
                } else {
                    string val = $3->eval_string();
                    Status status = cur_object_under_construction->set_member_variable(*name,val);
                }
            } else if (exp_type == ANIMATION_BLOCK) {
                if (*param_type != exp_type) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_under_construction_name, *$1);
                } else {
                    string var_name = $3->eval_variable()->get_name();
                    Symbol *var_sym = table->lookup(var_name);
                    Animation_block *ablock = var_sym->get_animation_block_value();
                    Symbol *param_symbol = ablock->get_parameter_symbol();
                    if (param_symbol == NULL) {} 
                    else if (param_symbol->get_type() != cur_object_under_construction->get_type()) {
                        Error::error(Error::TYPE_MISMATCH_BETWEEN_ANIMATION_BLOCK_AND_OBJECT,cur_object_under_construction_name,ablock->name());
                    } else {
                        Symbol *curr = table->lookup(cur_object_under_construction_name);
                        ablock->initialize(curr,var_name);
                        Status status = cur_object_under_construction->set_member_variable(*name,ablock);
                    }
                }
            } else {}
        } 
    }
    ;

//---------------------------------------------------------------------
forward_declaration:
    T_FORWARD T_ANIMATION T_ID T_LPAREN object_type T_ID T_RPAREN 
    {
        if (table->lookup(*$6) != NULL) {
            Error::error(Error::ANIMATION_PARAMETER_NAME_NOT_UNIQUE,*$6);
        }

            // put animation block and game object into symbol table
            Symbol *s_object = new Symbol(*$6, $5);
            Symbol *s_ablock = new Symbol(*$3,ANIMATION_BLOCK);

            Animation_block *a = s_ablock->get_animation_block_value();
            a->initialize(s_object, *$3);

            table->insert(s_object);
            bool flag = table->insert(s_ablock);
            if (!flag) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$3);
            }
        
    }
    ;

//---------------------------------------------------------------------
block_list:
    block_list block
    | empty
    ;

//---------------------------------------------------------------------
block:
    initialization_block
    | termination_block
    | animation_block
    | on_block
    ;

//---------------------------------------------------------------------
initialization_block:
    T_INITIALIZATION statement_block
    ;

//---------------------------------------------------------------------
termination_block:
    T_TERMINATION statement_block
    ;

//---------------------------------------------------------------------
animation_block:
    T_ANIMATION T_ID T_LPAREN check_animation_parameter T_RPAREN T_LBRACE statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
animation_parameter:
    object_type T_ID
    ;

//---------------------------------------------------------------------
check_animation_parameter:
    object_type T_ID
    ;

//---------------------------------------------------------------------
on_block:
    T_ON keystroke statement_block
    ;

//---------------------------------------------------------------------
keystroke:
    T_SPACE
    | T_LEFTARROW
    | T_RIGHTARROW
    | T_UPARROW
    | T_DOWNARROW
    | T_LEFTMOUSE_DOWN
    | T_MIDDLEMOUSE_DOWN
    | T_RIGHTMOUSE_DOWN
    | T_LEFTMOUSE_UP
    | T_MIDDLEMOUSE_UP
    | T_RIGHTMOUSE_UP
    | T_MOUSE_MOVE
    | T_MOUSE_DRAG
    | T_F1
    | T_AKEY
    | T_SKEY
    | T_DKEY
    | T_FKEY
    | T_HKEY
    | T_JKEY
    | T_KKEY
    | T_LKEY
    | T_WKEY
    | T_ZKEY
    ;

//---------------------------------------------------------------------
if_block:
    statement_block_creator statement end_of_statement_block
    | statement_block
    ;

//---------------------------------------------------------------------
statement_block:
    T_LBRACE statement_block_creator statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
statement_block_creator:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
end_of_statement_block:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
statement_list:
    statement_list statement
    | empty
    ;

//---------------------------------------------------------------------
statement:
    | assign_statement T_SEMIC
    | if_statement
    | print_statement T_SEMIC
    | exit_statement T_SEMIC
    | for_statement
    ;

//---------------------------------------------------------------------
if_statement:
    T_IF T_LPAREN expression T_RPAREN if_block %prec IF_NO_ELSE
    | T_IF T_LPAREN expression T_RPAREN if_block T_ELSE if_block
    ;

//---------------------------------------------------------------------
for_statement:
    T_FOR T_LPAREN statement_block_creator assign_statement_or_empty end_of_statement_block T_SEMIC expression T_SEMIC statement_block_creator assign_statement_or_empty end_of_statement_block T_RPAREN statement_block
    ;

//---------------------------------------------------------------------
print_statement:
    T_PRINT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
exit_statement:
    T_EXIT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
assign_statement_or_empty:
    assign_statement
    | empty
    ;

//---------------------------------------------------------------------
assign_statement:
    variable T_ASSIGN expression
    | variable T_PLUS_ASSIGN expression
    | variable T_MINUS_ASSIGN expression
    | variable T_PLUS_PLUS
    | variable T_MINUS_MINUS
    ;

//---------------------------------------------------------------------
variable:
    T_ID {
        string *id = $1; 
        Symbol *s = table->lookup(*id);
        if (s == NULL) {
            Error::error(Error::UNDECLARED_VARIABLE,*id);
            $$ = new Variable(new Symbol("undeclared",0));
        }
        else if (s->is_array()) {
            Error::error(Error::VARIABLE_IS_AN_ARRAY,*id);
            $$ = new Variable(new Symbol("undeclared",0));
        } else {
            $$ = new Variable(table->lookup(*id));
        }
    }
    | T_ID T_LBRACKET expression T_RBRACKET {
            string *id = $1; 
            Symbol *s = table->lookup(*id);
            Expression *e = $3;
            if (s == NULL) {
                string name = *id + "[]";
                Error::error(Error::UNDECLARED_VARIABLE,name);
                $$ = new Variable(new Symbol("undeclared",0));
            }
            else if (!s->is_array()){
                Error::error(Error::VARIABLE_NOT_AN_ARRAY,*id);
                $$ = new Variable(new Symbol("undeclared",0));
            } else if (e == NULL) {
                
            } else if (e->get_type() != INT) {
                string err = "";
                if (e->get_type() == DOUBLE) {
                    err = "A double expression";
                } else if (e->get_type() == STRING) {
                    err = "A string expression";
                } else {
                    err = "A animation_block expression";
                }
                Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*id, err);
                $$ = new Variable(new Symbol("undeclared",0));
            } else if (!s->index_within_range(e->eval_int())) {
                int num = e->eval_int();
                string n = std::to_string(num);
                Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,*id,n);
                $$ = new Variable(new Symbol("undeclared",0));
            }
            else {$$ = new Variable(s, $3);}
        }
    | T_ID T_PERIOD T_ID
    {
        Symbol *s = table->lookup(*$1);
        if (s == NULL) {
            Error::error(Error::UNDECLARED_VARIABLE, *$1);
            $$ = new Variable(new Symbol("undeclared",0));
        } else {
            if (!(s->get_type() & GAME_OBJECT)) {
                Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT,*$1);
                $$ = new Variable(new Symbol("undeclared",0));
            } else {
                Game_object *g = s->get_game_object_value();
                if (g == NULL) {

                } else {
                    Gpl_type *type = new Gpl_type(NO_TYPE);
                    if (!g->has_member_variable(*$3)) {
                        Error::error(Error::UNDECLARED_MEMBER,*$1,*$3);
                        $$ = new Variable(new Symbol("undeclared",0));
                    } else {
                        g->get_member_variable_type(*$3,*type);
                        if (*type == INT) {
                            int *val = new int(0);
                            Status status = g->get_member_variable(*$3,*val);
                            string newName = *$1 + "." + *$3;
                            Symbol *newSymbol = new Symbol(newName,*val);
                            $$ = new Variable(newSymbol);
                        } else if (*type == DOUBLE) {
                            double *val = new double(0.0);
                            Status status = g->get_member_variable(*$3,*val);
                            string newName = *$1 + "." + *$3;
                            Symbol *newSymbol = new Symbol(newName,*val);
                            $$ = new Variable(newSymbol);
                        } else if (*type == STRING) {
                            string *val = new string("");
                            Status status = g->get_member_variable(*$3,*val);
                            string newName = *$1 + "." + *$3;
                            Symbol *newSymbol = new Symbol(newName,*val);
                            $$ = new Variable(newSymbol);
                        } else if (*type == ANIMATION_BLOCK) {
                            // Animation_block **a;
                            // Status status = g->get_member_variable(*$3,*a);
                            // string newName = *$1 + "." + *$3;
                            // Symbol *newSymbol = new Symbol(newName,ANIMATION_BLOCK);
                            // $$ = new Variable(newSymbol);
                        } else {

                        }
                    }
                }
            }
        }
    }
    | T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID {
            string *id = $1; 
            Symbol *s = table->lookup(*id);
            Expression *e = $3;
            if (s == NULL) {
                string name = *id + "[]";
                Error::error(Error::UNDECLARED_VARIABLE,name);
                $$ = new Variable(new Symbol("undeclared",0));
            }
            else if (!s->is_array()){
                Error::error(Error::VARIABLE_NOT_AN_ARRAY,*id);
                $$ = new Variable(new Symbol("undeclared",0));
            } else if (e == NULL) {
                
            } else if (e->get_type() != INT) {
                string err = "";
                if (e->get_type() == DOUBLE) {
                    err = "A double expression";
                } else if (e->get_type() == STRING) {
                    err = "A string expression";
                } else {
                    err = "A animation_block expression";
                }
                Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*id, err);
                $$ = new Variable(new Symbol("undeclared",0));
            } else if (!s->index_within_range(e->eval_int())) {
                int num = e->eval_int();
                string n = std::to_string(num);
                Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,*id,n);
                $$ = new Variable(new Symbol("undeclared",0));
            }
            else if (!s->is_game_object()) {
                Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT,*$1);
                $$ = new Variable(new Symbol("undeclared",0));
            } else {
                int index = e->eval_int();
                Game_object *g = s->get_game_object_value(index);
                Gpl_type *type = new Gpl_type(NO_TYPE);
                if (!g->has_member_variable(*$6)) {
                    
                } else {
                    g->get_member_variable_type(*$6,*type);
                    if (*type == INT) {
                        int *val = new int(0);
                        Status status = g->get_member_variable(*$6,*val);
                        string newName = *$1 + "." + *$6;
                        Symbol *newSymbol = new Symbol(newName,*val);
                        $$ = new Variable(newSymbol);
                    } else if (*type == DOUBLE) {
                        double *val = new double(0.0);
                        Status status = g->get_member_variable(*$6,*val);
                        string newName = *$1 + "." + *$6;
                        Symbol *newSymbol = new Symbol(newName,*val);
                        $$ = new Variable(newSymbol);
                    } else if (*type == STRING) {
                        string *val = new string("");
                        Status status = g->get_member_variable(*$6,*val);
                        string newName = *$1 + "." + *$6;
                        Symbol *newSymbol = new Symbol(newName,*val);
                        $$ = new Variable(newSymbol);
                    } else if (*type == ANIMATION_BLOCK) {
                        // Animation_block **a;
                        // Status status = g->get_member_variable(*$6,*a);
                        // string newName = *$1 + "." + *$6;
                        // Symbol *newSymbol = new Symbol(newName,ANIMATION_BLOCK);
                        // $$ = new Variable(newSymbol);
                    } else {

                    }
                }
            }
    }

    ;

//---------------------------------------------------------------------
expression:
    primary_expression {
        Expression *e = $1;
        $$ = $1;
        }
    | expression T_OR expression {
            $$ = new Expression(0);
            if ($1->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "||");
            } 
            if ($3->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "||");
            } 
            if ($1->get_type() != STRING && $3->get_type() != STRING) {
                $$ = new Expression(OR, $1, $3);
            }
        }
    | expression T_AND expression {
            $$ = new Expression(0);
            if ($1->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "&&");
                $$ = new Expression(0);
            } 
            if ($3->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "&&");
                $$ = new Expression(0);
            } 
            if ($1->get_type() != STRING && $3->get_type() != STRING) {
                $$ = new Expression(AND, $1, $3);
            }
        }
    | expression T_LESS_EQUAL expression {
        $$ = new Expression(LESS_EQUAL, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE && $1->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "<=");
            $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE && $3->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "<=");
            $$ = NULL;
        }
        }
    | expression T_GREATER_EQUAL  expression {
        $$ = new Expression(GREATER_EQUAL, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE && $1->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, ">=");
            $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE && $3->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, ">=");
            $$ = NULL;
        }
        }
    | expression T_LESS expression {
        $$ = new Expression(LESS_THAN, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE && $1->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "<");
            $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE && $3->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "<");
            $$ = NULL;
        }
        }
    | expression T_GREATER  expression {
        $$ = new Expression(GREATER_THAN, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE && $1->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, ">");
            $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE && $3->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, ">");
            $$ = NULL;
        }
        }
    | expression T_EQUAL expression {
        $$ = new Expression(EQUAL, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE && $1->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "==");
            $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE && $3->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "==");
            $$ = NULL;
        }
        }
    | expression T_NOT_EQUAL expression {$$ = new Expression(NOT_EQUAL, $1, $3);}
    | expression T_PLUS expression {
        $$ = new Expression(PLUS, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE && $1->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "+");
            $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE && $3->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "+");
            $$ = NULL;
        }
    }
    | expression T_MINUS expression {
        $$ = new Expression(MINUS, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "-");
                $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
                $$ = NULL;
        } 
        }
    | expression T_MULTIPLY expression {
        $$ = new Expression(MULTIPLY, $1, $3);
        if ($1->get_type() != INT && $1->get_type() != DOUBLE){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "*");
                $$ = NULL;
        }
        if ($3->get_type() != INT && $3->get_type() != DOUBLE){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "*");
                $$ = NULL;
        } 
        }
    | expression T_DIVIDE expression {
            $$ = new Expression(DIVIDE, $1, $3);
            if ($1->get_type() != INT && $1->get_type() != DOUBLE){
                    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "/");
                    $$ = NULL;
            }
            if ($3->get_type() != INT && $3->get_type() != DOUBLE){
                    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "/");
                    $$ = NULL;
            } 
        }
    | expression T_MOD expression {
            $$ = new Expression(MOD, $1, $3);
            if ($1->get_type() != INT){
                    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "%");
                    $$ = NULL;
            }
            if ($3->get_type() != INT){
                    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "%");
                    $$ = NULL;
            } 
        }
    | T_MINUS  expression %prec UNARY_OPS {
            if ($2->get_type() != INT && $2->get_type() != DOUBLE){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
                $$ = new Expression(0);
            } else {
                $$ = new Expression(UNARY_MINUS, $2);
            }
        }
    | T_NOT  expression %prec UNARY_OPS {
            if ($2->get_type() != INT && $2->get_type() != DOUBLE) {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "!");
                $$ = new Expression(0);
            } else {
                $$ = new Expression(NOT, $2);
            }
        }
    | math_operator T_LPAREN expression T_RPAREN {
        if ($3->get_type() == INT || $3->get_type() == DOUBLE){
            $$ = new Expression($1, $3);
        } else {

            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string($1));
            $$ = new Expression(0);
        }
        }
    | expression T_NEAR expression
    | expression T_TOUCHES expression
    ;

//---------------------------------------------------------------------
primary_expression:
    T_LPAREN  expression T_RPAREN {$$ = $2;}
    | variable {
            if ($1 == NULL) {
            } else {
                $$ = new Expression($1);
            }
        }
    | T_INT_CONSTANT {$$ = new Expression($1);}
    | T_TRUE {$$ = new Expression(1);}
    | T_FALSE {$$ = new Expression(0);}
    | T_DOUBLE_CONSTANT {$$ = new Expression($1);}
    | T_STRING_CONSTANT {$$ = new Expression($1);}
    ;

//---------------------------------------------------------------------
math_operator:
    T_SIN {$$ = SIN;}
    | T_COS {$$ = COS;}
    | T_TAN {$$ = TAN;}
    | T_ASIN {$$ = ASIN;}
    | T_ACOS {$$ = ACOS;}
    | T_ATAN {$$ = ATAN;}
    | T_SQRT {$$ = SQRT;}
    | T_ABS {$$ = ABS;}
    | T_FLOOR {$$ = FLOOR;}
    | T_RANDOM {$$ = RANDOM;}
    ;

//---------------------------------------------------------------------
empty:
    // empty goes to nothing so that you can use empty in productions
    // when you want a production to go to nothing
    ;
