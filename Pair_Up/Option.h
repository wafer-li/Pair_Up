#ifndef OPTION_H
#define OPTION_H
class Option
{
private:
	int skin;
	int background;
protected:
public:
	/* Ctor & Dtor */
	Option();
	~Option();

	//Skin
	int getSkin(void);
	void setSkin(int);

	//Background
	int getBackground(void);
	void setBackground(int);
};

#endif