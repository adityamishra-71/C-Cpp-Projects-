#include <iostream>
#include <queue>

using namespace std;

void showq(queue<int> mq) {
    queue<int> q = mq;
    cout<<endl;
    while (!q.empty()) {
        cout<<q.front()<<endl;
        q.pop();
    }
}

int main() {
    queue<int> queue1;
    queue1.push(10);
    queue1.push(20);
    queue1.push(30);

    cout<<"The queue is : ";
    showq(queue1);

    queue1.push(40);
    showq(queue1);

    cout<<"\nqueue.size() : "<<queue1.size();
    cout<<"\nqueue.front() : "<<queue1.front();
    cout<<"\nqueue.back() : "<<queue1.back();

    cout<<"\nqueue.pop() : ";
    queue1.pop();
    showq(queue1);
}