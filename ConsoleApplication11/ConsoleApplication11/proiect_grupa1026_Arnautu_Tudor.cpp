#include <iostream>
#include <cstring>
#include <windows.h>
#include <list>
#include <tchar.h>

using namespace std;

namespace MediaPlus {
	
	class DirectoyMonitor {
		int files_number = 0;
		char *path;
		

		void set_path(char *path) {
			this->path = new char[strlen(path) + 1];
			std::strcpy(this->path, path);
		}

		char *get_path() {
			return path;
		}

		void set_files_number(int files_number = 0) {
			this->files_number = files_number;
		}

		int get_files_number() {
			return files_number;
		}

		void inc_files_number() {
			this->files_number++;
		}
		
		/*char **get_all_files() {
			char **files = new char *[10];
			
			return files;
		}*/


		friend ostream &operator<<(ostream &out, DirectoyMonitor aux);
	};
	
	ostream &operator<<(ostream &out, DirectoyMonitor aux) {
		out << " ";
		out << aux.path << "\n";
		

		return out;
	}

	class Option {
	public:
		char *title;
		Option *parent = NULL;
		Option **options = NULL;
		int option_number;
		bool is_exit = false;
		bool is_help = false;

		void set_title(char const *title) {
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
			cout << "\n====================================\n\n";

			if (this->get_parent() != NULL) {
				std::cout << 0 << ". Inapoi la '" << this->get_title() << "'\n";
				
			}

			for (int i = 0; i < this->get_option_number(); i++) {
				std::cout << i + 1 << ". " << this->options[i]->title << "\n";
			}
		}

		~Option() {
			delete[] title;
			delete[] parent;
			delete[] options;
		}
	};

	//clasa interfata linie de comanda
	class CLI {
	public:
		Option *current_option;
		bool exit = false;

		void set_current_option(Option *current_option) {
			this->current_option = current_option;
		}

		Option  *get_current_option() {
			return this->current_option;
		}

		void set_exit(bool exit) {
			this->exit = exit;
		}

		bool get_exit() {
			return this->exit;
		}

		CLI() {
		}

		// optiunile meniului
		void build_options() {
			Option *first_option = new Option(" ");
			Option *monitor_directory = new Option("Vizualizare directoare monitorizate.", first_option);
			Option *view_extensions = new Option("Vizualizare lista extensii", first_option);
			Option *help = new Option("Ajutor", first_option);
			Option *exit = new Option("Exit", first_option);
			exit->is_exit = true;

			first_option->set_option_number(4);
			Option **chilren = new Option *[4];

			chilren[0] = monitor_directory;
			chilren[1] = view_extensions;
			chilren[2] = help;
			chilren[3] = exit;

			first_option->set_options(chilren);
			
			//optiunea 1 pt monitor_directory
			Option *monitor_directory1 = new Option("Adauga director", monitor_directory);
			monitor_directory->set_option_number(3);
			Option **monitor_directory_chilren = new Option *[monitor_directory->get_option_number()];

			monitor_directory_chilren[0] = monitor_directory1;
			monitor_directory_chilren[1] = help;
			monitor_directory_chilren[2] = exit;

			monitor_directory->set_options(monitor_directory_chilren);

			//optiunea 2 pt monitor_directory
			Option *monitor_directory2 = new Option("Sterge director", monitor_directory);
			monitor_directory->set_option_number(4);
			Option **monitor_directory2_chilren = new Option *[monitor_directory->get_option_number()];

			monitor_directory_chilren[0] = monitor_directory1;
			monitor_directory_chilren[1] = monitor_directory2;
			monitor_directory_chilren[2] = help;
			monitor_directory_chilren[3] = exit;

			view_extensions->set_options(monitor_directory_chilren);

			//optiuni pt view_extension
			Option *view_extensions1 = new Option("Adauga extensie", view_extensions);
			view_extensions->set_option_number(3);
			Option **view_extensions_chilren = new Option *[view_extensions->get_option_number()];

			view_extensions_chilren[0] = view_extensions1;
			view_extensions_chilren[1] = help;
			view_extensions_chilren[2] = exit;

			view_extensions->set_options(view_extensions_chilren);

			//optiunea 2
			Option *view_extensions2 = new Option("Sterge extensie", view_extensions);
			view_extensions->set_option_number(4);
			Option **view_extensions2_chilren = new Option *[view_extensions->get_option_number()];

			view_extensions_chilren[0] = view_extensions1;
			view_extensions_chilren[1] = view_extensions2;
			view_extensions_chilren[2] = help;
			view_extensions_chilren[3] = exit;

			view_extensions->set_options(view_extensions_chilren);

			this->set_current_option(first_option);

		}

		~CLI() {
			delete[] current_option;
		}

		void run() {
			this->build_options();

			this->start_main_loop();
		}

		void start_main_loop() {
			this->current_option->draw();

			int selected_option;

			std::cout << "\n> Alege optiunea: ";
			while (this->exit == false && cin >> selected_option) {
				this->process(selected_option);
			}
		}


		void process(int selected_option) {
			//std::cout << "Ai ales " << selected_option << "\n";
			
			int max_options = this->current_option->get_option_number();
			if (selected_option >= 0 && selected_option <= max_options) {
				// du-te la parinte
				if (selected_option == 0) {
					this->current_option = this->current_option->get_parent();
				}
				else {
					// du-te la optiunea selectata
					this->current_option = this->current_option->get_options()[selected_option - 1];
				}

				// if pentru exit
				if (this->current_option->is_exit) {
					this->set_exit(true);

					return;
				}
				else {
					// pentru altceva, afiseaza optiunile disponibile
					this->current_option->draw();
				}
			}
			else {
				std::cout << ">> Optiune gresita.\n";
			}

			std::cout << "\n> Alege optiunea: ";
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
