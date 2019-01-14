#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>


using namespace std;

struct budget{
	double category[7][8];//days and category done
	double budgetCategory[8]; //done
	double sumPerCategory[8];//one week done
	double sumPerDay[7];//done
	double sumPerWeek;//done
	double sumBudget;//done
	string maxDay1;//hari //done
	string minDay1;//done
	double maxDay2;//amount
	double minDay2;//done
	double avgDay;//done
	double avgCategory;//done;
	double maxCategory2;//done
	double minCategory2;//done
	string maxCategory1;//done
	string minCategory1;//done
	double remainBudget[8];//done
	double amtOverBudget;//done
	}student;
	
	void display();
	void loadingBar();
	void TQ();
	double inputBudget(double[]);
	void inputExpenses(budget&);
	void searchCategory(budget&);
	void analysis(budget&);



int main()
{	

//initialize all array to 0
	
	student.maxDay2=0,student.minDay2=999999999,student.maxCategory2=0,student.minCategory2=99999,student.avgCategory=0,student.amtOverBudget=0;
	int count;
	int maximum=0,minimum=99999;
	char response2;
	
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<8;j++)
		{
			student.category[i][j]=0;
			student.budgetCategory[j]=0;
			student.sumPerCategory[j]=0;
			student.remainBudget[j]=0;
			student.sumPerCategory[i]=0;
		}
		student.sumPerDay[i]=0;		
	}
	
	double setbudget=0;
	system ("color 0f");
	display();
    inputBudget(student.budgetCategory);
    system ("color 0D");
    system("pause");
    system("cls");    
	cout<<endl<<endl<<"  Do  you want to key-in your expenses? (y or n) :";
    cin>>response2;
    if(response2=='Y'||response2=='y')
    {
    	inputExpenses(student);
	}
	
	cout<<endl;
	
	//search category
	searchCategory(student);
    system("pause");
    system("cls");
    system ("color 0A");
	loadingBar();
	system("pause");
    system("cls");
    
    //display analysis to file
    analysis(student);
    
	//display thankyou
    system ("color 0b");
	TQ();
	system("pause");
}

void display()
{

	cout<<endl;
    cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
    cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                          hello :)                              "<<endl;
	cout<<"\t\t               Welcome to Student Buget System                  "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;
	cout<<"\t\t                                                                "<<endl;

	system ("color 0f");
	
}

double inputBudget(double budgetCategory[])
{
	string category;
	cout<<endl<<endl;
	ifstream indata("Data.txt");
	for(int i=0;i<8;i++)
	{	
		indata>>student.budgetCategory[i];
	}
	
	if(!indata)
     {
         cout<<"Input file doesnt exist";
         exit(-1);
     }
     
     system("pause");
    system("cls");
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t _____________________  "<<endl;
	cout<<"\t\t\t\t\t|  _________________  |"<<endl;
	cout<<"\t\t\t\t\t| | STUDENT BUDGET  | |"<<endl;
	cout<<"\t\t\t\t\t| |_____SYSTEM______| |"<<endl;
	cout<<"\t\t\t\t\t|  ___ ___ ___   ___  |"<<endl;
	cout<<"\t\t\t\t\t| | 7 | 8 | 9 | | + | |"<<endl;
	cout<<"\t\t\t\t\t| |___|___|___| |___| |"<<endl;
	cout<<"\t\t\t\t\t| | 4 | 5 | 6 | | - | |"<<endl;
	cout<<"\t\t\t\t\t| |___|___|___| |___| |"<<endl;
	cout<<"\t\t\t\t\t| | 1 | 2 | 3 | | x | |"<<endl;
	cout<<"\t\t\t\t\t| |___|___|___| |___| |"<<endl;
	cout<<"\t\t\t\t\t| | . | 0 | = | | / | |"<<endl;
	cout<<"\t\t\t\t\t| |___|___|___| |___| |"<<endl;
	cout<<"\t\t\t\t\t|_____________________|"<<endl<<endl;
    cout<<"\t\t\t\tBudget for this week as follows :"<<endl;
     for (int i=0;i<8;i++)
	{
		if (i== 0)  category="  1. Food           : RM ";
		if (i ==1)	category="  2. Groceries      : RM ";
		if (i ==2)	category="  3. Transportation : RM ";
		if (i ==3)	category="  4. Social         : RM ";
		if (i ==4)	category="  5. Education      : RM ";
		if (i ==5)	category="  6. Donation       : RM ";
		if (i ==6)	category="  7. Clothing       : RM ";
		if (i ==7)	category="  8. Others         : RM ";
		
		cout<<"  \t\t\t\t"<<category;
		cout<<student.budgetCategory[i]<<endl;
		student.sumBudget += student.budgetCategory[i];	
	}
}

void inputExpenses(budget& student)
{
	int i;
	string days, category, desicion;
	
	cout<<endl<<"           What day you want to key-in your expenses?"<<endl;
	cout<<" [1]Monday \t[2]Tuesday \t[3]Wednesday \t[4]Thursday"<<endl<<" [5]Friday \t[6]Saturday \t[7]Sunday"<<endl<<endl;
	cout<<"  -->";
	cin>>i; 
	i--;
	
	cout<<endl;

	for(i;i<7;i++)
	{
		
	if (i ==0)	days ="Monday"; 
	if (i ==1)	days="Tuesday";
	if (i ==2)	days="Wednesday";
	if (i ==3)	days="Thursday";
	if (i ==4)	days="Friday";
	if (i ==5)	days="Saturday";
	if (i ==6)	days="Sunday";	
	
	cout<<"  Enter your expenses for "<<days<<endl<<endl;
		for(int j=0;j<8;j++)
		{
			if (j== 0)	category="  1. Food           : RM ";
			if (j ==1)	category="  2. Groceries      : RM ";
			if (j ==2)	category="  3. Transportation : RM ";
			if (j ==3)	category="  4. Social         : RM ";
			if (j ==4)	category="  5. Education      : RM ";
			if (j ==5)	category="  6. Donation       : RM ";
			if (j ==6)	category="  7. Clothing       : RM ";
			if (j ==7)	category="  8. Others         : RM ";
			
			cout<<category;
			cin>>student.category[i][j];
			//total sum per day
			student.sumPerDay[i] += student.category[i][j];

		}

	
	cout<<endl;
	cout<<"  Total expenses on "<<days<<" : RM"<<student.sumPerDay[i]<<endl;
	cout<<"  -----------------------------------------"<<endl<<endl;
	// find min and max days
	if( student.sumPerDay[i]>student.maxDay2)
	{
		student.maxDay2=student.sumPerDay[i];
		student.maxDay1=days;
		
	}	
	
	if(student.sumPerDay[i]<student.minDay2)
	{
		student.minDay2=student.sumPerDay[i];
		student.minDay1=days;
	}
	student.sumPerWeek +=student.sumPerDay[i];
	
	
		if (i<6)
		{
			cout<<"  Do you want to key-in expenses for the next day? (yes/no) : ";
			cin>>desicion;
			if (desicion=="no")
				break;
		}
		else
		{
			desicion="no";
		}	
	}
	student.avgDay = student.sumPerWeek/7;
	student.avgCategory= student.sumPerWeek/8;
}

void searchCategory(budget& student)
{
		string days,category,category2;
		string search;
		int y;
		bool found=false;
		cout<<"  What category you want to search: ";
		cin>>search;
		cout<<endl;
		
		for(y=0;y<8;y++)
		{
			if (y== 0)	category2="Food";
			if (y ==1)	category2="Groceries";
			if (y ==2)	category2="Transportation";
			if (y ==3)	category2="Social";
			if (y ==4)	category2="Education";
			if (y ==5)	category2="Donation";
			if (y ==6)	category2="Clothing";
			if (y ==7)	category2="Others";
			
			if(search == category2)
			{
				cout<<"  -->The list of "<<category2<<" according to days :"<<endl;
				for(int j=0;j<7;j++)
				{	
					system("Color 07");		
					if (j ==0)	days="  Monday    "; 
					if (j ==1)	days="  Tuesday   ";
					if (j ==2)	days="  Wednesday ";
					if (j ==3)	days="  Thursday  ";
					if (j ==4)	days="  Friday    ";
					if (j ==5)	days="  Saturday  ";
					if (j ==6)	days="  Sunday    ";
					
					cout<<days<<" : RM "<<student.category[j][y]<<endl;
				}

				found=true;	
				break;
			}
			
		}
		if(found==false)
		{
			system("Color 0C");
			cout<<"  404: ERROR NOT FOUND!"<<endl;
		}
}


void loadingBar()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\n\n\n\t\t\t\t\t      LOADING...\n\n";
	char a=186, b=177;
	cout<<"\t\t\t\t";
	for (int i=0;i<=5;i++)
		cout<<a;
		cout<<"\r";
		cout<<"\t\t\t\t\t\t";
	for (int i=0;i<=5;i++)
	{
		cout<<b;
		for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
	} 
	cout<<endl<<endl;
	cout<<"\t\t\t\t\tDATA HAS BEEN SAVED"<<endl<<endl<<endl<<endl<<endl;

}                   

void analysis(budget& student)
{	
	int count=0,i;
	string category2, category, days;
	
	ofstream outfile("analysis.txt");
	
	if(!outfile)
	{ //pergerakan atau pembukaan fail
	cout<<"File analysis does not exit";
	exit(-2);	
	}
	

	outfile<<"  ====================================="<<endl;
	outfile<<"  ||       BUGDGET ANALYSIS           || "<<endl;
	outfile<<"  ====================================="<<endl<<endl;	
	outfile<<"  -->Total expenses Per Day"<<endl;
	for(int j=0;j<7;j++)
	{
			if (j ==0)	days=" Monday    "; 
			if (j ==1)	days=" Tuesday   ";
			if (j ==2)	days=" Wednesday ";
			if (j ==3)	days=" Thursday  ";
			if (j ==4)	days=" Friday    ";
			if (j ==5)	days=" Saturday  ";
			if (j ==6)	days=" Sunday    ";
			
			outfile<<"  "<<j+1<<days<<" : RM "<<student.sumPerDay[j]<<endl;	
	
	}
//expences by category
	outfile<<endl<<"  -->Total expenses Per Category"<<endl;
	for(int i=0;i<8;i++)
	{	
		if (i== 0)	category="  1. Food           : RM ";
		if (i ==1)	category="  2. Groceries      : RM ";
		if (i ==2)	category="  3. Transportation : RM ";
		if (i ==3)	category="  4. Social         : RM ";
		if (i ==4)	category="  5. Education      : RM ";
		if (i ==5)	category="  6. Donation       : RM ";
		if (i ==6)	category="  7. Clothing       : RM ";
		if (i ==7)	category="  8. Others         : RM ";
	
		if (i== 0)	category2="Food";
		if (i ==1)	category2="Groceries";
		if (i ==2)	category2="Transportation";
		if (i ==3)	category2="Social";
		if (i ==4)	category2="Education";
		if (i ==5)	category2="Donation";
		if (i ==6)	category2="Clothing";
		if (i ==7)	category2="Others";
	
		
		
		for(int j=0;j<7;j++)
		{
			student.sumPerCategory[i] += student.category[j][i];
			student.remainBudget[i] = student.budgetCategory[i]-student.sumPerCategory[i];
		}
		//find min and max per category
			if(student.sumPerCategory[i]>student.maxCategory2)
		{
			student.maxCategory2=student.sumPerCategory[i];
			student.maxCategory1=category2;
			
		}	
		if(student.sumPerCategory[i]<student.minCategory2)
		{
			student.minCategory2=student.sumPerCategory[i];
			student.minCategory1=category2;
		}
	
	
		outfile<<category<<student.sumPerCategory[i]<<endl;
	}
	outfile<<endl;
	outfile<<"  MAX DAY      : "<<student.maxDay1<<", RM "<<student.maxDay2<<endl;
	outfile<<"  MIN DAY      : "<<student.minDay1<<", RM "<<student.minDay2<<endl;
	outfile<<"  MAX CATEGORY : "<<student.maxCategory1<<", RM "<<student.maxCategory2<<endl;
	outfile<<"  MIN CATEGORY : "<<student.minCategory1<<", RM "<<student.minCategory2<<endl;
	outfile<<"  AVERAGE PER DAY      : RM "<<student.avgDay<<endl;
	outfile<<"  AVERAGE PER CATEGORY : RM "<<student.avgCategory<<endl;
	outfile<<"  TOTAL                : RM "<<student.sumPerWeek<<endl<<endl;
	
	outfile<<endl;
	//sorting days
	
	outfile<<"  -->Ranking of days of most spent :"<<endl;
	double temp=0;
	string tempday;
	
	string days3[7];
	
	days3[0]="  Monday    ";
	days3[1]="  Tuesday   ";
	days3[2]="  Wednesday ";
	days3[3]="  Thursday  ";
	days3[4]="  Friday    ";
	days3[5]="  Saturday  ";
	days3[6]="  Sunday    ";
	for(int i=0;i<7;i++)
	{
		for(int j=i+1;j<7;j++)
		{
			if(student.sumPerDay[j]>student.sumPerDay[i])
			{
				temp=student.sumPerDay[i];
				tempday=days3[i];
				student.sumPerDay[i]=student.sumPerDay[j];
				days3[i]=days3[j];
				student.sumPerDay[j]=temp;
				days3[j]=tempday;
			}
		}		
	
		outfile<<days3[i]<<" : RM "<<student.sumPerDay[i]<<endl;
	}
	

	outfile<<endl;
	
	//sorting category
	string category3[8];
	string tempcategory;
	outfile<<"  -->Ranking of category of most spent:"<<endl;

	category3[0]="  Food          ";
	category3[1]="  Groceries     ";
	category3[2]="  Transportation";
	category3[3]="  Social        ";
	category3[4]="  Education     ";
	category3[5]="  Donation      ";
	category3[6]="  Clothing      ";
	category3[7]="  Others        ";

	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<8;j++)
		{
			if(student.sumPerCategory[j]>student.sumPerCategory[i])
			{
				temp=student.sumPerCategory[i];
				tempcategory=category3[i];
				student.sumPerCategory[i]=student.sumPerCategory[j];
				category3[i]=category3[j];
				student.sumPerCategory[j]=temp;
				category3[j]=tempcategory;
			}
			
		}
		outfile<<category3[i]<<" : RM "<<student.sumPerCategory[i]<<endl;		
	}
	
	outfile<<endl;
	
	//caculate remaining budget
	outfile<<"  -->Remaining budget Per Category"<<endl;
	for(i=0;i<8;i++)
	{
		if (i== 0)	category="  1. Food           : RM ";
		if (i ==1)	category="  2. Groceries      : RM ";
		if (i ==2)	category="  3. Transportation : RM ";
		if (i ==3)	category="  4. Social         : RM ";
		if (i ==4)	category="  5. Education      : RM ";
		if (i ==5)	category="  6. Donation       : RM ";
		if (i ==6)	category="  7. Clothing       : RM ";
		if (i ==7)	category="  8. Others         : RM ";
		
		//count how much over budget
		if (student.remainBudget[i]<0)
		{
			count++;
			student.amtOverBudget += student.remainBudget[i];

		}
		outfile<<category<<student.remainBudget[i]<<endl;
		
	}
		outfile<<endl;
		outfile<<"  You have been over budget in "<<count<<" categories"<<endl;
		outfile<<"  AMOUNT OVER BUDGET : RM "<<-1*student.amtOverBudget<<endl;
		outfile<<"  Be careful on spending your money. "<<endl<<endl;
		outfile<<"______________________________________________________"<<endl;	
	
	outfile.close();
}
                                  

void TQ()
{
	for (int i=0;i<7;i++)
	{
	system ("color b0");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t,--------.,--.  ,--.  ,---.  ,--.  ,--.,--. ,--.    ,--.   ,--.,-----. ,--. ,--. "<<endl;
	cout<<"\t.--.  .--.|  `--'  | /  O  \ |  ,'. |  || .'   /       \  `.'  /'  .-.  '|  | |  | "<<endl;system ("color 0b");
	cout<<"\t   |  |   |  .--.  ||  .-.  ||  |' '  ||  .  '.       '.    / |  | |  ||  | |  | "<<endl;
	cout<<"\t   |  |   |  |  |  ||  | |  ||  | `   ||  |\   \          |  |  '  '-'  ''  '-'  ' "<<endl;
	cout<<"\t   `--'   `--'  `--'`--' `--'`--'  `--'`--' '--'        `--'   `-----'  `-----'  "<<endl;
	system ("color 0b");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	}
}
