#include <bits/stdc++.h>
using namespace std;

class Scheduler {
public:
    virtual void schedule() = 0;
};

class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;

public:
    Process(int id, int at, int bt) : pid(id), arrival_time(at), burst_time(bt) {
        start_time = completion_time = turnaround_time = waiting_time = response_time = 0;
    }

    int getPID() const { return pid; }
    int getArrivalTime() const { return arrival_time; }
    int getBurstTime() const { return burst_time; }
    int getStartTime() const { return start_time; }
    int getCompletionTime() const { return completion_time; }
    int getTurnaroundTime() const { return turnaround_time; }
    int getWaitingTime() const { return waiting_time; }
    int getResponseTime() const { return response_time; }

    void setStartTime(int time) { start_time = time; }
    void setCompletionTime(int time) { completion_time = time; }
    void setTurnaroundTime(int time) { turnaround_time = time; }
    void setWaitingTime(int time) { waiting_time = time; }
    void setResponseTime(int time) { response_time = time; }

    bool operator<(const Process& other) const {
        return arrival_time < other.arrival_time;
    }
    
    void display() const {
        cout << pid << "\t" << arrival_time << "\t" << burst_time << "\t" << start_time
             << "\t" << completion_time << "\t" << turnaround_time << "\t" << waiting_time
             << "\t" << response_time << "\n";
    }

    void display(const string& message) const {
        cout << message << "\n";
        display();
    }
};

class RoundRobin : public Scheduler {
private:
    vector<Process> processes;
    int time_quantum;
    vector<int> burst_remaining;
    int total_turnaround_time, total_waiting_time, total_response_time, total_idle_time;

public:
    RoundRobin(vector<Process> proc, int tq) : processes(proc), time_quantum(tq) {
        total_turnaround_time = total_waiting_time = total_response_time = total_idle_time = 0;
        burst_remaining.resize(proc.size());
        for (int i = 0; i < proc.size(); i++) {
            burst_remaining[i] = processes[i].getBurstTime();
        }
    }

    void schedule() override {
        sort(processes.begin(), processes.end());

        queue<int> q;
        int current_time = 0;
        q.push(0);
        vector<int> mark(processes.size(), 0);
        mark[0] = 1;
        int completed = 0;

        while (completed != processes.size()) {
            int idx = q.front();
            q.pop();

            Process &p = processes[idx];

            if (burst_remaining[idx] == p.getBurstTime()) {
                int start_time = max(current_time, p.getArrivalTime());
                total_idle_time += start_time - current_time;
                current_time = start_time;
                processes[idx].setStartTime(start_time);
            }

            if (burst_remaining[idx] > time_quantum) {
                burst_remaining[idx] -= time_quantum;
                current_time += time_quantum;
            } else {
                current_time += burst_remaining[idx];
                burst_remaining[idx] = 0;
                completed++;

                processes[idx].setCompletionTime(current_time);
                processes[idx].setTurnaroundTime(current_time - p.getArrivalTime());
                processes[idx].setWaitingTime(p.getTurnaroundTime() - p.getBurstTime());
                processes[idx].setResponseTime(p.getStartTime() - p.getArrivalTime());

                total_turnaround_time += p.getTurnaroundTime();
                total_waiting_time += p.getWaitingTime();
                total_response_time += p.getResponseTime();
            }

            for (int i = 1; i < processes.size(); i++) {
                if (burst_remaining[i] > 0 && processes[i].getArrivalTime() <= current_time && mark[i] == 0) {
                    q.push(i);
                    mark[i] = 1;
                }
            }

            if (burst_remaining[idx] > 0) {
                q.push(idx);
            }

            if (q.empty()) {
                for (int i = 1; i < processes.size(); i++) {
                    if (burst_remaining[i] > 0) {
                        q.push(i);
                        mark[i] = 1;
                        break;
                    }
                }
            }
        }

        displayResults();
    }

    void displayResults() {
        cout << endl;
        cout << "#P\tAT\tBT\tST\tCT\tTAT\tWT\tRT\t\n" << endl;
        for (const Process &p : processes) {
            p.display();
        }

        float avg_turnaround_time = (float)total_turnaround_time / processes.size();
        float avg_waiting_time = (float)total_waiting_time / processes.size();
        float avg_response_time = (float)total_response_time / processes.size();
        float cpu_utilization = ((processes.back().getCompletionTime() - total_idle_time) /
                                 (float)processes.back().getCompletionTime()) * 100;
        float throughput = float(processes.size()) / (processes.back().getCompletionTime() - processes[0].getArrivalTime());

        cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
        cout << "Average Waiting Time = " << avg_waiting_time << endl;
        cout << "Average Response Time = " << avg_response_time << endl;
        cout << "CPU Utilization = " << cpu_utilization << "%" << endl;
        cout << "Throughput = " << throughput << " process/unit time" << endl;
    }
};

int main() {
    int n, tq;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> tq;

    vector<Process> processes;

    for (int i = 0; i < n; i++) {
        int at, bt;
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> at;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> bt;
        processes.emplace_back(i + 1, at, bt);
        cout << endl;
    }

    RoundRobin rr(processes, tq);
    rr.schedule();

    return 0;
}
