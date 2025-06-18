#include<iostream>
using namespace std;

class Task {
private:
    string title;
    string deadline;
    int priority;
    int track_process;

public:
    Task() {}

    Task(string t, string d, int p, int tp) {
        title = t;
        deadline = d;
        priority = p;
        track_process = tp;
    }

    void process() {
        if (track_process > 0)
            cout << "Status: Completed\n";
        else if (track_process < 0)
            cout << "Status: Pending\n";
        else
            cout << "Status: Under process\n";
    }

    void display() {
        cout << "Title: " << title << "\n";
        cout << "Deadline: " << deadline << "\n";
        cout << "Priority: " << priority << "\n";
        process();
        cout << "-----------------------\n";
    }

    void fun(string t, string d, int p, int tp) {
        title = t;
        deadline = d;
        priority = p;
        track_process = tp;
    }
};

class User {
private:
    string name;

public:
    User(string n) {
        name = n;
    }

    void showName() {
        cout << "\nWelcome, " << name << "!\n";
        cout << "=======================\n";
    }
};

class TaskList {
private:
    Task task[100];
    int count = 0;

public:
    void add(Task t) {
        if (count < 100) {
            task[count++] = t;
        } else {
            cout << "Task list full!\n";
        }
    }

    void showTask() {
        for (int i = 0; i < count; i++) {
            cout << "Task " << i + 1 << ":\n";
            task[i].display();
        }
    }

    void fung(int x, string Title, string Deadline, int Priority, int Track) {
        if (x >= 0 && x < count) {
            task[x].fun(Title, Deadline, Priority, Track);
            cout << "Task updated successfully\n";
        } else {
            cout << "Invalid task index\n";
        }
    }

    void del(int x) {
        if (x >= 0 && x < count) {
            for (int i = x; i < count - 1; i++) {
                task[i] = task[i + 1];
            }
            count--;
            cout << "Task deleted successfully\n";
        } else {
            cout << "Invalid task index\n";
        }
    }

    int getCount() {
        return count;
    }
};

int main() {
    string name;
    cout << "Enter the Name: ";
    cin >> name;

    User obj(name);
    obj.showName();

    TaskList obj2;

    int total;
    cout << "How many tasks? ";
    cin >> total;

    for (int i = 0; i < total; i++) {
        string title, deadline;
        int priority, track;

        cout << "\nEnter details for Task " << i + 1 << ":\n";
        cout << "Title: ";
        cin >> title;
        cout << "Deadline: ";
        cin >> deadline;
        cout << "Priority (1-5): ";
        cin >> priority;
        cout << "Track Process (-1=Pending, 0=Under Process, 1=Completed): ";
        cin >> track;

        Task t(title, deadline, priority, track);
        obj2.add(t);
    }

    cout << "\nAll Tasks:\n";
    obj2.showTask();

    int choice;
    while (true) {
        cout << "\nOptions:\n1. Edit Task\n2. Delete Task\n3. Show Tasks\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            if (obj2.getCount() == 0) {
                cout << "No tasks to edit\n";
                continue;
            }
            int index;
            string Title, Deadline;
            int Priority, Track;

            cout << "Enter task index to edit: ";
            cin >> index;

            cout << "New Title: ";
            cin >>  Title;
            cout << "New Deadline: ";
            cin >> Deadline;
            cout << "New Priority (1-5): ";
            cin >> Priority;
            cout << "New Track Process (-1=Pending, 0=Under Process, 1=Completed): ";
            cin >> Track;

            obj2.fung(index - 1, Title, Deadline, Priority, Track);

        } else if (choice == 2) {
            if (obj2.getCount() == 0) {
                cout << "No tasks to delete\n";
            }
            int index;
            cout << "Enter task index to delete: ";
            cin >> index;
            obj2.del(index - 1);

        } else if (choice == 3) {
            cout << "\nCurrent Task List:\n";
            obj2.showTask();

        } else if (choice == 4) {
            cout << ".____.____.Exiting program.___.___.\n";
            break;

        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}