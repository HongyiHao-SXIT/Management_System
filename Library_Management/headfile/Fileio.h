#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <string>
#include "User.h"

enum class Gender;

void loadUsersFromFile(std::vector<User>& users);

void saveUsersToFile(const std::vector<User>& users);

#endif