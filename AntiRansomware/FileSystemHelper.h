#pragma once

#include <string>
#include <list>
#include <exception>
#include <functional>

#include <windows.h>
#include <tchar.h> 
#include <string>
#include <shlwapi.h>

using std::wstring;
using std::list;
using std::exception;

class FileSystemHelper
{
private:
	static void getFirstAndLastByCoparable(const wstring & directoryPath, wstring & firstFile, wstring & lastFile, std::function<bool(const WIN32_FIND_DATA &, const WIN32_FIND_DATA &)> compare);
public:

	/*
	* 3 for each: access time, creation time & write time.
	* in each directory we put files with least, middle and most attribute value.
	*/
	static const unsigned int NUMBER_OF_FILES_IN_DIR = 9;

	enum {
		FILE_ACCESS_TIME_ATTRIBUTE,
		FILE_CREATION_TIME_ATTRIBUTE,
		FILE_WRITE_TIME_ATTRIBUTE,
	};

	static list<wstring> getAllSubDirectories(const wstring& directoryPath);
	static list<wstring> getAllFilesInDir(const wstring& directoryPath);
	static void getFirstAndLastFileLexicographicOrder(const wstring& directoryPath, wstring& firstFile, wstring& lastFile);
	static void getFirstAndLastAccessTimeOrder(const wstring& directoryPath, wstring& firstFile, wstring& lastFile);
	static void getFirstAndLastFileWriteTimeOrder(const wstring& directoryPath, wstring& firstFile, wstring& lastFile);
	static void setFileAttribute(const wstring & filename, FILETIME creationTime, FILETIME accessTime, FILETIME writeTime);
	static bool isTempOrAppData(const wstring & filename);
	static FILETIME getFileAttribute(const wstring & filename, int fileAttributeType);
};

class FileSystemHelperException : public exception {};

