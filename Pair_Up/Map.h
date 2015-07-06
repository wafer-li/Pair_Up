#ifndef MAP_HEADER_FILE 
#define MAP_HEADER_FILE 

//include parts
#include <deque>


class Map{
private:
	static const int MAX_SIZE = 9;
	std::deque<Piece> maplists[MAX_SIZE];//Use deque instead of list
	//Piece[9][9] piece;	//基于list 这个数据结构LHT你把他解决了
	bool isPass; //当前游戏是否过关
	int passScore;
protected:
public:
	Map();
	~Map();
	
	//initial & fill the map
	void initMap();

	//Swap
	void Swap(Piece & piece1, Piece & piece2);

	//isDeadMap
	bool isDeadMap();

	//isDead
	bool isDead(int x, int y);

	//-----bool isPass-----
	bool getIsPass();
	void setIsPass(int flag);
	//-----int passScore----
	int getPassScore();
	void setPassScore(int score);
};


#endif // !MAP_HEADER_FILE 
