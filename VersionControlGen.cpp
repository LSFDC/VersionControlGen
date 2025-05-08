#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

std::string get_formatted_date() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char buffer[32];
	strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", ltm);
	return buffer;
}

int get_random_version() {
	srand(static_cast<unsigned>(time(0)));
	return 10000 + rand() % 89999;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: generate_version <output_path>\n";
		return 1;
	}

	std::string output = argv[1];
	std::ofstream outfile(output);
	if (!outfile) {
		std::cerr << "Cannot write to: " << output << "\n";
		return 2;
	}

	int version = get_random_version();
	std::string date = get_formatted_date();

	outfile << "#define FILEVER               " << version << "\n";
	outfile << "#define STRFILEVER           \"" << version << "\"\n";
	outfile << "#define STRINTERNALNAME      \"" << date << "\"\n";

	std::cout << "Generated " << output << " with random version " << version << "\n";
	return 0;
}
