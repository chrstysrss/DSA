#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "myheader.h"

Stack removeExpired(Stack s, Date today) {
    Stack expired = createStack(s.max);
    // [1] to do code logic here ...
    initStack(&expired, s.max);
    
    for(int i = s.top - 1; i >= 0; i--){
        if(compareDates(s.prodList[i].expDate, today) < 0)
            push(&expired, s.prodList[i]);
    }
    
    return expired;
}

void main() {
    Stack prods;
    Stack sortedProds;
    int n, d, m , y;

    printf("Enter how many products to populate: ");
    scanf("%d", &n);
    printf("Enter date reference(dd-mm-yyyy): ");
    scanf("%d-%d-%d", &d, &m, &y);

    prods = populateStack(n);

    printf("Initial List: ");
    // [2] Call visualize to display initially populated products
    visualize(prods);
    
    sortedProds = removeExpired(prods, new_date(d, m, y));

    printf("Expired Goods: ");
    // [3] Call visualize to display expired goods
    visualize(sortedProds);

    printf("Original List: ");
    // [4] Call visualize to display orginal List
    visualize(prods);

}

/*************************************************************************
    PRODUCT REFERENCE LIST
    "saging", 10.0, "15/8/2024"
    "binangkal", 7.5, "12/6/2024"
    "bibingka", 2.75, "25/7/2024"
    "linubid", 8, "1/5/2024"
    "puto", 3, "15/8/2023"
    "balanghoy", 10.0, "20/6/2024"
    "balut", 20, "15/7/2024"
    "sapin-sapin", 1, "10/9/2024"
    "biko", 4.0, "8/7/2024"
    "kutsinta", 1, "28/6/2024"
    "maja", 12.0, "1/10/2024"
    "pichi-pichi", 1.5, "2/5/2024"
    "suman", 10.0, "15/8/2024"
    "turon", 0.5, "10/10/2024"
    "bilo-bilo", 0.25, "1/1/2024"
 ************************************************************************/