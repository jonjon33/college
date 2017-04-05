class fraction{
public:
	int numerator;
	int denominator;
	fraction();
	fraction(int,int);
	int getNum();
	int getDen();
	void setNum(int);
	void setDen(int);
	bool equals(fraction);
	fraction add(fraction);
	void reduce();
};
