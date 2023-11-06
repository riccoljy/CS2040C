#include "customer.h"
#include "heap.h"
#include <iostream>
using namespace std;
int comparisonWay = 0; // 0 for arrival time, 1 for processing time


bool Customer::operator>(const Customer& c) {
	return comparisonWay ? processing_time < c.processing_time : arrival_time < c.arrival_time; // a customer is "greater" if his time is shorter
};


void customerQueueTest(int n_cust) {
	int current_time = 0;
	int totalWaitingTime = 0;
	int i;
	//int WT = 0; // waiting time for each customer
	int available_time = 0;
	bool counter_avail = true;

	Heap<Customer> queue;

	Customer* custList = new Customer[n_cust];
	cout << endl << endl << "Setup" << endl;
	cout << "List of customers and their arrival and processing times" << endl;
	for (i = 0; i<n_cust; i++)
	{
		custList[i].setAT(i);
		custList[i].setPT((n_cust - i) % (n_cust / 2) + 1 + (i % 2)*(n_cust / 2));
		cout << "Customer " << i << " will arrive at time " << custList[i].AT() << " with PT=" << custList[i].PT() << endl;
	}
	cout << endl;


	for (int round = 0; round<2; round++) {
		// you may need a big modification within this for-loop
		cout << endl << endl;
		cout << "Test Round " << round + 1 << endl;
		cout << (round == 0 ? "First come first serve" : "Customer with the least PT served first") << endl;
		comparisonWay = round;
		current_time = 0;
		totalWaitingTime = 0;
		available_time = 0;
		Customer c;

		for (i = 0; i < n_cust; i++) {
			current_time = min(custList[i].AT(), available_time);

			//if ((current_time == available_time) && !queue.empty()) {
			//	counter_avail = true;
			//	c = queue.extractMax();
			//	i--;
			//}
			//else {
			//	c = custList[i];
			//	cout << "Customer arrives at time " << c.AT() << " with PT=" << c.PT() << endl;
			//}

			if (current_time == available_time) {
				counter_avail = true;
				if (!queue.empty()) {
					c = queue.extractMax();
					i--;
				}
				else {
					c = custList[i];
					cout << "Customer arrives at time " << c.AT() << " with PT=" << c.PT() << endl;
				}
			}
			else {
				c = custList[i];
				cout << "Customer arrives at time " << c.AT() << " with PT=" << c.PT() << endl;
			}
			
			//SERVE CUSTOMER PART
			if (!counter_avail) {
				queue.insert(c);
				continue; // to bring in next customer
			}

			//else (counter is available)
			if (c.AT() == available_time) cout << "Customer arrives when no one is waiting" << endl;

			counter_avail = false; //i close down the counter to server current customer
			available_time += c.PT();
			cout << "Customer is served at time " << current_time << " with AT=" << c.AT() << " and PT=" << c.PT() << " after waiting for " << (current_time - c.AT()) << " min." << endl;
			totalWaitingTime += (current_time - c.AT());
			//END OF SERVE CUSTOMER
		}

		while (!queue.empty()) {
			// you should change all of the code here inside
			current_time = available_time;
			Customer c = queue.extractMax();

			available_time += c.PT();
			cout << "Customer is served at time " << current_time << " with AT=" << c.AT() << " and PT=" << c.PT() << " after waiting for " << (current_time - c.AT()) << " min." << endl;
			totalWaitingTime += (current_time - c.AT());
		}
		cout << "Total Waiting Time: " << totalWaitingTime << endl;
		cout << "Average Waiting Time: " << totalWaitingTime / (float)n_cust << endl;

	}


	delete[] custList;
}
