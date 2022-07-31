#include<bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int food_quantity;

private:
    double Tax;

public:
    Restaurant()
    {
        this->Tax = 0;
    }
    void set_total_tax(double total_amount)
    {
        this->Tax += total_amount;
    }
    double get_total_tax()
    {
        return this->Tax;
    }
};

class Table
{
public:


    int itemCode[12];
    int itemQuantity[12];
    int items;
    int tab_no;
};


Restaurant *take_input(Restaurant *restaurant)
{
    int food_quantity;

    cin >> food_quantity;

    restaurant->food_quantity = food_quantity;
    for (int i = 0; i < food_quantity; i++)
    {
        cout<<"food code"<<endl;
        cin >> restaurant->food_item_codes[i];
        fgetc(stdin);
        cout<<"food name"<<endl;
        getline(cin, restaurant->food_item_names[i]);
        cout<<"food price"<<endl;
        cin >> restaurant->food_item_prices[i];
    }
    return restaurant;
}



Table *no_of_tab(Table *table, Restaurant *restaurant)
{
    int tab_no,items;
    //cout<<"Enter Table No:";
    cout<<"enter table no:";
    cin >> tab_no;
    cout << "Enter Number of Items : ";
    cin >> items;
    table->tab_no = tab_no;
    table->items = items;
    for (int i = 0; i <items; i++)
    {
        bool found = true;
        cout << "Enter Item " << i+1 << " code : ";
Flag:
        cin >> table->itemCode[i];
        for (int j = 0; j < restaurant->food_quantity; j++)
        {
            if (table->itemCode[i] == restaurant->food_item_codes[j])
            {
                found = false;
            }
        }
        if(found)
        {
            cout<<"Code is not valid. Please try another code: ";
            goto Flag;
        }
        cout << "Enter Item " << i + 1 << " Quantity : ";
        cin >> table->itemQuantity[i];
    }
    return table;
}



void make_bill(Restaurant *restaurant)
{
    cout << "\t\t\t\t\t     MAKE BILL  " << endl;
    cout << "\t\t\t\t\t____________________" << endl;
    cout << "Item Code\t\t\t\t";
    cout << "Item Name\t\t\t\t";
    cout << "Item Price\t\t\t\t";
    cout << endl;

    for (int i = 0; i < restaurant->food_quantity; i++)
    {
        cout << restaurant->food_item_codes[i] << "\t\t\t\t\t" << restaurant->food_item_names[i] << "\t\t\t" << restaurant->food_item_prices[i] << endl;
    }
}



void bill_summary(Restaurant *restaurant, Table *table)
{
    cout << "\t\t\t\t\t  BILL SUMMARY " << endl;
    cout << "\t\t\t\t\t___________________ " << endl;
    cout << "Table No. : " << table->tab_no << endl;
    cout << "Item Code\t\t\t\t";
    cout << "Item Name\t\t\t";
    cout << "Item Price\t\t";
    cout << "Item Quantity\t";
    cout << "Total Price";
    cout << endl;
    int total_bill = 0;
    for (int i = 0; i < restaurant->food_quantity; i++)
    {
        for (int j = 0; j < table->items; j++)
        {
            if (restaurant->food_item_codes[i]==table->itemCode[j])
            {
                total_bill += table->itemQuantity[j] * restaurant->food_item_prices[i];
                cout << restaurant->food_item_codes[i] << "\t\t\t\t\t" <<restaurant->food_item_names[i]<<"\t\t"<<restaurant->food_item_prices[i]<<"\t\t\t" <<table->itemQuantity[j] <<"\t\t"<<table->itemQuantity[j]*restaurant->food_item_prices[i]<<endl;
            }
        }
    }
    double add_tax = double(total_bill * 5) / 100;
    double net_total = add_tax + double(total_bill);
    cout << "TAX\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << fixed << setprecision(2) << add_tax << endl;
    cout << endl;
    cout << "____________________________________________________________________________________________________________________________________________" << endl;
    cout << "NET TOTAL\t\t\t\t\t\t\t\t\t\t\t\t\t" << net_total << " Taka" << endl;
    restaurant->set_total_tax(add_tax);
    cout << endl;
    cout << "Total Tax = " << restaurant->get_total_tax() << endl;
}


int main()
{
    Restaurant *restaurant = new Restaurant();
    Table *table = new Table();
    take_input(restaurant);
    cout << endl;
Flag:
    make_bill(restaurant);
    cout << endl;
    no_of_tab(table,restaurant);
    cout << endl;
    bill_summary(restaurant, table);
    cout << endl;
    goto Flag;
    return 0;
}

