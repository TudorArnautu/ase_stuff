





#include<iostream>
#include<string>

using namespace std;

namespace MediaPlus {

	class CLI {
		Option *current_option;

		void set_current_option(Option *current_option) {
			this->current_option = current_option;
		}

		Option  *get_current_option() {
			return this->current_option;
		}

		CLI() {
			
			Option first_option("");
			Option monitor_directory("Vizualizare directoare monitorizate." );
			Option view_extensions("Vizualizare lista extensii");
			monitor_directory.set_parent(&first_option);
			view_extensions.set_parent(&first_option);

			
		}
	};

	class Option {
		char *title;
		Option *parent;
		Option(*options)[];
		int option_number;


		void set_title(char *title) {
			delete[] this->title;
			this->title = new char[strlen(title) + 1];
			strcpy(this->title, title);
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

		void set_Option(Option(*options)[]) {
			this->options = options;
		}

		Option *get_Option() {
			return *this->options;
		}


		Option(){
			this->set_option_number = 0;

		}
	public:
		Option(char *title) {
			this->title = title;
			this->parent = parent;
			

		}
	};


}









int main() {
	
	
	
	
	
	return 0;
}