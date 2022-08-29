//Description:
//
//All of the animals are having a feast!Each animal is bringing one dish.There is just one rule : the dish must startand end with the same letters as the animal's name. For example, the great blue heron is bringing garlic naan and the chickadee is bringing chocolate cake.
//
//Write a function feast that takes the animal's name and dish as arguments and returns true or false to indicate whether the beast is allowed to bring the dish to the feast.
//
//Assume that beast and dish are always lowercase strings, and that each has at least two letters.beastand dish may contain hyphensand spaces, but these will not appear at the beginning or end of the string.They will not contain numerals.

#include <string>

bool feast(std::string beast, std::string dish) {
	return ((beast[0] == dish[0]) && (beast[beast.length() - 1] == dish[dish.length() - 1])) ? true : false;
}