#include <iostream>
 
using namespace std;
 
class mRND
{
    public:
        void seed(unsigned int s)
        {
            _seed = s;
        }
 
    protected:
        mRND() :
            _seed(0), _a(0), _c(0), _m(2147483648)
        {
        }
        int rnd()
        {
            return (_seed = (_a * _seed + _c) % _m);
        }
 
        int _a, _c;
        unsigned int _m, _seed;
};
 
 
class BSD_RND: public mRND
{
    public:
        BSD_RND()
        {
            _a = 1103515245;
            _c = 12345;
        }
        int rnd()
        {
            return mRND::rnd();
        }
};
 
int main()
{
    BSD_RND bsd_rnd;
 
    cout << "BSD RAND:" << endl << "=========" << endl;
    for (int x = 0; x < 10; x++)
        cout << bsd_rnd.rnd() << endl;
 
    return 0;
}
