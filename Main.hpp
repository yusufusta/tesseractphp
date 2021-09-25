#include <phpcpp.h>
#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
using namespace std;

class Tesseract : public Php::Base
{
public:
    void __construct(Php::Parameters &params);
    Php::Value init(Php::Parameters &params);
    Php::Value setImage(Php::Parameters &params);
    Php::Value getUTF8Text();
    Php::Value getHOCRText(Php::Parameters &params);
    Php::Value getBoxText(Php::Parameters &params);
    Php::Value getIterator();
    Php::Value clear();
    Php::Value end();

private:
    tesseract::TessBaseAPI *api;
    Pix *image;
};
