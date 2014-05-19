#ifndef __TREE_H_
#define __TREE_H_

#ifndef CODE
typedef struct burm_state *STATEPTR_TYPE; 
#endif

enum {
  /* logical ops */
  OP_NOT = 1,
  OP_OR,

  /* comparison */
  OP_EQ,
  OP_GT,
  OP_GEQ,
  OP_LS,
  OP_LEQ,
  OP_NEQ,

  /* arithmetic */
  OP_ADD,
  OP_MUL,
  OP_NEG,

  /* various */
  OP_ID,
  OP_Number,
  OP_Field,
  OP_Return,
  OP_Zero,
  OP_One,
  OP_Args,
  OP_Call,
  OP_ReadMem,
  OP_IF,
  OP_Stats,
  OP_NOP,
  OP_Assign,
  OP_AND,
  OP_GREATER
};

static char rule_names[100][100]={
  "",
  /* logical ops */
  "OP_NOT",
  "OP_OR",

  /* comparison */
  "OP_EQ",
  "OP_GT",
  "OP_GEQ",
  "OP_LS",
  "OP_LEQ",
  "OP_NEQ",

  /* arithmetic */
  "OP_ADD",
  "OP_MUL",
  "OP_NEG",

  /* various */
  "OP_ID",
  "OP_Number",
  "OP_Field",
  "OP_Return",
  "OP_Zero",
  "OP_One",
  "OP_Args",
  "OP_Call",
  "OP_ReadMem",
  "OP_IF",
  "OP_Stats",
  "OP_NOP",
  "OP_Assign",
  "OP_AND",
  "OP_GREATER"
};
    

/* struct for the tree build by ox for iburg */
typedef struct treenode {
  int op;
  struct treenode *child[2];
  STATEPTR_TYPE label;
  char *name;
  long value;
  char *reg;
  struct treenode *parent;
  int skip_reg;
  int param_index; /* -1 if not a parameter */
  int usage_count;
  int offset;
} treenode;

typedef treenode *treenodep;

/* macros for iburg being able to traverse the tree */
#define NODEPTR_TYPE      treenodep
#define OP_LABEL(p)       ((p)->op)
#define LEFT_CHILD(p)     ((p)->child[0])
#define RIGHT_CHILD(p)    ((p)->child[1])
#define STATE_LABEL(p)    ((p)->label)
#define PANIC     printf

/* see tree.c for description about these procedures */
treenode *new_node(int, treenode *, treenode *);
treenode *new_node_value(int, treenode *, treenode *, long, int);
treenode *new_leaf(int);
treenode *new_number_leaf(long);
treenode *new_named_leaf(int , char *);
treenode *new_named_leaf_value(int , char *, long);
treenode *new_named_node(int, treenode *, treenode *, char *);
treenode *new_id_leaf(int, char *, int);
treenode * new_field_leaf(int ,char* ,treenode * ,int);

void write_indent(int );
void write_tree(treenode *, int);

#endif /* __TREE_H */
