#pragma once

#include <iostream>
#include <fstream>
#include <string>

// Prints message and content of the file 
void PrintFileContent(const std::string kFileName, const std::string kMessage);

// Returns true if file contains at least one line starting with conditional character '#' and false if not
bool IsSourceFileConditional(const std::string kFileName);

// Extends initial text file with entered text
void AppendTextToFile(const std::string kFileName, const std::string kText);

// Writes a new file or rewrites the existing file
void WriteTextFile(const std::string kFileName, const std::string kText);

// Returns the text typed by the user
std::string GetText();

// User interface for working with the source text file
void SourceFileProcessing(const std::string kFileName);

// Returns true if the file can be opened and false if not
bool IsFileAccessible(const std::string kFileName);

// Forms new text file based on source text file
void NewFileForming(std::string kSourceFileName, std::string kNewFileName);