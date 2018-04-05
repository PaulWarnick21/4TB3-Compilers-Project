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
  int   address
} Variable;

typedef struct {
  SCOPE scope;
  TYPE  type;
  char *name;
  int   localVars;
  int   globalVars;
} Function;

// TODO: expand to use classes and read classes
// struct Class {
//      SCOPE scope;
//      char *name;
//      Function *funcs;
// };
//
