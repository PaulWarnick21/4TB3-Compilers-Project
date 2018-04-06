typedef enum { Void, Int, Float, Double, String, Char, Bool } TYPE;
typedef enum { Protected, Private, Public, None }             SCOPE;

typedef struct {
  const char *file;
  bool  userDef;
} Include;

// typedef struct {
//   const char *file;
//   bool  userDef;
// } Comment;

typedef struct {
  TYPE type;
  const char *value;
} Print;

typedef struct {
  TYPE  type;
  const char *name;
  const char *value;
  int   address = -1;
} Variable;

typedef struct {
  SCOPE scope;
  TYPE  type;
  const char *name;
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
