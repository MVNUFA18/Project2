/* CapitalGains.cpp
 * Description: Buy and sell shares, reports gain/loss
 * Author: Dante
 * Date: 10/8/2018
 * Data Structures & Algorithms
*/ 

#include "pch.h"
#include "Queue.h" // defines Queue class
#include <iostream>
using namespace std;

#define CAPACITY 1000 //Sets maximum capacity to 1000 shares

int main() {
	Queue<int> myQueue(CAPACITY);
	string buyOrSell, junk = "";
	int numberOfShares, price, temp, total = 0;
	
	while (true) {
		cin >> buyOrSell;
		if (buyOrSell == "gains" || buyOrSell == "Gains") {
			string output = "";
			if (total >= 0) { output = "*** Report gain: $"; }
			else { output = "*** Report loss: $"; }
			cout << output << total << endl;
			total = 0;
		}
		if (buyOrSell == "stop" || buyOrSell == "Stop") {
			break;
		}
		if (buyOrSell == "buy" || buyOrSell == "Buy") {
			cin >> numberOfShares >> junk >> price;
			try {
				temp = myQueue.size();
				for (int i = 0; i < numberOfShares; i++) {
					myQueue.enqueue(price);
				}
			}
			catch(QueueFull e){
				cout << "Error! Attempted to buy " << numberOfShares << " shares, but there was only room for " << (CAPACITY - temp) << " more shares!" << endl;
			}
		}
		if (buyOrSell == "sell" || buyOrSell == "Sell") {
			cin >> numberOfShares >> junk >> price;
			temp = myQueue.size();
			try {
				for (int i = 0; i < numberOfShares; i++) {
					total += (price - myQueue.front());
					myQueue.dequeue();
				}
			}
			catch(QueueEmpty e){
				cout << "Error! Attempted to sell " << numberOfShares << " shares, but only " << temp << " shares were owned!" << endl;
			}
		}
	}
	("pause");
	return 0;
}
