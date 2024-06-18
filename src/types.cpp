#include "types.h"

simpleSFM::simpleSFM(std::string &directory)
{
    image_directory = directory;
}

 void simpleSFM::loadImageExifData(std::string image_path)
 {
    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(image_path);
    assert(image.get() != 0);
    image->readMetadata();

    Exiv2::ExifData &exifData = image->exifData();
    if (exifData.empty()) {
        std::string error=image_path;
        error += ": No Exif data found in the file";
        std::cerr << error<<std::endl;
        return;
        // throw Exiv2::Error(1, error);
    }

   

    Exiv2::ExifData::const_iterator end = exifData.end();
    for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
        const char* tn = i->typeName();
        std::cout << std::setw(44) << std::setfill(' ') << std::left
                  << i->key() << " "
                  << "0x" << std::setw(4) << std::setfill('0') << std::right
                  << std::hex << i->tag() << " "
                  << std::setw(9) << std::setfill(' ') << std::left
                  << (tn ? tn : "Unknown") << " "
                  << std::dec << std::setw(3)
                  << std::setfill(' ') << std::right
                  << i->count() << "  "
                  << std::dec << i->value()
                  << "\n";
    }

 }

void simpleSFM::processDataset()
{
    //read exif metadata

}