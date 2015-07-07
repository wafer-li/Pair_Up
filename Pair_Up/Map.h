#ifndef MAP_HEADER_FILE 
#define MAP_HEADER_FILE 

//include parts
#include <deque>


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
	void Swap(Piece & piece1, Piece & piece2);

	//isDeadMap
	bool isDeadMap();	//The new version is as default
	
	//another way to judge the DeadMap
	bool isDeadMap_();

	//isDead
	bool isDead(int x, int y);

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