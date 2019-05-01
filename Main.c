#include <stdio.h>
#include <Windows.h>

int k=0;
#define ListSize 100      //���Ա����󳤶�
typedef int DataType;

typedef struct
{
    DataType data[ListSize];   //������洢���Ա��е�Ԫ��
    DataType length;           //˳���ĳ���
}SeqList, *PSeqList;

void InitList(PSeqList L);  //˳���ĳ�ʼ������
int LengthList(PSeqList L); //��˳���ĳ���
int GetData(PSeqList L, int i); //�������ݱ��е�i��Ԫ�ص�ֵ
int InsList(PSeqList L, int i, DataType e);   //��˳���ĵ�i��λ�ò���Ԫ��
int DelList(PSeqList L, DataType i, DataType* e); //ɾ��˳���L�ĵ�i������Ԫ��
int Locate(PSeqList L, DataType e); //��������Ԫ��e�ڱ��е�λ��
void PushFront(PSeqList L, DataType e); //ͷ�壬�ڱ�ͷ����Ԫ��e
void PopFront(PSeqList L);    //ͷɾ,ɾ�����еĵ�һ��Ԫ��
void PushBack(PSeqList L, DataType e);  //β�壬�ڱ�β����Ԫ��e
void PopBack(PSeqList L); //βɾ��ɾ����βԪ��
void ClearList(PSeqList L);  //���˳���
int EmptyList(PSeqList L);   //�ж�˳����Ƿ�Ϊ��
void PrintList(PSeqList L);  //��ӡ����Ԫ��

int main()
{
    SeqList L;
    DataType data;
    //��ʼ��˳���
    InitList(&L);
    //�ڱ��в���Ԫ��
    printf("�����ڱ��в���Ԫ��(1,2,3,4,5)��\n");
    InsList(&L, 1, 1);
    InsList(&L, 2, 2);
    InsList(&L, 3, 3);
    InsList(&L, 4, 4);
    InsList(&L, 5, 5);

    //��ӡ����Ԫ��
    printf("����Ԫ���У�\n");
    PrintList(&L);
    //ͷ��
    printf("�ڱ�ͷ���β���Ԫ�أ�6,7:\n");
    PushFront(&L, 6);
    PushFront(&L, 7);
    //β��
    printf("�ڱ�β���β���Ԫ�أ�8,9:\n");
    PushBack(&L, 8);
    PushBack(&L, 9);
    printf("����Ԫ���У�\n");
    PrintList(&L);
    //ͷɾ
    printf("ͷɾһ��Ԫ��:\n");
    PopFront(&L);
    //βɾ
    printf("βɾһ��Ԫ��:\n");
    PopBack(&L);
    //������е�4��Ԫ��ֵ
    PrintList(&L);
    printf("���е�4��Ԫ��ֵΪ��\n%d\n",GetData(&L, 4));
    //���ұ��е� i��Ԫ�ص�λ��
    printf("Ԫ��2�ڱ��е�λ��Ϊ��\n");
    printf("%d\n",Locate(&L, 2));
    //ɾ�����е�2��Ԫ�ض�Ӧ��ֵ
    printf("ɾ�����е�2��Ԫ�أ�%d\n", DelList(&L, 2, &data));
    printf("˳���ĳ���Ϊ��%d\n", LengthList(&L));
    printf("����Ԫ��Ϊ��\n");
    PrintList(&L);
    //printf("ɾ����Ԫ��ֵΪ��%d\n", data);
    //���˳���
    ClearList(&L);
    PrintList(&L);
    system("pause");
    return 0;
}

//��ʼ��˳���
void InitList(PSeqList L)
{
    if (L == NULL)
    {
        return;
    }
    L->length = 0;
}

//��˳���ĳ���

int LengthList(PSeqList L)
{
    if (L == NULL)
    {
        return 0;
    }
    return L->length;
}

//�������ݱ��е�i��Ԫ�ص�ֵ
int GetData(PSeqList L, int i)
{
    if (L->length < 1 || (L->length > LengthList(L)))
    {
        return 0;
    }
    //����Ԫ�ص���Ŵ�1��ʼ�������±��0��ʼ����i��Ԫ�ض�Ӧ�������±�Ϊi-1;
    return L->data[i - 1];
}

//��L�е�i��λ�ã������µ�����Ԫ��e

int InsList(PSeqList L, int i, DataType e)
{

    //�жϲ���λ���Ƿ�Ϸ�
    if (i < 1 || L->length >(LengthList(L) + 1))
    {
        printf("����λ�ò��Ϸ�!\n");
        return 0;
    }
    //�ж�˳����Ƿ�����
    else if (L->length >= ListSize)
    {
        printf("˳������������ܲ��룡\n");
        return 0;
    }
    else
    {
        for (k = i; k <= L->length; k--)
        {
            L->data[k + 1] = L->data[k];
        }
        L->data[i - 1] = e;
        L->length++;   //���ݱ�ĳ��ȼ�1
        return 1;
    }
    return 0;
}

//ɾ��L�ĵ�i������Ԫ��

int DelList(PSeqList L, DataType i, DataType* e)
{
    if (L->length < 1)
    {
        printf("��Ϊ�գ�\n");
        return  0;
    }
    *e = L->data[i - 1];
    for (k = i; k < L->length; k++)
    {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
    return *e;
}

//����e�ڱ��е�λ��

int Locate(PSeqList L, DataType e)
{
    for (k = 0; k < L->length; k++)
    {
        if (L->data[k] == e)
        {
            //kΪe��Ӧ�������±꣬�ڱ��ж�Ӧ���ӦΪk+1
            return k + 1;
        }
    }
    return 0;
}

//ͷ�壬�ڱ�ͷ����Ԫ��e

void PushFront(PSeqList L, DataType e)
{
    if (L->length == ListSize)
    {
        printf("˳������������ܲ��룡\n");
    }
    //������Ԫ�����κ���һλ
    for (k = L->length; k > 0; k--)
    {
        L->data[k] = L->data[k - 1];
    }
    //����Ԫ��
    L->data[0] = e;
    L->length++;
}

//ͷɾ,ɾ��˳����еĵ�һ��Ԫ�أ���˳����е�Ԫ��������ǰ�ƶ�һλ

void PopFront(PSeqList L)
{
    if (EmptyList(L))
    {
        printf("˳���Ϊ�գ����ܲ��룡\n");
    }
    for (k = 1; k <= L->length - 1; k++)
    {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
}

//β��
void PushBack(PSeqList L, DataType e)
{
    if (L->length == ListSize)
    {
        printf("˳������������ܲ���!\n");
    }
    L->data[L->length] = e;
    L->length++;
}


//βɾ
void PopBack(PSeqList L)
{
    if (EmptyList(L))
    {
        printf("��Ϊ�գ�\n");
    }
    L->length--;

}

//���˳���
void ClearList(PSeqList L)
{
    L->length = 0;
}

//�жϱ��Ƿ�Ϊ��

int EmptyList(PSeqList L)
{
    if (L->length == 0)
    {
        return 1;
    }
    return 0;
}

//��ӡ����Ԫ��

void PrintList(PSeqList L)
{
    if (EmptyList(L))
    {
        printf("��Ϊ�գ�\n");
        return;
    }
    for (k = 0; k < L->length; k++)
    {
        printf("%-3d", L->data[k]);
    }
    printf("\n");
}



