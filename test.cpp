// // #include <iostream>
// // using namespace std;

// // int c;
// // int a[10];
// // int main() {
// //     a[-1] = 2000;
// //     a[-2] = 2000;
// //     cout << a[-1] << c << endl;
// // }
// #include <cmath>
// #include <iostream>

// using namespace std;

// int Log[(int)2e5];
// void pre() {
//     Log[1] = 0, Log[2] = 1;
//     for(int i = 3; i <= 2e5; i ++) {
//         Log[i] = Log[i / 2] + 1;
//     }
// }

// int main() {
//     // int n; cin >> n;
//     int n = 2e5;
//     pre();
//     for(int i = 1; i <= n; i++) {
//         if((int)log2(i) != Log[i]) {
//             cout << i << ' ' << Log[i] << ' ' <<(int) log2(i) << endl;
//         }
//     }
//     cout << "successful!" << endl;
// }

#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <windows.h>

int zhiye=0;
int xiyoudu=6;
int line=0;
int num=0;
int enchantcount=0;
 
		 
void AttributeModifiers()
{
	SetConsoleOutputCP(CP_UTF8);
	FILE *fp = fopen("item.txt","a");
	
	printf("物品属性生效唯一位置:\n");
	printf("4、手持\n5、头部\n6、胸部\n7、腿部\n8、鞋子\n");
    scanf("%d",&num);

    if(num>8 || num<4)
    {
		printf("输入非法,AttributeModifiers部分请自行填充");
		return ; 
	}
	fprintf(fp,",AttributeModifiers:[");
	float count;
	
	printf("基础伤害:\n");
	scanf("%f",&count);
	fprintf(fp,"{Operation:0,UUIDLeast:%d01,UUIDMost:%d01,Amount:%f,AttributeName:generic.attackDamage,Name:基础伤害},\n",num,num,count);
	
	if(num==4) {
	printf("百分伤害:\n");
	scanf("%f",&count);
	fprintf(fp,"{Operation:1,UUIDLeast:%d02,UUIDMost:%d02,Amount:%f,AttributeName:generic.attackDamage,Name:百分伤害},\n",num,num,count);
	}
	
	printf("基础生命:\n");
	scanf("%f",&count);
	fprintf(fp,"{Operation:0,UUIDLeast:%d03,UUIDMost:%d03,Amount:%f,AttributeName:generic.maxHealth,Name:基础生命},\n",num,num,count);
	
	if(num==4) {
	printf("百分生命:\n");
	scanf("%f",&count);
	fprintf(fp,"{Operation:1,UUIDLeast:%d04,UUIDMost:%d04,Amount:%f,AttributeName:generic.maxHealth,Name:百分生命},\n",num,num,count);	
	}
	
	printf("击退抗性:\n");
	scanf("%f",&count);
	fprintf(fp,"{Operation:0,UUIDLeast:%d05,UUIDMost:%d05,Amount:%f,AttributeName:generic.knockbackResistance,Name:击退抗性},\n",num,num,count);		
	
    printf("移动速度:\n");
	scanf("%f",&count);	
	fprintf(fp,"{Operation:1,UUIDLeast:%d06,UUIDMost:%d06,Amount:%f,AttributeName:generic.movementSpeed,Name:移动速度}]",num,num,count);
	fclose(fp); 
}

void Enchant()
{
	FILE *fp = fopen("item.txt","a");
	enchantcount++;
	printf("输入第%d项附魔的ID类型(输入-1来停止附魔）\n",enchantcount);
	int level; int enchant; scanf("%d",&enchant);
	if(enchant>100||enchant<-1)
	{
		printf("非法输入导致非法输出,附魔部分程序已终止\n");
		fprintf(fp,"],");
		fclose(fp);		
		return ; 
	}
	if(enchant!=-1)
	{
		fprintf(fp,"{id:%d,lvl:",enchant);
		printf("输入该附魔等级\n");
		scanf("%d",&level);
	    if(level<0||level>32767)
	    {
			printf("非法输入导致非法输出,附魔被视作0级,附魔部分程序已终止\n");
			fprintf(fp,"0}],");
			fclose(fp);		
			return ; 
		}	
			
		fprintf(fp,"%d},",level);

		fclose(fp);
		Enchant();
	}
	else
	{
		fprintf(fp,"],");
		fclose(fp);
	}
	return;
}


void Display2()
{
		FILE *fp = fopen("item.txt","a");
		line++;
		printf("填写第%d行描述,用enter键来确认并换行,不要使用空格,不写入颜色符号,结束描述输入\"e\"\n",line);
		char text[1000];
		scanf("%s",text);
		int n=strlen(text);
		

		if(n!=1 || text[0] != 'e')		
		{
			fprintf(fp,"\"§7§o");
			for(int i=0;i<n;i++)			
			{	
				fprintf(fp,"%c",text[i]);
			}
			fprintf(fp,"\",\n");
			fclose(fp);		
			Display2();
			return;
		}
		fclose(fp);	
		FILE *fp1 = fopen("item.txt","a");
		
		if(n==1 && text[0] == 'e')
		{
			printf("分别输入箭矢强度,阵法强度和战斗强度,数字间用空格分开,不写入颜色符号\n");
			int arrowstrength,formstrength,attackstrength;
			scanf("%d %d %d",&arrowstrength,&formstrength,&attackstrength);
		
			if (arrowstrength != 0)
			{
				fprintf(fp1,"\"§7箭矢强度 ");
		    	fprintf(fp1,"%d",arrowstrength);
				fprintf(fp1,"\",\n");
			}
			
			if (formstrength != 0)
			{
				fprintf(fp1,"\"§7阵法强度 ");
			   	fprintf(fp1,"%d",formstrength);
			   	fprintf(fp1,"\",\n");
			}
			
	        if (attackstrength != 0)
			{
		    	fprintf(fp1,"\"§7阵法强度 ");
			   	fprintf(fp1,"%d",formstrength);
			   	fprintf(fp1,"\",\n");
			}
						
			fclose(fp1);			
		}
		
				
		
}

void Display()
{
	FILE *fp = fopen("item.txt","a");
	fprintf(fp,"display:{"); 
	printf("自定义物品名称,\"^\"可自动转换为颜色符号§,不要使用空格\n");
	char text[1000];
	scanf("%s",text);
	int n=strlen(text);
	fprintf(fp,"Name:\"");
	for(int i=0;i<n;i++)
	{
		if(text[i]=='^') fprintf(fp,"§");
		else fprintf(fp,"%c",text[i]);
	}
	fprintf(fp,"\",");
	
	printf("输入物品的稀有度3/4/5/6:\n");
	scanf("%d",&xiyoudu);
	if(xiyoudu==3)
	{
		fprintf(fp,"Lore:[\"§9稀有度：★★★\",\n");
	}
	else if(xiyoudu==4)
	{
		fprintf(fp,"Lore:[\"§d稀有度：★★★★\",\n");
	}
	else if(xiyoudu==5)
	{
		fprintf(fp,"Lore:[\"§e稀有度：★★★★★\",\n");
	}
	else if(xiyoudu==6)
	{
		fprintf(fp,"Lore:[\"§c稀有度：★★★★★★  [唯一]\",\n");
	}
	else
	{
		printf("输入非法，已默认稀有度为 6\n");
		fprintf(fp,"Lore:[\"§c稀有度：★★★★★★  [唯一]\",\n");
	}
	
	
	printf("输入物品使用的职业要求 0:战士 1:弓箭手 2:炼丹师 3或其他数字:无限制\n");
	scanf("%d",&zhiye);
	if(zhiye>3 || zhiye<0)
	{
		fprintf(fp,"\"§6推薦職業：[戰] [弓] [丹]\",\n");
	}
	else if(zhiye==0)
	{
		fprintf(fp,"\"§6限制職業：[戰]\",\n");
	}
	else if(zhiye==1)
	{
		fprintf(fp,"\"§6限制職業：[弓]\",\n");
	}
	else if(zhiye==2)
	{
		fprintf(fp,"\"§6限制職業：[丹]\",\n");
	}	
	fclose(fp);
}

void Create()
{ 
FILE *fp = fopen("item.txt","w");
fprintf(fp,"give @p");

printf("输入物品item\n");
char item[100]; scanf("%s",item);
fprintf(fp," %s",item);

printf("数量\n");
char number[100]; scanf("%s",number);
fprintf(fp," %s",number);

printf("数据\n");
char data[100]; scanf("%s",data);
fprintf(fp," %s \n{",data);

fclose(fp);

FILE *fp1 = fopen("item.txt","a");
fprintf(fp1,"ench:[");
fclose(fp1);
Enchant();

Display();
Display2();
FILE *fpd = fopen("item.txt","a");
fprintf(fpd,"]}");
fclose(fpd);


FILE *fp2 = fopen("item.txt","a");
if(num==4) fprintf(fp2,",\nHideFlags:4");
else fprintf(fp2,",\nHideFlags:61");
fprintf(fp2,",\nUnbreakable:1");
fclose(fp2);

AttributeModifiers();

FILE *fpa = fopen("item.txt","a");
fprintf(fpa,"}");
fclose(fpa);

return;
}

int main()
{
	printf("\n=======物品生成器=======\n");
	printf("梦回录1.8.3盘灵古域专供生成器:QQ597147107\n");
	printf("符号使用:换行符用\\n，颜色符用^代替§\n");
	printf("正在进入系统...\n");
	Create();
	printf("生成成功，请在同级文件夹中查找\'item.txt\'");
}
