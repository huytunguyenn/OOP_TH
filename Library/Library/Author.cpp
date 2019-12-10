#include "Author.h"

Author::Author(string username, string password, string AuthorName)
{
	this->username = username;
	this->password = password;
	this->AuthorName = AuthorName;
}

string Author::getAuthorName()
{
	return this->AuthorName;
}

string Author::getObjName()
{
	return "Author";
}
