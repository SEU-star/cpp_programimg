#include<stdio.h>
#include<string.h>
void fangwuxinxi();
void zuke();
void ruzu();
void add();
void add1();
void xiugai();
void xiugai1();
void shanchu();
void shanchu1(); 
void xianshi();
void xianshi1();
void chazhao();
void chazhao1(); 
void guanli();
void cha1();
void cha2();
struct fang{
	int bianma;
	char dizhi[10];
	int mengpaihao;
	double price;
	int AN;
	char name[10];
}a[10];
struct zu{
	int id;
	char name[10];
	char jiguan[10];
	int shijian;
	int fangbian;
}b[10];
int n=0;
int k=0;
int main()
{
	int no=1;
	int num;
	while(no)
	{
		printf("*************************************\n");
		printf("           房屋租赁信息系统         *\n");
		printf("*************************************\n");
		printf("          1.房屋信息                 \n\n");
		printf("          2.承租者信息               \n\n");
		printf("          3.入住管理                 \n\n");
		printf("          4.退出系统                 \n\n");
		scanf("%d",&num);
		switch(num)
		{
		case 1:fangwuxinxi();
			break;
		case 2:zuke();
			break;
		case 3:guanli();
			break;
		case 4:
			{
				printf("欢迎下次继续使用");
				no=0;
				return 0;
			}
		}
	}
}
void fangwuxinxi(){
	int no=1;
	int f;
	while(no)
	{
	
	printf("**************************************\n");
	printf("             房屋信息                 \n");
	printf("**************************************\n");
	printf("            1.添加房屋信息            \n\n");
	printf("            2.修改房屋信息            \n\n");
	printf("            3.删除房屋信息            \n\n");
	printf("            4.显示房屋信息            \n\n");
	printf("            5.查找房屋信息            \n\n");
	printf("            6.返回上一界面            \n\n");
	scanf("%d",&f);
	switch(f)
		{
		case 1:add();
			break;
		case 2:xiugai();
			break;
		case 3:shanchu();
			break;
		case 4:xianshi();
			break;
		case 5:chazhao();
			break;
		case 6:no=0;
		break;
		}
	}
}
void add()//添加 
{
	int m;
	int b=1;
	char c;
	printf("现在录入数据\n\n");
	while(b)
	{
		
		for(m=n;m<10;m++)
		{
			
			printf("请输入你想录入的房屋编码：\n");
			scanf("%d",&a[m].bianma);
			printf("请输入房屋地址：\n\n");
			scanf("%s",a[m].dizhi);
			printf("请输入房屋的门牌号：\n\n");
			scanf("%d",&a[m].mengpaihao);
			printf("请输入房屋的价格：\n\n");
			scanf("%lf",&a[m].price);
			printf("请输入房屋是否出租(是为1，否为0)\n\n");
			scanf("%d",&a[m].AN);
			printf("请输入租房者姓名，没有的话输入无：\n\n");
			scanf("%s",a[m].name); 
			n++;
			
			printf("是否继续录入？\n\n");
			scanf(" %c",&c);
			if(c=='Y')
			{
				b=1;
				break; 
			}
			else(c=='N');
			{
				
				b=0;
				printf("输入完成！\n");
				break;
			}
		}
	}
}
void xiugai()//修改 
{
	int i,z;
	char x[20],c[20];
	printf("请输入您想修改的房屋编码：\n");
	scanf("%d",&z);
	if(n<=0)
	{
		printf("没有任何住房信息，无法修改\n");
		return; 
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(z==a[i].bianma)
			{
				printf("请输入你想录入的房屋编码：\n");
				scanf("%d",&a[i].bianma);
				printf("请输入房屋地址：\n\n");
				scanf("%s",x);
				strcpy(a[i].dizhi,x);
				printf("请输入房屋的门牌号：\n\n");
				scanf("%d",&a[i].mengpaihao);
				printf("请输入房屋的价格：\n\n");
				scanf("%f",&a[i].price);
				printf("请输入房屋是否出租(是为1，否为0)\n\n");
				scanf("%d",&a[i].AN);
				printf("请输入租房者姓名，没有的话输入无：\n\n");
				scanf("%s",c); 
				strcpy(a[i].name,c);
			}
			else
			{
			    printf("没有找到您要修改的房屋信息\n");
			}
		}
	}
 
}
void shanchu()//删除 
{
	int i,s;
	int j;
	for(i=0;i<n;i++)
	{
		printf("请输入您想删除的房屋编码：\n");
		scanf("%d",&s);
		if(s==a[i].bianma)
		{
			printf("已经成功删除\n\n");
			for(j=i;j<n;j++)
			{
				a[j]=a[j+1];
				n--;
			}
		break;
		}else
		{
			printf("没有该房屋的具体信息\n\n");
		}
	}
 
}
void xianshi()//显示 
{
	int i;
	printf("房屋编码	房屋地址    	房屋门牌号   	房屋价格     	 是否承租    	承租者姓名\n");
	printf("------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++){
		printf("%d		%s		%d		%lf  		%d		%s\n\n",a[i].bianma,a[i].dizhi,a[i].mengpaihao,a[i].price,a[i].AN,a[i].name);	
	}
	return;
 } 
void chazhao()//查找 
{
	int g,i;
	printf("请输入您像查看的房屋编码：\n\n");
	scanf("%d",&g);
	for(i=0;i<n;i++)
	{
		if(g==a[i].bianma)
		{
			printf("房屋编码	房屋地址    	房屋门牌号   	房屋价格     	 是否承租    	承租者姓名\n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%d		%lf  		%d		%s\n\n",a[i].bianma,a[i].dizhi,a[i].mengpaihao,a[i].price,a[i].AN,a[i].name);
			return;	
		}
	}
	printf("没有查到房屋的相关信息") ;
}
void zuke()
{
	int z;
	int no=1;
	while(no)
	{
		printf("************************************************\n");
		printf("*                承租者信息                    *\n");
		printf("************************************************\n\n");
		printf(" 1.添加承租者信息        2.修改承租者信息  \n\n");
		printf(" 3.删除承租者信息        4.显示承租者信息  \n\n");
		printf(" 5.查找承租者信息        6.返回主界面    \n");
		scanf("%d",&z);
		switch(z)
		{
			case 1:add1();
				break;
			case 2:xiugai1();
				break;
			case 3:shanchu1();
				break;
			case 4:xianshi1();
				break;
			case 5:chazhao1();
				break;
			case 6:no=0;
				break;
		}
	}
	
}
void add1()//添加 
{
	int m;
	int p=1;
	char c;
	printf("现在录入数据\n\n");
	while(p)
	{
		
		for(m=k;m<10;m++)
		{
			
			printf("请输入你想录入的承租者ID：\n");
			scanf("%d",&b[m].id);
			printf("请输入承租者姓名：\n\n");
			scanf("%s",b[m].name);
			printf("请输入承租者的籍贯：\n\n");
			scanf("%s",b[m].jiguan);
			printf("请输入承租者入住的时间：\n\n");
			scanf("%d",&b[m].shijian);
			printf("请输入租房者租的房子的房屋编码,没有请输入0\n\n");
			scanf("%d",&b[m].fangbian); 
			k++;
			
			printf("是否继续录入？\n\n");
			scanf(" %c",&c);
			if(c=='Y')
			{
				p=1;
				break; 
			}
			else(c=='N');
			{
				
				p=0;
				printf("输入完成！\n");
				break;
			}
		}
	}
}
void xiugai1()//修改 
{
	int m,z;
	char x[20],c[20];
	printf("请输入您想修改的承租者id：\n");
	scanf("%d",&z);
	if(k<=0)
	{
		printf("没有任何住房信息，无法修改\n");
		return; 
	}
	else
	{
		for(m=0;m<k;m++)
		{
			if(z==b[m].id)
			{
				printf("请输入你想录入的承租者ID：\n");
				scanf("%d",&b[m].id);
				printf("请输入承租者姓名：\n\n");
				scanf("%s",x);
				strcpy(b[m].name,x);
				printf("请输入承租者的籍贯：\n\n");
				scanf("%s",c);
				strcpy(b[m].jiguan,c);
				printf("请输入承租者入住的时间：\n\n");
				scanf("%d",&b[m].shijian);
				printf("请输入租房者租的房子的房屋编码,没有请输入0\n\n");
				scanf("%d",&b[m].fangbian); 
			}
			else
			{
			    printf("没有找到您要修改的房屋信息\n");
			}
		}
	}
 
}
void shanchu1()//删除
{
	int i,s;
	int j;
	for(i=0;i<k;i++)
	{
		printf("请输入您想删除的承租者的id：\n");
		scanf("%d",&s);
		if(s==b[i].id)
		{
			printf("已经成功删除\n\n");
			for(j=i;j<n;j++)
			{
				b[j]=b[j+1];
				k--;
			}
		break;
		}else
		{
			printf("没有该承租者的具体信息\n\n");
		}
	}
} 
void xianshi1()//显示 
{
	int i;
	printf("租客id		租客姓名    	租客籍贯  	 租客入住时间    	房屋编号     \n");
	printf("------------------------------------------------------------------------------------------\n");
	for(i=0;i<k;i++){
		printf("%d		%s		%s		%d  		%d		\n\n",b[i].id,b[i].name,b[i].jiguan,b[i].shijian,b[i].fangbian);	
	}
	return;
 } 
 
void chazhao1()//查找 
{
	int g,i;
	printf("请输入承租者的id：\n\n");
	scanf("%d",&g);
	for(i=0;i<k;i++)
	{
		if(g==b[i].id)
		{
			printf("租客id		租客姓名    	租客籍贯  	 租客入住时间    	房屋编号     \n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%s		%d  		%d		\n\n",b[i].id,b[i].name,b[i].jiguan,b[i].shijian,b[i].fangbian);	
			return;	
		}
	}
	printf("没有查到承租者的信息\n\n") ;
}//void ruzu()
void guanli()
{
	int r;
	int no=1;
	while(no)
	{
		printf("************************************************\n");
		printf("*               入住管理                       *\n");
		printf("************************************************\n");
		printf("  1.输入房屋编号查询         2.输入客户ID查询  \n");
		printf("  3.返回主页面\n");
		scanf("%d",&r);
		switch(r)
			{
			case 1:cha1();
				break;
			case 2:cha2();
				break;
			case 3:no=0;
				break;
			}
	}
	
}
void cha1()
{
	int g,i;
	printf("请输入您像查看的房屋编码：\n\n");
	scanf("%d",&g);
	for(i=0;i<n;i++)
	{
		if(g==a[i].bianma)
		{
			if(a[i].AN==1)
			{
				printf("房屋编号		承租者\n\n");
				printf("%d		%s\n\n",a[i].bianma,a[i].name);
				return; 
			}
			else
			{
				printf("没有任何承租信息\n\n");
			}
			return;	
		}
	}
	printf("没有查到房屋的相关信息\n\n") ;
	 
}
void cha2()
{
	int g,i;
	printf("请输入承租者的id：\n\n");
	scanf("%d",&g);
	for(i=0;i<k;i++)
	{
		if(g==b[i].id)
		{
			if(b[i].fangbian!=0)
			{
				printf("房屋编号		承租者\n\n");
				printf("%d		%s\n\n",b[i].fangbian,b[i].name);
				return; 
			}
			else
			{
				printf("没有任何承租信息\n\n");
			}
			return;	
		}
	}
	printf("没有查到承租者的信息\n\n") ;
}