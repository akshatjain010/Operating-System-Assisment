#include<iostream> 
#include<algorithm>
using namespace std; 
struct Process 
{ 
    int pid;  // Process ID 
    int bt;   // CPU Burst time required 
    int priority; // Priority of this process 
}; 
  
// Function to sort the Process acc. to priority 
bool comparison(Process a, Process b) 
{ 
    return (a.priority < b.priority); 
} 
  
// Function to find the waiting time for all 
// processes 
void findWaitingTime(Process proc[], int n, 
                     int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  proc[i-1].bt + wt[i-1] ; 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime( Process proc[], int n, 
                         int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
  
//Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function to find waiting time of all processes 
    findWaitingTime(proc, n, wt); 
  
    //Function to find turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    //Display processes along with all details 
    cout << "\nProcesses  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t    " << wt[i] 
             << "\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
void priorityScheduling(Process proc[], int n) 
{ 
    // Sort processes by priority 
    sort(proc, proc + n, comparison); 
  
    cout<< "Order in which processes gets executed \n"; 
    for (int  i = 0 ; i <n; i++) 
        cout << proc[i].pid <<" " ; 
  
    findavgTime(proc, n); 
}  
void findwaitingtime(int processes[], int p, 
             int bt[], int wt[], int quantum) 
{ 
    // Make a copy of burst times bt[] to store remaining 
    // burst times. 
    int rem_bt[p]; 
    for (int i = 0 ; i < p ; i++) 
        rem_bt[i] =  bt[i]; 
  
    int t = 0; // Current time 
  
    // Keep traversing processes in round robin manner 
    // until all of them are not done. 
    while (1) 
    { 
        bool done = true; 
  
        // Traverse all processes one by one repeatedly 
        for (int i = 0 ; i < p; i++) 
        { 
            // If burst time of a process is greater than 0 
            // then only need to process further 
            if (rem_bt[i] > 0) 
            { 
                done = false; // There is a pending process 
  
                if (rem_bt[i] > quantum) 
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t += quantum; 
  
                    // Decrease the burst_time of current process 
                    // by quantum 
                    rem_bt[i] -= quantum; 
                } 
  
                // If burst time is smaller than or equal to 
                // quantum. Last cycle for this process 
                else
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + rem_bt[i]; 
  
                    // Waiting time is current time minus time 
                    // used by this process 
                    wt[i] = t - bt[i]; 
  
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
  
        // If all processes are done 
        if (done == true) 
          break; 
    } 
} 
  
// Function to calculate turn around time 
void findturnaroundtime(int processes[], int p, 
                        int bt[], int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < p ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
// Function to calculate average time 
void findavgtime(int processes[], int p, int bt[], 
                                     int quantum) 
{ 
    int wt[p], tat[p], total_wt = 0, total_tat = 0; 
  
    // Function to find waiting time of all processes 
    findwaitingtime(processes, p, bt, wt, quantum); 
  
    // Function to find turn around time for all processes 
    findturnaroundtime(processes, p, bt, wt, tat); 
  
    // Display processes along with all details 
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int i=0; i<p; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = "
         << (float)total_wt / (float)p; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)p; 
} 
  
// Driver code 
int main() 
{ 
    Process proc[] = {{1, 10, 0}, {2, 5, 1}, {3, 8, 2}}; 
    int n = sizeof proc / sizeof proc[0]; 
    priorityScheduling(proc, n);
    int processes[] = { 1, 2, 3}; 
    int p = sizeof processes / sizeof processes[0]; 
  
    // Burst time of all processes 
    int burst_time[] = {10, 5, 8}; 
  
    // Time quantum 
    int quantum = 8; 
    findavgtime(processes, p, burst_time, quantum); 
    return 0; 
}
