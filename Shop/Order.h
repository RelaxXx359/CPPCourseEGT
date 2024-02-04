#ifndef SHOP_ORDER_H
#define SHOP_ORDER_H

//Поръчка: - напитки, дата, крайна сума
class Order {
public:
    Order(int drinks, int date, double totalPrice);

    int getDrinks() const;
    void setDrinks(int drinks);
    int getDate() const;
    void setDate(int date);
    double getTotalPrice() const;
    void setTotalPrice(double totalPrice);

    void print();
    double calculatePrice();

private:
    int drinks;
    int date;
    double totalPrice;

};


#endif //SHOP_ORDER_H
