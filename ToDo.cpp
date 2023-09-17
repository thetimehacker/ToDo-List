#include <bits/stdc++.h>
using namespace std;
// atleast 100

map<pair<string,int>, unordered_map<string,int>> m;
int x=1;
vector<int>p(26,0);

vector<string>priority_from_number_to_char;

void input(){
      string date,task,priority;
     // int priority;  //l,m,h
      cin.ignore();
      std::cout<<"Enter deadline : ";
      getline(cin,date);

      std::cout<<"Enter task : ";
      getline(cin,task);
      
      std::cout<<"Enter Priority (l/m/h) : ";
      std::getline(std::cin,priority);
      
      char c=priority[0];

      if(m[{date,p[c-'a']}][task]){
        cout<<endl<<"---->> Item already present :( <<----"<<endl<<endl;
        return;
      }
    
      m[{date,p[c-'a']}][task]= x++;
      cout<<endl<<"---->> Item Added Successfully :) <<----"<<endl<<endl;

}

void printFinal(){

  vector<string> v;

  for(auto x: m){
    for(auto y: x.second){
      string k=priority_from_number_to_char[x.first.second];
      string s=x.first.first+"   "+k+"     "+y.first;

      v.push_back(s);
    }
  }

  if(v.empty()){
    cout<<endl<<"---->> Todo list is empty :( <<----"<<endl<<endl;
    return;
  }

  cout<<endl<<"SNO. Date         Priority  Task"<<endl<<"------------------------------------------------------"<<endl;
  int n=v.size();
  for(int i=v.size()-1;i>=0;i--){
      cout<<n-i<<".   "<<v[i]<<endl;
    }

    cout<<endl<<"------------------------------------------------------"<<endl;
}

void printDate(string s){
  vector<string> v;

  for(auto x: m){
    for(auto y: x.second){
      if(x.first.first==s){
        string k=priority_from_number_to_char[x.first.second];
        string s=x.first.first+"   "+k+"     "+y.first;

        v.push_back(s);
      }
    }
  }

  if(v.empty()){
    cout<<endl<<"---->> No events for given Date :( <<-----"<<endl<<endl;
    return;
  }

  cout<<"SNO. Date         Priority  Task"<<endl<<"------------------------------------------------------"<<endl;
  int n=v.size();
  for(int i=v.size()-1;i>=0;i--){
    cout<<n-i<<".   "<<v[i]<<endl;
  }

  cout<<endl<<"------------------------------------------------------"<<endl;
}

void del(){
  int i=1;
  unordered_map<int,int> temp;
   for (auto &x : m) {
     for(auto y:x.second){
      cout<<i<<" : ";
      temp[i]=y.second;
      cout<<y.first<<endl;
      i++;
     }
   }

   int user_value;
   cin>>user_value;
   int d = temp[user_value];


   for(auto &x: m){
    bool flag=false;
    for(auto &y:x.second){
      //  cout<<y.second<<endl;
      if(y.second==d){
        x.second.erase(y.first);
        flag=true;
        break;
      }
    }
    if(flag)break;
   }


    
}

int main() {
    
  p['l'-'a']=1;
  p['m'-'a']=2;
  p['h'-'a']=3;
  // x=1;
  char ans='y';

  //pushback for priority_from_number_to_char
  priority_from_number_to_char.push_back("Nothing here");
  priority_from_number_to_char.push_back("Low ");
  priority_from_number_to_char.push_back("Mid ");
  priority_from_number_to_char.push_back("High");


  while(ans=='y'){

    cout<<"----------------Main Menu---------------------"<<endl;
    cout<<"1. Add to Todo"<<endl;
    cout<<"2. Go to Date"<<endl;
    cout<<"3. Display Everything"<<endl;
    cout<<"4. Delete from Todo"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Choose any option (1-5) : ";

    // int inp; --- taking a string instead of this because it will not work correcty
    // if someone give date instead of input
    string inp;
    cin>>inp;
    //switch statements

    bool flag = false;

    if(inp.size()>1){
      cout<<endl<<"-----------Wrong option selected !!!"<<endl;
    }
    else{

      int n=inp[0]-'0';

      switch(n){
        case 1: 
          cout<<endl;
          input();
          break;
        case 2:
          {
          string s;
          cout<<"Enter the date: ";
          cin>>s;
          printDate(s);
        }
          break;
        case 3:
          printFinal();
          break;
        case 4:
          del();
          break;
        case 5: cout<<endl<<"Kindly visit again!!!"<<endl;flag=true;
          break;

        default: {
          cout<<endl<<"-----------Wrong option selected !!!"<<endl;
        }
        break;
        }
    }

    if(flag)break;
  }

}