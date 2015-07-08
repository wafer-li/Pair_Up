#ifndef MAP_HEADER_FILE 
#define MAP_HEADER_FILE 

//include parts
#include <deque>
#include "Piece.h"

class Map{
private:
	static const int MAX_SIZE = 9;
	std::deque<Piece> maplists[MAX_SIZE];//Use deque instead of list
	bool isPass; //当前游戏是否过关
	int passScore;
protected:
public:
	Map();
	~Map();

	//initial & fill the map
	void initMap();

	//Swap
	void Swap(int x1, int y1, int x2, int y2);

	//isDeadMap
	bool isDeadMap();
	
	//another way to judge the DeadMap
	bool isDeadMap_();

	//isDead
	bool isDead(int x, int y);

	//isPieceClearale
	//NOTICE:
	//Only judge the single piece
	//Do NOT change the Piece.isClear
	bool isPieceClearable(int x, int y);

	//-----bool isPass-----
	bool getIsPass();
	void setIsPass(int flag);
	//-----int passScore----
	int getPassScore();
	void setPassScore(int score);

	//Maplists
	std::deque<Piece> * getMaplists();
};


#endif // !MAP_HEADER_FILE 