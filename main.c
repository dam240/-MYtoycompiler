#include "list.h"
#include "befile.h"
#include <stdio.h>
#include <stdlib.h>
#include "sybla.h"
#include "uril.h"
#include <sys/stat.h>
#include <fcntl.h>

#include "centre.h"


void filew2(char * na, char  *obj){
 int r_id=open(na,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
  int r=0;
  int j,i;
 int cou=0;



// for(j=0;j<obj->length;j++){
//char * p=getarray(obj,j);
//int  size=strlen(p);
//size+=10;

//char o[]="hello\nohjee\n";
int  size=strlen(obj);
//printf(" %s%d \n",p,size);
  r = write(r_id,obj,size);

    //  printf("--> %d %d\n",r,obj->typesize);
	  
// }
    if(close(r_id)==-1){
     printf("clsee--> %s\n",na);
     }
}



void filewrite(char * name,  char  *obj){
int r_id=open(name,O_RDWR|O_APPEND,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);//读写和创建和尾部写, rw-rw-rw前线
   if(r_id==-1){
   filew2(name,obj);
   puts("编译成功");
  // return;
  // exit(-1);
   }

  if(lseek(r_id,0,SEEK_END)==-1)
   {

    if(close(r_id)==-1){
    // puts("编译失败");
     }

    exit(-1);
    }
      int r =0,i;
//  for(i=0;i<obj->length;i++){
	//char * p=getarray(obj,i);
  int size=strlen(obj);
   r = write(r_id,obj,size);

//  }
   // printf("-->%d %d %d\n",r,obj->typesize,obj->length);

    if(close(r_id)==-1){
     printf("clsee--> %s\n",name);
	 
     }

}

void setMethodesn(struct Arraylist *  storageCode,char * name);


void printfparameter(struct parameter * p,int len){

	//printf(" printfparameter===========%d \n",len);
             int i;

	for( i=0;i<len;i++){
		
		
		//printf(" type== %s \n",p[i].type);

		//printf(" parametername== %s \n",p[i].parametername);
	}


// printf("-----------\n");

}





void printfcopde( struct Arraylist *  list){


		int size	=list->length;
 int j;	
   for( j=0;j<size;j++){

	 //  printf("%s \n",getarray(list,j));
   }

}






 struct Arraylist * loadfile(  struct Arraylist * list){
	//  printf("loadfile======================\n");

	      struct Arraylist * line;
		  line=inif();
		  int size=list->length;
		  char *os=	getarray( list,size-1);
	struct	 Structsend * p=(struct Structsend  *  )malloc(sizeof(struct Structsend));
	if(p==NULL){
// printf("00000000000\n");	 
	 exit(-1);	
	}
	 p->b=(struct Structstride *)malloc(sizeof(struct Structstride));
	if(!p->b)
		exit(-1);
		p->e=(struct Structstride *)malloc(sizeof(struct Structstride));
	if(!p->e)
		exit(-1);
	
	//	  printf("loadfile=======1=========%d=====\n",list->length);
		 p->b->in=0;
		 p->b->index=0;
		 p->b->type=1;
		 //	  printf("loadfile=======1=========%d=====\n",list->length);
		
		 p->e->in=strlen(os);
		 	//  printf("loadfile=======1=========%d=====\n",list->length);
		 p->e->index=size-1;
		 p->e->type=2;
		//  printf("loadfile======fff  \n");
		 add(line,p);
		 	//  printf("loadfile======fsff  \n");
		// line.push_back();
		 	//  printf("loadfile=========end=============\n");
		 return line;

}



int main(int argc,char *argv[]){






//printf("%d  %s\n",argc,argv[r]);

  char * filenasd=NULL;
if(argc>=4){

 if(compareNames(argv[1],"gdd")){
   if(compareNames(argv[2],"-d")){

        filenasd=argv[3];
        int fsize=strlen(filenasd);
    if(filenasd[fsize-1]=='c'){
         if(filenasd[fsize-2]=='d'){
           if(filenasd[fsize-3]=='.'){

 printf("%s\n",filenasd);
}else{
 printf("文件不对 %s\n",filenasd);
 exit(-1);
        }

}else{
 printf("文件不对 %s\n",argv[3]);
 exit(-1);
        }

       }else{
 printf("文件不对%s\n",argv[2]);
 exit(-1);
        }
          

//compareNames(,"-d")





}else{
 printf("无法识别该命令  %s\n",argv[1]);
 exit(-1);

}

 
}else{
 printf("无法识别该命令%s\n",argv[1]);
 exit(-1);

}
}else if(argc==2){

 if(compareNames(argv[1],"help")){

 printf("暂时不支持\n");
 exit(-1);
 
 }


}








struct Arraylist * reTlist  =returntype();
//printf("hello \n");

int j;
char * p= readfile(filenasd);
//printf("====%d\n",strlen(p));
   struct Arraylist * meth;
   meth=pd(p);
   free(p);
// printf("==================================================\n");
 /*
for(j=0;j<meth->length;j++){
    p = getarray(meth,j); 
   printf("%s  \n",p);
  
}
*/

 //printf("==================================================\n");


  meth=LOWDd(meth);
/*
for(j=0;j<meth->length;j++){
    p = getarray(meth,j);
   printf("%s  \n",p);

}
*/



printf("==================================================\n");






struct Arraylist *  lists   =halffile(meth);







//printf("===============main===end===========\n");
struct Arraylist *  relist;
  relist=inif();

 struct Arraylist *mdf;
	 mdf=inif();

 struct methods * pri=(struct methods *)malloc(sizeof( struct methods));
	 char prina[]="printf";
	 pri->name=prina;
	 char priva[]="void";
	 pri->retype=priva;
	 pri->patansize=1;
	 add(mdf,pri);
	//printf("====================000000000000==============================\n");
for(j=0;j<lists->length;j++){
struct symbolMethod * sp=	(struct symbolMethod *)getarray(lists,j);

  if(verifyReType(reTlist,sp->retParam)==0){
    printf("找不到%s函数 返回类型 %s \n",sp->MethodName,sp->retParam);
  exit(-1);	
  }


  struct methods * sdi=(struct methods *)malloc(sizeof( struct methods));
	if(!sdi)
		exit(-1);
	
	 sdi->name=sp->MethodName;
	 sdi->retype=sp->retParam;
             sdi->patansize=sp->params;
             sdi->partParams=sp->partParams;
	 	 add(mdf,sdi);



}

//printf("=====================000000000000000000=============================\n");

for(j=0;j<lists->length;j++){



	struct symbolMethod * sp=	(struct symbolMethod *)getarray(lists,j);

    //      printf("函数%s \n",sp->MethodName);
	//printf("参数%d \n",sp->params);
	//printf("返回%s \n",sp->retParam);	


	//printfparameter(sp->partParams,sp->params);
	//printf("内部代码\n");

  //    printfcopde(sp->code);
      
    if(sp->code->length!=0){

       //   printf(" ========================sss --------\n");
            strutcMthod(sp);

          strutcMthodechan(sp);

              
	   verifyType(sp,1); //校验变量和类型
	   	//printf("====================excreteStructs==============================\n");

//printf("================================================\n");
	
     struct Arraylist * listStructsend;
	
		listStructsend=loadfile(sp->code);
//printf("====================\n");
          struct Arraylist * lisexcrete    =excreteStructs(listStructsend,sp,mdf);

    //   printf("==================%d=======%d========\n",lisexcrete->length,relist->length);
int y=0;
   for(y=0;y<lisexcrete->length;y++){
   char * opd =(char *)getarray(lisexcrete,y);
 //  printf("%s   ",opd);
       add(relist,opd);
//add(relist,"\n");
   }
//printf("=================================\n");


}else{

 setMethodesn(relist,sp->MethodName);
add(relist,"\n");
add(relist,"\n");
add(relist,"\n");
add(relist,"\n");
add(relist,"\n");
}


}














//printf("=============sssssssssssssssssssssss====================\n");

  int rebei= returnIndex('.',filenasd);
   char * nametxt=divideStr(filenasd,rebei,0);
 char * nafile=malloc(40);
 sprintf(nafile,"%s.od\0\n",nametxt);

//printf("=================%s================\n",nafile);


//printf("=================%d================\n",relist->length);
int uo;
int counts=0;
for(uo=0; uo<relist->length; uo++){
   char * p=getarray(relist, uo);
  counts+=strlen(p);
}

  int r,n,c=0;
  char * fien=malloc(counts+20);

//printf("==========d====d======\n");
 for(r=0;r<relist->length;r++){
	  
	  
	  char * ptxt=(char *)getarray(relist,r);
	//  printf("%d\n",r);
	   int sizns=strlen(ptxt);
	//  printf("%d\n",sizns);
	  for(n=0;n<sizns;n++){

		  fien[c]=ptxt[n];
		  c++;
	  }
	  
        //   printf("==========end==========\n");
	//  free(ptxt);
	 
	  
  }

//printf("==========d==========\n");






for( uo=0; uo<relist->length; uo++){
char * p=getarray(relist, uo);
//printf("%d\n", uo);
//filewrite(nafile,p);

printf("%s\n",p);

}

filewrite(nafile,fien);


free(meth->obj);
free(meth);
free(lists->obj);
free(lists);



free(relist->obj);

free(relist);


return 0;
}
