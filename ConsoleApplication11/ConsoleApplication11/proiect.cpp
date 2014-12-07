#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace MediaPlus {
	class Option {
	public:
		char *title;
		Option *parent;
		Option **options = NULL;
		int option_number;
		
		void set_title(char const *title) {
//			delete[] this->title;

			this->title = new char[strlen(title) + 1];
			std::strcpy(this->title, title);
		}

		char *get_title() {
			return title;
		}

		void set_option_number(int options_number) {
			this->option_number = options_number;
		}

		int get_option_number() {
			return option_number;
		}

		void set_parent(Option *parent) {
			this->parent = parent;
		}

		Option  *get_parent() {
			return this->parent;
		}

		void set_options(Option **options) {
			this->options = options;
		}

		void set_options(Option **options, int option_number) {
			this->set_options(options);
			this->set_option_number(option_number);
		}

		/*
		void add_option(Option *option) {
			if (this->options == NULL) {
				this->options = new Option *[this->option_number];
			}

			int i = 0;
			while (this->options[i] != NULL) {
				i++;
			}

			this->options[i] = option;
		}
		*/
		Option **get_options() {
			return this->options;
		}

		Option() {
			this->set_option_number(0);

		}

		Option(char const *title, Option *parent) {
			this->set_parent(parent);
			this->set_title(title);
			
			this->set_option_number(0);
			
		}

		Option(char const *title) {
			this->set_title(title);
		}

		void draw() {
			for (int i = 0; i < this->get_option_number(); i++) {
				std::cout << i + 1 << ". " << this->options[i]->title << "\n";
			}
		}
	};

	class CLI {
	public:
		Option *current_option;

		void set_current_option(Option *current_option) {
			this->current_option = current_option;
		}

		Option  *get_current_option() {
			return this->current_option;
		}
	
		CLI() {
		}

		void build_options() {
			Option *first_option = new Option(" ");
			Option *monitor_directory = new Option("Vizualizare directoare monitorizate.", first_option);
			Option *view_extensions = new Option("Vizualizare lista extensii", first_option);

			first_option->set_option_number(2);
			Option **chilren = new Option *[2];

			chilren[0] = monitor_directory;
			chilren[1] = view_extensions;

			first_option->set_options(chilren);
			
			// pana aici ai pus prima optiunea si copii lui
			// poti sa continui cu celelalte optiuni
			// ai lista in email


			this->set_current_option(first_option);

		}

		void run() {
			this->build_options();

			this->start_main_loop();
		}

		void start_main_loop() {	
			this->current_option->draw();

			string word;

			std::cout << "Alege optiunea: ";
			//while-ul asta e pana dai ctrl + d
			while (cin >> word) {
				this->process(word);
			}
		}

		void process(string word) {
			std::cout << "Ai ales " << word << "\n";
			std::cout << "Alege optiunea: ";
			// ai optiunea in word
			// transform-o in int
			// vezi daca this->current_option are optiunea aia, adica sa te uiti daca are options[word -1]
			// verifica ca word - 1 asta e intre 0 si numarul de optiuni
			// have fun
			// ai inceputul facu
			// restul, vezi tu
			
		}

		void go_to_option(int number) {
		}
	};
}

int main() {

	MediaPlus::CLI *cli = new MediaPlus::CLI();

	cli->run();

	return 0;
}
