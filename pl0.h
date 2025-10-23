/*
 * PL/0 complier program for win32 platform (implemented in C)
 *
 * The program has been test on Visual C++ 6.0,  Visual C++.NET and
 * Visual C++.NET 2003,  on Win98,  WinNT,  Win2000,  WinXP and Win2003
 *
 */

#define false_val 0
#define true_val 1


#define norw 18     /* 关键字个数 */
#define txmax 100   /* 名字表容量 */
#define nmax 14     /* number的最大位数 */
#define al 10       /* 符号的最大长度 */
#define amax 2047   /* 地址上界*/
#define levmax 3    /* 最大允许过程嵌套声明层数 [0,  levmax]*/
#define cxmax 500   /* 最多的虚拟机代码数 */
#define countmax 3
/* 符号 */
enum symbol {
    nul,         ident,     number,     plus,      minus,
    times,       slash,     oddsym,     eql,       neq,
    lss,         leq,       gtr,        geq,       lparen,
    rparen,      comma,     semicolon,  period,    becomes,
    beginsym,    endsym,    ifsym,      thensym,   whilesym,
    writesym,    readsym,   dosym,      callsym,   constsym,
    varsym,      procsym,   forsym,     tosym,     colon,
    mod,         power,     andop,      orop,      notop,
    elsesym,     typedefsym
};
#define symnum 42  

/* 名字表中的类型 */
enum object {
    constant,
    variable,
    procedur,
    array,      // 1维数组
    array2d,    // 2维数组
    typedef_obj // typedef定义的类型别名
};

/* 虚拟机代码 */
enum fct {
    lit,     opr,     lod,
    sto,     cal,     inte,
    jmp,     jpc,     sto2,
    lod2,    lod2d,  sto2d,
};
#define fctnum 12

/* 虚拟机代码结构 */
struct instruction
{
    enum fct f; /* 虚拟机代码指令 */
    int l;      /* 引用层与声明层的层次差 */
    int a;      /* 根据f的不同而不同 */
};

FILE* fas;  /* 输出名字表 */
FILE* fa;   /* 输出虚拟机代码 */
FILE* fa1;  /* 输出源文件及其各行对应的首地址 */
FILE* fa2;  /* 输出结果 */
int listswitch;    /* 显示虚拟机代码与否 */
int tableswitch;   /* 显示名字表与否 */
char ch;            /* 获取字符的缓冲区，getch 使用 */
enum symbol sym;    /* 当前的符号 */
char id[al+1];      /* 当前ident, 多出的一个字节用于存放0 */
int num;            /* 当前number */
int cc, ll;          /* getch使用的计数器，cc表示当前字符(ch)的位置 */
int cx;           /* 虚拟机代码指针, 取值范围[0, cxmax-1]*/
char line[81];      /* 读取行缓冲区 */
char a[al+1];       /* 临时符号, 多出的一个字节用于存放0 */
struct instruction code[cxmax]; /* 存放虚拟机代码的数组 */
char word[norw][al];        /* 保留字 */
enum symbol wsym[norw];     /* 保留字对应的符号值 */
enum symbol ssym[256];      /* 单字符的符号值 */
char mnemonic[fctnum][6];   /* 虚拟机代码指令名称 */
int declbegsys[symnum];    /* 表示声明开始的符号集合 */
int statbegsys[symnum];    /* 表示语句开始的符号集合 */
int facbegsys[symnum];     /* 表示因子开始的符号集合 */

/* 名字表结构 */
struct tablestruct
{
    char name[al];      /* 名字 */
    enum object kind;   /* 类型：const, var, array, array2d, procedure or typedef */
    int val;            /* 数值，仅const使用 */
    int level;          /* 所处层，仅const不使用 */
    int adr;            /* 地址，仅const不使用 */
    int size;           /* 需要分配的数据区空间, 仅procedure使用 */
    int low;            /* 数组下界，仅array使用 */
    int high;           /* 数组上界，仅array使用 */
    int low2;           /* 2维数组第二维下界，仅array2d使用 */
    int high2;          /* 2维数组第二维上界，仅array2d使用 */
    int dim1_size;      /* 第一维大小，仅array2d使用 */
    char original_type[al]; /* 原始类型名，仅typedef使用 */
    int original_kind;  /* 原始类型种类，仅typedef使用 */
};

struct tablestruct table[txmax]; /* 名字表 */

FILE* fin;
FILE* fout;
char fname[al];
int err; /* 错误计数器 */
int count;

/* 当函数中会发生fatal error时，返回-1告知调用它的函数，最终退出程序 */
#define getsymdo                      if(-1 == getsym()) return -1
#define getchdo                       if(-1 == getch()) return -1
#define testdo(a, b, c)               if(-1 == test(a, b, c)) return -1
#define gendo(a, b, c)                if(-1 == gen(a, b, c)) return -1
#define expressiondo(a, b, c)         if(-1 == expression(a, b, c)) return -1
#define factordo(a, b, c)             if(-1 == factor(a, b, c)) return -1
#define termdo(a, b, c)               if(-1 == term(a, b, c)) return -1
#define conditiondo(a, b, c)          if(-1 == condition(a, b, c)) return -1
#define statementdo(a, b, c)          if(-1 == statement(a, b, c)) return -1
#define constdeclarationdo(a, b, c)   if(-1 == constdeclaration(a, b, c)) return -1
#define vardeclarationdo(a, b, c)     if(-1 == vardeclaration(a, b, c)) return -1
#define power_termdo(a, b, c)         if(-1 == power_term(a, b, c)) return -1

void error(int n);
int getsym();
int getch();
void init();
int gen(enum fct x, int y, int z);
int test(int* s1, int* s2, int n);
int inset(int e, int* s);
int addset(int* sr, int* s1, int* s2, int n);
int subset(int* sr, int* s1, int* s2, int n);
int mulset(int* sr, int* s1, int* s2, int n);
int block(int lev, int tx, int* fsys);
void interpret();
int factor(int* fsys, int* ptx, int lev);
int term(int* fsys, int* ptx, int lev);
int condition(int* fsys, int* ptx, int lev);
int expression(int* fsys, int* ptx, int lev);
int statement(int* fsys, int* ptx, int lev);
void listcode(int cx0);
int vardeclaration(int* ptx, int lev, int* pdx);
int constdeclaration(int* ptx, int lev, int* pdx);
int typedefdeclaration(int* ptx, int lev, int* pdx);
int position(char* idt, int tx);
void enter(enum object k, int* ptx, int lev, int* pdx);
void enterArray2D(int* ptx, int lev, int* pdx, int start1, int end1, int start2, int end2, char* nameBuf);
int base(int l, int* s, int b);
int power_term(int* fsys, int* ptx, int lev);