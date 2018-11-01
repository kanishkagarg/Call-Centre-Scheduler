#include <bits/stdc++.h>
#include<windows.h>


using namespace std;


struct Customer
{
	int cid;
	int at;
	int bt;
	string company;
	int pri;
	int io;
	int bt2;
	int wt;
	int tat;
	int st;
	bool asgn;
};

struct Employee
{
	int eid;
	bool free;
	int compl_time;
	//int lunch_time;
	char shift[10];
	int shift_no;
	int cur_cid;

};

struct Company
{
	string comp;
	int priority;
};

struct cus_time
{
    int cid;
    int time;
};

struct out_Employee
{
    int eid;
    int shift_no;
    char shift[10];
    vector<cus_time> kol;
};

vector <Company> C;
vector <Customer> Cus;
vector<Employee> E;
vector<Customer> output_cus;
vector<out_Employee> output_emp;
int t=0;


void input();
void take_input();
void input_of_emp(int n);
int priority_sched_cus();
int evening_shift();
int morning_shift();
int night_shift();
int shift_emp(int t);
void callcentre();
void print_everything();
bool comp(Customer c1, Customer c2);
bool comp_morn(Employee e1, Employee e2);
bool comp_night(Employee e1, Employee e2);
bool arrival(Customer c1, Customer c2);
void run(int n1, int n2);


//declaring dataset
void input()
{
    Company S;

	S.comp="Reebok";       S.priority=1;       C.push_back(S);
	S.comp="Adidas";       S.priority=2;       C.push_back(S);
	S.comp="Woodland";     S.priority=3;       C.push_back(S);
	S.comp="H&M";          S.priority=4;       C.push_back(S);
	S.comp="Forever_21";   S.priority=5;       C.push_back(S);
}



//this function takes input of customers and set their priority according to their company.
void take_input()
{
    Customer K;


	K.cid=1;
	K.at=0;
	K.bt=3;
	K.company="Forever_21";
	K.pri=0;
	K.io=2;
    K.bt2=3;
    K.st=0;
    K.wt=0;
    K.tat=0;
    K.asgn=false;
	Cus.push_back(K);

	K.cid=2;
	K.at=0;
	K.bt=8;
	K.company="Adidas";
	K.pri=0;
	K.io=3;
    K.bt2=5;
    K.st=0;
    K.wt=0;
    K.tat=0;
	Cus.push_back(K);

	K.cid=3;
	K.at=0;
	K.bt=10;
	K.company="Reebok";
	K.pri=0;
	K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
	Cus.push_back(K);

	K.cid=4;
	K.at=6;
	K.bt=12;
	K.company="Woodland";
	K.pri=0;
	K.io=1;
    K.bt2=1;
    K.st=0;
    K.wt=0;
    K.tat=0;
	Cus.push_back(K);

	K.cid=5;
	K.at=6;
	K.bt=13;
	K.company="Reebok";
	K.pri=0;
	K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
	Cus.push_back(K);

    K.cid=6;
    K.at=10;
    K.bt=14;
    K.company="H&M";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=7;
    K.at=16;
    K.bt=10;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=8;
    K.at=20;
    K.bt=10;
    K.company="H&M";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=9;
    K.at=30;
    K.bt=10;
    K.company="Reebok";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=10;
    K.at=35;
    K.bt=10;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=11;
    K.at=39;
    K.bt=3;
    K.company="H&M";
    K.pri=0;
    K.io=5;
    K.bt2=2;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=12;
    K.at=39;
    K.bt=10;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=13;
    K.at=40;
    K.bt=10;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=14;
    K.at=44;
    K.bt=10;
    K.company="Reebok";
    K.pri=0;
    K.io=3;
    K.bt2=3;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=15;
    K.at=45;
    K.bt=9;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=16;
    K.at=46;
    K.bt=23;
    K.company="Forever_21";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=17;
    K.at=47;
    K.bt=10;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=18;
    K.at=48;
    K.bt=12;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=19;
    K.at=49;
    K.bt=10;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

    K.cid=20;
    K.at=50;
    K.bt=10;
    K.company="Woodland";
    K.pri=0;
    K.io=0;
    K.bt2=0;
    K.st=0;
    K.wt=0;
    K.tat=0;
    Cus.push_back(K);

	int l1=C.size();
	int l2=Cus.size();

	for(int j=0;j<l2;j++)
	{
		for(int i=0;i<l1;i++)
		{
			if(Cus[j].company==C[i].comp)
			{
				Cus[j].pri=C[i].priority;
				break;
            }
		}
	}
}



//making vector of employees with there details
void input_of_emp(int n)
{
   struct Employee e;
   int a=n/3;
   int b=a+a;
   for(int i=1;i<=n;i++)
   {
       e.eid=i;
       e.free=true;
       e.compl_time=0;
       if(i<=a)
       {
        strcpy(e.shift,"morning");
        e.shift_no=1;
       }
       else if(i>a && i<=b)
       {
           strcpy(e.shift,"evening");
           e.shift_no=2;
       }
       else
       {
           strcpy(e.shift,"night");
           e.shift_no=3;
       }
       E.push_back(e);
   }
}



//sort(customers)
bool comp(Customer c1, Customer c2)
{
    return c1.pri<c2.pri;
}



//sorting vector of customers
/*****************************/
int priority_sched_cus(int t)
{
    int pos1=0,pos2=0,i=0;
    for(vector<Customer>::iterator it=Cus.begin();it!=Cus.end();it++)
    {
        if(it->at<=t)
        {
            i++;
        }
    }
    sort(Cus.begin(),Cus.begin()+i,comp);

   return i;
}
/*****************************/

// employee sorting
int evening_shift()
{
    int n=0;
    morning_shift();
    vector<Employee>::iterator itr=E.begin();
    for(vector<Employee>::iterator it=E.begin();it!=E.end();it++)
    {
        if(it->shift_no==2)
        {
            swap(*itr,*it);
            *itr++;
        }
        if(it->shift_no==3)
            break;
    }
    for(vector<Employee>::iterator it=E.begin();it!=E.end();it++)
    {
        if(it->shift_no==2)
            n++;
        else
            break;
    }
    return n;
}

// employee sorting
bool comp_morn(Employee e1, Employee e2)
{
    return e1.shift_no<e2.shift_no;
}



// employee sorting
int morning_shift()
{
    int n=0;
    sort(E.begin(),E.end(),comp_morn);
    for(vector<Employee>::iterator it=E.begin();it!=E.end();it++)
    {
        if(it->shift_no==1)
            n++;
        else
            break;
    }
    return n;
}



// employee sorting
bool comp_night(Employee e1, Employee e2)
{
    return e1.shift_no>e2.shift_no;
}



// employee sorting
int night_shift()
{
    int n=0;
    sort(E.begin(),E.end(),comp_night);
    for(vector<Employee>::iterator it=E.begin();it!=E.end();it++)
    {
        if(it->shift_no==3)
            n++;
        else
            break;
    }
    return n;
}



// employee sorting
int shift_emp(int t)
{
    int n=0;
    if(t>=0 && t<20)
       n=night_shift();
    else if(t>=21 && t<30)
        n=morning_shift();
    else
        n=evening_shift();
    return n;
}




bool arrival(Customer c1, Customer c2)
{
    return c1.at<c2.at;
}


void if_emp_free(Customer *i, Customer *previous_cus, Employee *j, int k)
{
    j->compl_time = i->bt;      j->free = false;        j->cur_cid = i->cid;
    i->asgn = 1;

    if(i->io==0)
        i->wt = t-i->at;
    else
        i->wt = t - i->at + i->wt;

    i->tat = i->bt + i->wt;
}


void check_wait_for_customer(Customer *i)
{
    if(i->io != 0)
    {
        i->at = i->bt + i->wt;
        i->bt = i->bt2;
    }
}


void copying(int count)
{
   vector<Customer>::iterator current;
        current=Cus.begin()+count;
        Customer cur;
        cur.asgn = current->asgn;
        cur.at = current->at;
        cur.cid = current->cid;
        cur.bt = current->bt;
        cur.bt2 = current->bt2;
        cur.company = current->company;
        cur.io = current->io;
        cur.pri = current->pri;
        cur.wt = current->wt;
        cur.tat = current->tat;
        output_cus.push_back(cur);
}

void emp_detail(Employee *k,  Customer *it)
{
     out_Employee e;
     cus_time c;
     c.cid=it->cid;
     c.time=t;
     e.eid=k->eid;
     e.shift_no=k->shift_no;
     strcpy(e.shift, k->shift);
     e.kol.push_back(c);
     output_emp.push_back(e);
}


int wait_for_emp_free(int c, int b, int n1, int n2)    // n1 is no of employee till time t    c is the indicator
{
    int ctr=1, count=0, n=0;
    if(c==0)
    {
        while(ctr)
        {
            t++;
            count =0;
            n2=priority_sched_cus(t);
                n=n2;
            for(vector<Employee>::iterator it=E.begin(); it!=E.begin()+n1; it++)
            {
                it->compl_time = it->compl_time - 1;
                if(it->compl_time == 0 )
                {
                    it->free = true;
                    ctr=0;
                    for(vector<Customer>::iterator k=Cus.begin(); k!=Cus.begin()+n2; k++)
                    {
                        count++;
                        if(k->cid == it->cur_cid)
                        {
                            count--;
                            copying(count);
                            emp_detail(&(*it), &(*k));
                            Cus.erase(Cus.begin()+count);
                            n2--;

                            break;
                        }

                    }
                }
            }
        }
    }

    else if(b==0)
    {
        n=n2;
        while(n<=n2)
        {
            t++;
            n2=priority_sched_cus(t);
        }
    }
    return n2;
}


void run(int n1, int n2)      // n1=employee   n2=customer
{
    int k=0, c=0;             // k indicating the first customer   c indicating if any employee free or not
    int emp_is_free=0, cus_is_free=0;
    vector<Customer>::iterator previous_cus;

    while(t<100)
    {
        n1=shift_emp(t);
            for(vector<Customer>::iterator i=Cus.begin(); i!=Cus.begin()+n2; i++)
            {
                c=0;
                if(i->asgn==0)
                {
                    for(vector<Employee>::iterator j=E.begin(); j!=E.begin()+n1; j++)
                    {
                        if(j->free==true )
                        {
                            if_emp_free(&(*i), &(*previous_cus), &(*j), k);
                            c=1;
                            break;
                        }
                    }

                    check_wait_for_customer(&(*i));

                    for(vector<Employee>::iterator it=E.begin(); it!=E.begin()+n1; it++)
                    {
                        if(it->free==true)
                            emp_is_free++;
                    }
                    if(emp_is_free==0)
                        break;
                    emp_is_free=0;
                }

            }
            for(vector<Customer>::iterator it=Cus.begin(); it!=Cus.begin()+n2; it++)
            {
                if(it->asgn==0)
                    cus_is_free++;
            }
            n2 = wait_for_emp_free(emp_is_free, cus_is_free, n1, n2);
            emp_is_free=0;
            cus_is_free=0;

    }
}



void call()
{
    sort(Cus.begin(), Cus.end(), arrival);
    int n1,n2;

        n1=shift_emp(t);                    //sorting the employees according to the shift and getting the no of employees currently in that shift
        n2=priority_sched_cus(t);           //sorting the customers according to priority till time t

        run(n1,n2);


}


void print_everything()
{
    cout<<"\tinitial Company list\n\n";
    Sleep(1000);
    cout<<"   COMPANY\t\t    PRIORITY\n\n";
    Sleep(1000);

    for(vector<Company>::iterator it=C.begin();it!=C.end();it++)
    {
        cout <<setw(10) <<it->comp;
        cout<<setw(20)<<it->priority;
        cout<<endl;
    }
    cout << "\n\n";
    Sleep(1000);
    cout<<"\tinitial Customer list\n\n";
    Sleep(1000);
    cout<<"   CUSTOMER_ID\t\tARRIVAL TIME\t\tBURST TIME\t\tCOMPANY\t\tPRIORITY\n\n";
    Sleep(1000);
    for(vector<Customer>::iterator it=Cus.begin();it!=Cus.end();it++)
    {
        cout<<setw(10)<<it->cid;
        cout<<setw(15)<< it->at;
        cout<<setw(25)<< it->bt;
        cout<<setw(30)<< it->company;
        cout<<setw(15)<< it->pri <<endl;
    }
    cout << "\n\n";
    Sleep(1000);
    cout<<"\tinitial Employee list\n\n";
    Sleep(1000);
    cout<<"   EMPLOYEE ID\t\tSHIFT\t\tSHIFT NO\n\n";
    Sleep(1000);
    for(vector<Employee>::iterator it=E.begin();it!=E.end();it++)
    {
        cout<<setw(10)<<it->eid;
        cout<<setw(20)<< it->shift;
        cout<<setw(15)<< it->shift_no << endl;
    }

}

void print_final()
{

   cout << "\n\n";
   Sleep(1000);
   cout<<"\tFINAL customer list\n\n";
   Sleep(1000);
   cout<< "   CUSTOMER_ID\t\tARRIVAL TIME\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n\n";
   Sleep(1000);
   for(vector<Customer>::iterator it=output_cus.begin();it!=output_cus.end();it++)
    {
        cout<<setw(10)<<it->cid;
        cout<<setw(15)<< it->at;
        cout<<setw(25)<< it->bt;
        cout<<setw(30)<< it->wt;
        cout<<setw(20)<< it->tat <<endl;
    }

    cout << "\n\n";
    Sleep(1000);
    cout<<"\tFINAL Employee list\n\n";
    Sleep(1000);
    cout<<"   EMPLOYEE ID\t\tSHIFT\t\tCUSTOMER ID\t\tTIME\n\n";
    Sleep(1000);
    for(vector<out_Employee>::iterator it=output_emp.begin(); it!=output_emp.end(); it++)
    {
        cout<<setw(10)<<it->eid;
        cout<<setw(15)<<it->shift;
        for(vector<cus_time>::iterator j=it->kol.begin(); j!=it->kol.end(); j++)
        {
            cout<<setw(30)<<j->cid;
            cout<<setw(30)<<j->time;

        }
        cout<<endl;
    }
}



int main()
{
    input();
	take_input();
	input_of_emp(6);
	print_everything();
    call();
	print_final();

    return 0;
}
