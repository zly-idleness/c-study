
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
#define NUM 10000 //洗牌混乱度
 
char color[7][20] = {"none","Heart","Spades","Clubs","Diamonds","Color joker","Black joker"};  
char number[13][10]={"0","A","2","3","4","5","6","7","8","9","jack","queen","king"};  
 
//构建扑克
struct card{
    char* color;
    char* number;
};
 
int NUM_card=53; //剩余未发的牌数(发牌时用的变量)
 
struct card card[54]; //创建保存一副牌的结构体
 
 
//构建一副牌(有序)
void creat_pair_card()
{
    int num=1;
    int col=1;
    int i=0;
    for (num=1;num<=15;num++)
    {
        //生成大小王
        if (num>=14)
        {
            card[i].number=number[num];
            card[i].color=color[col++];
            i++;
        }
        else
        {
            //生成普通牌
            for (col=1;col<=4;col++)
            {
                card[i].number=number[num];
                card[i].color=color[col];
                i++;
            }
        }
    }
}
 
//显示牌
void print_card(struct card card[],int num)
{
 //点数与花色对应数组下标
    for(int i = 0;i < num;i++)
    {
        printf ("%s %s\n\n",card[i].color,card[i].number);
    }
    printf ("\n");
}
 
 
//洗牌
void wash_card()
{
    int i;
    int pos1,pos2;
    srand ((unsigned)time(NULL));
    for (i = 0;i < NUM;i++) //循环次数越大越乱
    {
        
        
        pos1 = rand() % 100;  //2147483647 取最后两位0-99
        pos2 = rand() % 100;
        
 
        if(pos1>53)
        {
            pos1 = 100-pos1; //随机数大于53则减小
        }
 
        if (pos2 > 53)
        {
            pos2 = 100-pos2;
        }
 
        if(pos1 == pos2)
        {
            continue;
        }
        //两个随机牌交换
        struct card tmp=card[pos1];
        card[pos1]=card[pos2];
        card[pos2]=tmp;
    }
}
 
//发牌
void send_card(struct card hand[],int num)
{
    if(NUM_card<num)
    {
        printf("数量不足,请洗牌\n");
        return;
    }

    for(int i=0;i<num;i++)
        hand[i]=card[NUM_card-i];
    
    NUM_card -= num;
}
 
int main(void)
{
 
    creat_pair_card();  //创建一副牌
    wash_card();//洗牌
    print_card(card,NUM_card);//显示牌
 
    struct card hand1[17]; //创建两个结构体保存手牌17张
    struct card hand2[17];
    send_card(hand1,17); //发牌
    send_card(hand2,17);
    printf("手牌A: ");
    print_card(hand1,17);
    printf("\n");
    printf("手牌B: ");
    print_card(hand2,17);
    printf("\n");
}