class Map{
private:
	Piece[9][9] piece;	//基于list 这个数据结构LHT你把他解决了
	bool isPass; //当前游戏是否过关
	bool isDeadMap;
	int passScore;
protected:
public:
	Map() :piece{};
	//-----bool isPass-----
	getIsPass();
	setIsPass();
	//-----int passScore----
	getPassScore();
	setPassScore();

	fillMap();
};


