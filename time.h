/**
* Class Time used for timeout functionality
*
**/
class Time
{ 

    private:
    double start;

	public:
	void tic();
   double toc();

	
};

//Updates private variable start to now
void Time::tic()
{
    start = TimeNow();
}

//Returns time since tic() called;
double Time::toc()
{
    return TimeNow() - start;
}
