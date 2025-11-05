/*
  This design is bad and breaking several SOLID design principles.
  S = It's breaking SRP because one class is doing all the work.
      That means it has multiple reasons to change.

  O = It is also breaking OCP, because if in future if we need to
      add new features or change the logic of existing feature, we
      need to update or change the code of this class.

  LSP, ISP and DIP are absent.
*/

#include "../../../utils/Logger.h"
#include <bits/stdc++.h>
using namespace std;

class DocumentEditor {
private:
  vector<string> documentElements;
  string renderedDocument;

public:
  void addText(string text) { documentElements.push_back(text); }

  void addImage(string imagePath) { documentElements.push_back(imagePath); }

  string renderDocument() {
    if (renderedDocument.empty()) {
      string result;

      for (auto element : documentElements) {
        if (element.size() > 4 &&
            ((element.substr(element.size() - 4) == ".jpg") ||
             (element.substr(element.size() - 4) == ".png"))) {
          result += "[Image: " + element + "]" + "\n";
        } else {
          result += element + "\n";
        }
      }
      renderedDocument = result;
    }

    return renderedDocument;
  }

  void saveToFile() {
    ofstream file("document.txt");

    if (file.is_open()) {
      file << renderDocument();
      file.close();
      LOG_SUCCESS("Document saved to document.txt");
    } else {
      LOG_ERROR("Unable to open file for writing");
    }
  }
};

int main() {
  DocumentEditor editor;
  editor.addText("My name is yash bhavsar");
  editor.addImage("profile.png");
  editor.addImage("profile2.png");
  editor.addText("This is another paragraph.");

  cout << editor.renderDocument() << endl;
  editor.saveToFile();
  return 0;
}
