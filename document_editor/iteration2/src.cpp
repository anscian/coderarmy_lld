#include <vector>
#include <string>
#include <iostream>
#include <fstream>

// Document Element
class DocumentElement {
public:
  virtual std::string render() = 0;
};


class TextElement: public DocumentElement {
private:
  std::string text;

public:
  TextElement(std::string text) {
    this->text = text;
  }

  std::string render() override {
    return text;
  }
};


class ImageElement: public DocumentElement {
private:
  std::string imgPath;

public:
  ImageElement(std::string path) {
    imgPath = path;
  }

  std::string render() override {
    return "[Image: " + imgPath + "]";
  }
};


class NewlineElement: public DocumentElement {
public:
  std::string render() override {
    return "\n";
  }
};


class TabspaceElement: public DocumentElement {
public:
  std::string render() override {
    return "\t";
  }
};


class Document {
private:
  std::vector<DocumentElement *> documentElements;

public:
  void addElement(DocumentElement* element) {
    documentElements.push_back(element);
  }

  std::string render() {
    std::string result;

    for (auto element: documentElements) {
      result += element->render();
    }

    return result;
  }
};


// Persistence
class Persistence {
public:
  virtual void save(std::string data) = 0;
};


class FileStorage: public Persistence {
public:
  void save(std::string data) override {
    std::ofstream outFile("document.txt");

    if (outFile.is_open()) {
      outFile << data;
      outFile.close();
      std::cout<< "Document saved to document.txt\n";
    } else {
      std::cout << "Error: Unable to open file for writing.\n";
    }
  }
};


class DBStorage: public Persistence {
public:
  void save(std::string data) override {
    // TODO: save to DB implementation
    std::cout << "Document saved to database\n";
  }
};


// Document Editor
class DocumentEditor {
private:
  Document *document;
  Persistence *storage;
  std::string renderedDocument;

public:
  DocumentEditor(Document *document, Persistence *storage) {
    this->document = document;
    this->storage = storage;
  }

  void addText(std::string text) {
    document->addElement(new TextElement(text));
  }

  void addImage(std::string imagePath) {
    document->addElement(new ImageElement(imagePath));
  }

  void addTabspace() {
    document->addElement(new TabspaceElement());
  }

  void addNewline() {
    document->addElement(new NewlineElement());
  }

  std::string renderDocument() {
    if (renderedDocument.empty()) {
      renderedDocument = document->render();
    }

    return renderedDocument;
  }

  void saveDocument() {
    storage->save(renderDocument());
  }
};


// Client
int
main(void) {
  Document *document = new Document();
  Persistence *storage = new FileStorage();

  DocumentEditor *editor = new DocumentEditor(document, storage);

  editor->addText("Hello, world!");
  editor->addNewline();
  editor->addTabspace();
  editor->addText("Indented text");
  editor->addNewline();
  editor->addImage("image.png");
  editor->addNewline();
  editor->addText("End of document");

  std::cout << editor->renderDocument() << std::endl;

  editor->saveDocument();

  return 0;
}
