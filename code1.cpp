#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct Task {
    int id;
    int arrivalTime;
    int burstTime;
    // int priority;
    int remainingTime;
    // int startTime;
    // int endTime;
    int waitingTime;
    int turnaroundTime;
};

struct res{
    int id;
    int startTime;
    int endTime;
};
void gantt(vector<res>&letsgo,ofstream& output){
    for(auto& it:letsgo){
        output<<"|P"<<it.id<<" ";
    }
    output<<" | "<<endl;

    for(auto it:letsgo){
        output<<it.startTime<<"\t";
    }
    output<<letsgo.back().endTime<<endl;
}
void wait_turning_time(vector<Task>&ans){
    for(auto it:ans){
        it.turnaroundTime=it.waitingTime+it.burstTime;
    }
}
void averagetime(vector<Task>&ans,ofstream &output){
    int tw=0;
    int ta=0;
    int n=ans.size();
    for(auto it:ans){
        tw+=it.waitingTime;
        ta+=it.turnaroundTime;
    }
    output<<(float)tw/n<<endl;
    output<<(float)ta/n<<endl;
}
void check(int t,int arr[],queue<int>& r_queue,vector<Task>&ans){
    int n=ans.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=t && arr[i]!=-1){
            r_queue.push(i);
            arr[i]=-1;
        }
    }
}
void manage_queue(int index,queue<int>&r_queue){
    r_queue.push(index);
}
void RoundRobin(vector<Task>&ans,ofstream&output,int quant){
    vector<res>lets;
    int crnt=0;// currentTime;
    int n=ans.size();//size of ans;
    int arr[n];
    queue<int>r_queue;//ready
    int comp=0;
    for(auto &it:ans){
        it.remainingTime=it.burstTime;
    }
    for(int i=0;i<n;i++){
        arr[i]=ans[i].arrivalTime;
    }
    while(comp!=n){
        check(crnt,arr,r_queue,ans);
        if(r_queue.empty()){
            crnt++;
            continue;
        }
        int crt=r_queue.front();// current
        r_queue.pop();

        int tSlice =min(quant,ans[crt].remainingTime);
        lets.push_back({ans[crt].id,crnt,crnt+tSlice});
        ans[crt].remainingTime-=tSlice;
        crnt+=tSlice;
        check(crnt,arr,r_queue,ans);
        if(ans[crt].remainingTime >0){
            manage_queue(crt,r_queue);
        }
        else{
            comp++;
            ans[crt].waitingTime=crnt-ans[crt].arrivalTime-ans[crt].burstTime;
        }
    }
    output<<"RoundRobin scheduling"<<quant<< endl;
    gantt(lets,output);
    averagetime(ans,output);
    wait_turning_time(ans);
}
void FCFS(vector<Task>&ans,ofstream&output){
    std::sort(ans.begin(),ans.end(), [](const Task& x,const Task& y){
        return x.arrivalTime < y.arrivalTime;
    });
    // sort(ans.begin(),ans.end());
    vector<res>lets;
    int currentTime=0;
    for(auto& it:ans){
        if(currentTime<it.arrivalTime){
            currentTime=it.arrivalTime;
        }
        it.waitingTime=max(0,currentTime-it.arrivalTime);
        lets.push_back({it.id,currentTime,currentTime+it.burstTime});
        currentTime+=it.burstTime;
    }
    output<<"FCFS Scheduling:"<<endl;
    gantt(lets,output);
    averagetime(ans,output);
    wait_turning_time(ans);
}
void SRTF(vector<Task>&ans,ofstream &output){
    int n=ans.size();
    vector<res>lets;
    int crr=0,comp=0;
    while(comp!=n){
        int sort=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(ans[i].arrivalTime <=crr && ans[i].remainingTime >0 && ans[i].remainingTime<mini){
                mini=ans[i].remainingTime;
                sort=i;
            }
        }
        if(sort==-1){
            crr++;
            continue;
        }
        lets.push_back({ans[sort].id,crr,crr+1});
        ans[sort].remainingTime--;
        if(ans[sort].remainingTime==0){
            comp++;
            ans[sort].waitingTime=crr+1-ans[sort].arrivalTime-ans[sort].burstTime;
        }
        crr++;
    }
    output<<"SRTF scheduling"<<endl;
    gantt(lets,output);
    averagetime(ans,output);
    wait_turning_time(ans);
}
void SJF(vector<Task>&ans,ofstream&output){
    auto comp_arrival=[](const Task& x,const Task&y){
        return x.arrivalTime < y.arrivalTime;
    };
    sort(ans.begin(),ans.end(),comp_arrival);
    vector<res>lets;
    vector<Task>ready_queue;
    int currentTime=0;
    int index=0;
    int n=ans.size();
    while(index<n || !ready_queue.empty()){
        while(index<n && ans[index].arrivalTime<=currentTime){
            ready_queue.push_back(ans[index]);
            index++;
        }
        if(ready_queue.empty()){
            currentTime=ans[index].arrivalTime;
            continue;
        }
        auto comp_burst = [](const Task& x, const Task& y) {
            return x.burstTime < y.burstTime;
        };
        sort(ready_queue.begin(), ready_queue.end(), comp_burst);

       
        Task q = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        q.waitingTime = max(0, currentTime - q.arrivalTime);
        lets.push_back({q.id, currentTime, currentTime + q.burstTime});
        currentTime += q.burstTime;

        
        for (auto& it: ans) {
            if (it.id == q.id) {
                it.waitingTime = q.waitingTime;
                it.turnaroundTime = it.waitingTime + it.burstTime;
                break;
            }
        }
    }
    output<<"SJF scheduling"<<endl;
    gantt(lets,output);
    averagetime(ans,output);
    wait_turning_time(ans);
}
void LJF(vector<Task>&ans,ofstream&output){
    // complete arrivaltime;
    auto compt=[](const Task&x,const Task&y){
        return x.arrivalTime < y.arrivalTime;
    };
    vector<Task>r_queue;
    vector<res>lets;
    int crnt=0;
    int index=0;
    int n=ans.size();
    sort(ans.begin(),ans.end(),compt);
    while(index < n || !r_queue.empty()){
        while(index < n && ans[index].arrivalTime<=crnt){
            r_queue.push_back(ans[index]);
            index++;
        }
        if(r_queue.empty()){
            crnt=ans[index].arrivalTime;
            continue;
        }
        // complete burstTime;
        auto compb = [](const Task& x, const Task& y) {
            return x.burstTime > y.burstTime; // Sort in descending order for LJF
        };
        sort(r_queue.begin(),r_queue.end(),compb);
        Task T=r_queue.front();
        r_queue.erase(r_queue.begin());

        T.waitingTime=max(0,crnt-T.arrivalTime);
        lets.push_back({T.id,crnt,crnt+T.burstTime});
        crnt+=T.burstTime;
        for(auto &it:ans){
            if(it.id==T.id){
                it.waitingTime=T.waitingTime;
                it.turnaroundTime=it.waitingTime+it.burstTime;
                break;
            }
        }
    }
    output<<"LJF scheduling:"<<endl;
    gantt(lets,output);
    averagetime(ans,output);
    wait_turning_time(ans);
}
string PredictAlgo(vector<Task>&ans){
    // total burst time
    int n=ans.size();
    double Tbt=accumulate(ans.begin(),ans.end(),0.0,[](double s,const Task&T) {return s+T.burstTime;});
    double avg_B_T=Tbt/n;//avg burst time
    // all burst time same
    bool all_B_T_S = all_of(ans.begin(),ans.end(),[&](const Task&T) {return T.burstTime==ans[0].burstTime;});

    if(all_B_T_S) return"FCFS";
    // burst time variancec
    double burst_T_V=0;

    for(const auto &it:ans){
        burst_T_V+=(it.burstTime-avg_B_T)*(it.burstTime-avg_B_T);
    }

    burst_T_V/=n;
  // total arriving time
    double total_A_T = accumulate(ans.begin(), ans.end(), 0.0, 
    [](double sum, const Task& T) { return sum + T.arrivalTime;});

    double avg_A_T = total_A_T /n;
   
    double arrival_T_V = 0;

    for(const auto& it: ans) {
        arrival_T_V += (it.arrivalTime - avg_A_T) * (it.arrivalTime - avg_A_T);
    }
    arrival_T_V /=n;

    int long_B_cnt = count_if(ans.begin(), ans.end(), [&](const Task& p) {
        return p.burstTime > avg_B_T;
    });

    if(burst_T_V < avg_B_T && arrival_T_V < avg_A_T) {
        return "SJF";
    } else if (burst_T_V < avg_B_T) {
        return "SRTF";
    } else if (long_B_cnt > n/ 2) {
        return "LJF";
    } else {
        return "Round Robin";
    }
}
void scheduler(){
    ifstream input("input.text");
    ofstream output("output.txt");
    if(!input.is_open()){
        cout<<"error in input"<<endl;
        return;
    }
    if(!output.is_open()){
        cout<<"error in output"<<endl;
        return;
    }
    // std::vector<Task>ans;
    vector<Task>ans;
    //  int n = ans.size();
    int id,arrivalTime,burstTime;
    while(input>>id>>burstTime>>arrivalTime){
        ans.push_back({id,burstTime,arrivalTime,burstTime,0,0});
    }
    if(ans.empty()){
        output<<"No ans in input"<<endl;
        return;
    }
    else{
        for(const auto&it:ans){
            cout<<"id"<<it.id<<"burst Time"<<it.burstTime<<"arrival time"<<it.arrivalTime<<endl;
        }
    }
    string pred=PredictAlgo(ans);
    output<<"predictalgo"<<pred<<endl;
    output<<endl;
    RoundRobin(ans,output,2);
    FCFS(ans,output);
    SRTF(ans,output);
    SJF(ans,output);
    LJF(ans,output);

    input.close();
    output.close();
}
int main(){
    scheduler();
    return 0;
}