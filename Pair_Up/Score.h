#ifndef SCORE_H
#define SCORE_H
class Score
{
private:
	//Score
	static int score;

	//Level
	static int level;

	//PassScore
	int passScore;

	/* Private Method */
	
	//Count the PassScore
	int countPassScore(int level);

	//Set the PassScore
	void setPassScore(int result);

	//Count the additional number
	int countAdditionNum(int level);

public:
	/* Ctor & Dtor */
	Score();
	~Score();

	/* Method */
	
	//Score
	int getScore();
	void changeScore(int num, int com);

	//PassScore
	int getPassScore();

	//Level
	int getLevel();

	//isLevelUp
	bool levelUp();
};

#endif