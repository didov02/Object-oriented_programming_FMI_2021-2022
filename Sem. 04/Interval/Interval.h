class Interval
{
	int a;
	int b;
public:
	Interval();
	Interval(int, int);
	
	//Accessors
	int getA() const;
	int getB() const;
        
	//Mutators
	void setA(int);
	void setB(int);

	size_t getLength() const;
	bool isMemberOfInterval(int) const;

	size_t calcPrimeNumbersInTheInterval() const;
	size_t calcPalindromicNumbersInTheInterval() const;
	size_t calcDiffrentDigitNumbersInTheInverval() const;
	
	bool areStartAndEndPowersOfTwo() const;
	
	Interval intersect(const Interval&) const;
	
	bool isSuperInterval(const Interval&) const;
private:
	size_t countNumbersInIntervalCondition(bool(*pred)(int)) const;
};
