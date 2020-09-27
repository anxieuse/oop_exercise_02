#ifndef TIMEPOINT_HPP
#define TIMEPOINT_HPP

class TimePoint
{
public:
    TimePoint();
    TimePoint(const std::string &_time);
    TimePoint(const int &_val);
    TimePoint operator-(const TimePoint &rhs) const;
    TimePoint operator+(const TimePoint &rhs) const;
    double operator/(const TimePoint &rhs) const;
    void add(const int &_ss);
    void subtract(const int &_ss);
    bool operator>(TimePoint const &rhs) const;
    bool operator==(TimePoint const &rhs) const;
    bool operator<(TimePoint const &rhs) const;
    int toMins() const;
    int toSecs() const;
    std::string getTime() const;
    void display() const;

private:
    std::string time;
    int hh, mm, ss, val;
};

TimePoint::TimePoint() : hh(0), mm(0), ss(-1), val(-1) {}

TimePoint::TimePoint(const std::string &_time)
{
    sscanf(_time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    val = hh * 60 * 60 + mm * 60 + ss;
    char tmp[9];
    snprintf(tmp, 10, "%02d:%02d:%02d", hh, mm, ss);
    time = tmp;
}

void renew(std::string &time, int &hh, int &mm, int &ss, int &val, const int &_val) {
    val = _val;
    hh = val / 60 / 60, val -= hh * 60 * 60;
    mm = val / 60, val -= mm * 60;
    ss = val;
    val = _val;
    char tmp[9];
    snprintf(tmp, 10, "%02d:%02d:%02d", hh, mm, ss);
    time = tmp;
}

TimePoint::TimePoint(const int &_val) {
    renew(time, hh, mm, ss, val, _val);
}

TimePoint TimePoint::operator-(const TimePoint &rhs) const {
    return TimePoint(abs(val - rhs.val));
}

TimePoint TimePoint::operator+(const TimePoint &rhs) const {
    return TimePoint(val + rhs.val);
}

double TimePoint::operator/(const TimePoint &rhs) const {
    return 1.0 * val / rhs.val;
}

void TimePoint::add(const int &_ss) {
    renew(time, hh, mm, ss, val, val + _ss);
}

void TimePoint::subtract(const int &_ss) {
    renew(time, hh, mm, ss, val, val - _ss);
}

bool TimePoint::operator>(TimePoint const &rhs) const {
    return val > rhs.val;
}
bool TimePoint::operator==(TimePoint const &rhs) const {
    return val == rhs.val;
}
bool TimePoint::operator<(TimePoint const &rhs) const {
    return val < rhs.val;
}

int TimePoint::toSecs() const {
    return val;
}
std::string fromSecs(const int &ss) {
    return TimePoint(ss).getTime();
}

int TimePoint::toMins() const {
    return val / 60;
}
std::string fromMins(const int &mm) {
    return TimePoint(mm * 60).getTime();
}

void TimePoint::display() const {
    std::cout << time;
}

std::string TimePoint::getTime() const {
    return time;
}

#endif
