#include<iostream>
#include<fstream>
#include<limits>
#include<iomanip>
using namespace std;
void displayProducts(){
	cout<<"\n================= *AVAILABLE PRODUCTS* ================\n";
	cout<<setw(4)<<"\nNo."<<setw(20)<<"Products."<<setw(20)<<"Price.\n";
	cout<<"------------------------------------------------------\n";
	cout<<setw(4)<<"\n1."<<setw(20)<<"MacBook Pro"<<setw(20)<<"$1500\n";
	cout<<setw(4)<<"\n2."<<setw(20)<<"iPhone 17"<<setw(20)<<"$2500\n";
	cout<<setw(4)<<"\n3."<<setw(20)<<"Samsung S.W."<<setw(20)<<"$450\n";
	cout<<setw(4)<<"\n4."<<setw(20)<<"Air Jordans"<<setw(20)<<"$799\n";
	cout<<setw(4)<<"\n5."<<setw(20)<<"Flowerbomb perfume'"<<setw(20)<<"$2000\n";
	cout<<setw(4)<<"\n6."<<setw(20)<<"J&co. Watch"<<setw(20)<<"$10000\n";
	cout<<setw(4)<<"\n7."<<setw(20)<<"SkateBoard"<<setw(20)<<"$50\n";
	cout<<setw(4)<<"\n8."<<setw(20)<<"Samsung S27 ultra"<<setw(20)<<"$2000\n";
	cout<<setw(4)<<"\n9."<<setw(20)<<"Apple Vision Pro"<<setw(20)<<"$1500\n";
	cout<<setw(4)<<"\n10."<<setw(20)<<"DashCam"<<setw(20)<<"$300\n";
	cout<<setw(4)<<"\n11."<<setw(20)<<"Cerave all in one"<<setw(20)<<"$150\n";
	cout<<setw(4)<<"\n12."<<setw(20)<<"Dish Washer"<<setw(20)<<"$400\n";
	cout<<setw(4)<<"\n13."<<setw(20)<<"Zara Bag"<<setw(20)<<"$1250\n";
	cout<<setw(4)<<"\n14."<<setw(20)<<"Airpods"<<setw(20)<<"$100\n";
 	cout<<setw(4)<<"\n15."<<setw(20)<<"Weed"<<setw(20)<<"$10\n";
	cout<<"\n=======================================================\n";
}
void placeOrder(){
	int productNo;
	int quantity;
	cout<<"Enter the Product Choice from (1-15) : ";
	cin>>productNo;
	while(cin.fail() || productNo<1||productNo>15){
		cout<<"Invalid Input! Please Choose a Number from (1-15) : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>productNo;
	}
	cout<<"Enter quantity : ";
	cin>>quantity;
	while(cin.fail() || quantity<=0){
		cout<<"Please enter a positive quantity : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>quantity;
	}
	ofstream orderFile("orders.txt",ios::app);
	if(orderFile.is_open()){
		orderFile<< "\nProduct : "<<productNo<<"\nQuantity : "<<quantity<<"\n";
		orderFile.close();
		cout<<"Order Placed. \n";
	}
	else{
		cout<<"Error. No orders \n";
	}
}
void viewOrders(){
	ifstream orderFile("orders.txt");
	string line;
	cout<<"\n=================== *YOUR ORDERS* =================== \n\n";
	if(orderFile.is_open()){
		while(getline(orderFile, line)){
		cout<<line<<"\n";
	}
	orderFile.close();
     }else{
	cout<<"No orders Found.\n";
       }
    cout<<"\n===================================================\n";
    }
    int main(){
    	int choice;
    	do{
    		cout<<"\n================== *ONLINE SHOPPING SYSTEM* ====================\n";
    		cout<<"\n1. View Products\n";
    		cout<<"\n2. Place Order\n";
    		cout<<"\n3. View Orders\n";
    		cout<<"\n4. Exit\n";
    		cout<<"\n================================================================\n";
    		cout<<"\nSELECT AN OPTION : ";
    		cin>>choice;
    		
		while(cin.fail()||choice<1||choice>4){
		cout<<"\nInvalid Choice. Choose from 1 to 4 : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>choice;
				}
		switch(choice){
			case 1:
			    displayProducts();
			    break;
			case 2:
				placeOrder();
				break;
			case 3:
			    viewOrders();
				break;
			case 4:
			    cout<<"Exiting.....\n\n";
				break;		
			default:
			    cout<<"Invalid Input. Try Again :\n ";	
	}
		}while(choice!=4);
	return 0;	
}
