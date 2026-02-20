
/*
Dependency Inversion Principle (DIP)
Definition

High-level modules should not depend on low-level modules.
Both should depend on abstraction.

AND

Abstractions should not depend on details.
Details should depend on abstractions.

Problems:
Tight coupling
Cannot change service easily
Hard to extend
Difficult to test
If tomorrow:
WhatsAppService
PushNotificationService
You must modify Notification class 
 Violates DIP

 Now (Correct Design):
We introduced abstraction:
MessageService
*/

#include<iostream>
using namespace std;

// ---------------- Abstraction ----------------

class MessageService
{
public:
    virtual void sendMessage() = 0;
    virtual ~MessageService() {}
};

// ---------------- Low Level Modules ----------------

class EmailService : public MessageService
{
public:
    void sendMessage() override
    {
        cout << "Sending Email Message..." << endl;
    }
};

class SMSService : public MessageService
{
public:
    void sendMessage() override
    {
        cout << "Sending SMS Message..." << endl;
    }
};

// ---------------- High Level Module ----------------

class Notification
{
    MessageService* service;

public:
    Notification(MessageService* s) : service(s) {}

    void notify()
    {
        service->sendMessage();
    }
};

// ---------------- Main Function ----------------

int main()
{
    EmailService email;
    SMSService sms;

    Notification n1(&email);
    Notification n2(&sms);

    n1.notify();
    n2.notify();

    return 0;
}


       


