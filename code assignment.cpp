#include <iostream>
#include <string>
using namespace std;

class EmployeeDetails {  // SRP
public:
    string name;
    int age;
    string position;

    void printDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Position: " << position << endl;
    }
};

class EmployeeManagement {  // SRP
public:
    void hireEmployee(EmployeeDetails& Emp) {
        cout << "Hiring employee: " << Emp.name << endl;
    }

    void fireEmployee(EmployeeDetails& Emp) {
        cout << "Firing employee: " << Emp.name << endl;
    }
};

class Manager : public EmployeeDetails {
public:
    int teamSize;

    void manageTeam() {
        cout << "Managing a team of size: " << teamSize << endl;
    }

    void addTeamMember() {
        cout << "Adding team member" << endl;
    }

    void removeTeamMember() {
        cout << "Removing team member" << endl;
    }

    void scheduleMeeting() {
        cout << "Scheduling a meeting" << endl;
    }

    void reviewPerformance() {
        cout << "Reviewing performance" << endl;
    }
};

class Report {   // OCP
public:
    virtual void generateReport() = 0;
    virtual ~Report() {}
};

class PDFReport : public Report {   // OCP
public:
    void generateReport() override {
        cout << "Generating PDF report with special format" << endl;
    }
};

class WordReport : public Report {    // LSP
public:
    void generateReport() override {
        cout << "Generating Word report" << endl;
    }
};

class PayrollSystem {  // SRP
public:
    void calculatePay(EmployeeDetails& Emp) {
        cout << "Calculating pay for: " << Emp.name << endl;
    }

    void processPayroll() {
        cout << "Processing payroll" << endl;
    }

    void generatePayslip() {
        cout << "Generating payslip" << endl;
    }

    void sendPayslip() {
        cout << "Sending payslip" << endl;
    }

    void handleEmployeeBenefits() {
        cout << "Handling employee benefits" << endl;
    }

    void handleEmployeeTaxes() {
        cout << "Handling employee taxes" << endl;
    }
};

class ILogger {  // ISP
public:
    virtual void log(string message) = 0;
    virtual ~ILogger() {}
};

class ErrorLogger : public ILogger {
public:
    void log(string message) override {
        cout << "Logging error: " << message << endl;
    }
};

class DebugLogger : public ILogger {
public:
    void log(string message) override {
        cout << "Logging debug: " << message << endl;
    }
};

class WarnLogger : public ILogger {
public:
    void log(string message) override {
        cout << "Logging warning: " << message << endl;
    }
};

class InfoLogger : public ILogger {
public:
    void log(string message) override {
        cout << "Logging info: " << message << endl;
    }
};

class TraceLogger : public ILogger {
public:
    void log(string message) override {
        cout << "Logging trace: " << message << endl;
    }
};

int main() {
    // Creating an employee
    EmployeeDetails emp;
    emp.name = "Rawan Yasser";
    emp.age = 20;
    emp.position = "Developer";
    emp.printDetails();

    // Managing employee (hiring and firing)
    EmployeeManagement empMgr;
    empMgr.hireEmployee(emp);
    //empMgr.fireEmployee(emp);

    // Manager actions
    Manager mgr;
    mgr.name = "Mohamed Yasser";
    mgr.age = 25;
    mgr.position = "Team Lead";
    mgr.teamSize = 10;
    mgr.printDetails();
    mgr.manageTeam();
   // mgr.addTeamMember();
   // mgr.scheduleMeeting();
    mgr.reviewPerformance();

    // Payroll actions
    PayrollSystem payroll;
    payroll.calculatePay(emp);
    payroll.processPayroll();

    // Generating reports
    PDFReport pdfReport;
    pdfReport.generateReport();

    WordReport wordReport;
    wordReport.generateReport();

    // Logging
    DebugLogger debugLogger;
    ErrorLogger errorLogger;
  //  WarnLogger warnLogger;
   // InfoLogger infoLogger;
   // TraceLogger traceLogger;

    debugLogger.log("This is a debug message.");
    errorLogger.log("This is an error message.");
  //  warnLogger.log("This is a warning message.");
  // infoLogger.log("This is an info message.");
  //  traceLogger.log("This is a trace message.");

    return 0;
}
