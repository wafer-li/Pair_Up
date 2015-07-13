#ifndef OPTION_H
#define OPTION_H
class Option
{
private:
	int skin;
	int background;
protected:
public:
	Option();
	~Option();
	int getSkin(void);
	int getBackground(void);
	void setSkin(int);
	void setBackground(int);
};

#endif