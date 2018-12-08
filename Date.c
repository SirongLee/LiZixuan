#include<iostream>
#include<stdio.h>
const static size_t unleap_day_from_mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
const static size_t leap_day_from_mon[]={31,29,31,30,31,30,31,31,30,31,30,31};
class Date
{
private:
    const static size_t year_start=1980,mon_start=1,day_start=1;
    size_t d_from_start,d_from_year_start;
    size_t year,mon,day;
public:
    Date()
    {
        year=1980;
        mon=1;
        day=1;
        d_from_start=0;
        d_from_year_start=0;
    }
    Date(const Date &oth)
    {
        this->d_from_start=oth.d_from_start;
        this->d_from_year_start=oth.d_from_year_start;
        this->year=oth.year;
        this->mon=oth.mon;
        this->day=oth.day;
    }
    Date(size_t lenth)
    {
        d_from_start=lenth;
        if(lenth<0)
            lenth=0;
        size_t day400=365*400+97;
        year=1980;
        if(lenth/day400>0)
            year+=lenth/day400*400;
        int loss=lenth%day400;
        while(1)
        {
            bool leap=year%400==0||year%100&&year%4==0;
            if(loss<365+leap)
                break;
            loss-=365+leap;
            year++;
        }
        mon=0;
        for(int i=0;i<12;i++)
        {
            bool leap=year%400==0||year%100&&year%4==0;
            if(leap)
            {
                if(loss<leap_day_from_mon[i])
                {
                    day=loss;
                    break;
                }
                loss-=leap_day_from_mon[i];
                mon++;
            }
            else
            {
                if(loss<unleap_day_from_mon[i])
                {
                    day=loss;
                    break;
                }
                loss-=unleap_day_from_mon[i];
                mon++;
            }
        }
        mon++;
        day++;
        d_from_year_start=0;
        bool leap=year%400==0||year%100&&year%4==0;
        for(size_t i=0;i<mon;i++)
            if(leap)
                d_from_year_start+=leap_day_from_mon[i];
            else
                d_from_year_start+=unleap_day_from_mon[i];
        d_from_year_start+=day-1;
    }
    Date(size_t year,size_t mon,size_t day)
    {
        if(year<1980)
            year=1980;
        this->year=year;
        if(mon<1||mon>12)
            mon=1;
        this->mon=mon;
        bool leap=year%400==0||year%100&&year%4==0;
        if(leap)
        {
            if(day<1||day>leap_day_from_mon[mon-1])
                day=1;
        }
        else
        {
            if(day<1||day>unleap_day_from_mon[mon-1])
                day=1;
        }
        this->day=day;
        d_from_year_start=0;
        for(size_t i=0;i<mon-1;i++)
            if(leap)
                d_from_year_start+=leap_day_from_mon[i];
            else
                d_from_year_start+=unleap_day_from_mon[i];
        d_from_year_start+=day-1;
        size_t i=1980/400+1980/4-1980/100;
        size_t j=year/400+year/4-year/100;
        d_from_start=(year-1980)*365+j-i+d_from_year_start;
    }
    ~Date(){}
    bool is_leap_year()
    {
        return year%400==0||year%100&&year%4==0;
    }
    void print()
    {
        std::cout<<"year:"<<this->year<<" month:"<<this->mon<<" day:"<<this->day<<std::endl;
    }
    bool is_period(const Date &a,const Date &b)
    {
        return a<=*this&&*this<=b;
    }
    friend bool operator<(const Date &a,const Date &b)
    {
        if(a.year<b.year)
            return true;
        else if(a.year>b.year)
            return false;
        if(a.mon<b.mon)
            return true;
        else if(a.mon>b.mon)
            return false;
        if(a.day<b.day)
            return true;
        return false;
    }
    friend bool operator<=(const Date &a,const Date &b)
    {
        if(a.year<=b.year)
            return true;
        else if(a.year>b.year)
            return false;
        if(a.mon<=b.mon)
            return true;
        else if(a.mon>b.mon)
            return false;
        if(a.day<=b.day)
            return true;
        return false;
    }
    size_t get_day_from_year_start()
    {
        return d_from_year_start;
    }
    size_t get_dat_from_start()
    {
        return d_from_start;
    }
    Date operator+(const int & add_day)
    {
        Date re(d_from_year_start+add_day);
        return re;
    }
    friend int operator-(const Date& a,const Date& b)
    {
        int ans=a.d_from_start-b.d_from_start;
        std::cout << a.d_from_start << " " << b.d_from_start <<std::endl;
        if(ans<0)
            ans=-ans;
        return ans;
    }
    operator int()
    {
        return d_from_start;
    }
    size_t get_year()
    {
        return year;
    }
    size_t get_month()
    {
        return mon;
    }
    size_t get_day()
    {
        return day;
    }
    void set_year(size_t year)
    {
        Date ans(year,this->mon,this->day);
        this->d_from_start=ans.d_from_start;
        this->d_from_year_start=ans.d_from_year_start;
        this->year=ans.year;
        this->mon=ans.mon;
        this->day=ans.day;
    }
    void set_month(size_t mon)
    {
        Date ans(this->year,mon,this->day);
        this->d_from_start=ans.d_from_start;
        this->d_from_year_start=ans.d_from_year_start;
        this->year=ans.year;
        this->mon=ans.mon;
        this->day=ans.day;
    }
    void set_day(size_t day)
    {
        Date ans(this->year,this->mon,day);
        ans.print();
        this->d_from_start=ans.d_from_start;
        this->d_from_year_start=ans.d_from_year_start;
        this->year=ans.year;
        this->mon=ans.mon;
        this->day=ans.day;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
