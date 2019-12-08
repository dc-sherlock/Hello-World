/* ����
  flex exp.l
  bison -d exp.y
  gcc -o a lex.yy.c exp.tab.c
  a        
  ���뺬�������ͱ�ʶ���ı��ʽ��س�
  ����CTRL+Z����
*/


%error-verbose
%{
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
extern FILE *yyin;
extern char *yytext;
struct ASTNode {
		int kind;     //0��ʾ�������㣬1��ʾ������ 2��ʾ��ʶ��
		union {
			  struct {
					  char op;
					  struct ASTNode *first,*second;
					 } OPNode;
			  int int_const;
			  char id[32];
			  };
		};
void display(struct ASTNode *T,int ident);
%}
%union {
	int    type_int;
	char   type_id[32];
	struct ASTNode *ptr;
	};
%token <type_int> INTEGER
%token <type_id>  ID
%type  <ptr> line exp

%left '+'
%left '*'
%%
input:
	 |input line
line : '\n'    {}
	 | exp'\n' {display($1,0);}

exp	 : INTEGER {printf("����%d��Լ��exp������Ҷ�ӽ��\n",$1);$$=(struct ASTNode *)malloc(sizeof(struct ASTNode ));$$->kind=1;$$->int_const=$1;}
	 | ID {printf("��ʶ��%s��Լ��exp������Ҷ�ӽ��\n",$1);$$=(struct ASTNode *)malloc(sizeof(struct ASTNode ));$$->kind=2;strcpy($$->id, $1);}
	 | exp '+' exp {printf("exp + exp��Լ��exp�����ɡ�+���ķ�Ҷ�ӽ��\n");$$=(struct ASTNode *)malloc(sizeof(struct ASTNode ));
					$$->kind=0;$$->OPNode.first=$1;$$->kind=0;$$->OPNode.second=$3;$$->OPNode.op='+';}
	 | exp '*' exp {printf("exp *exp��Լ��exp�����ɡ�*���ķ�Ҷ�ӽ��\n");
					$$=(struct ASTNode *)malloc(sizeof(struct ASTNode ));
					$$->kind=0;$$->OPNode.first=$1;$$->kind=0;$$->OPNode.second=$3;$$->OPNode.op='*';}
	 | '(' exp')'  {printf("(exp)��Լ��exp���������½��\n");$$=$2;}  

%%
int main(int agrc, char **argv){
	yyparse();
	return 0;
	}
yyerror(char *s){
   printf(" %s\n",s);
 }
void display(struct ASTNode *T,int ident)
{
if (T){
	switch (T->kind) {
		case 0: printf("%*c%c\n",ident,' ',T->OPNode.op);
				display(T->OPNode.first,ident+4);
				display(T->OPNode.second,ident+4);
				break;
		case 1:printf("%*c%d\n",ident,' ',T->int_const);
				break;
		case 2:printf("%*c%s\n",ident,' ',T->id);
	
		}

}


}

