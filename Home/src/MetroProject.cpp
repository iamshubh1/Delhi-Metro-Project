#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stdio.h>
#include<graphics.h>
#include<queue>
#include<limits.h>
#include<conio.h>
#include<math.h>
#include<vector>
#include<iterator>
#include<utility>
#include<time.h>        
#define PI 3.14159265
using namespace std;
void addEdge(vector<vector<pair<int,int>>>&adj,int u,int v,int wt){
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}
void createGraph(vector<vector<pair<int,int>>>&adjd,vector<vector<pair<int,int>>>&adjt){
    addEdge(adjd,0,1,3);
    addEdge(adjt,0,1,4);
    addEdge(adjd,1,2,2);
    addEdge(adjt,1,2,2);
    addEdge(adjd,2,5,5);
    addEdge(adjt,2,5,4);
    addEdge(adjd,3,1,5);
    addEdge(adjt,3,1,6);
    addEdge(adjd,2,4,3);
    addEdge(adjt,2,4,4);
    addEdge(adjd,4,6,8);
    addEdge(adjt,4,6,7);
    addEdge(adjd,4,7,8);
    addEdge(adjt,4,7,8);
    addEdge(adjd,3,7,2);
    addEdge(adjt,3,7,4);
    addEdge(adjd,7,10,8);
    addEdge(adjt,7,10,8);
    addEdge(adjd,10,11,7);
    addEdge(adjt,10,11,6);
    addEdge(adjd,11,18,9);
    addEdge(adjt,11,18,8);
    addEdge(adjd,18,12,7);
    addEdge(adjt,18,12,9);
    addEdge(adjd,10,12,4);
    addEdge(adjt,10,12,4);
    addEdge(adjd,12,13,10);
    addEdge(adjt,12,13,11);
    addEdge(adjd,13,19,12);
    addEdge(adjt,13,19,13);
    addEdge(adjd,12,16,9);
    addEdge(adjt,12,16,11);
    addEdge(adjd,7,8,6);
    addEdge(adjt,7,8,5);
    addEdge(adjd,8,9,13);
    addEdge(adjt,8,9,14);
    addEdge(adjd,8,14,3);
    addEdge(adjt,8,14,4);
    addEdge(adjd,14,15,7);
    addEdge(adjt,14,15,9);
    addEdge(adjd,15,16,9);
    addEdge(adjt,15,16,11);
    addEdge(adjd,16,17,2);
    addEdge(adjt,16,17,5);
}
vector<string> mappingSC(unordered_map<string,string>&mp,vector<string>&STN){
    mp["SPB"]="Samaypur Badli";
    mp["AZP"]="Azadpur";
    mp["NSP"]="NSP";
    mp["VVL"]="Vishwavidhyalaya";
    mp["ILK"]="Inderlok";
    mp["RTH"]="Rithala";
    mp["PJB"]="Punjabi Bagh";
    mp["KMG"]="Kashmere Gate";
    mp["WLC"]="Welcome";
    mp["SDR"]="Shahdara";
    mp["NDL"]="New Delhi";
    mp["RJC"]="Rajiv Chowk";
    mp["INA"]="INA";
    mp["SKT"]="Saket";
    mp["AVIS"]="Anand Vihar ISBT";
    mp["AKD"]="Akshardham";
    mp["LJP"]="Lajpat Nagar";
    mp["BPB"]="Badarpur Border";
    mp["SJN"]="Sarojini Nagar";
    mp["HCC"]="Huda City Centre";
    vector<string>SCToNC{"SPB","AZP","NSP","VVL","ILK","RTH","PJB","KMG","WLC","SDR","NDL","RJC","INA","SKT","AVIS","AKD","LJP","BPB","SJN","HCC"};
    return SCToNC;
}
void printIntro(){
        for(int i=0;i<17;i++)cout<<" ";
        for(int i=0;i<20;i++)cout<<"* ";cout<<endl;
        for(int i=0;i<17;i++)cout<<" ";
        cout<<"*";
        for(int i=0;i<10;i++)cout<<" ";
        cout<<"METRO ROUTE FINDER";
        for(int i=0;i<9;i++)cout<<" ";
        cout<<"*";
        cout<<endl;
        for(int i=0;i<17;i++)cout<<" ";
        for(int i=0;i<20;i++)cout<<"* ";cout<<endl;
        for(int i=0;i<8;i++)cout<<"* ";
        cout<<"WELCOME TO THE DELHI METRO ROUTE FINDER APP ";
        for(int i=0;i<9;i++)cout<<"* ";cout<<endl<<endl;
}
void printMM(){
    for(int i=0;i<78;i++)cout<<"*";cout<<endl;
    cout<<"*** THE FOLLOWING IS THE MAIN MENU. CHOOSE OPTIONS (1 TO 7) FROM THE MENU. ***"<<endl;
    cout<<"1. SHOW ALL THE STATIONS WITH STATION CODE AS WELL AS STATION NUMERIC CODE(OR STATION LIST)."<<endl;
    cout<<"2. SHOW THE GRAPICAL VISUALIZATION OF ALL STATIONS(OR STATIONS MAP)."<<endl;
    cout<<"3. DETERMINE THE 'SHORTEST DISTANCE' FROM A SOURCE STATION TO A DESTINATION STATION."<<endl;
    cout<<"4. DETERMINE THE 'SHORTEST TIME' FROM A SOURCE STATION TO A DESTINATION STATION."<<endl;
    cout<<"5. DETERMINE THE SHORTEST PATH(OR DISTANCE WISE) FROM A SOURCE STATION TO A DESTINATION STATION.:"<<endl;
    cout<<"6. DETERMINE THE SHORTEST PATH(OR TIME WISE) FROM A SOURCE STATION TO A DESTINATION STATION."<<endl;
    cout<<"7. EXIT THE MAIN MENU."<<endl;
    for(int i=0;i<78;i++)cout<<"*";cout<<endl;
}
void findPath(int i,int dist,int dest,vector<bool>&vis,vector<vector<int>>v,vector<vector<int>>&ans,vector<vector<pair<int,int>>>&adj){
    vis[i]=1;
    if(dist==0 && dest==i){
        ans=v;return;
    }
    for(auto& j:adj[i]){
        if(vis[j.first]==0){
            v.push_back({i,j.first,j.second});
            findPath(j.first,dist-j.second,dest,vis,v,ans,adj);
            v.pop_back();
        }
    }
    vis[i]=0;
}
vector<vector<pair<int,int>>> dijkstra(int n,vector<vector<pair<int,int>>>&adj,int src,int dest,int mode,int&mini){
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first,ele=pq.top().second;pq.pop();
            for(auto& i:adj[ele]){
                if((d+i.second)<dist[i.first]){
                    dist[i.first]=d+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
        mini=dist[dest];
        if(mode==1)return {};
        vector<bool>vis(n,0);
        vector<vector<int>>ans;
        findPath(src,dist[dest],dest,vis,{},ans,adj);
        vector<vector<pair<int,int>>>res(20);
        //cout<<ans.size()<<endl;
        for(auto& i:ans){
            res[i[0]].push_back({i[1],i[2]});
            res[i[1]].push_back({i[0],i[2]});
        }
        return res;
    }
vector< pair<int,int> > getCoords(int n)
{
    int cenX=getmaxx()/2,cenY=getmaxy()/2; 
    vector< pair<int,int> > coords; 
    int x,y;
    x=0;
    y=(22*n);
    coords.push_back(make_pair(x+cenX,cenY+y));
    for(int i=1;i<n;i++)
    {
    int newX=(x*cos(2*PI/n) - y*sin(2*PI/n));
    y=(y*cos(2*PI/n) + x*sin(2*PI/n));
    x=newX;
    coords.push_back(make_pair(x+cenX,cenY+y));
    }
    return coords;
}
void diplayGraph(vector<vector< pair<int,int> > >&arr,int n,vector<string>&v)
{
    vector< pair<int,int> > coords = getCoords(n); 
    vector< pair<int,int> >::iterator i;
    char str[5];
    for(int f=0;f<n;f++){
        for(i = arr[f].begin();i <  arr[f].end();i++)
        {
            line(coords[f].first,coords[f].second,coords[(*i).first].first,coords[(*i).first].second);
            sprintf(str,"%d",(*i).second);
            outtextxy((coords[(*i).first].first + coords[f].first)/2 - 5,(coords[(*i).first].second + coords[f].second)/2 -7,str);
            }
    }
    string symbol;
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    for(int i=0;i<coords.size();i++)
    {
        symbol=v[i];
        setcolor(LIGHTGRAY);
        circle(coords[i].first,coords[i].second,13);
        floodfill(coords[i].first+1,coords[i].second+1,LIGHTGRAY); 
        setcolor(BLACK);
        outtextxy(coords[i].first-12,coords[i].second-7,&symbol[0]);
    }
}
int main() {
unordered_map<string,string>mp;
vector<vector<pair<int,int>>>adjd(20),adjt(20);
vector<string>SCToNC;
createGraph(adjd,adjt);
SCToNC=mappingSC(mp,SCToNC);
printIntro();
while(true){
    printMM();
    int input;
    cout<<"CHOOSEN OPTION IS :: ";
    cin>>input;
    if(input==1){
       cout<<"SHOWING ALL THE STATIONS WITH STATION CODE AS WELL AS STATION NUMERIC CODE."<<endl; 
       cout<<" STATION NUMERIC CODE     STATION NAME   ( WITH STATION CODE )"<<endl;
       for(int i=0;i<20;i++){
           cout<<"            "<<i<<"              "<<mp[SCToNC[i]]<<"    ( "<<SCToNC[i]<<" )"<<endl;
       }
    } 
    
    else if(input==2){
        int choice;
        cout<<"WHICH OF THE FOLLOWING GRAPHICAL VISUALIZATION DO YOU WANT TO SEE::  \n 1. DISTANCE WISE GRAPHICAL VISUALIZATION \n 2. TIME WISE GRAPHICAL VISUALIZATION "<<endl;
        cin>>choice;
        if(choice==1){
            initwindow(getmaxwidth( ), getmaxheight( ));
            diplayGraph(adjd,20,SCToNC);
        }
        if(choice==2){
            initwindow(getmaxwidth( ), getmaxheight( ));
            diplayGraph(adjt,20,SCToNC);
        }
    }
    
    else if(input==3){
        int src,dest;
        cout<<"ENTER THE SOURCE STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>src;
        cout<<"ENTER THE DESTINATION STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>dest;
        int shortestDistance;
        dijkstra(20,adjd,src,dest,1,shortestDistance);
        cout<<"THE FOLLOWING SHORTEST DISTANCE FROM THE "<<mp[SCToNC[src]]<<" TO THE "<<mp[SCToNC[dest]]<<" IS :: "<<shortestDistance<<endl;
    }
    else if(input==4){
        int src,dest;
        cout<<"ENTER THE SOURCE STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>src;
        cout<<"ENTER THE DESTINATION STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>dest;
        int shortestTime;
        dijkstra(20,adjt,src,dest,1,shortestTime);
        cout<<"THE FOLLOWING SHORTEST TIME FROM THE "<<mp[SCToNC[src]]<<" TO THE "<<mp[SCToNC[dest]]<<" IS :: "<<shortestTime<<endl;
    }
    else if(input==5){
        int src,dest;
        cout<<"ENTER THE SOURCE STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>src;
        cout<<"ENTER THE DESTINATION STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>dest;
        int shortestDistance;
        auto ans=dijkstra(20,adjd,src,dest,0,shortestDistance);
        cout<<"THE FOLLOWING SHORTEST DISTANCE FROM THE "<<mp[SCToNC[src]]<<" TO THE "<<mp[SCToNC[dest]]<<" IS :: "<<shortestDistance<<endl;
        initwindow(getmaxwidth( ), getmaxheight( ));
        diplayGraph(ans,20,SCToNC);
    }
    else if(input==6){
        int src,dest;
        cout<<"ENTER THE SOURCE STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>src;
        cout<<"ENTER THE DESTINATION STATION NUMERIC CODE FROM THE STATIONS LIST :: ";cin>>dest;
        int shortestTime;
        auto ans=dijkstra(20,adjt,src,dest,0,shortestTime);
        cout<<"THE FOLLOWING SHORTEST TIME FROM THE "<<mp[SCToNC[src]]<<" TO THE "<<mp[SCToNC[dest]]<<" IS :: "<<shortestTime<<endl;
        initwindow(getmaxwidth( ), getmaxheight( ));
        diplayGraph(ans,20,SCToNC);
    }
    else if(input==7){
        cout<<" WE HOPE THAT ALL YOUR QUERIES HAVE BEEN ADDRESSED TO YOUR SATISFACTION,AND WE SINCERELY HOPE THAT YOU ARE PLEASED WITH THE LEVEL OF SERVICE WE HAVE PROVIDED.  "<<endl;
        int choice;
        cout<<endl<<"PRESS ANY KEY OTHER THAN ENTER KEY TO CLOSE THE APP."<<endl;
        cin>>choice;
        return 0;
    }
    else{
        cout<<"THE SELECTED OPTION DOES NOT APPEAR TO BE FROM THE MAIN MENU. ";
    }
}
}