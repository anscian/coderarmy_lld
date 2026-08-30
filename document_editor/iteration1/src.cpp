#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class DocumentEditor {
private:
  std::vector<std::string> documentElements;
  std::string renderedDocument;
public:
  void addText(std::string text) {
    documentElements.push_back(text);
  }

  void addImage(std::string imagePath) {
    documentElements.push_back(imagePath);
  }

  std::string renderDocument() {
    if (renderedDocument.empty()) {
      std::string result;
      for (auto element: documentElements) {
        if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
              element.substr(element.size() - 4) == ".png")) {
          result += "[Image: " + element + "]\n";
        } else {
          result += element + "\n";
        }
      }
      renderedDocument = result;
    }
    return renderedDocument;
  }

  void saveToFile() {
    std::ofstream file("document.txt");
    if (file.is_open()) {
      file << renderDocument();
      file.close();
      std::cout<< "Document saved to document.txt\n";
    } else {
      std::cout << "Error: Unable to open file for writing.\n";
    }
  }
};


int
main(void) {
  DocumentEditor editor;
  editor.addText("Hello, world!");
  editor.addImage("picture.jpg");
  editor.addText("This is a document editor.");

  std::cout << editor.renderDocument() << std::endl;

  editor.saveToFile();

  return 0;
}
