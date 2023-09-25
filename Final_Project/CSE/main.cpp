#include <iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;


///Template class and use of dynamic allocation using new
template <class T>
class tour_venue {
    T* v;
    int s;
public:
    tour_venue(int m) {
        s = m;
        v = new T[s];
        for (int i = 0; i < s; i++) {
            v[i] = 0;
        }
    }

   tour_venue(T* a, int size) {
        ofstream of1("tour_venue.txt");
        s = size;
        v = new T[s];
        for (int i = 0; i < s; i++) {
            v[i] = a[i];
            of1<<v[i]<<endl;
        }
    }

    ///destructor
    ~tour_venue() {
        delete[] v;
    }
};

///friend class
class new_account
{
private:
    string Name;
    string Hall;
    string Year;
    int Roll;
    public:
        friend class store_data;

    ///default constructor
    new_account()
    {
    Name="Unavailable";
    Hall="Unavailable";
    Year="Unavailable";
    Roll=0;
    }

    ///operator overloading using friend function

    friend istream& operator >>(istream &inn, new_account &p);

};
         istream& operator >>(istream &inn, new_account &p){
            string a,b,c;
            int d;
            cout<<"Name : ";
            inn>>a;
            cout<<"Hall : ";
            inn>>b;
            cout<<"Year : ";
            inn>>c;
            cout<<"Roll : ";
            inn>>d;
            p.Name=a;
            p.Hall=b;
            p.Year=c;
            p.Roll=d;
            return inn;
    }

    ///friend class
class store_data
{

    ///use of vector (STL)
    vector<new_account>Student;
public:

    friend class new_account;

    void create_account(new_account a)
    {
        Student.push_back(a);
    }
        void display_details()
        {
            cout<<"Students information:\n"<<endl;
             for(long long unsigned int i=0;i<Student.size();i++)
             {
                    cout<<"Name:"<<Student[i].Name<<endl;
                    cout<<"Roll:"<<Student[i].Roll<<endl;
                    cout<<"Hall:"<<Student[i].Hall<<endl;
                    cout<<"Year:"<<Student[i].Year<<endl;
                    cout<<"\n"<<endl;

             }


        }
        ///Friend function declaration

        friend int total_std(store_data &st);

};

///friend function implementation
 int total_std(store_data &st)
 {
     return st.Student.size();
 }


 ///Absolute base class
class event_manager
{
    protected:
    string name;
    int roll;
public:
    event_manager()
    {

    }
    event_manager(string xx,int yy)
    {
        name=xx;
        roll=yy;
    }
    ///declaration of pure virtual function
    virtual void display_function()=0;
};

///use of virtual class inheritance to avoid ambiguity
class campfire:virtual public event_manager
{
string performance;
public:
     campfire()
    {

    }
int campfire1;
    campfire(string a1,int a2,string a3):event_manager(a1,a2)
    {
        performance=a3;
    }

    void cultural()
    {
        ofstream outf1("Cultural_Performance.txt",ios :: app);
        outf1<<"Name : "<<name<<"  Roll : "<<roll<<"   Performance : "<<performance<<endl;
    }
    void game()
    {
        ofstream outf2("Game.txt",ios :: app);
        outf2<<"Name : "<<name<<"  Roll : "<<roll<<"   Performance : "<<performance<<endl;
    }
      void campfire_get_fee()
    {
        cout<<"Enter individual Ammount"<<endl;
        cin>>campfire1;
    }
    ///runtime polymorphism
    void display_function()
    {
        cout<<"You can get all the necessary info regarding campfire.... "<<endl;
    }
};
///use of virtual class inheritance to avoid ambiguity
class tour:virtual public event_manager
{

    string st2;
public:
    tour()
    {

    }
    int tour1;
    void display_venue()
    {
    ifstream fin("tour_Venue.txt");
     while(fin.eof()==0)
     {
          getline(fin, st2);
          cout<<st2<<endl;
     }

    }
    void tour_get_fee()
    {
        cout<<"Enter individual Ammount"<<endl;
        cin>>tour1;
    }
    ///runtime polymorphism
      void display_function()
    {
       cout<<"You can get all the necessary info regarding tour.... "<<endl;
    }
};


///inheritance and diamond problem solved by virtual class
class payment:public tour,public campfire{

   int  tour_collection;
   int campfire_collection;

public:
    payment()
    {
        tour_collection = 0;
        campfire_collection = 0;
    }
    int total2=0;
char ch;
int rl;
    void pay_tour()
    {
          cout<<"Tour Fee is "<<tour1<<endl;
          cout<<"Do you want to pay it?Press Y to pay"<<endl;
          cin>>ch;
          cout<<"Enter your roll : "<<endl;
          cin>>rl;
          if(ch=='Y')
          {
            tour_collection=tour_collection+tour1;
            cout<<"Your Payment is successfully done...Thank you for your co-operation"<<endl;
          }
          ofstream out1("Tourfee.txt",ios::app);
          out1<<rl<<endl;
    }
     void pay_campfire()
    {
          cout<<"Campfire Fee is "<<campfire1<<endl;
          cout<<"Do you want to pay it?Press Y to pay"<<endl;
          cin>>ch;
          cout<<"Enter your roll : "<<endl;
          cin>>rl;
          if(ch=='Y')
          {
            campfire_collection=campfire_collection+campfire1;
            cout<<"Your Payment is successfully done...Thank you for your co-operation"<<endl;
            total2++;
          }
          ofstream out2("Campfirefee.txt",ios::app);
          out2<<rl<<endl;
    }


    int total()
               {
               return total2;
               }


    int total_campfire()
     {
             return campfire_collection;
     }
     int total_tour()
     {
             return tour_collection;
     }
///runtime polymorphism
  void display_function()
    {
       cout<<"You can get all the necessary info regarding payment and fees.... "<<endl;
    }

};

int main()
{
    string ab,ca;
    int bc,rol;
    store_data abc;
    payment pp;
    char c;
    cout<<"********************************* Welcome to KUET CSE *********************************\n"<<endl;
    cout<<"********************************* For any action press Y *********************************\n"<<endl;
    cin>>c;
    int x;
    while('Y')
    {
     cout<<"\nWelcome to the Main Menu\n"<<endl;
     cout<<"1.Database of students"<<endl;
     cout<<"2.Events"<<endl;
     cout<<"3.Update(Exclucive for managers)"<<endl;
     cout<<"4.Payment"<<endl;
     cout<<"5.Functions of this management program"<<endl;
     cout<<"\nEnter your choice 1/2/3/4/5"<<endl;
     cin>>x;
     switch(x)
     {
        case 1:
        {
        int xa=1;
        do
        {
        cout<<"\n1.Create Account"<<endl;
        cout<<"2.Show all the data of the students"<<endl;
        cout<<"3.Total number of students login\n"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>xa;
        if(xa==1)
        {
            new_account newa;
            cin>>newa;
            abc.create_account(newa);
        }
        else if(xa==2)
        {
             abc.display_details();
        }
        else if(xa==3)
        {
            int ts;
            store_data stt;
            ts=total_std(abc);
            cout<<"Total number of students login is : "<<ts<<endl;
        }
        else
        {
            cout<<"Exit"<<endl;
        }
        cout<<"\n\nTo exit from this function and back to Main Menu press 0\n\n"<<endl;
        cin>>xa;
     }while(xa!=0);
     break;
        }
        case 2:
        {
             int xb=1;
        do{
        cout<<"\n1.Campfire"<<endl;
        cout<<"2.Tour\n"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>xb;
        if(xb==1)
        {
             cout<<"Do you want to perform in campfire?If YES then press Y"<<endl;
    cin>>c;
    if(c=='Y')
    {
        cout<<"Enter your name "<<endl;
        cin>>ab;
        cout<<"Enter your roll "<<endl;
        cin>>bc;
        cout<<"Enter your performance "<<endl;
        cin>>ca;
        campfire ccc(ab,bc,ca);
        ccc.cultural();
    }
    cout<<"Do you want to play in campfire?If YES then press Y"<<endl;
    cin>>c;
    if(c=='Y')
    {
        cout<<"Enter your name "<<endl;
        cin>>ab;
        cout<<"Enter your roll "<<endl;
        cin>>bc;
        cout<<"Enter the name of the game "<<endl;
        cin>>ca;
        campfire ccb(ab,bc,ca);
        ccb.game();
    }
        }
        else if(xb==2)
        {
             cout<<"Do you want to see the venue?Press Y to see the venue"<<endl;
             tour tt;
             cin>>c;
             if(c=='Y')
             {
                 tt.display_venue();
             }
             else
             {
                 cout<<"Sorry cannot display venue"<<endl;
             }
             cout<<"Do you want to see total number of people going to tour?Press Y to see the number of people"<<endl;
             cin>>c;
             if(c=='Y')
             {
                 int tf;
                 tf=pp.total();
                 cout<<"Total number of people going to tour is : "<<tf<<endl;
             }
             else
             {
                 cout<<"Sorry cannot display total"<<endl;
             }
        }
        else
        {
            cout<<"Exit"<<endl;
        }
        cout<<"\n\nTo exit from this function and back to Main Menu press 0\n\n"<<endl;
                cin>>xb;

                    }while(xb!=0);
                    break;

        }
        case 3:
        {
            int xc;
        vector<int> org;
        do{
        cout<<"\n1.Login as organizer first to access the other function"<<endl;
        cout<<"2.Tour Fee"<<endl;
        cout<<"3.Update Tour Venue"<<endl;
        cout<<"4.Campfire Fee"<<endl;
        cout<<"5.Total collection for tour"<<endl;
        cout<<"6.Total collection for campfire"<<endl;
        cout<<"\nEnter your choice"<<endl;
        cin>>xc;
        if(xc==1)
        {
            cout<<"Enter your roll"<<endl;
            cin>>rol;
            org.push_back(rol);
        }
        else if(xc==2)
        {
            cout<<"Enter your roll"<<endl;
            cin>>x;
            for(long long unsigned int i=0;i<org.size();i++)
            {
                if(org[i]==x)
                {
                    pp.tour_get_fee();
                }
                else
                {
                    cout<<"You are not an organizer\nYou can not update any information"<<endl;
                }
            }
        }
        else if(xc==3)
        {
             cout<<"Enter your roll"<<endl;
            cin>>x;
            for(long long unsigned int i=0;i<org.size();i++)
            {
                if(org[i]==x)
                {
                    cout<<"Enter number of places"<<endl;
            int tx;
            string str;
            cin>>tx;
            string xt[tx];
            cout<<"Enter the places"<<endl;
            for(int i=0;i<tx;i++)
            {
                 cin>>str;
                 xt[i]=str;
            }
             tour_venue<string> v1(xt,tx);
                }
                else
                {
                    cout<<"You are not an organizer\nYou can not update any information"<<endl;
                }
            }

        }
        else if(xc==4)
        {
            cout<<"Enter your roll"<<endl;
            cin>>x;
            for(long long unsigned int i=0;i<org.size();i++)
            {
                if(x==org[i])
                {
                    pp.campfire_get_fee();
                }
                else
                {
                    cout<<"You are not an organizer\nYou can not update any information"<<endl;
                }
            }
        }

          else if(xc==5)
        {
            cout<<"Enter your roll"<<endl;
            cin>>x;
            for(long long unsigned int i=0;i<org.size();i++)
            {
                if(x==org[i])
                {
                    int zz;
                    zz=pp.total_tour();
                    cout<<"Total collection for tour is "<<zz<<" Tk"<<endl;
                }
                else
                {
                    cout<<"You are not an organizer\nYou can not update any information"<<endl;
                }
            }
        }
           else if(xc==6)
        {
            cout<<"Enter your roll"<<endl;
            cin>>x;
            for(long long unsigned int i=0;i<org.size();i++)
            {
                if(x==org[i])
                {
                    int zy;
                    zy=pp.total_campfire();
                    cout<<"Total collection for campfire is "<<zy<<" Tk"<<endl;
                }
                else
                {
                    cout<<"You are not an organizer\nYou can not update any information"<<endl;
                }
            }
        }


        else
        {
            cout<<"Exit"<<endl;
        }
         cout<<"\n\nTo exit from this function and back to Main Menu press 0\n\n"<<endl;
                cin>>xc;
             }while(xc!=0);
        break;
        }
        case 4:
        {
        int xd=1;
        do{
        cout<<"\n1.Pay Tour Fee"<<endl;
        cout<<"2.Pay Campfire Fee\n"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>xd;
        if(xd==1)
        {
            pp.pay_tour();
        }
        else if(xd==2)
        {
            pp.pay_campfire();
        }

        else
        {
            cout<<"Exit"<<endl;
        }
                cout<<"\n\nTo exit from this function and back to Main Menu press 0\n\n"<<endl;
                cin>>xd;

        }while(xd!=0);
        break;
        }
        case 5:
            {
                event_manager *obj1=new campfire;
                obj1->display_function();
                 event_manager *obj2=new tour;
                obj2->display_function();
                 pp.display_function();
            }
     }
      cout<<"\n\nTo exit from this entire program enter N else press any other key for going back to Main Menu\n!!"<<endl;
                char ssa;
                cin>>ssa;
                if(ssa=='N')
                {
                    cout<<"\n\n\n*************** Thank you for your cooperation ***************\n\n"<<endl;
                    break;
                }

    }
   return 0;

}

