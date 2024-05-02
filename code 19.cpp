#include <iostream>
using namespace std;

class Theater 
{
public:
    void showdata() {
        cout<<"1. Display movies"<<endl;
        cout<<"2. Display seat availability"<<endl;
        cout<<"3. Book a ticket"<<endl;
        cout<<"4. Cancel_ticket"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<endl;
    }

    void Display_movies() {
        cout<<"Available movies:"<<endl;
        cout<<"0. Avengers (Action) - 150 min"<<endl;
        cout<<"1. Jawan (Action thriller) - 120 min"<<endl;
        cout<<"2. The Nun (Horror) - 145 min"<<endl;
        cout<< "---------------------------"<<endl;
    }

    void Display_seat_availability(char seats[7][7]) 
	{
        cout<<"Seat availability:"<<endl;
        for(int i=0;i<7;i++) 
		{
            for(int j=0;j<7;j++) 
			{
                if(seats[i][j]=='O') 
				{
                    cout<<'O'<<" "; 
                } else 
				{
                    cout<<'X'<<" "; 
                }
            }
            cout<<endl;
        }
        cout<<"-----------------------------"<< endl;
    }
};

class Booking : public Theater 
{
public:
    char seats[7][7]; 

    Booking() 
	{
        for(int i=0;i<7;i++) 
		{
            for(int j=0;j<7;j++) 
			{
                seats[i][j]='O';
            }
        }
    }

    void Book_ticket() 
	{
        Display_movies();

        int movieIndex;
        cout << "Select movie index: ";
        cin >> movieIndex;

        if(movieIndex<0||movieIndex>2) 
		{
            cout<<"Invalid movie index."<<endl;
        }

        Display_seat_availability(seats);

        int row, column;
        cout<<"Choose row and column to select a seat for booking (1-7): ";
        cin>>row>>column;

        if(row>=1&&row<=7&&column>=1&&column<=7) 
		{
            if(seats[row-1][column-1]=='O') 
			{
                seats[row-1][column-1]='X';
                cout<<"Ticket booked successfully for movie index "<< movieIndex<<" and seat "<<row<< "-"<< column << endl;
            } 
			else 
			{
                cout<<"Seat is already booked. Please select another seat."<<endl;
            }
        
        cout<< "-------------------"<< endl;
    
    	}
	}
	void Cancel_ticket() 
	{
        Display_seat_availability(seats);
        int row,column;
        cout<<"Choose row and column to cancel a booked seat(1-7): ";
        cin>>row>>column;

        if(row>=1&&row<=7&&column>=1&&column<=7) 
		{
            if(seats[row-1][column-1]=='X') 
			{
                seats[row - 1][column - 1]='O';
                cout<<"Ticket canceled successfully for seat "<<row<< "-"<<column<<endl;
            } 
			else 
			{
                cout <<"Seat is not booked. Please select a valid seat to cancel."<<endl;
            }
            cout<<"-------------------"<<endl;
        }
    }
};

void intro() 
{
    cout<<"WELCOME TO THEATER MANAGEMENT PROJECT"<< endl;
    cout<<"Created by Vaishnavi and Pradnya"<< endl;
}

int main() 
{
    intro();
    Booking b;
    int choice;

    while (true) 
	{
        b.showdata();
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) 
		{
            case 1:
                b.Display_movies();
                break;
            case 2:
                b.Display_seat_availability(b.seats);
                break;
            case 3:
                b.Book_ticket();
                break;
            case 4:
            	b.Cancel_ticket();
            case 5:
                cout<<"Exiting the program"<< endl;
                
            default:
                cout<<"Invalid choice"<< endl;
	
        }
        
    }
    return 1;
}


