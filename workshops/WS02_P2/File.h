#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char m_postalcode[]);
	bool read(int & m_pop);
}
#endif	// !SDDS