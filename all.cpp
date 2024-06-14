
FCFS

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string P[] = {"p1", "p2", "p3", "p4", "p5"};
    int AT[] = {0, 1, 2, 3, 4};
    int BT[] = {2, 3, 5, 4, 6};
    int n = sizeof AT / sizeof AT[0];
    int CT[n], WT[n], TAT[n];
    int total_CT = 0;
    for (int i = 0; i < n; i++)
    {
        CT[i] = total_CT + BT[i];
        total_CT = CT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << P[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
    }
    float sum_TAT = 0, sum_WT = 0;
    for (int i = 0; i < n; i++)
    {
        sum_TAT += TAT[i];
        sum_WT += WT[i];
    }
    cout << "Avg. TAT = " << sum_TAT / n << endl;
    cout << "Avg. WT = " << sum_WT / n << endl;
    return 0;
}


SJF


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string P[] = {"p1", "p2", "p3", "p4", "p5"};
    int AT[] = {3, 1, 4, 0, 2};
    int BT[] = {1, 4, 2, 6, 3};
    int old_BT[] = {1, 4, 2, 6, 3};
    int n = sizeof AT / sizeof AT[0];
    int CT[n], WT[n], TAT[n];
    int total_CT = 0;
    int H_AT = 0, T_BT = 0;
    for (int i = 0; i < n; i++)
    {
        CT[i] = 0;
        WT[i] = 0;
        TAT[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (AT[i] > H_AT)
        {
            H_AT = AT[i];
        }
        T_BT += BT[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (AT[i] == 0)
        {
            BT[i] -= 1;
            total_CT += 1;
        }
    }

    for (int i = 0; i < H_AT - 1; i++)
    {
        int small[100];
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (AT[j] <= total_CT)
            {
                small[temp++] = j;
            }
        }
        // for(int k=0;k<temp;k++)
        // {
        //     cout<<small[k]<<" "<<endl;
        // }
        int smaller = T_BT;
        int smaller_index;
        for (int j = 0; j < temp; j++)
        {
            if (BT[small[j]] < smaller && BT[small[j]] != 0)
            {
                smaller = BT[small[j]];
                smaller_index = small[j];
            }
        }
        BT[smaller_index] -= 1;
        total_CT += 1;
        if (BT[smaller_index] == 0)
        {
            CT[smaller_index] = total_CT;
        }
        // cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
        // for(int k=0;k<n;k++)
        // {
        //     cout<<P[k]<<"\t"<<AT[k]<<"\t"<<BT[k]<<"\t"<<CT[k]<<"\t"<<TAT[k]<<"\t"<<WT[k]<<"\n";
        // }
        // cout<<"Total CT = "<<total_CT<<endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int temp2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (BT[j] > temp2)
            {
                temp2 = BT[j];
            }
        }
        if (temp2 != 0)
        {
            int S_BT = T_BT;
            int index = 0;
            for (int j = 0; j < n; j++)
            {
                if (BT[j] < S_BT && BT[j] != 0)
                {
                    S_BT = BT[j];
                    index = j;
                }
            }
            if (S_BT != 0)
            {
                BT[index] -= S_BT;
                total_CT += S_BT;
                if (BT[index] == 0)
                {
                    CT[index] = total_CT;
                }
            }
            // cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
            // for(int k=0;k<n;k++)
            // {
            //     cout<<P[k]<<"\t"<<AT[k]<<"\t"<<BT[k]<<"\t"<<CT[k]<<"\t"<<TAT[k]<<"\t"<<WT[k]<<"\n";
            // }
            // cout<<"Total CT = "<<total_CT<<endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - old_BT[i];
    }
    cout << "PID\tAT\told_BT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << P[i] << "\t" << AT[i] << "\t" << old_BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
    }
    float sum_TAT = 0, sum_WT = 0;
    for (int i = 0; i < n; i++)
    {
        sum_TAT += TAT[i];
        sum_WT += WT[i];
    }
    cout << "Avg. TAT = " << sum_TAT / n << endl;
    cout << "Avg. WT = " << sum_WT / n << endl;
    return 0;
}



preemptive priority


#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> P = {"p1", "p2", "p3", "p4", "p5"};
    vector<int> AT = {0,1,2,4};
    vector<int> oBT = {5,4,2,1};
    vector<int> priority = {10,20,30,40};
    vector<int> index;
    vector<int> BT = {5,4,2,1};
    int n = AT.size();
    int CT[n], WT[n], TAT[n];
    int total_BT = 0;
    for(auto i:BT){
        total_BT += i;
    }
    int total_CT = 0;
    while(total_BT > total_CT)
    {
        for(int i=0;i<AT.size();i++){
            if(AT[i]<=total_CT && BT[i]>0){
                index.push_back(i);
            }
        }
        int temp_max = 0,temp_index;
        for(int j=0;j<index.size();j++){
            if(priority[index[j]]>temp_max){
                temp_max = priority[index[j]];
                temp_index = index[j];
            }
        }
        BT[temp_index] -= 1;
        total_CT += 1;
        if(BT[temp_index] == 0){
            CT[temp_index] = total_CT;
        }
        index.clear();
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - oBT[i];
        cout << P[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
    }
    float sum_TAT = 0, sum_WT = 0;
    for (int i = 0; i < n; i++)
    {
        sum_TAT += TAT[i];
        sum_WT += WT[i];
    }
    cout << "Avg. TAT = " << sum_TAT / n << endl;
    cout << "Avg. WT = " << sum_WT / n << endl;
    return 0;
}

Round Robin 

#include <iostream>
using namespace std;
struct Process {
  int id;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int turnaroundTime;
  int waitingTime;
};
void calculateTimes(Process processes[], int n, int quantum) {
  int remainingTime[n];
  for (int i = 0; i < n; i++) {
    remainingTime[i] = processes[i].burstTime;
  }
  int currentTime = 0;
  bool allDone = false;
  while (!allDone) {
    allDone = true;
    for (int i = 0; i < n; i++) {
      if (remainingTime[i] > 0) {
        allDone = false;
        if (remainingTime[i] > quantum) {
          currentTime = currentTime + quantum;
          remainingTime[i] = remainingTime[i] - quantum;
        } else {
          currentTime = currentTime + remainingTime[i];
          processes[i].completionTime = currentTime;
          remainingTime[i] = 0;
        }
      }
    }
  }
}
void calculateTurnaroundTime(Process processes[], int n) {
  for (int i = 0; i < n; i++)
    processes[i].turnaroundTime =
        processes[i].completionTime - processes[i].arrivalTime;
}

void claculateWaitingTime(Process processes[], int n) {
  for (int i = 0; i < n; i++)
    processes[i].waitingTime =
        processes[i].turnaroundTime - processes[i].burstTime;
}

void printTable(Process processes[], int n) {
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
  cout << "| Process | Arrival Time | Burst Time | Completion Time | "
          "Turnaround Time | Waiting Time |\n";
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
  for (int i = 0; i < n; i++) {
    cout << "|    " << processes[i].id << "    |      "
         << processes[i].arrivalTime << "      |     " << processes[i].burstTime
         << "     |        " << processes[i].completionTime
         << "        |        " << processes[i].turnaroundTime
         << "         |      " << processes[i].waitingTime << "      |\n";
  }
  cout << "--------------------------------------------------------------------"
          "----------------------\n";
}
int main() {
  int n, quantum;
  cout << "Enter The Number of Process";
  cin >> n;
  cout << "Enter The Time Quantum";
  cin >> quantum;

  Process processes[n];
  cout << "Enter process details:\n";
  for (int i = 0; i < n; i++) {
    cout << "Process " << i + 1 << ":\n";
    processes[i].id = i + 1;
    cout << "   Arrival Time: ";
    cin >> processes[i].arrivalTime;
    cout << "   Burst Time: ";
    cin >> processes[i].burstTime;
  }

  calculateTimes(processes, n, quantum);
  calculateTurnaroundTime(processes, n);
  claculateWaitingTime(processes, n);

  cout << "\nRound Robin Scheduling Results:\n";
  printTable(processes, n);

  return 0;
}




FIFO




#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v1={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int f_size = 3;
    int mis=0, hit=0,temp_i=0;
    vector<int> v2;
    for(int i=0;i<f_size;i++)
    {
        v2.push_back(v1[i]);
        mis++;
        cout<<"mis\t";
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=f_size;i<v1.size();i++){
        auto it = find(v2.begin(),v2.end(),v1[i]);
        if(it != v2.end()) {
            cout<<"hit\t";
            hit++;
        }
        else{
            cout<<"mis\t";
            v2[(temp_i++)%3] = v1[i];
            mis++;
        }
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Hit count = "<<hit<<endl;
    cout<<"Mis count = "<<mis<<endl;
    return 0;
}



LRU 


#include <bits/stdc++.h>
// some error is there in functio find_last()
using namespace std;
int find_last(vector<int> temp,vector<int> v1)
{
    int max_i = -1,max_e = 0;
    for(int i=0;i<v1.size();i++)
    {
        auto it = find(temp.begin(),temp.end(),v1[i]);
        if(max_i<(it-temp.begin())){
            max_i = it-temp.begin();
            max_e = temp[it-temp.begin()];
            cout<<max_i<<" "<<max_e<<endl;
        }
    }
    auto it1 = find(v1.begin(),v1.end(),max_e);
    return it1-v1.begin();
}

int main()
{
    vector<int> v1={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    vector<int> temp;
    int f_size = 4;
    int mis=0, hit=0;
    vector<int> v2;
    for(int i=0;i<f_size;i++)
    {
        v2.push_back(v1[i]);
        mis++;
        cout<<"mis\t";
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=f_size;i<v1.size();i++){
        auto it = find(v2.begin(),v2.end(),v1[i]);
        if(it != v2.end()) {
            cout<<"hit\t";
            hit++;
        }
        else{
            cout<<"mis\t";
            for(int j=i-1;j>=0;j--){
                temp.push_back(v1[j]);
            }
            cout<<endl;
            for(auto k:temp){
                cout<<k<<" ";
            }
            cout<<endl;
            int last_e_i = find_last(temp,v1);
            v2[last_e_i] = v1[i];
            mis++;
            temp.clear();
        }
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Hit count = "<<hit<<endl;
    cout<<"Mis count = "<<mis<<endl;
    return 0;
}


MRU 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v1={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int f_size = 4;
    int mis=0, hit=0,last=0;
    vector<int> v2;
    for(int i=0;i<f_size;i++)
    {
        v2.push_back(v1[i]);
        mis++;
        cout<<"mis\t";
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=f_size;i<v1.size();i++){
        auto it = find(v2.begin(),v2.end(),v1[i]);
        if(it != v2.end()) {
            cout<<"hit\t";
            hit++;
            last = v1[i];
        }
        else{
            cout<<"mis\t";
            auto it = find(v2.begin(),v2.end(),last);
            v2[it-v2.begin()] = v1[i];
            mis++;
            last = v1[i];
        }
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Hit count = "<<hit<<endl;
    cout<<"Mis count = "<<mis<<endl;
    return 0;
}


Optimal



#include <bits/stdc++.h>
using namespace std;
int find_last(vector<int> temp,vector<int> v1)
{
    for(int i=temp.size()-1;i>=0;i--)
    {
        auto it = find(v1.begin(),v1.end(),temp[i]);
        return it-v1.begin();
    }
    return 0;
}

int main()
{
    vector<int> v1={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    vector<int> temp;
    int f_size = 4;
    int mis=0, hit=0;
    vector<int> v2;
    for(int i=0;i<f_size;i++)
    {
        v2.push_back(v1[i]);
        mis++;
        cout<<"mis\t";
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=f_size;i<v1.size();i++){
        auto it = find(v2.begin(),v2.end(),v1[i]);
        if(it != v2.end()) {
            cout<<"hit\t";
            hit++;
        }
        else{
            cout<<"mis\t";
            for(int j=i+1;j<v1.size();j++){
                temp.push_back(v1[j]);
            }
            int last_e_i = find_last(temp,v1);
            v2[last_e_i] = v1[i];
            mis++;
            temp.clear();
        }
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Hit count = "<<hit<<endl;
    cout<<"Mis count = "<<mis<<endl;
    return 0;
}



FCFS disk




#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {176, 79, 34, 60, 92, 11, 41, 114};
    int ans = 0,hp = 50,total = 0, no_cyl = 200;
    cout<<"Seek operations sequence : \n";
    for(auto i:v)
    {
        cout<<i<<endl; 
    }
    total += abs(v[0] - hp);
    for(int i=0;i<(v.size()-1);i++){
        total += abs(v[i]-v[i+1]);
    }
    cout<<"Total No of seek movement : "<<total;
    return 0;
}




SSTF disk




#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {176, 79, 34, 60, 92, 11, 41, 114};
    int ans = 0,hp = 50,total = 0, no_cyl = 200;
    cout<<"Seek operations sequence : \n";
    for(auto i:v)
    {
        cout<<i<<endl; 
    }
    total += abs(v[0] - hp);
    for(int i=0;i<(v.size()-1);i++){
        total += abs(v[i]-v[i+1]);
    }
    cout<<"Total No of seek movement : "<<total;
    return 0;
}
