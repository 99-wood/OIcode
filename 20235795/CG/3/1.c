/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-12
* 题目：CG平台 链表操作
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>
#include<stdlib.h>


struct node{ //链表节点结构体
    int w; //当前节点的值
    struct node * nxt; // 下一个节点 
    struct node * pre; // 上一个节点
};

struct node * head = NULL; //链表头

void add(int w){ //添加节点
    struct node * now = (struct node *)malloc(sizeof(struct node));
    now -> nxt = head;
    now -> pre = NULL;
    now -> w = w;
    if(head != NULL) head -> pre = now;
    head = now;
    return;
}
struct node * del_node(struct node * p){ //删除单个节点并返回安全节点
    if(p -> pre == NULL){
        if(p -> nxt == NULL){
            free(p);
            return NULL;
        }
        else{
            p -> nxt -> pre = NULL;
            head = p -> nxt;
            free(p);
            return head;
        }
    }
    else if(p -> nxt == NULL){
        p -> pre -> nxt = NULL;
        struct node * pre = p -> pre;
        free(p);
        return pre;
    }
    else{
        p -> pre -> nxt = p -> nxt;
        p -> nxt -> pre = p -> pre;
        struct node * pre = p -> pre;
        free(p);
        return pre;
    }
}
void del(int w){ //删除值所在节点
    struct node * p = head;
    while(p != NULL){
        if(p -> w == w){
            p = del_node(p);
        }
        else{
            p = p -> nxt;
        }
    }
}
int main(){
    int num;
    while(scanf("%d", &num) && num != -1){
        add(num);
    }
    scanf("%d", &num);
    del(num); //删除节点
    for(struct node * p = head; p != NULL; p = p -> nxt){ //输出
        printf("%d ", p -> w);
    }
	return 0;
}

