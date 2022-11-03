
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
#define NUM 10000 //ϴ�ƻ��Ҷ�
 
char color[7][20] = {"none","Heart","Spades","Clubs","Diamonds","Color joker","Black joker"};  
char number[13][10]={"0","A","2","3","4","5","6","7","8","9","jack","queen","king"};  
 
//�����˿�
struct card{
    char* color;
    char* number;
};
 
int NUM_card=53; //ʣ��δ��������(����ʱ�õı���)
 
struct card card[54]; //��������һ���ƵĽṹ��
 
 
//����һ����(����)
void creat_pair_card()
{
    int num=1;
    int col=1;
    int i=0;
    for (num=1;num<=15;num++)
    {
        //���ɴ�С��
        if (num>=14)
        {
            card[i].number=number[num];
            card[i].color=color[col++];
            i++;
        }
        else
        {
            //������ͨ��
            for (col=1;col<=4;col++)
            {
                card[i].number=number[num];
                card[i].color=color[col];
                i++;
            }
        }
    }
}
 
//��ʾ��
void print_card(struct card card[],int num)
{
 //�����뻨ɫ��Ӧ�����±�
    for(int i = 0;i < num;i++)
    {
        printf ("%s %s\n\n",card[i].color,card[i].number);
    }
    printf ("\n");
}
 
 
//ϴ��
void wash_card()
{
    int i;
    int pos1,pos2;
    srand ((unsigned)time(NULL));
    for (i = 0;i < NUM;i++) //ѭ������Խ��Խ��
    {
        
        
        pos1 = rand() % 100;  //2147483647 ȡ�����λ0-99
        pos2 = rand() % 100;
        
 
        if(pos1>53)
        {
            pos1 = 100-pos1; //���������53���С
        }
 
        if (pos2 > 53)
        {
            pos2 = 100-pos2;
        }
 
        if(pos1 == pos2)
        {
            continue;
        }
        //��������ƽ���
        struct card tmp=card[pos1];
        card[pos1]=card[pos2];
        card[pos2]=tmp;
    }
}
 
//����
void send_card(struct card hand[],int num)
{
    if(NUM_card<num)
    {
        printf("��������,��ϴ��\n");
        return;
    }

    for(int i=0;i<num;i++)
        hand[i]=card[NUM_card-i];
    
    NUM_card -= num;
}
 
int main(void)
{
 
    creat_pair_card();  //����һ����
    wash_card();//ϴ��
    print_card(card,NUM_card);//��ʾ��
 
    struct card hand1[17]; //���������ṹ�屣������17��
    struct card hand2[17];
    send_card(hand1,17); //����
    send_card(hand2,17);
    printf("����A: ");
    print_card(hand1,17);
    printf("\n");
    printf("����B: ");
    print_card(hand2,17);
    printf("\n");
}