/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calc_morgana.y"

    //Codigo C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <math.h>
    #include <ctype.h>
    #include<stdbool.h>
    extern int yylineno;
    
    int yylex();
    void yyerror(const char *str)
    {
        fprintf(stderr,"Error: %s\n Linha: %d\n", str, yylineno);
    }

    #define name_size 50
    #define string_size 1000

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo real
    typedef struct vars {
        int nodetype;
		char name[name_size];
		float v;
        double *vet; /* variavel para vetor */
		struct vars * prox;
	} VARS;

    // Adicionar nova variavel do tipo real na lista
    VARS * ins(VARS *l, char n[]){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    // Insercao do tipo REAL dentro do Array
    VARS *ins_a(VARS*l,char n[], int tamanho){
		VARS*new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name,n);
		new->vet = (double*)malloc(tamanho * sizeof(double));
		new->prox = l;
		new->nodetype = 3; 
		return new;
	}

    // Insercao da variavel do tipo STRING dentro do Array
    // Insercao da variavel do tipo INT dentro do Array
    
    // Busca uma variável do tipo real na lista de variáveis
	VARS *srch(VARS *l, char n[]){
		VARS *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}
    
    // Verificar se o valor dado é real
    bool is_real(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0 || test[i] == '.'){
                if(test[i]=='.')
                    ponto = ponto + 1;
                if(ponto>1)
                    return false;
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo string
    typedef struct VARST {
		char name[name_size];
		char v[string_size];
		struct VARST * prox;
	} VARST;

    // Adicionar nova variável do tipo string na lista 
    VARST * inst(VARST *l, char n[]){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        strcpy(new->v, "");
		new->prox = l;
		return new;
	}

    // Busca uma nova variável do tipo string na lista de variáveis
    VARST *srcht(VARST *l, char n[]){
		VARST *aux = l;
		while(aux != NULL){
			if(strcmp(n,aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo inteiro
    typedef struct varsi {
		char name[name_size];
		int v;
		struct varsi * prox;
	} VARSI;

    // Adicionar nova variavel inteiro na lista de variáveis inteiro
    VARSI * insi(VARSI *l, char n[]){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    // Busca uma variável inteiro na lista de variáveis inteiro
	VARSI *srchi(VARSI *l, char n[]){
		VARSI *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Verificar se o valor dado é inteiro
    bool is_int(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0){
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

	VARS *rvar = NULL; 
    VARSI *ivar = NULL;
    VARST *tvar = NULL;

    /* O nodetype serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval entender o que realizar naquele no */
    typedef struct ast { /*Estrutura de um nó*/
        int nodetype;
        struct ast *l; /*Esquerda*/
        struct ast *r; /*Direita*/
    }Ast; 

    typedef struct intval { /*Estrutura de um número*/
        int nodetype;
        int v;
    }Intval;

    typedef struct realval { /* Estrutura de um número */
        int nodetype;
        double v;
    }Realval;

    typedef struct textoval { /*Estrutura de um número*/
        int nodetype;
        char v[string_size];
    }Textoval;

    typedef struct varval { /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
        int nodetype;
        char var[name_size];
        int size;
        Ast *length;
    }Varval;

    typedef struct flow { /*Estrutura de um desvio (if/else/while)*/
	    int nodetype;
	    Ast *cond;		/*condição*/
	    Ast *tl;		/*then, ou seja, verdade*/
	    Ast *el;		/*else*/
    }Flow;

    /*Estrutura para um nó de atribuição. Para atrubuir o valor de v em s*/
    typedef struct symasgn { 
        int nodetype;
        char s[name_size];
        Ast *v;
        Ast *n;
        int pos;
        Ast *indice; /* ponteiro para referenciar o indice(posicao) no Array */
    }Symasgn;

    /*Função para criar um nó*/
    Ast * newast(int nodetype, Ast *l, Ast *r){ 

	    Ast *a = (Ast*) malloc(sizeof(Ast));
	    if(!a) {
		    printf("out of space");
		    exit(0);
	}
	    a->nodetype = nodetype;
	    a->l = l;
	    a->r = r;
	    return a;
    }

    /*Função para criar um nó para operador iterator*/
    Ast * newastiterate(int nodetype, Ast *l, Ast *r){ 
         Ast *a = (Ast*) malloc(sizeof(Ast));
	    if(!a) {
		    printf("out of space");
		    exit(0);
	}
	    a->nodetype = nodetype;
	    a->l = l;
	    a->r = r;
	    return a;
    }

    /*Estrutura de um fluxo para o FOR*/
    typedef struct flowfor{ 
        int nodetype;
        Ast* v1;
        Ast* v2;
        Ast* v3;
    }Flowfor;

    /*Função que cria um nó de FOR*/
    Ast * newflowfor(int nodetype, Ast *b1, Ast *b2, Ast *b3, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        Flowfor *b = (Flowfor*)malloc(sizeof(Flowfor));
        if(!b) {
            printf("out of space");
            exit(0);
        }
        b->nodetype = 'F';
        b->v1 = b1;
        b->v2 = b2;
        b->v3 = b3;
        a->nodetype = nodetype;
        a->cond = (Ast*)b;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
    }

    /* Função de que cria um número inteiro (folha)*/
    Ast * newint(int d) {	
        Intval *a = (Intval*) malloc(sizeof(Intval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'k';
        a->v = d;
        return (Ast*)a;
    }


    /*Função de que cria um número real (folha)*/
    Ast * newreal(double d) {		
        Realval *a = (Realval*) malloc(sizeof(Realval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'K';
        a->v = d;
        return (Ast*)a;
    }

    /*Função de que cria um novo texto (folha)*/
    Ast * newtexto(char d[]) {			
        Textoval *a = (Textoval*) malloc(sizeof(Textoval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'm';
        strcpy(a->v, d);
        return (Ast*)a;
    }

    /*Função que cria um nó de if/else/while*/
    Ast * newflow(int nodetype, Ast *cond, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = nodetype;
        a->cond = cond;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
    }

    /*Função que cria um nó para testes lógicos*/
    Ast * newcmp(int cmptype, Ast *l, Ast *r){
        Ast *a = (Ast*)malloc(sizeof(Ast));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '0' + cmptype; /*Para pegar o tipe de teste, definido no arquivo.l e utilizar na função eval()*/
        a->l = l;
        a->r = r;
        return a;
    }

    /* Funcão que cria um nó para a variavel do tipo inteiro ou real ou texto e atribui o valor */
    Ast * newvar(int t, char s[], Ast *v, Ast *n){
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = t; /*tipo i, r ou t, conforme arquivo .l*/
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        a->n = n; /*proxima declaração*/
        return (Ast *)a;
    }

    /* Funcão que cria um nó para a variavel do tipo Array */
    Ast * newarray(int nodetype, char nome[50], int tam) {			
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = nodetype;
        strcpy(a->var,nome);
        a->size = tam;
        return (Ast*)a;
        // a->length = tam;
    }

    /*Função para um nó de atribuição*/
    Ast * newasgn(char s[], Ast *v) { 
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '=';
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        return (Ast *)a;
    }

    /*Função para um nó de atribuição de um numero a uma posicao do Array*/
    /*Ex: vet[2] = 10*/
    Ast * newasgn_a(char s[50], Ast *v, int indice) { 
	    Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '=';
        strcpy(a->s,s);
        a->v = v; /*Valor*/
        a->pos = indice; /* recebe o indice para atribuir o valor a esta posicao */
        return (Ast *)a;
    }

    /*Função que recupera o nome/referência de uma variável, neste caso o número*/
    Ast * newValorVal(char s[]) { 
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'N';
        strcpy(a->var, s);
        return (Ast*)a;
        
    }

    /*Função que recupera a variavel vet[indice===tam] do Array*/
    Ast *newValorVal_a(char s[], int indice)
    {
        Varval *a = (Varval *)malloc(sizeof(Varval));
        if (!a)
        {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'a';
        strcpy(a->var, s);
        a->size = indice;

        return (Ast *)a;
    }

    /* Verificar se a variavel existe na lista de variaveis */
    bool varexiste(char v[]) {
        VARS* xr = srch(rvar, v);
        VARSI* xi = srchi(ivar, v);
        VARST* xt = srcht(tvar, v);

    if(!xr && !xi && !xt) 
        return false; // se tudo NULL, var nao existe
    else
        return true;  // se tudo for TRUE, var existe
    }

    /*Função que executa operações a partir de um nó*/
    double eval(Ast *a) { 
        double v;
        char v1[50];
        double value;
        /*VARS *aux;*/

        if(!a) {
            printf("internal error, null eval\n");
            return 0.0;
        }
        //printf("nodetype: %c\n", a->nodetype);
        switch(a->nodetype) {
            case 'k': v = ((Intval *)a)->v; break; 	/*Recupera um número inteiro*/
            case 'K': v = ((Realval *)a)->v; break; 	/*Recupera um número real*/
            case 'm': v = atof(((Textoval *)a)->v); break; 	/*Recupera um número real dentro de string*/
            case 'N':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                VARS * aux = (VARS*)malloc(sizeof(VARS));
                aux = srch(rvar, ((Varval*)a)->var);
                if (!aux){
                    VARSI * aux2 = (VARSI*)malloc(sizeof(VARSI));
                    aux2 = srchi(ivar, ((Varval*)a)->var);
                    if (!aux2){
                        VARST * aux3 = (VARST*)malloc(sizeof(VARST));
                        if(!aux3){
                                printf("out of space");
                                exit(0);
                            }
                        aux3 = srcht(tvar, ((Varval*)a)->var);
                        if (!aux3){
                            printf ("Erro 'sem valor'. Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            v = atof(aux3->v);
                        }
                    }
                    else{
                        v = (double)aux2->v;
                    }
                }
                else{
                    v = aux->v;
                }
                break;
            case 'a':; /* vet [10] = 20 */
                VARST * xct = (VARST*)malloc(sizeof(VARST));
                xct = srcht(tvar, ((Varval *)a->l)->var);
                v = aux->vet[((Varval *)a)->size];

                aux1 = srch(l1, ((Varval *)a)->var);
                v = aux1->vet[(Varval *a)->size];
                break;
            // ----------------------------------------------------------------- // 
            case 'p':
                value = eval(a->l); /*Recupera um valor STRING*/
                printf("%.2lf", value);
                break;    

            case 'v':; /* buscar a variavel STRING no Array */
                aux = srch(rvar, ((Varval*)a)->var);
                value = eval(((Varval *)a)->length);
                v = aux->vet[(int)value];
                break;
    
            case 'V':; /* vetor */
                rvar = ins(rvar,((Varval*)a)->var);
				break;

            case 'A':;	/* vetor */
                VARST * xct = (VARST*)malloc(sizeof(VARST));
                xct = srcht(tvar, ((Varval*)a)->var);
				// rvar = ins_a(rvar,((Varval*)a)->var,((Varval*)a)->size);
                if (aux == NULL)
                {
                    // value = eval(((Varval *)a)->length);
                    tvar = ins_a(tvar, ((Varval *)a)->var, ((Varval*)a)->size);
                }
                else
                {
                    printf("Redeclaração de variável: %s\n", ((Varval *)a)->var);
                    exit(0);
                }
                break;
            // ----------------------------------------------------------------- //
            case '+': v = eval(a->l) + eval(a->r); break;	/*Operações "árv esq   +   árv dir"*/
            case '-': v = eval(a->l) - eval(a->r); break;	/*Operações de subtração */
            case '*': v = eval(a->l) * eval(a->r); break;	/*Operações de multiplicação */
            case '/': v = eval(a->l) / eval(a->r); break; /*Operação de divisão */
            case 'R': v = sqrt(eval(a->l)); break;				/*Operações RAIZ*/
            case 'M': v = -eval(a->l); break;				/*Operações, número negativo*/
            case '|': v = fabs(eval(a->l)); break;          /*Operações de módulo*/

            case '1': v = (eval(a->l) > eval(a->r))? 1 : 0; break;	/* Operações lógicas. "árv esq   >   árv dir"  Se verdade 1, falso 0 */
            case '2': v = (eval(a->l) < eval(a->r))? 1 : 0; break;
            case '3': v = (eval(a->l) != eval(a->r))? 1 : 0; break;
            case '4': v = (eval(a->l) == eval(a->r))? 1 : 0; break;
            case '5': v = (eval(a->l) >= eval(a->r))? 1 : 0; break;
            case '6': v = (eval(a->l) <= eval(a->r))? 1 : 0; break;
            case '7': v = (eval(a->l) || eval(a->r))? 1 : 0; break;
            case '8': v = (eval(a->l) && eval(a->r))? 1 : 0; break;
            case '?': (eval(((Flow *)a)->cond)) != 0 ? eval(((Flow *)a)->tl) : eval(((Flow *)a)->el); break; /* Case para operador iterator */
            
            /* Atribuicao */
            case '=':; 
                v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                
                VARS * x = (VARS*)malloc(sizeof(VARS));
                if(!x) {
                    printf("out of space");
                    exit(0);
                }
                x = srch(rvar, ((Symasgn *)a)->s);
                if(!x){
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(!xi){
                        printf("Erro 'atribuir valor'. Var '%s' nao declarada.\n", ((Symasgn *)a)->s);
                    } else
                        xi->v = (int)v; /*Atribui à variável do tipo */
                } else {
                        x->v = v; /*Atribui à variável*/
                    }
                }
                break;

            /* caso if ou if/else */
            case 'I': 
                if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
                    if (((Flow *)a)->tl)		/*Se existir árvore*/
                        v = eval(((Flow *)a)->tl); /*Verdade*/
                    else
                        v = 0.0;
                } else {
                    if( ((Flow *)a)->el) {
                        v = eval(((Flow *)a)->el); /*Falso*/
                    } else
                        v = 0.0;
                    }
                break;

            /* caso while */
            case 'W':
                v = 0.0;
                if( ((Flow *)a)->tl) {
                    while( eval(((Flow *)a)->cond) != 0){
                        v = eval(((Flow *)a)->tl);
                        }
                }
            break;

            // leitura das variaveis: int, real e texto
            case 'c':; 
                //v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                VARS * xcr = (VARS*)malloc(sizeof(VARS));
                if(!xcr) {
                    printf("out of space");
                    exit(0);
                }
                xcr = srch(rvar, ((Varval *)a->l)->var);
                if(xcr){
                    scanf("%f", &xcr->v);
                } else {
                    VARSI * xci = (VARSI*)malloc(sizeof(VARSI));
                    if(!xci) {
                        printf("out of space");
                        exit(0);
                    }
                    xci = srchi(ivar, ((Varval *)a->l)->var);
                    if(xci){
                        scanf("%d", &xci->v);
                    } else {
                        VARST * xct = (VARST*)malloc(sizeof(VARST));
                        if(!xct) {
                            printf("out of space");
                            exit(0);
                        }
                        xct = srcht(tvar, ((Varval *)a->l)->var);
                        if(xct){
                            scanf("%s", &xct->v);
                        } else {
                            printf("Variavel inválida!\n");
                        }
                    }
                }
                break;
            
            case 'L': eval(a->l); v = eval(a->r); break; /*Lista de operções em um bloco IF/ELSE/WHILE. Assim o analisador não se perde entre os blocos*/
            case 'n': 
            { /* printar os tipos de variaveis corretamente na saída */
                VARS * auxn = (VARS*)malloc(sizeof(VARS));
                auxn = srch(rvar, ((Varval*)a)->var);
                if (!auxn){
                    VARSI * auxn2 = srchi(ivar, ((Varval*)a)->var);
                    if (!auxn2){
                        VARST * auxn3 = srcht(tvar, ((Varval*)a)->var);
                        if (!auxn3){
                            printf ("359 - Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            Ast * auxnt = (Ast*)malloc(sizeof(Ast));
                            if(!auxnt){
                                printf("out of space");
                                exit(0);
                            }
                            printf("%s", auxn3->v);
                            /*
                            auxnt->nodetype = 'P';
                            auxnt->l = newtexto(auxn3->v);
                            auxnt->r = newast('P', NULL, NULL); // nova alteracao do escreva
                            eval(auxnt);
                            */
                            v = atof(auxn3->v);
                        }
                    }
                    else{
                        Ast * auxni = (Ast*)malloc(sizeof(Ast));
                        if(!auxni){
                            printf("out of space");
                            exit(0);
                        }
                        printf("%d", auxn2->v);
                        /*
                        auxni->nodetype = 'P';
                        auxni->l = newint(auxn2->v);
                        auxni->r = newast('P', NULL, NULL); // nova alteracao do escreva
                        eval(auxni);
                        */
                        v = (double)auxn2->v;
                    }
                }
                else{
                    Ast * auxnr = (Ast*)malloc(sizeof(Ast));
                    if(!auxnr){
                        printf("out of space");
                        exit(0);
                    }
                    printf("%.2f", auxn->v);
                    /*
                    auxnr->nodetype = 'P';
                    auxnr->l = newreal(auxn->v);
                    auxnr->r = newast('P', NULL, NULL); // nova alteracao do escreva
                    eval(auxnr);
                    */
                    v = auxn->v;
                }
                break;
            }
            case 'P': 
                //printf("P1: %c\nP2: %c\n", a->nodetype, a->l->nodetype);
                if(a->l==NULL)
                    break;
                else
                    printf("", a->l->nodetype);
                if(a->l->nodetype == 'N'){
                    a->l->nodetype = 'n';
                    v = eval(a->l);
                    //printf("\nnodetype 'N'\n");
                } else {
                    v = eval(a->l);
                    if(a->l->nodetype != 'n' && a->l->nodetype != 'k' && a->l->nodetype != 'K' && a->l->nodetype != 'm')
                        printf("%.2f", v);
                }
                if(((Intval*)a->l)->nodetype == 'k')
                    printf ("%d", ((Intval*)a->l)->v);		/*Recupera um valor inteiro*/
                else if(((Realval*)a->l)->nodetype == 'K')
                    printf ("%.2f", ((Realval*)a->l)->v);		/*Recupera um valor real*/
                else if(((Textoval*)a->l)->nodetype == 'm')
                    printf ("%s", ((Textoval*)a->l)->v);		/*Recupera um valor texto*/
                if(a->r==NULL){
                    //printf("a->r null\n");
                    printf("\n");
                }else{
                    //printf("a->r ok\n");
                    v = eval(a->r);
                }
                break;  
            /* caso para a opcao FOR */
            case 'F':
                v = 0.0;
                if( ((Flow *)a)->tl ) {
                    for(eval(((Flowfor*)((Flow *)a)->cond)->v1); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v2); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v3)
                        ){
                            v =  eval(((Flow *)a)->tl);
                    }
                }
                break;
            // declaracao da variavel inteira
            case 'i':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    ivar = insi(ivar, ((Symasgn *)a)->s);
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xi->v = (int)eval(((Symasgn *)a)->v); /*Atribui à variável*/
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            // declaracao da variavel real
            case 'r':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    rvar = ins(rvar, ((Symasgn *)a)->s);
                    VARS * xr = (VARS*)malloc(sizeof(VARS));
                    if(!xr) {
                        printf("out of space");
                        exit(0);
                    }
                    xr = srch(rvar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xr->v = eval(((Symasgn *)a)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            // declara a variavel texto
            case 't':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    tvar = inst(tvar, ((Symasgn *)a)->s);
                    VARST * xt = (VARST*)malloc(sizeof(VARST));
                    if(!xt) {
                        printf("out of space");
                        exit(0);
                    }
                    xt = srcht(tvar, ((Symasgn *)a)->s);
                    if((((Symasgn *)a)->v))
                        strcpy(xt->v, ((Textoval*)((Symasgn*)a)->v)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            case 'y':; 
                if(a->l) eval(a->l)
                printf('Entrou no case Y');
                break;
            case 'z':;
                printf("Fim do programa\n");
                free(ivar);
                ivar = NULL;
                free(rvar);
                rvar = NULL;
                free(tvar);
                tvar = NULL;
                exit(0);
                break;

            default: printf("internal error: bad node %c\n", a->nodetype);
        }
        return v;
    }


#line 862 "calc_morgana.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM_REAL = 258,                /* NUM_REAL  */
    NUM_INT = 259,                 /* NUM_INT  */
    VARIAVEL = 260,                /* VARIAVEL  */
    STRING = 261,                  /* STRING  */
    FUNC = 262,                    /* FUNC  */
    PLUS = 263,                    /* PLUS  */
    LESS = 264,                    /* LESS  */
    TIPO_REAL = 265,               /* TIPO_REAL  */
    TIPO_INT = 266,                /* TIPO_INT  */
    TIPO_TEXT = 267,               /* TIPO_TEXT  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    WHILE = 270,                   /* WHILE  */
    FOR = 271,                     /* FOR  */
    INICIO = 272,                  /* INICIO  */
    FINAL = 273,                   /* FINAL  */
    RAIZ = 274,                    /* RAIZ  */
    LEITURA = 275,                 /* LEITURA  */
    ESCREVER = 276,                /* ESCREVER  */
    COMENTARIO = 277,              /* COMENTARIO  */
    CMP = 278,                     /* CMP  */
    IFX = 279,                     /* IFX  */
    VARPREC = 280,                 /* VARPREC  */
    DECLPREC = 281,                /* DECLPREC  */
    NEG = 282,                     /* NEG  */
    VET = 283                      /* VET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 792 "calc_morgana.y"

    char texto[50];
    double real;
    int inteiro;
    int fn; /* operadores lógicos */
    Ast *ast;

#line 945 "calc_morgana.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM_REAL = 3,                   /* NUM_REAL  */
  YYSYMBOL_NUM_INT = 4,                    /* NUM_INT  */
  YYSYMBOL_VARIAVEL = 5,                   /* VARIAVEL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_FUNC = 7,                       /* FUNC  */
  YYSYMBOL_PLUS = 8,                       /* PLUS  */
  YYSYMBOL_LESS = 9,                       /* LESS  */
  YYSYMBOL_TIPO_REAL = 10,                 /* TIPO_REAL  */
  YYSYMBOL_TIPO_INT = 11,                  /* TIPO_INT  */
  YYSYMBOL_TIPO_TEXT = 12,                 /* TIPO_TEXT  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_INICIO = 17,                    /* INICIO  */
  YYSYMBOL_FINAL = 18,                     /* FINAL  */
  YYSYMBOL_RAIZ = 19,                      /* RAIZ  */
  YYSYMBOL_LEITURA = 20,                   /* LEITURA  */
  YYSYMBOL_ESCREVER = 21,                  /* ESCREVER  */
  YYSYMBOL_COMENTARIO = 22,                /* COMENTARIO  */
  YYSYMBOL_CMP = 23,                       /* CMP  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '^'  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_IFX = 31,                       /* IFX  */
  YYSYMBOL_VARPREC = 32,                   /* VARPREC  */
  YYSYMBOL_DECLPREC = 33,                  /* DECLPREC  */
  YYSYMBOL_NEG = 34,                       /* NEG  */
  YYSYMBOL_VET = 35,                       /* VET  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '?'  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_begin = 46,                     /* begin  */
  YYSYMBOL_prog = 47,                      /* prog  */
  YYSYMBOL_stm = 48,                       /* stm  */
  YYSYMBOL_stm1 = 49,                      /* stm1  */
  YYSYMBOL_declmult = 50,                  /* declmult  */
  YYSYMBOL_declmult2 = 51,                 /* declmult2  */
  YYSYMBOL_escrever = 52,                  /* escrever  */
  YYSYMBOL_list = 53,                      /* list  */
  YYSYMBOL_var = 54,                       /* var  */
  YYSYMBOL_expre = 55,                     /* expre  */
  YYSYMBOL_valor = 56                      /* valor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   330

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    29,    26,    24,    42,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    39,
       2,    38,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    31,
      32,    33,    34,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   836,   836,   840,   841,   845,   846,   847,   848,   849,
     850,   851,   852,   853,   854,   855,   856,   857,   858,   866,
     867,   868,   869,   873,   874,   875,   876,   877,   878,   882,
     883,   884,   885,   889,   890,   891,   892,   896,   897,   901,
     906,   909,   912,   915,   918,   921,   924,   927,   930,   933,
     936,   942,   943,   944
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM_REAL", "NUM_INT",
  "VARIAVEL", "STRING", "FUNC", "PLUS", "LESS", "TIPO_REAL", "TIPO_INT",
  "TIPO_TEXT", "IF", "ELSE", "WHILE", "FOR", "INICIO", "FINAL", "RAIZ",
  "LEITURA", "ESCREVER", "COMENTARIO", "CMP", "'+'", "'-'", "'*'", "'/'",
  "'^'", "')'", "'('", "IFX", "VARPREC", "DECLPREC", "NEG", "VET", "'{'",
  "'}'", "'='", "';'", "'?'", "':'", "','", "'['", "']'", "$accept",
  "begin", "prog", "stm", "stm1", "declmult", "declmult2", "escrever",
  "list", "var", "expre", "valor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,    94,    41,
      40,   279,   280,   281,   282,   283,   123,   125,    61,    59,
      63,    58,    44,    91,    93
};
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,   183,    15,  -100,  -100,     1,    11,    26,    36,    19,
      23,    40,    24,    25,    31,  -100,   230,   230,   160,  -100,
      14,    22,   244,  -100,  -100,  -100,  -100,   206,   230,    27,
      32,    33,   230,   230,    35,    46,   230,    69,   213,    43,
    -100,   267,  -100,  -100,    70,    86,   230,   230,   230,   230,
     230,   230,     0,  -100,   259,     2,   230,   230,    88,   274,
     281,   230,   230,   288,    66,    58,    72,   238,  -100,    65,
      67,   196,   -20,   -20,    76,    76,    76,     3,    78,    71,
    -100,   302,   302,  -100,    75,    79,   302,   250,  -100,  -100,
     213,  -100,   213,   230,   100,  -100,  -100,   223,     0,   183,
     183,    40,  -100,  -100,   302,  -100,    84,   295,    82,  -100,
      47,    77,    80,  -100,  -100,  -100,   108,  -100,  -100,   183,
      92,   114,   183,  -100,   137,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    52,    51,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     3,
      10,    11,     0,    50,     1,    16,    17,     0,     0,    27,
      25,    31,     0,     0,     0,     0,     0,     0,     0,    53,
      47,     0,     2,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,    33,    45,    23,
      29,    48,    41,    42,    43,    44,    46,     0,     0,     0,
      49,    28,    26,    32,     0,     0,    39,     0,    40,    13,
       0,    12,     0,     0,     0,    21,    22,     0,     0,     0,
       0,     0,    36,    34,    24,    30,     0,     0,     0,    37,
       0,     0,     0,    19,    20,    15,     5,    38,     7,     0,
       0,     0,     0,    14,     0,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,  -100,    -1,    34,  -100,  -100,   -52,   -99,    30,
     -14,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    18,   109,    79,    20,    21,    66,   110,    35,
      22,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,   111,    40,    41,     1,    77,    49,    50,    51,    25,
      26,    95,    96,    54,    55,    24,    29,    43,    59,    60,
     121,    78,    63,   124,    67,    46,    47,    48,    49,    50,
      51,    30,    71,    72,    73,    74,    75,    76,   102,    27,
     103,    31,    81,    82,    28,    34,    80,    86,    87,    32,
       3,     4,     5,    33,    36,    37,    44,     6,     7,     8,
       9,    38,    10,    11,    45,    56,    12,    13,    14,    15,
      57,    58,    16,    61,    64,    69,    67,    17,    67,   104,
       3,     4,     5,   107,   116,    62,    28,     6,     7,     8,
       9,    70,    10,    11,    83,    89,    12,    13,    14,    15,
      90,    91,    16,    93,    51,    94,   105,    17,    97,   117,
     117,    99,    98,   113,   118,   100,   119,     3,     4,     5,
     117,   115,   120,   117,     6,     7,     8,     9,   122,    10,
      11,   112,   108,    12,    13,    14,    15,     0,     0,    16,
       3,     4,     5,     0,    17,     0,     0,     6,     7,     8,
       9,   123,    10,    11,     0,     0,    12,    13,    14,    15,
       0,     0,    16,     3,     4,     5,     0,    17,     0,     0,
       6,     7,     8,     9,   125,    10,    11,     0,    42,    12,
      13,    14,    15,     0,     0,    16,     3,     4,     5,     0,
      17,     0,     0,     6,     7,     8,     9,     0,    10,    11,
       0,     0,    12,    13,    14,    15,     0,     0,    16,     3,
       4,    39,    53,    17,     0,     0,     3,     4,    39,    65,
      47,    48,    49,    50,    51,    12,     3,     4,    39,   106,
       0,    16,    12,     3,     4,    39,    17,     0,    16,     0,
       0,     0,    12,    17,     0,     0,     0,     0,    16,    12,
       0,     0,     0,    17,     0,    16,     0,     0,     0,     0,
      17,    46,    47,    48,    49,    50,    51,    46,    47,    48,
      49,    50,    51,    46,    47,    48,    49,    50,    51,     0,
      92,     0,    46,    47,    52,    49,    50,    51,     0,   101,
      46,    47,    48,    49,    50,    51,    68,    46,    47,    48,
      49,    50,    51,    84,    46,    47,    48,    49,    50,    51,
      85,    46,    47,    48,    49,    50,    51,    88,    46,    47,
      48,    49,    50,    51,   114,    46,    47,    48,    49,    50,
      51
};

static const yytype_int8 yycheck[] =
{
       1,   100,    16,    17,    17,     5,    26,    27,    28,     8,
       9,     8,     9,    27,    28,     0,     5,    18,    32,    33,
     119,    21,    36,   122,    38,    23,    24,    25,    26,    27,
      28,     5,    46,    47,    48,    49,    50,    51,    90,    38,
      92,     5,    56,    57,    43,     5,    44,    61,    62,    30,
       3,     4,     5,    30,    30,    30,    42,    10,    11,    12,
      13,    30,    15,    16,    42,    38,    19,    20,    21,    22,
      38,    38,    25,    38,     5,     5,    90,    30,    92,    93,
       3,     4,     5,    97,    37,    39,    43,    10,    11,    12,
      13,     5,    15,    16,     6,    29,    19,    20,    21,    22,
      42,    29,    25,    38,    28,    38,     6,    30,    30,   110,
     111,    36,    41,    29,    37,    36,    36,     3,     4,     5,
     121,    39,    14,   124,    10,    11,    12,    13,    36,    15,
      16,   101,    98,    19,    20,    21,    22,    -1,    -1,    25,
       3,     4,     5,    -1,    30,    -1,    -1,    10,    11,    12,
      13,    37,    15,    16,    -1,    -1,    19,    20,    21,    22,
      -1,    -1,    25,     3,     4,     5,    -1,    30,    -1,    -1,
      10,    11,    12,    13,    37,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,     3,     4,     5,    -1,
      30,    -1,    -1,    10,    11,    12,    13,    -1,    15,    16,
      -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,     3,
       4,     5,     6,    30,    -1,    -1,     3,     4,     5,     6,
      24,    25,    26,    27,    28,    19,     3,     4,     5,     6,
      -1,    25,    19,     3,     4,     5,    30,    -1,    25,    -1,
      -1,    -1,    19,    30,    -1,    -1,    -1,    -1,    25,    19,
      -1,    -1,    -1,    30,    -1,    25,    -1,    -1,    -1,    -1,
      30,    23,    24,    25,    26,    27,    28,    23,    24,    25,
      26,    27,    28,    23,    24,    25,    26,    27,    28,    -1,
      42,    -1,    23,    24,    40,    26,    27,    28,    -1,    39,
      23,    24,    25,    26,    27,    28,    29,    23,    24,    25,
      26,    27,    28,    29,    23,    24,    25,    26,    27,    28,
      29,    23,    24,    25,    26,    27,    28,    29,    23,    24,
      25,    26,    27,    28,    29,    23,    24,    25,    26,    27,
      28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    46,     3,     4,     5,    10,    11,    12,    13,
      15,    16,    19,    20,    21,    22,    25,    30,    47,    48,
      50,    51,    55,    56,     0,     8,     9,    38,    43,     5,
       5,     5,    30,    30,     5,    54,    30,    30,    30,     5,
      55,    55,    18,    48,    42,    42,    23,    24,    25,    26,
      27,    28,    40,     6,    55,    55,    38,    38,    38,    55,
      55,    38,    39,    55,     5,     6,    52,    55,    29,     5,
       5,    55,    55,    55,    55,    55,    55,     5,    21,    49,
      44,    55,    55,     6,    29,    29,    55,    55,    29,    29,
      42,    29,    42,    38,    38,     8,     9,    30,    41,    36,
      36,    39,    52,    52,    55,     6,     6,    55,    49,    48,
      53,    53,    54,    29,    29,    39,    37,    48,    37,    36,
      14,    53,    36,    37,    53,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    51,
      51,    51,    51,    52,    52,    52,    52,    53,    53,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     7,    11,     7,     3,     3,
       1,     1,     4,     4,     9,     6,     2,     2,     1,     4,
       4,     2,     2,     3,     5,     2,     4,     2,     4,     3,
       5,     2,     4,     1,     3,     1,     3,     1,     2,     3,
       4,     3,     3,     3,     3,     3,     3,     2,     3,     4,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* begin: INICIO prog FINAL  */
#line 836 "calc_morgana.y"
                         {eval(newast('z', NULL, NULL));}
#line 2091 "calc_morgana.tab.c"
    break;

  case 3: /* prog: stm  */
#line 840 "calc_morgana.y"
          {eval((yyvsp[0].ast));}
#line 2097 "calc_morgana.tab.c"
    break;

  case 4: /* prog: prog stm  */
#line 841 "calc_morgana.y"
                   {eval((yyvsp[0].ast));}
#line 2103 "calc_morgana.tab.c"
    break;

  case 5: /* stm: IF '(' expre ')' '{' list '}'  */
#line 845 "calc_morgana.y"
                                              {(yyval.ast) = newflow('I', (yyvsp[-4].ast), (yyvsp[-1].ast), NULL);}
#line 2109 "calc_morgana.tab.c"
    break;

  case 6: /* stm: IF '(' expre ')' '{' list '}' ELSE '{' list '}'  */
#line 846 "calc_morgana.y"
                                                      {(yyval.ast) = newflow('I', (yyvsp[-8].ast), (yyvsp[-5].ast), (yyvsp[-1].ast));}
#line 2115 "calc_morgana.tab.c"
    break;

  case 7: /* stm: WHILE '(' expre ')' '{' list '}'  */
#line 847 "calc_morgana.y"
                                       {(yyval.ast) = newflow('W', (yyvsp[-4].ast), (yyvsp[-1].ast), NULL);}
#line 2121 "calc_morgana.tab.c"
    break;

  case 8: /* stm: VARIAVEL '=' expre  */
#line 848 "calc_morgana.y"
                                       {(yyval.ast) = newasgn((yyvsp[-2].texto), (yyvsp[0].ast));}
#line 2127 "calc_morgana.tab.c"
    break;

  case 9: /* stm: VARIAVEL '=' STRING  */
#line 849 "calc_morgana.y"
                          {(yyval.ast) = newasgn((yyvsp[-2].texto), newtexto((yyvsp[0].texto)));}
#line 2133 "calc_morgana.tab.c"
    break;

  case 10: /* stm: declmult  */
#line 850 "calc_morgana.y"
               { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2139 "calc_morgana.tab.c"
    break;

  case 11: /* stm: declmult2  */
#line 851 "calc_morgana.y"
                { (yyval.ast) = (yyvsp[0].ast) ;}
#line 2145 "calc_morgana.tab.c"
    break;

  case 12: /* stm: ESCREVER '(' escrever ')'  */
#line 852 "calc_morgana.y"
                                {(yyval.ast) = (yyvsp[-1].ast);}
#line 2151 "calc_morgana.tab.c"
    break;

  case 13: /* stm: LEITURA '(' VARIAVEL ')'  */
#line 853 "calc_morgana.y"
                               {(yyval.ast) = newast('c', newValorVal((yyvsp[-1].texto)), NULL);}
#line 2157 "calc_morgana.tab.c"
    break;

  case 14: /* stm: FOR var ';' expre ';' var '{' list '}'  */
#line 854 "calc_morgana.y"
                                             { (yyval.ast) = newflowfor('F', (yyvsp[-7].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), NULL);}
#line 2163 "calc_morgana.tab.c"
    break;

  case 15: /* stm: expre '?' stm1 ':' stm1 ';'  */
#line 855 "calc_morgana.y"
                                  {(yyval.ast) = newflow('?', (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));}
#line 2169 "calc_morgana.tab.c"
    break;

  case 16: /* stm: VARIAVEL PLUS  */
#line 856 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2175 "calc_morgana.tab.c"
    break;

  case 17: /* stm: VARIAVEL LESS  */
#line 857 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2181 "calc_morgana.tab.c"
    break;

  case 18: /* stm: COMENTARIO  */
#line 858 "calc_morgana.y"
                 {(yyval.ast) = newast('P', NULL, NULL);}
#line 2187 "calc_morgana.tab.c"
    break;

  case 19: /* stm1: ESCREVER '(' STRING ')'  */
#line 866 "calc_morgana.y"
                              {(yyval.ast) = newast('P', newtexto((yyvsp[-1].texto)), NULL);}
#line 2193 "calc_morgana.tab.c"
    break;

  case 20: /* stm1: ESCREVER '(' expre ')'  */
#line 867 "calc_morgana.y"
                             {(yyval.ast) = newast('P', (yyvsp[-1].ast), NULL);}
#line 2199 "calc_morgana.tab.c"
    break;

  case 21: /* stm1: VARIAVEL PLUS  */
#line 868 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2205 "calc_morgana.tab.c"
    break;

  case 22: /* stm1: VARIAVEL LESS  */
#line 869 "calc_morgana.y"
                               {(yyval.ast) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2211 "calc_morgana.tab.c"
    break;

  case 23: /* declmult: declmult ',' VARIAVEL  */
#line 873 "calc_morgana.y"
                                 {(yyval.ast) = newvar((yyvsp[-2].ast)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].ast));}
#line 2217 "calc_morgana.tab.c"
    break;

  case 24: /* declmult: declmult ',' VARIAVEL '=' expre  */
#line 874 "calc_morgana.y"
                                      {(yyval.ast) = newvar((yyvsp[-4].ast)->nodetype, (yyvsp[-2].texto), (yyvsp[0].ast), (yyvsp[-4].ast));}
#line 2223 "calc_morgana.tab.c"
    break;

  case 25: /* declmult: TIPO_INT VARIAVEL  */
#line 875 "calc_morgana.y"
                        {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2229 "calc_morgana.tab.c"
    break;

  case 26: /* declmult: TIPO_INT VARIAVEL '=' expre  */
#line 876 "calc_morgana.y"
                                  {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].ast), NULL);}
#line 2235 "calc_morgana.tab.c"
    break;

  case 27: /* declmult: TIPO_REAL VARIAVEL  */
#line 877 "calc_morgana.y"
                         {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2241 "calc_morgana.tab.c"
    break;

  case 28: /* declmult: TIPO_REAL VARIAVEL '=' expre  */
#line 878 "calc_morgana.y"
                                   {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].ast), NULL);}
#line 2247 "calc_morgana.tab.c"
    break;

  case 29: /* declmult2: declmult2 ',' VARIAVEL  */
#line 882 "calc_morgana.y"
                                  {(yyval.ast) = newvar((yyvsp[-2].ast)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].ast));}
#line 2253 "calc_morgana.tab.c"
    break;

  case 30: /* declmult2: declmult2 ',' VARIAVEL '=' STRING  */
#line 883 "calc_morgana.y"
                                        {(yyval.ast) = newvar((yyvsp[-4].ast)->nodetype, (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), (yyvsp[-4].ast));}
#line 2259 "calc_morgana.tab.c"
    break;

  case 31: /* declmult2: TIPO_TEXT VARIAVEL  */
#line 884 "calc_morgana.y"
                         {(yyval.ast) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2265 "calc_morgana.tab.c"
    break;

  case 32: /* declmult2: TIPO_TEXT VARIAVEL '=' STRING  */
#line 885 "calc_morgana.y"
                                    {(yyval.ast) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), NULL);}
#line 2271 "calc_morgana.tab.c"
    break;

  case 33: /* escrever: expre  */
#line 889 "calc_morgana.y"
                {(yyval.ast) = newast('P', (yyvsp[0].ast), NULL);}
#line 2277 "calc_morgana.tab.c"
    break;

  case 34: /* escrever: expre ',' escrever  */
#line 890 "calc_morgana.y"
                         {(yyval.ast) = newast('P', (yyvsp[-2].ast), (yyvsp[0].ast));}
#line 2283 "calc_morgana.tab.c"
    break;

  case 35: /* escrever: STRING  */
#line 891 "calc_morgana.y"
             {(yyval.ast) = newast('P', newtexto((yyvsp[0].texto)), NULL);}
#line 2289 "calc_morgana.tab.c"
    break;

  case 36: /* escrever: STRING ',' escrever  */
#line 892 "calc_morgana.y"
                          {(yyval.ast) = newast('P', newtexto((yyvsp[-2].texto)), (yyvsp[0].ast));}
#line 2295 "calc_morgana.tab.c"
    break;

  case 37: /* list: stm  */
#line 896 "calc_morgana.y"
          {(yyval.ast) = (yyvsp[0].ast);}
#line 2301 "calc_morgana.tab.c"
    break;

  case 38: /* list: list stm  */
#line 897 "calc_morgana.y"
               { (yyval.ast) = newast('L', (yyvsp[-1].ast), (yyvsp[0].ast));}
#line 2307 "calc_morgana.tab.c"
    break;

  case 39: /* var: VARIAVEL '=' expre  */
#line 901 "calc_morgana.y"
                         {(yyval.ast) = newasgn((yyvsp[-2].texto), (yyvsp[0].ast));}
#line 2313 "calc_morgana.tab.c"
    break;

  case 40: /* expre: RAIZ '(' expre ')'  */
#line 906 "calc_morgana.y"
                       { 
        {(yyval.ast) = newast('R',(yyvsp[-1].ast),NULL);}
    }
#line 2321 "calc_morgana.tab.c"
    break;

  case 41: /* expre: expre '+' expre  */
#line 909 "calc_morgana.y"
                      {
        (yyval.ast) = newast('+', (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2329 "calc_morgana.tab.c"
    break;

  case 42: /* expre: expre '-' expre  */
#line 912 "calc_morgana.y"
                      {
        (yyval.ast) = newast('-',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2337 "calc_morgana.tab.c"
    break;

  case 43: /* expre: expre '*' expre  */
#line 915 "calc_morgana.y"
                      {
        (yyval.ast) = newast('*',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2345 "calc_morgana.tab.c"
    break;

  case 44: /* expre: expre '/' expre  */
#line 918 "calc_morgana.y"
                      {
        (yyval.ast) = newast('/',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2353 "calc_morgana.tab.c"
    break;

  case 45: /* expre: '(' expre ')'  */
#line 921 "calc_morgana.y"
                    {
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2361 "calc_morgana.tab.c"
    break;

  case 46: /* expre: expre '^' expre  */
#line 924 "calc_morgana.y"
                      {
        (yyval.ast) = newast('^',(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2369 "calc_morgana.tab.c"
    break;

  case 47: /* expre: '-' expre  */
#line 927 "calc_morgana.y"
                          {
        (yyval.ast) = newast('M',(yyvsp[0].ast),NULL); 
    }
#line 2377 "calc_morgana.tab.c"
    break;

  case 48: /* expre: expre CMP expre  */
#line 930 "calc_morgana.y"
                      { /* Testes condicionais */
        (yyval.ast) = newcmp((yyvsp[-1].fn),(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2385 "calc_morgana.tab.c"
    break;

  case 49: /* expre: VARIAVEL '[' expre ']'  */
#line 933 "calc_morgana.y"
                             {
        (yyval.ast) = newValorVal_a((yyvsp[-3].texto), (yyvsp[-1].ast));
    }
#line 2393 "calc_morgana.tab.c"
    break;

  case 50: /* expre: valor  */
#line 936 "calc_morgana.y"
            { 
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 2401 "calc_morgana.tab.c"
    break;

  case 51: /* valor: NUM_INT  */
#line 942 "calc_morgana.y"
               { (yyval.ast) = newint((yyvsp[0].inteiro));}
#line 2407 "calc_morgana.tab.c"
    break;

  case 52: /* valor: NUM_REAL  */
#line 943 "calc_morgana.y"
               { (yyval.ast) = newreal((yyvsp[0].real));}
#line 2413 "calc_morgana.tab.c"
    break;

  case 53: /* valor: VARIAVEL  */
#line 944 "calc_morgana.y"
               {           
        (yyval.ast) = newValorVal((yyvsp[0].texto));  /* Funcao da chamada newValorVal retorna um tipo Ast que dps e usado em eval */
    }
#line 2421 "calc_morgana.tab.c"
    break;


#line 2425 "calc_morgana.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 949 "calc_morgana.y"


#include "lex.yy.c"

int main(){
    yyin=fopen("entrada_morg.txt", "r");
    
    yyparse();
    yylex();
    fclose(yyin);
    return 0;

}

int yywrap(){
    return 0;
}
