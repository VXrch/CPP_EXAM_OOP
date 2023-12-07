#pragma once
#include "Library.h"
#include <fstream>

class FilesWork
{
	void ReadLibrary(Library& library);
	void WriteLibrary(Library& library);

	void ReadAdmins(vector<Admin>& admins);
	void WriteAdmins(vector<Admin>& admins);

	void ReadUsers(vector<User>& users);
	void WriteUsers(vector<User>& users);

public:

	void WriteToFile(Library& library, vector<Admin>& admins, vector<User>& users)
	{
		WriteLibrary(library);
		WriteAdmins(admins);
		WriteUsers(users);
	}
	void ReadFromFile(Library& library, vector<Admin>& admins, vector<User>& users)
	{
		ReadLibrary(library);
		ReadAdmins(admins);
		ReadUsers(users);
	}
};
