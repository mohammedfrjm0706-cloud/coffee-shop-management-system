#include <iostream>
#include <string>
#define size 4
using namespace std;
string str;
float total = 0.0;
struct checkout
{
    string name; 
};
int add_price(int);
void print_product(int);
string add_to_list(int);
void print_list(); 
int main()
{
    int choice,checkout_coniform;
    float price;
	bool flag = true;  
    while(flag)
    {
	    print_list();
		cin >> choice; //user enters his choice to choose his product or exit the program            //user cannot leave the store while his cart is not emptyif(choice == 1) //this section checks the user's choice
        if(choice==1)
		{
            int index = 0;
            price = add_price(index); //add the amount of the product to total amount
            print_product(index); //print an alert for the user that it has added an item to his cart
            str = add_to_list(index); //adds the chosen item to the list so it can be printed later in checkout
            //this all happens for all other choices execept choice 5 and 6        
        }
        else if(choice == 2)
        {
            int index = 1;
            price = add_price(index);
            print_product(index);
            str = add_to_list(index);   
        }
        else if(choice == 3)
        {
            int index = 2;
            price = add_price(index);
            print_product(index);
            str = add_to_list(index);
       
        }
        else if(choice == 4)
        {
            int index = 3;
            price = add_price(index);
            print_product(index);
            str = add_to_list(index);  
        }
        else if(choice==5) //this is the checkout section where the user chooses to checkout or not
        {
        	if(str.empty()==1)
			{ //this checks if the user has added items to his order or not
        		cout<<"Your order is empty "<<endl; 
			}
			else //if there is an item it print strs which is a string that is saved from every if or else if block
			{
				cout<<"------Checkout------"<<endl; 
				cout<<str<<endl;
				cout<<"Total price: "<<"$"<<total<<endl;
				cout<<"Do you want to checkout? press 1 to check out or press 2 to persist: ";
				cin>>checkout_coniform;
				switch(checkout_coniform)  
				{
					case 1:  //this is in checkout it makes the user choose between checking out or staying in the program
					cout<<"Thanks for visiting goodbye "<<endl;
					cout<<"Amount paid successfully "<<endl; 
					flag = false;
					break;  
					case 2:
					break;
					default:
					cout<<"The choice you have written is not in the list"<<endl; 
					cout<<"Please try again! "<<endl;
				}
			}		
		}
		else if(choice==6) 
		{
			  if(str.empty()==0) //if the user has items in his cart he cannot leave the program
			  {                  
				cout<<"You cannot leave while you have items in your cart: "<<endl;
			  }
			  else 
			  {  //if he does not have anthing he can leave the program
			  cout<<"Thanks for visiting goodbye "<<endl;
			  break;  
			  }
		}
		else if(choice==7) 
		{
			if(str.empty()==0) //if the user wants to empty his order
			{ 
			    total = 0.0; //resets the amount
				str.clear(); //resets the list
			    cout<<"Items cleared from your order "<<endl;
			}
			else 
			{
				cout<<"Your order is empty "<<endl;
			}
		}
		else 
		{
			cout<<"The choice you have written is not in the list "<<endl; 
		}
		//if the choice written is not in the list
    }
    return 0;
}

int add_price(int index)  
{
	float costs[size] = {2.5, 3.5, 3.0, 2.0};//all prices are here
    total += costs[index];//array element is added to total acourding to the index
	return total;//the total will be used  for checkout later
}

void print_product(int index)
{
    //this function is responsible for printing the element chosen by the user after selecting it
    string list2[size] = {"Espresso","Latte","Cappuccino","Americano"};
    cout << "Added " << list2[index] << " to your order" << endl;  
}

string add_to_list(int i) 
{	//adds the element in the list string for checkout using struct and array
	checkout menu[size] = {
        {"Espresso"},
        {"Latte"},
        {"Cappuccino"},
        {"Americano"}
    };
	str += menu[i].name+"\n";
	return str;
}

void print_list() 
{
    //this one prints the list
	string list[size] = {"Espresso","Latte","Cappuccino","Americano"};
	cout << "               Coffee menu               " << endl;
    cout << "-----------------------------------------" << endl;

    int count = 0;
    for(int i = 0 ; i < size ; i++) //prints the list 
    {
        count++;
        if(i == 0)
        {
        cout << count << "." << list[i] << " - $2.5" << endl;
        }
        else if(i == 1)
        {
            cout << count << "." << list[i] << " - $3.5" << endl;
        }
        else if(i == 2)
        {
                cout << count << "." << list[i] << " - $3.0" << endl;
        }
        else if(i == 3)
        {
                cout << count << "." << list[i] << " - $2.0" << endl;
        }
    }
    cout << "5.View order" << endl;
    cout << "6.Exit" << endl;
    cout << "7.Clear items"<<endl; 
    cout << "Choose an option: ";
}

