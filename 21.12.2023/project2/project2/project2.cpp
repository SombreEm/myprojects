#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <Windows.h>

using namespace std;

class Task {
public:
    string description;
    bool completed;
    time_t deadline;

    Task(const string& desc, time_t deadline)
        : description(desc), completed(false), deadline(deadline) {}

    void markAsCompleted() {
        completed = true;
    }
};

class Project {
public:
    string name;
    string description;
    time_t startDate;
    time_t endDate;
    vector<Task> tasks;

    Project(const string& projectName, const string& projectDesc,
        time_t start, time_t end)
        : name(projectName), description(projectDesc), startDate(start), endDate(end) {}

    void addTask(const string& taskDesc, time_t deadline) {
        tasks.emplace_back(taskDesc, deadline);
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex);
        }
    }

    void setProjectStatus() {
      
    }
};

class ProjectManager {
public:
    vector<Project> projects;

    void createProject(const string& projectName, const string& projectDesc,
        time_t start, time_t end) {
        projects.emplace_back(projectName, projectDesc, start, end);
    }

    void addTaskToProject(int projectIndex, const string& taskDesc, time_t deadline) {
        if (projectIndex >= 0 && projectIndex < projects.size()) {
            projects[projectIndex].addTask(taskDesc, deadline);
        }
    }

    void removeTaskFromProject(int projectIndex, int taskIndex) {
        if (projectIndex >= 0 && projectIndex < projects.size()) {
            projects[projectIndex].removeTask(taskIndex);
        }
    }

    void trackProjects() {
        for (auto& project : projects) {
            project.setProjectStatus();
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ProjectManager projectManager;

    int choice;
    do {
        cout << "1. �������� ������\n"
            << "2. ������ �������� �� �������\n"
            << "3. �������� �������� � �������\n"
            << "4. �������� �������� � �������\n"
            << "0. �����\n"
            << "������ ��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, desc;
            time_t start, end;
            cout << "������ ����� �������: ";
            cin >> name;
            cout << "������ ���� �������: ";
            cin >> desc;
            cout << "������ ���� ������� �������: ";
            cin >> start;
            cout << "������ ���� ���������� �������: ";
            cin >> end;

            projectManager.createProject(name, desc, start, end);
            break;
        }
        case 2: {
            int projectIndex;
            string taskDesc;
            time_t deadline;
            cout << "������ ������ �������, ��� ������ ��������: ";
            cin >> projectIndex;
            cout << "������ ���� ���������� �������: ";
            cin >> taskDesc;
            cout << "������ ����� ��������� ��������: ";
            cin >> deadline;

            projectManager.addTaskToProject(projectIndex, taskDesc, deadline);
            break;
        }
        case 3: {
            int projectIndex, taskIndex;
            cout << "������ ������ �������, ��� �������� ��������: ";
            cin >> projectIndex;
            cout << "������ ������ �������� ��� ���������: ";
            cin >> taskIndex;

            projectManager.removeTaskFromProject(projectIndex, taskIndex);
            break;
        }
        case 4:
            projectManager.trackProjects();
            break;
        case 0:
            cout << "����� � ��������.\n";
            break;
        default:
            cout << "������� ����. ���� ����� ��������� �� ���.\n";
        }

    } while (choice != 0);

    return 0;
}