/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:40:07 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 08:28:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //* input output stream
#include <sstream> //* string stream
#include <fstream> //* File stream
#include <string>
#include <cstdlib>

void usage(void) {
	std::cout << "Three arguments required: \n";
	std::cout << "=========================\n";
	std::cout << "First: the Filename you need to read from\n";
	std::cout << "Second: string to be replaced\n";
	std::cout << "Third: second string to replace occurences of first string\n";
	std::cout << "[file] [s1] [s2]\n" << std::endl;
}

//* Open the file, reads it's content, and return it as string. Because you don't want to alter the original file.
std::string FileToString(const std::string& filename) {

	//* ifstream = read from a file
	std::ifstream read_file;
	read_file.open(filename.c_str());
	
	//* check for error
	if (!read_file.is_open())
	{
		std::cerr << "Error: Could not open file - " << filename << std::endl;
		exit (EXIT_FAILURE);
	}
	
	//* A stringstream associates a string object with a stream
	//* allowing you to read from the string as if it were a stream (like std::cin)
	std::ostringstream file_content;
	file_content << read_file.rdbuf(); //* return a pointer to the stream buffer of the file
	
	//* close the opened file
	read_file.close();
	return (file_content.str());  //* returns the object as a string;
}

//* replace all occurence of s1 with s2
void replace_content(std::string& file, std::string& s1, std::string& s2)
{
	for (int index = file.find(s1); file.find(s1) != std::string::npos; ) {
		file.erase(index, s1.length());
		file.insert(index, s2);
		index = file.find(s1);
	}
}

int main(int argc, char **argv) {
	
	if (argc != 4)
	{
		std::cerr << "\nError: Invalid number of arguments\n" << std::endl;
		usage();
		exit (EXIT_FAILURE);
	}
	
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	if (s1.empty() || s2.empty())
	{
		std::cerr << "\nError: s1 and s2 cannot be empty\n" << std::endl;
		usage();
		exit (EXIT_FAILURE);
	}
	
	std::string file_content = FileToString(filename);
	
	replace_content(file_content, s1, s2);
	
	//* appends filename with .replace
	filename += ".replace";
	
	//* ofstream = write to file. Create a file if not already existing
	std::ofstream output;
	output.open(filename.c_str());

	//* Check for error
	if (!output.is_open())
	{
		std::cerr << "Error: Could not create file - " << filename << std::endl;
		exit (EXIT_FAILURE);
	}

	//* put newly replaced content into output file.
	output << file_content;
	output.close();

	return (EXIT_SUCCESS);		
}
