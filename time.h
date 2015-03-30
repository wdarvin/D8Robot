
class Time
{ 

    private:
    double start;

	public:
	void tic();
    double toc();

	
};
	
void Time::tic()
{
    start = TimeNow();
}

double Time::toc()
{
    return TimeNow() - start;
}
