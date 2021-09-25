#include <phpcpp.h>
#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

using namespace std;

class Tesseract : public Php::Base
{
private:
    tesseract::TessBaseAPI *api;
    Pix *image;

public:
    Tesseract() = default;

    virtual ~Tesseract() = default;

    void __construct(Php::Parameters &params)
    {
        api = new tesseract::TessBaseAPI();
    }

    Php::Value init(Php::Parameters &params)
    {
        std::string datapath = params[0];
        std::string language = params[1];

        return !(api->Init(datapath.c_str(), language.c_str()));
    }

    Php::Value setImage(Php::Parameters &params)
    {
        std::string filename = params[0];
        image = pixRead(filename.c_str());
        api->SetImage(image);
        return true;
    }

    Php::Value getUTF8Text()
    {
        return api->GetUTF8Text();
    }

    Php::Value getHOCRText(Php::Parameters &params)
    {
        int page_number = params[0];
        return api->GetHOCRText(page_number);
    }

    Php::Value getBoxText(Php::Parameters &params)
    {
        int page_number = params[0];
        return api->GetBoxText(page_number);
    }

    Php::Value getIterator()
    {
        return api->GetIterator();
    }

    Php::Value clear()
    {
        api->Clear();
        return true;
    }

    Php::Value end()
    {
        api->End();
        return true;
    }
};

extern "C"
{
    PHPCPP_EXPORT void *get_module()
    {
        static Php::Extension extension("tesseract", "1.0");

        Php::Class<Tesseract> tesseract("Tesseract");
        tesseract.method<&Tesseract::__construct>("__construct");
        tesseract.method<&Tesseract::init>("init");
        tesseract.method<&Tesseract::setImage>("setImage");
        tesseract.method<&Tesseract::getUTF8Text>("getUTF8Text");
        tesseract.method<&Tesseract::getHOCRText>("getHOCRText");
        tesseract.method<&Tesseract::getBoxText>("getBoxText");
        tesseract.method<&Tesseract::getIterator>("getIterator");
        tesseract.method<&Tesseract::clear>("clear");
        tesseract.method<&Tesseract::end>("end");
        extension.add(tesseract);

        return extension;
    }
}
