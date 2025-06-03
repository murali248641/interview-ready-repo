#include <stdio.h>

int main()
{
    double meal_cost = 10.25;
    int tip_percent = 17;
    int tax_percent = 5;

    double tip = ((double)tip_percent/100)*meal_cost;
    double tax = ((double)tax_percent/100)*meal_cost;
    double total = meal_cost+(tip+tax);

    printf("%0.0lf %f %f", total, tip, tax);
}

