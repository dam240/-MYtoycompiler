
struct parameter 
{
	char * type;
	char * parametername;
	char *  value;
	int ip;
	int typem;

};

struct Structpost{
	int index;
	char * step;
	int vail;
};



struct StructSymbol
{
	//parameter *  para;
	//vector<Structpost>  step;
     struct Arraylist *  paraname;
	struct StructSymbol * net;

	int len;
};


struct methods{

	char * name;
	char * retype;
	struct	parameter  * partParams;
	int patansize;

};

struct Structstride{
	
 
	int index; 
	int in;
		int type;

};


struct  Vsort{
	int ip;
	int index;
};

struct processInstruct{

	char * code;
    int index;
	 int valid;

};


struct  expressionV{
	   
	 char * left;
	 char *  right;
	 int ip;
	  int opem; 
	
};




struct ANDORS{
	
 
	int E; 
	int B;
    int type;

};






struct operation{
	int step;
   int code;
};


struct operationinstruct //
{
  	int step;
	int index;
	char * code;

};
struct instruct // 处理if + ，
{
	int step;
	int index;
	char * code;
    struct operation oper;
    struct Arraylist *  parameter;

};



struct Structsend{
	
 
struct	Structstride * b; 
struct	Structstride * e;

};



struct IFLR{
	
	 struct Arraylist * ob;
	 struct Arraylist * operns;
	//vector<instruct *> ob;
	//vector<operation> operns;

};


struct symbolMethod
{
	 char * MethodName;
	    struct Arraylist *   code;
	 //  vector <processInstruct> stepcodel;
	  char * Paramscode;
	  char * retParam;
	 int  params;//函数传参
	 int MethodHead;
	 int MethodEnd;
struct	parameter  * partParams; //函数传参
struct	StructSymbol  * MethodStruct;
};


int ReturnEndPart(char * p);
int ReturnHeadPart(char * p);
int ReturnMoPart(char * p);

void setcode(struct  symbolMethod * m, struct Arraylist * p,int index,int endddd);
char * FindMethdNames(char * p,int end);
struct symbolMethod * FindMethdName( struct Arraylist * m,int index,int endddd,int other);
