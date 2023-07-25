#include<iostream>
using namespace std;
int main()
{
    int  n;
    cout<<"Enter Total Number of Processes:";
    cin>>n;
    int wait_time = 0, ta_time = 0, arr_time[n], burst_time[n], temp_burst_time[n];
    int x = n;
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter Details of Process  "<<i + 1<<endl;
        cout<<"Arrival Time:  ";
        cin>>arr_time[i];
        cout<<"Burst Time:   ";
        cin>>burst_time[i];
        temp_burst_time[i] = burst_time[i];
    }
 
     int time_slot;
    cout<<"Enter Time Slot:";
    cin>>time_slot;
 
    int total = 0,  counter = 0,i;
    cout<<"Process ID           Burst Time          Turnaround Time         Waiting Time\n";
    for(total=0, i = 0; x!=0; )  
    {  
        if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0)    
        {  
            total = total + temp_burst_time[i];  
            temp_burst_time[i] = 0;  
            counter=1;  
        }     
        else if(temp_burst_time[i] > 0)  
        {  
            temp_burst_time[i] = temp_burst_time[i] - time_slot;  
            total  += time_slot;    
        }  
        if(temp_burst_time[i]==0 && counter==1)  
        {  
            x--;  
            printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d", i+1, burst_time[i],
                   total-arr_time[i], total-arr_time[i]-burst_time[i]);  
            wait_time = wait_time+total-arr_time[i]-burst_time[i];  
            ta_time += total -arr_time[i];  
            counter =0;     
        }  
        
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(arr_time[i+1]<=total)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;
    cout<<"\n\nAverage Waiting Time:"<<average_wait_time;
    cout<<"\n\nAvg Turnaround Time:"<<average_turnaround_time;
    return 0;
}
