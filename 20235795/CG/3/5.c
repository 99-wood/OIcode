#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct order                     //购物信息
{
    int ID;                           //商品编号
    char goods[30];           //商品名称
    float price;                //商品价格
    int quantity;            //商品数量
};

#define MAXN 10
float getsum(struct order a){
    return a.price * a.quantity;
}
int main(){
    struct order good[MAXN];
    for(int i = 0; i < MAXN; ++i){
        scanf("%d%s%f%d", &good[i].ID, good[i].goods, &good[i].price, &good[i].quantity);
    }
    int ans = 0;
    for(int i = 0; i < MAXN; ++i){
        if(getsum(good[i]) > getsum(good[ans])) ans = i; //更新最值
    }
    printf("%d\n", good[ans].ID);
    printf("%s\n", good[ans].goods);
    printf("%.2f\n", good[ans].price);
    printf("%d\n", good[ans].quantity);
    return 0;
}

