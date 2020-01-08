// **** include files ****
#include <iostream>
#include <thread>


// **** name spaces ****
using namespace std;


//
// This function implements a thread.
//
void threadFunc (
                int &delay,
                int value
                )
{

    // **** ****
    cout << "threadFunc <<< entering\n";

    // **** increase the delay and value ****
    cout << "threadFunc <<< delay: " << delay << " value: " << value << endl;
    delay += 2;
    value += 3;
    cout << "threadFunc <<< delay: " << delay << " value: " << value << endl;

    // **** sleep for a few ****
    this_thread::sleep_for(chrono::seconds(delay));

    // **** ****
    cout << "threadFunc <<< exiting\n";
}


//
// Main entry point.
//
int main()
{

    // **** welcome message ****
    cout << "main <<< Hello!!!\n";

    // **** call the thread function (without / with argument(s)) ****
    //thread t1(threadFunc);
    int delay   = 7;
    int value   = 100;
    //thread t1{ threadFunc, ref(delay) };
    //thread t1(threadFunc, ref(delay), value);

    // **** replace the thread function with a lambda expression ****
    //thread t1{ [](int &delay, int value) {
    //thread t1{ [=]() {
    thread t1{ [&]() {

        // **** increase the delay and value ****
        cout << "lambda <<< delay: " << delay << " value: " << value << endl;
        delay += 2;
        value += 3;
        cout << "lambda <<< delay: " << delay << " value: " << value << endl;

        // **** sleep for a few ****
        this_thread::sleep_for(chrono::seconds(delay));

    //}, ref(delay), value};
    }};

    // **** do some work ****
    cout << "main <<< working ...\n";
    this_thread::sleep_for(chrono::seconds(3));
    cout << "main <<< done working\n";

    // **** wait for the thread to complete ****
    t1.join();

    // **** display the delay ****
    cout << "main <<< delay: " << delay << " value: " << value << endl;

    // **** good bye message ****
    cout << "main <<< Bye-bye!!!\n";

    // **** ****
    return 0;
}
