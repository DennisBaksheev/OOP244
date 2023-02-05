#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
	class Mark {
		int m_mark;
	public:
		Mark();
		Mark(int mark);
		operator int() const;
		operator double() const;
		operator char() const;
    operator bool() const;
    bool operator== (const Mark& other) const;
		bool operator!= (const Mark& other) const;
    bool operator< (const Mark& other) const;
    bool operator> (const Mark& other) const;
    bool operator<= (const Mark& other) const;
    bool operator>= (const Mark& other) const;
	  Mark& operator++ ();
    Mark& operator-- ();
    bool operator~ ();
    Mark operator++ (int temp);
    Mark& operator= (int newVal);
    Mark& operator+= (int addedVal);
    Mark& operator-= (int minusVal);
    Mark operator-- (int temp);
    Mark& operator<< (Mark& otherMark);
    Mark& operator>> (Mark& otherMark);
    int getm_mark() const;
    Mark operator+ (const Mark& otherMark) const;
    Mark operator+ (int otherVal) const;
};
	int& operator +=(int& oldVal, const Mark& themark);
  int& operator -=(int& oldVal, const Mark& themark);
  int operator+ (int otherVal,const Mark& themark );
}



#endif // !SDDS_MARK_H