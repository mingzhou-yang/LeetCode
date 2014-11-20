/*
 * TakeMetro.h
 *
 *  Created on: Oct 28, 2014
 *      Author: frye
 */

#ifndef TAKEMETRO_H_
#define TAKEMETRO_H_

#include "commonHeader.h"

struct tunnel_t{
	int x1;
	int y1;
	int x2;
	int y2;
	int time;
	tunnel_t(): x1(0), y1(0), x2(0), y2(0), time(0){}
	tunnel_t(int x, int y, int xx, int yy, int t): x1(x), y1(y), x2(xx), y2(yy), time(t) {}
	void printTunnel(){
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<time<<endl;
	}
};

struct query_t{
	int x1;
	int y1;
	int x2;
	int y2;
	query_t(): x1(0), y1(0), x2(0), y2(0){}
	query_t(int x, int y, int xx, int yy): x1(x), y1(y), x2(xx), y2(yy){}
	void printQuery(){
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<endl;
	}
};

struct station{
	int x;
	int y;
	int dist;
	station(): x(0), y(0), dist(INT_MAX){}
	station(int xx, int yy): x(xx), y(yy), dist(INT_MAX){}
	station(int xx, int yy, int d): x(xx), y(yy), dist(d){}
};

class mycomparison
{
public:
	mycomparison(){}
	bool operator() (const station& lhs, const station&rhs) const
	{
		return (lhs.dist>rhs.dist);
	}
};

void takeMetro(){
//Read data in
	ifstream input("B-small-practice.in");
	ofstream output("output.txt");
	int testSize;
	input >> testSize;
	for(int i=0;i<testSize;i++){
		output<<"Case #"<<i+1<<":"<<endl;
		int metroNum;
		input >> metroNum;
		int *stationNum = new int[metroNum];
		int *waitTime = new int[metroNum];
		vector<vector<int>> time;
		vector<vector<vector<station>>> adj;

		for(int j=0;j<metroNum;j++){
			input >> stationNum[j] >> waitTime[j];
			vector<int> tempVec;
			vector<station> base;
			vector<vector<station>> row(stationNum[j], base);
			for(int k=0;k<stationNum[j]-1;k++) {
				int tempTime;
				input >> tempTime;
				tempVec.push_back(tempTime);
			}
			time.push_back(tempVec);
			adj.push_back(row);
		}
		int tunnelNum;
		input >> tunnelNum;
		tunnel_t *tunnel = new tunnel_t[tunnelNum];

		for(int j=0;j<tunnelNum;j++){
			int x, y, xx, yy, t;
			input >> x >> y >> xx >> yy >> t;
			tunnel[j] = tunnel_t(x, y, xx, yy, t);
			station d1 = station(x,y,t+waitTime[x-1]);
			adj[xx-1][yy-1].push_back(d1);
			station d2 = station(xx,yy,t+waitTime[xx-1]);
			adj[x-1][y-1].push_back(d2);
//			cout<<d1.dist<<" "<<d2.dist<<endl;
		}
		int queryNum;
		input >> queryNum;
		query_t *query = new query_t[queryNum];
		for(int j=0;j<queryNum;j++){
			int x, y, xx, yy;
			input >> x >> y >> xx >> yy;
			query[j] = query_t(x, y, xx, yy);
		}
/*		for(int j=0;j<metroNum;j++)
			for(int k=0;k<stationNum[j];k++)
				for(int n=0;n<adj[j][k].size();n++)
					cout<<j+1<<" "<<k+1<<" "<<adj[j][k][n].x<<" "<<adj[j][k][n].y<<" "<<adj[j][k][n].dist<<endl;*/
//		printVecVector(adj);

//Dijkstra
		for(int j=0;j<queryNum;j++){
			priority_queue<station, vector<station>, mycomparison> dist_heap;
			vector<vector<int>> dist;
			for(int k=0;k<metroNum;k++){
				vector<int> row(stationNum[k], INT_MAX);
				dist.push_back(row);
			}
			station begin = station(query[j].x1, query[j].y1, waitTime[query[j].x1-1]);
			dist_heap.push(begin);
			bool flag = false;
			while(!dist_heap.empty()){
				station current = dist_heap.top();
				int x = current.x;
				int y = current.y;
				dist_heap.pop();
				if (x==query[j].x2 && y==query[j].y2){
					output<<current.dist<<endl;
					flag = true;
					break;
				}
				if (current.dist < dist[x-1][y-1]){
					dist[x-1][y-1] = current.dist;
					if (y>1 && time[x-1][y-2]+current.dist < dist[x-1][y-2]){
						station temp = station(x, y-1, time[x-1][y-2]+current.dist);
						dist_heap.push(temp);
					}
					if (y<stationNum[x-1] && time[x-1][y-1]+current.dist < dist[x-1][y]){
						station temp = station(x, y+1, time[x-1][y-1]+current.dist);
						dist_heap.push(temp);
					}
					for(int k=0;k<adj[x-1][y-1].size();k++){
						int xx = adj[x-1][y-1][k].x;
						int yy = adj[x-1][y-1][k].y;
						if (dist[x-1][y-1]+adj[x-1][y-1][k].dist < dist[xx-1][yy-1]){
							station temp = station(xx, yy, dist[x-1][y-1]+adj[x-1][y-1][k].dist);
							dist_heap.push(temp);
						}
					}
				}
			}
			if (!flag) output << -1 <<endl;
		}
	}
	input.close();
}


#endif /* TAKEMETRO_H_ */
