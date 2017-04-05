class line{
private:
	char the_line[100];
	int length;
public:
	line();
	line(char [],int);
	int get_length();
	void print();
	char first();
	char last();
	int count(char);
};
