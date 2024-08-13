#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box {
    private:
        int l, b, h;
    public:
        Box(int length=0, int breadth=0, int height=0){
            l = length;
            b = breadth;
            h = height;
        }
        Box(Box& box){
            l = box.l;
            b = box.b;
            h = box.h;
        }
        int getLength(){
            return l;
        }
        int getBreadth(){
            return b;
        }
        int getHeight(){
            return h;
        }
        long CalculateVolume(){
            return (long)l*(long)b*(long)h;
        }
        bool operator < (Box& box2){
            if(l < box2.l || (l==box2.l && b < box2.b) || (l==box2.l && b == box2.b && h < box2.h))
            {
                return true;
            }else{
                return false;
            }
        }
        friend ostream& operator<< (ostream& out, Box& box){
            string result = "";
            stringstream ss;
            ss << box.l << " " << box.b << " " << box.h;
            result += ss.str();
            out << result;
            return out;
        }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}