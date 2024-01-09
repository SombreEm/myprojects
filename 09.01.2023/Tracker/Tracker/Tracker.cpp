#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <functional>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
using namespace std;

class Expense {
public:
    double sum;
    string description;
    time_t date;

    Expense(double sum, const string& description, time_t date)
        : sum(sum), description(description), date(date) {}
};

class ExpenseTracker {
private:
    vector<Expense> expenses;

public:
    void addExpense(double sum, const string& description, time_t date) {
        expenses.emplace_back(sum, description, date);
    }

    void removeExpense() {
        if (!expenses.empty()) {
            expenses.pop_back();
        }
    }

    double totalExpense() const {
        double total = 0.0;
        for (const auto& expense : expenses) {
            total += expense.sum;
        }
        return total;
    }

    void sortExpenseDate() {
        sort(expenses.begin(), expenses.end(), [](const Expense& a, const Expense& b) {
            return a.date < b.date;
            });
    }

    void ExpensePeriod(time_t startDate, time_t endDate) {
        cout << "Expenses for the period:\n";
        for (const auto& expense : expenses) {
            if (expense.date >= startDate && expense.date <= endDate) {
                time_t dateCopy = expense.date;
                cout << expense.sum << " " << expense.description << " " <<ctime(&dateCopy);
            }
        }
    }

    void filterExpense(function<bool(const Expense&)> predicate) {
        cout << "Filtered Expenses:\n";
        for (const auto& expense : expenses) {
            if (predicate(expense)) {
                time_t dateCopy = expense.date;
                cout << expense.sum << " " << expense.description << " " << ctime(&dateCopy);
            }
        }
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.addExpense(50.0, "Groceries", time(nullptr));
    tracker.addExpense(30.0, "Dinner", time(nullptr));
    tracker.addExpense(100.0, "Shopping", time(nullptr));
    cout << "Total Expense: " << tracker.totalExpense() << "\n";
    tracker.sortExpenseDate();
    time_t startDate = time(nullptr) - 7 * 24 * 60 * 60;
    time_t endDate = time(nullptr);
    tracker.ExpensePeriod(startDate, endDate);
    tracker.filterExpense([](const Expense& expense) {
        return expense.sum > 50.0;
        });
    return 0;
}