// ifstream constructor.
#include<string>
#include<fstream>

class FileIO {
  public:
    FileIO(char * input_file): input(input_file) {}
    std::ifstream input;
    void print_file() {
      char c = input.get();
      while (input.good()){
        printf("%c",c);
        c = input.get();
      }
      input.close();
    }
};

int main () {

  std::string s = "in.txt";
  char c[s.length() + 1];
  strcpy(c, s.c_str());

  FileIO f(c);
  f.print_file();

  return 0;
}
