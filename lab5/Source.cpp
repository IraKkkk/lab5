#include <iostream>
#include <sstream>
#include <iomanip>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // ����������� �� ��������� ����������
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // ����������� �� ������ � ������ "������:�������:�������"
    Time(const std::string& timeStr) {
        std::istringstream ss(timeStr);
        char delimiter;
        ss >> hours >> delimiter >> minutes >> delimiter >> seconds;
    }

    // ����������� �� ���������
    Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
    }

    // ����������� �� ��'����� Time
    Time(const Time& other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }

    // ���������� ������ �� ����� ��������� ���� � ��������
    int differenceInSeconds(const Time& other) const {
        return (hours - other.hours) * 3600 + (minutes - other.minutes) * 60 + (seconds - other.seconds);
    }

    // ��������� ���� �� ��������� ���� �� ������� ������� ������
    void addSeconds(int secs) {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds + secs;
        *this = Time(totalSeconds);
    }

    // ����������� � ���� ������ ������� ������
    void subtractSeconds(int secs) {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds - secs;
        *this = Time(totalSeconds);
    }

    // ��������� ������� ����
    bool operator<(const Time& other) const {
        return hours < other.hours || (hours == other.hours && (minutes < other.minutes || (minutes == other.minutes && seconds < other.seconds)));
    }

    // ����������� � �������
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // ����������� � ������� � ����������� �� ���� �������
    int toMinutesRounded() const {
        return (hours * 60) + ((minutes + (seconds >= 30 ? 1 : 0)) % 60);
    }
};

int main() {
    // �������� ������������ ����� Time
    Time t1(10, 30, 45);
    Time t2("12:15:20");

    std::cout << "Difference between t1 and t2 in seconds: " << t1.differenceInSeconds(t2) << std::endl;

    t1.addSeconds(100);
    std::cout << "t1 after adding 100 seconds: " << t1.toSeconds() << " seconds" << std::endl;

    t2.subtractSeconds(30);
    std::cout << "t2 after subtracting 30 seconds: " << t2.toSeconds() << " seconds" << std::endl;

    if (t1 < t2) {
        std::cout << "t1 is less than t2" << std::endl;
    }
    else {
        std::cout << "t1 is greater than or equal to t2" << std::endl;
    }

    std::cout << "t1 in minutes (rounded): " << t1.toMinutesRounded() << " minutes" << std::endl;

    return 0;
}
