typedef enum { Void, Int, Float, Double, String, Char, Bool } TYPE;
typedef enum { Protected, Private, Public, None }             SCOPE;

typedef struct {
  char *file;
  bool  userDef;
} Include;

typedef struct {
  TYPE  type;
  char *name;
  char *value;
} Variable;

typedef struct {
  SCOPE     scope;
  TYPE      type;
  char     *name;
  Variable *vars;
} Function;

// TODO: expand to use classes and read classes
// struct Class {
//      SCOPE scope;
//      char *name;
//      Function *funcs;
// };
//
