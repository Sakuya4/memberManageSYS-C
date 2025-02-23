#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pre def limit 
#define TRUE    1
// #define FALSE   0
#define MAX     128
#define MAXCLINE   16
#define MAXNAME     64
#define MAXDATA     1024
#define MEMBERNUMLEN 8  // 8 digits mem code or def by your self

// B+ tree
#define MAX_KEYS 3  // 最大鍵數
#define MAX_CHILD (MAX_KEYS + 1) // 子節點數量

// def fun use num (CRUD or another)
#define INSERT  1
#define DELETE  2
#define UPDATE  3
#define SEARCH  4
#define SAVE    5  //or auto save
#define DISPLAY 6  //if data large maybe useless
#define HELP    7
#define EXIT    0
#define ILLEGAL  -1 //syntax error
#define ERROR   -2 //normal error


typedef struct member
{
    unsigned int memberNUMBER;
    char name[MAXNAME];
}Member;

/* build B+ tree for efficacy */
typedef struct BPlusTreeNode {
    int keys[MAX_KEYS];                  
    Member* members[MAX_KEYS];         
    struct BPlusTreeNode* children[MAX_CHILD];  // child
    struct BPlusTreeNode* next;          // Leaf connect
    int key_count;                       // key num
    int is_leaf;                         // leaf yes or not
} BPlusTreeNode;

BPlusTreeNode* createNode(int is_leaf) {
    BPlusTreeNode *node = (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
    node->is_leaf = is_leaf;
    node->key_count = 0;
    node->next = NULL;
    for (int i = 0; i < MAX_CHILD; i++) {
        node->children[i] = NULL;
    }
    return node;
}

/* def every function */

int getCommand(char *command)
{
    int CMD = ILLEGAL;
    if(strcmp(command, "insert") == 0) CMD = INSERT;
    if(strcmp(command, "delete") == 0) CMD = DELETE;
    if(strcmp(command, "update") == 0) CMD = UPDATE;
    if(strcmp(command, "search") == 0) CMD = SEARCH;
    if(strcmp(command, "save") == 0) CMD = SAVE;
    if(strcmp(command, "display") == 0) CMD = DISPLAY;
    if(strcmp(command, "help") == 0) CMD = HELP;
    if(strcmp(command, "exit") == 0) CMD = EXIT;
    return CMD;
}

int insert()
{
    printf("insert: insert a new member\n");
    return 0;
}

int delete()
{
    printf("delete: delete a member\n");
    return 0;
}

int update()
{
    printf("update: update a member\n");
    return 0;
}

int search()
{
    printf("search: search a member\n");
    return 0;
}

int save()
{
    printf("save: save all members\n");
    return 0;
}

int display()
{
    printf("display: display all members\n");
    return 0;
}

int help()
{
    printf("help: show help\n");
    printf("All Commands:\n");
    printf("  insert   : Insert a new member\n");
    printf("  delete   : Delete a member\n");
    printf("  update   : Update member information\n");
    printf("  search   : Search for a member\n");
    printf("  save     : Save all members to file\n");
    printf("  display  : Display all members\n");
    printf("  help     : Show help message\n");
    printf("  exit     : Exit the program\n");
    return 0;
}

void exitProgram()
{
    printf("exit: exit the program\n");
    exit(0); //exit program
}

int main()
{
    int CMD = ILLEGAL;
    char command[MAXCLINE] = {0};
    char data[MAXDATA] = {0};
    Member maxmem[MAX];
    Member *mems = maxmem;

    while(TRUE)
    {
        printf("memberMangeSYS> ");
        scanf("%s", command);
        CMD = getCommand(command);
        switch(CMD)
        {
            case INSERT:
                insert();
                break;
            case DELETE:
                delete();
                break;
            case UPDATE:
                update();
                break;
            case SEARCH:
                search();
                break;
            case SAVE:
                save();
                break;
            case DISPLAY:
                display();
                break;
            case HELP:
                help();
                break;
            case EXIT:
                exitProgram();
                break;
            default:
                printf("illegal command, use command help for available commands.\n");
                break;
        }
    }
    return 0;
}