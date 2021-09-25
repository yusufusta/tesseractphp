# Tesseract OCR extension for PHP

> Written in C++

## Install

`make && make install`

## Usage

```php
$Tesseract = new Tesseract();
$Tesseract->init(null, "eng");
$Tesseract->setImage("text.png");
echo $Tesseract->getUTF8Text();
```

## License

MIT
