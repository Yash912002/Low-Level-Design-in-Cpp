#include "../../../utils/Logger.h"
#include <bits/stdc++.h>
using namespace std;

class DocumentElement {
public:
  virtual string render() = 0;
};

class TextElement : public DocumentElement {
private:
  string text;

public:
  TextElement(string text) { this->text = text; }

  string render() override {
    return text;
  }
};

class ImageElement : public DocumentElement {
private:
  string ImagePath;

public:
  ImageElement(string ImagePath) { this->ImagePath = ImagePath; }

  string render() override {
    return "[Image: " + ImagePath + "]";
  }
};

class NewLineElement : public DocumentElement {
public:
  string render() override {
    return "\n";
  }
};

class TabElement : public DocumentElement {
public:
  string render() override {
    return "\t";
  }
};

class Document {
private:
  vector<DocumentElement *> docElements;

public:
  void addElements(DocumentElement *element) { docElements.push_back(element); }

  string render() {
    string result = "";

    if (docElements.size() > 0) {
      for (auto document : docElements) {
        result += document->render();
      }
    }

    return result;
  }
};

class Storage {
public:
  virtual void save(string document) = 0;
};

class FileStorage : public Storage {
public:
  void save(string document) override {
    ofstream file("document.txt");

    if (file.is_open()) {
      file << document;
      file.close();
      LOG_SUCCESS("Document saved to document.txt");
    } else {
      LOG_ERROR("Unable to open file for writing");
    }
  }
};

class DatabaseStorage : public Storage {
public:
  void save(string document) override {
    LOG_SUCCESS("Document saved to Database.");
  }
};

class DocumentEditor {
private:
  Document *document;
  Storage *storage;
  string renderedDocument;

public:
  DocumentEditor(Document *document, Storage *storage) {
    this->document = document;
    this->storage = storage;
  }

  void addText(string text) { document->addElements(new TextElement(text)); }

  void addImage(string imagePath) {
    document->addElements(new ImageElement(imagePath));
  }

  void addNewLine() {
    document->addElements(new NewLineElement());
  }

  void addTab() { document->addElements(new TabElement()); }

  string renderDocument() {
    if (renderedDocument.empty()) {
      renderedDocument = document->render();
    }

    return renderedDocument;
  }

  void save() {
    if (renderedDocument.empty()) {
      renderedDocument = renderDocument();
    }

    storage->save(renderedDocument);
  }
};

int main() {
  Document* document = new Document();
  Storage* fileStorage = new FileStorage();
  DocumentEditor* documentEditor = new DocumentEditor(document, fileStorage);

  documentEditor->addText("Name: Yash Bhavsar");
  documentEditor->addNewLine();
  documentEditor->addText("Age: 23");
  documentEditor->addNewLine();

  documentEditor->addImage("Profile.png");
  documentEditor->addTab();
  documentEditor->addImage("Profile.png");

  // Render the document
  cout << documentEditor->renderDocument() << endl;

  // Save the document
  documentEditor->save();

  delete document;
  delete fileStorage;
  delete documentEditor;

  return 0; 
}
