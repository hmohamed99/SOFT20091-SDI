#ifndef SOURCE_2
#define SOURCE_2
#endif // !SOURCE_2


/**  
 *A very basic header class to test header importing/inheritance
 */

/*inline*/ class TestClass 
{
public:
	uint64_t x;
	//long y;
	TestClass(uint64_t a);
	/*{
		x = a;
		dbl(a);
		mult(a);
		pwr(a);
	}*/

	int /*TestClass::*/dbl(uint64_t a)/** Doubles provided Values **/
	{
		return /*aa*/x * 2;
	}
	int mult(uint64_t a)
	{
		return a * x;
	}
	int pwr(uint64_t b)
	{
		//long aa = (long)a;
		return std::pow(x, b);//x^aaaa;
	}
	~TestClass()
	{
		//delete& x;
	}
};

TestClass::TestClass(uint64_t a)
	{
		/*long*/ x = a;
		//y;
		//y = (long)a;
		/*TestClass::*/dbl(a);
		mult(a);
		pwr(a);
	}
//TestClass::~TestClass()
//{
//
//}