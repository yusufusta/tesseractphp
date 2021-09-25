<?php
$Tesseract = new Tesseract();
if ($Tesseract->init(null, "eng")) {
    $Tesseract->setImage(__DIR__ . "/text.png");
    echo $Tesseract->getUTF8Text();
}
