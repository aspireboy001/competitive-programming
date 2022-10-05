#include<bits/stdc++.h>
using namespace std ;

class node {
public:
    int process_Number ;
    int arrival_Time ;
    int burst_Time ;
    int waiting_Time ;
    int turn_Around_Time;
    int completion_Time;
    int priority ;
};

void FCFSwithoutAT() {

    cout << "\nEnter number of processes : ";
    int n;
    cin >> n ;

    vector<node> processes(n);

    cout << "\nEnter burst_Time  : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].burst_Time ;
        processes[i].process_Number = i + 1 ;
    }


    int waited_Till = 0 ;

    float Average_WT = 0 ;
    float Average_TAT = 0 ;

    for (int i = 0 ; i < n; i++) {
        processes[i].waiting_Time = waited_Till ;
        waited_Till += processes[i].burst_Time ;
        Average_WT += (processes[i].waiting_Time);
    }


    for (int i = 0 ; i < n; i++) {
        processes[i].turn_Around_Time =  processes[i].burst_Time + processes[i].waiting_Time;
        Average_TAT += (processes[i].turn_Around_Time);
    }

    cout << "id  BT  WT TAT" << endl;

    for (int i = 0 ; i < n ; i++) {
        cout << "P" << processes[i].process_Number << "\t";
        cout << processes[i].burst_Time << "\t";
        cout << processes[i].waiting_Time << "\t";
        cout << processes[i].turn_Around_Time << "\t";
        cout << endl;
    }

    cout << "\nAverage waiting time is : " << Average_WT / n << endl;
    cout << "Average turn around time is : " << Average_TAT / n << endl;

}

void FCFSwithAT() {

    cout << "\nEnter number of processes  :";
    int n;
    cin >> n ;

    vector<node> processes(n);

    cout << "\nEnter arrival_Time  : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].arrival_Time ;
        processes[i].process_Number = i + 1 ;
    }

    cout << "\nEnter burst_Time  : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].burst_Time ;
    }

    sort(processes.begin() , processes.end() , [](node a , node b) {
        return a.arrival_Time < b.arrival_Time ;
    });

    int prev_process_completion_time = processes[0].arrival_Time ;

    for (int i = 0 ; i < n ; i++) {
        processes[i].completion_Time = processes[i].burst_Time + max(prev_process_completion_time, processes[i].arrival_Time) ;
        prev_process_completion_time = processes[i].completion_Time;
    }

    float Average_WT = 0;
    float Average_TAT = 0 ;

    for (int i = 0 ; i < n ; i++) {
        processes[i].turn_Around_Time = processes[i].completion_Time - processes[i].arrival_Time ;
        processes[i].waiting_Time = processes[i].turn_Around_Time - processes[i].burst_Time ;
        Average_WT += processes[i].waiting_Time;
        Average_TAT += processes[i].turn_Around_Time ;
    }

    cout << "id  AT  BT  CT  WT TAT" << endl;

    for (int i = 0 ; i < n ; i++) {
        cout << "P" << processes[i].process_Number << "\t";
        cout << processes[i].arrival_Time << "\t";
        cout << processes[i].burst_Time << "\t";
        cout << processes[i].completion_Time << "\t";
        cout << processes[i].waiting_Time << "\t";
        cout << processes[i].turn_Around_Time << "\t";
        cout << endl;
    }

    cout << "\nAverage waiting time is : " << Average_WT / n << endl;
    cout << "Average turn around time is : " << Average_TAT / n << endl;
}

void round_robbin() {

    cout << "\nEnter number of processes  :";
    int n;
    cin >> n ;

    vector<node> processes(n);

    cout << "\nEnter arrival_Time  : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].arrival_Time ;
        processes[i].process_Number = i ;
    }

    cout << "\nEnter burst_Time  : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].burst_Time ;
    }

    cout << "\nEnter time quantam : ";
    int tc ; cin >> tc ;

    vector<node> copy = processes ;

    sort(processes.begin() , processes.end() , [](node a , node b) {
        if (a.arrival_Time == b.arrival_Time)
            return a.process_Number < b.process_Number;
        return a.arrival_Time < b.arrival_Time ;
    });

    queue<node> q;

    vector<int> Gantt_Chart ;

    int i = 1 ;

    q.push(processes[0]) ;

    int time = processes[0].arrival_Time ;

    while ( i < n || !q.empty()) {

        if (q.empty()) {
            time++;

            while (i < n) {
                if (processes[i].arrival_Time <= time) {
                    q.push(processes[i]) ;
                    i++;
                }
                else break;
            }

            continue ;
        }

        node curr = q.front() ;
        q.pop() ;

        Gantt_Chart.push_back(curr.process_Number + 1) ;

        if (curr.burst_Time <= tc) {
            time += curr.burst_Time ;
            curr.burst_Time = 0 ;
            copy[curr.process_Number].completion_Time = time ;

            while (i < n) {
                if (processes[i].arrival_Time <= time) {
                    q.push(processes[i]) ;
                    i++;
                }
                else break;
            }

        }
        else {
            time += tc ;
            curr.burst_Time -= tc ;

            while (i < n) {
                if (processes[i].arrival_Time <= time) {
                    q.push(processes[i]) ;
                    i++;
                }
                else break;
            }

            q.push(curr) ;
        }
    }


    float Average_WT = 0;
    float Average_TAT = 0 ;

    for (int i = 0 ; i < n ; i++) {
        copy[i].turn_Around_Time = copy[i].completion_Time - copy[i].arrival_Time ;

        copy[i].waiting_Time = copy[i].turn_Around_Time - copy[i].burst_Time ;

        Average_WT += copy[i].waiting_Time;
        Average_TAT += copy[i].turn_Around_Time ;
    }


    cout << "\n\nGantt Chart : ";
    for (int i = 0 ; i < Gantt_Chart.size(); i++) {
        cout << "P" << Gantt_Chart[i] << " ";
    }


    cout << "\n\nid  AT  BT  CT  WT TAT" << endl;

    for (int i = 0 ; i < n ; i++) {
        cout << "P" << copy[i].process_Number + 1 << "\t";
        cout << copy[i].arrival_Time << "\t";
        cout << copy[i].burst_Time << "\t";
        cout << copy[i].completion_Time << "\t";
        cout << copy[i].waiting_Time << "\t";
        cout << copy[i].turn_Around_Time << "\t";
        cout << endl;
    }

    cout << "\nAverage waiting time is : " << Average_WT / n << endl;
    cout << "Average turn around time is : " << Average_TAT / n << endl;

}


struct compare {
    bool operator()(const node &p1, const node &p2) const {
        if (p1.priority == p2.priority)
            return p1.process_Number < p2.process_Number;
        return p1.priority > p2.priority ;
    }
};
void priority_scheduling_NP() {

    cout << "\nEnter number of processes  : ";
    int n;
    cin >> n ;

    vector<node> processes(n);

    cout << "\nEnter priorities  : \n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].priority ;
    }

    cout << "\nEnter arrival_Time  : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].arrival_Time ;
        processes[i].process_Number = i ;
    }

    cout << "\nEnter burst_Time  : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].burst_Time ;
    }

    vector<node> copy = processes ;

    sort(processes.begin() , processes.end() , [](node a , node b) {
        if (a.arrival_Time == b.arrival_Time)
            return a.priority > b.priority;
        return a.arrival_Time < b.arrival_Time ;
    });

    set<node, compare> pq ;

    pq.insert(processes[0]);
    vector<int> Gantt_Chart ;

    int i = 1 ;

    int time = processes[0].arrival_Time ;

    while ( i < n || (pq.size() != 0)) {

        if (pq.size() == 0) {
            time++;

            while (i < n) {
                if (processes[i].arrival_Time <= time) {
                    pq.insert(processes[i]) ;
                    i++;
                }
                else break;
            }

            continue ;
        }

        node curr = *pq.begin() ;
        pq.erase(pq.begin()) ;

        Gantt_Chart.push_back(curr.process_Number + 1) ;


        time += curr.burst_Time ;

        copy[curr.process_Number].completion_Time = time ;

        while (i < n) {
            if (processes[i].arrival_Time <= time) {
                pq.insert(processes[i]) ;
                i++;
            }
            else break;
        }
    }

    float Average_WT = 0;
    float Average_TAT = 0 ;

    for (int i = 0 ; i < n ; i++) {
        copy[i].turn_Around_Time = copy[i].completion_Time - copy[i].arrival_Time ;

        copy[i].waiting_Time = copy[i].turn_Around_Time - copy[i].burst_Time ;

        Average_WT += copy[i].waiting_Time;
        Average_TAT += copy[i].turn_Around_Time ;
    }


    cout << "\n\nGantt Chart : ";
    for (int i = 0 ; i < Gantt_Chart.size(); i++) {
        cout << "P" << Gantt_Chart[i] << " ";
    }


    cout << "\n\nid  AT  BT  CT  WT TAT" << endl;

    for (int i = 0 ; i < n ; i++) {
        cout << "P" << copy[i].process_Number + 1 << "\t";
        cout << copy[i].arrival_Time << "\t";
        cout << copy[i].burst_Time << "\t";
        cout << copy[i].completion_Time << "\t";
        cout << copy[i].waiting_Time << "\t";
        cout << copy[i].turn_Around_Time << "\t";
        cout << endl;
    }

    cout << "\nAverage waiting time is : " << Average_WT / n << endl;
    cout << "Average turn around time is : " << Average_TAT / n << endl;
}


void priority_scheduling_Premtive() {

    cout << "\nEnter number of processes : ";
    int n;
    cin >> n ;

    vector<node> processes(n);

    cout << "\nEnter priorities : \n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].priority ;
    }

    cout << "\nEnter arrival_Time : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].arrival_Time ;
        processes[i].process_Number = i ;
    }

    cout << "\nEnter burst_Time : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].burst_Time ;
    }

    vector<node> copy = processes ;

    sort(processes.begin() , processes.end() , [](node a , node b) {
        if (a.arrival_Time == b.arrival_Time)
            return a.priority > b.priority;
        return a.arrival_Time < b.arrival_Time ;
    });

    set<node, compare> pq ;

    pq.insert(processes[0]);

    vector<int> Gantt_Chart ;

    int i = 1 ;

    int time = processes[0].arrival_Time ;

    while ( i < n || (pq.size() != 0)) {

        if (pq.size() == 0) {
            time++;

            while (i < n) {
                if (processes[i].arrival_Time <= time) {
                    pq.insert(processes[i]) ;
                    i++;
                }
                else break;
            }

            continue ;
        }

        node curr = *pq.begin() ;
        pq.erase(pq.begin()) ;

        Gantt_Chart.push_back(curr.process_Number + 1) ;

        bool inserted = false ;

        while (!inserted) {
            time++;
            curr.burst_Time--;
            if (curr.burst_Time == 0) {
                copy[curr.process_Number].completion_Time = time ;

                while (i < n) {
                    if (processes[i].arrival_Time <= time) {
                        pq.insert(processes[i]) ;
                        i++;
                        inserted = true ;
                    }
                    else break;
                }
                break;
            }
            else {
                while (i < n) {
                    if (processes[i].arrival_Time <= time) {
                        pq.insert(processes[i]) ;
                        pq.insert(curr) ;
                        i++;
                        inserted = true ;
                    }
                    else break;
                }
            }
        }
    }

    float Average_WT = 0;
    float Average_TAT = 0 ;

    for (int i = 0 ; i < n ; i++) {
        copy[i].turn_Around_Time = copy[i].completion_Time - copy[i].arrival_Time ;

        copy[i].waiting_Time = copy[i].turn_Around_Time - copy[i].burst_Time ;

        Average_WT += copy[i].waiting_Time;
        Average_TAT += copy[i].turn_Around_Time ;
    }


    cout << "\n\nGantt Chart : ";
    for (int i = 0 ; i < Gantt_Chart.size(); i++) {
        cout << "P" << Gantt_Chart[i] << " ";
    }


    cout << "\n\nid  AT  BT  CT  WT TAT" << endl;

    for (int i = 0 ; i < n ; i++) {
        cout << "P" << copy[i].process_Number + 1 << "\t";
        cout << copy[i].arrival_Time << "\t";
        cout << copy[i].burst_Time << "\t";
        cout << copy[i].completion_Time << "\t";
        cout << copy[i].waiting_Time << "\t";
        cout << copy[i].turn_Around_Time << "\t";
        cout << endl;
    }

    cout << "\nAverage waiting time is : " << Average_WT / n << endl;
    cout << "Average turn around time is : " << Average_TAT / n << endl;
}


struct compare2 {
    bool operator()(const node &p1, const node &p2) const {
        if (p1.burst_Time == p2.burst_Time)
            return p1.process_Number < p2.process_Number;
        return p1.burst_Time < p2.burst_Time ;
    }
};
void shortest_job_first_NP() {

    cout << "\nEnter number of processes : ";
    int n;
    cin >> n ;

    vector<node> processes(n);

    cout << "\nEnter arrival_Time : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].arrival_Time ;
        processes[i].process_Number = i ;
    }

    cout << "\nEnter burst_Time : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].burst_Time ;
    }

    vector<node> copy = processes ;

    sort(processes.begin() , processes.end() , [](node a , node b) {
        if (a.arrival_Time == b.arrival_Time)
            return a.burst_Time < b.burst_Time;
        return a.arrival_Time < b.arrival_Time ;
    });

    set<node, compare2> pq ;

    pq.insert(processes[0]);

    vector<int> Gantt_Chart ;

    int i = 1 ;

    int time = processes[0].arrival_Time ;

    while ( i < n || (pq.size() != 0)) {
        cout << time << " ";
        if (pq.size() == 0) {
            time++;

            while (i < n) {
                if (processes[i].arrival_Time <= time) {
                    pq.insert(processes[i]) ;
                    i++;
                }
                else break;
            }

            continue ;
        }

        node curr = *pq.begin() ;
        pq.erase(pq.begin()) ;

        Gantt_Chart.push_back(curr.process_Number + 1) ;


        time += curr.burst_Time ;

        copy[curr.process_Number].completion_Time = time ;

        while (i < n) {
            if (processes[i].arrival_Time <= time) {
                pq.insert(processes[i]) ;
                i++;
            }
            else break;
        }
    }

    float Average_WT = 0;
    float Average_TAT = 0 ;

    for (int i = 0 ; i < n ; i++) {
        copy[i].turn_Around_Time = copy[i].completion_Time - copy[i].arrival_Time ;

        copy[i].waiting_Time = copy[i].turn_Around_Time - copy[i].burst_Time ;

        Average_WT += copy[i].waiting_Time;
        Average_TAT += copy[i].turn_Around_Time ;
    }


    cout << "\n\nGantt Chart : ";
    for (int i = 0 ; i < Gantt_Chart.size(); i++) {
        cout << "P" << Gantt_Chart[i] << " ";
    }


    cout << "\n\nid  AT  BT  CT  WT TAT" << endl;

    for (int i = 0 ; i < n ; i++) {
        cout << "P" << copy[i].process_Number + 1 << "\t";
        cout << copy[i].arrival_Time << "\t";
        cout << copy[i].burst_Time << "\t";
        cout << copy[i].completion_Time << "\t";
        cout << copy[i].waiting_Time << "\t";
        cout << copy[i].turn_Around_Time << "\t";
        cout << endl;
    }

    cout << "\nAverage waiting time is : " << Average_WT / n << endl;
    cout << "Average turn around time is : " << Average_TAT / n << endl;

}


void shortest_job_first_premptive() {

    cout << "\nEnter number of processes :";
    int n;
    cin >> n ;

    vector<node> processes(n);

    cout << "\nEnter arrival_Time : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].arrival_Time ;
        processes[i].process_Number = i ;
    }

    cout << "\nEnter burst_Time : \n";
    for (int i = 0 ; i < n ; i++) {
        cin >> processes[i].burst_Time ;
    }

    vector<node> copy = processes ;

    sort(processes.begin() , processes.end() , [](node a , node b) {
        if (a.arrival_Time == b.arrival_Time)
            return a.burst_Time < b.burst_Time;
        return a.arrival_Time < b.arrival_Time ;
    });

    set<node, compare2> pq ;

    pq.insert(processes[0]);

    vector<int> Gantt_Chart ;

    int i = 1 ;

    int time = processes[0].arrival_Time ;

    while ( i < n || (pq.size() != 0)) {
        cout << time << " ";
        if (pq.size() == 0) {
            time++;

            while (i < n) {
                if (processes[i].arrival_Time <= time) {
                    pq.insert(processes[i]) ;
                    i++;
                }
                else break;
            }

            continue ;
        }

        node curr = *pq.begin() ;
        pq.erase(pq.begin()) ;

        Gantt_Chart.push_back(curr.process_Number + 1) ;

        bool inserted = false ;

        while (!inserted) {
            time++;
            curr.burst_Time--;
            if (curr.burst_Time == 0) {
                copy[curr.process_Number].completion_Time = time ;

                while (i < n) {
                    if (processes[i].arrival_Time <= time) {
                        pq.insert(processes[i]) ;
                        i++;
                        inserted = true ;
                    }
                    else break;
                }
                break;
            }
            else {
                while (i < n) {
                    if (processes[i].arrival_Time <= time) {
                        pq.insert(processes[i]) ;
                        pq.insert(curr) ;
                        i++;
                        inserted = true ;
                    }
                    else break;
                }
            }
        }
    }

    float Average_WT = 0;
    float Average_TAT = 0 ;

    for (int i = 0 ; i < n ; i++) {
        copy[i].turn_Around_Time = copy[i].completion_Time - copy[i].arrival_Time ;

        copy[i].waiting_Time = copy[i].turn_Around_Time - copy[i].burst_Time ;

        Average_WT += copy[i].waiting_Time;
        Average_TAT += copy[i].turn_Around_Time ;
    }


    cout << "\n\nGantt Chart : ";
    for (int i = 0 ; i < Gantt_Chart.size(); i++) {
        cout << "P" << Gantt_Chart[i] << " ";
    }


    cout << "\n\nid  AT  BT  CT  WT TAT" << endl;

    for (int i = 0 ; i < n ; i++) {
        cout << "P" << copy[i].process_Number + 1 << "\t";
        cout << copy[i].arrival_Time << "\t";
        cout << copy[i].burst_Time << "\t";
        cout << copy[i].completion_Time << "\t";
        cout << copy[i].waiting_Time << "\t";
        cout << copy[i].turn_Around_Time << "\t";
        cout << endl;
    }

    cout << "\nAverage waiting time is : " << Average_WT / n << endl;
    cout << "Average turn around time is : " << Average_TAT / n << endl;

}


int main() {

    char c = 'y' ;

    while (c == 'y' || c == 'Y') {
        cout << "\n    ---- CPU SCHEDULING ALGORITHMS ----\n1. FCFS without AT\n2. FCFS with AT\n3. Shortest job first nonPremptive\n4. Shortest job first Premptive\n5. Round Robbin\n6. Priority scheduling nonPremptive\n7. Priority scheduling Premtive\n\n";

        cout << "Choose algorithm : ";
        int choice ; cin >> choice ;

        switch (choice) {
        case 1 :
            FCFSwithoutAT();
            break;
        case 2 :
            FCFSwithAT();
            break;
        case 3 :
            shortest_job_first_NP();
            break;
        case 4 :
            shortest_job_first_premptive();
            break;
        case 5 :
            round_robbin();
            break;
        case 6 :
            priority_scheduling_NP();
            break;
        case 7 :
            priority_scheduling_Premtive();
            break;
        default:
            cout << "\nWrong choice\n";
            break;
        }

        cout << "\nDo you want to continue : ";
        cin >> c ;
    }

    return 0 ;
}
