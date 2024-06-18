#pragma once
#include <string>
#include <vector>
#include <Eigen/Geometry>
#include <exiv2/exiv2.hpp>



struct ImageReader{
    public:
    ImageReader(std::string &directory):directory(directory)
    {
        imageId=-1;
    }
    private:
        std::string directory;
        int imageId;

};

struct Camera{
    double fx;
    double fy;
    double cx;
    double cy;
};

class ImageData{
    private:
        std::string path;
        int width;
        int height;
        std::vector<double> GPS_prior;
        Eigen::Quaterniond rotation;
        Eigen::Vector3d translation;
        Camera camera;
    public:
        ImageData(std::string &path){
            path = path;
            
            rotation = Eigen::Quaterniond::Identity();
            translation = Eigen::Vector3d::Zero();

        };
};

class simpleSFM{
    public:
        simpleSFM(std::string &directory);
        simpleSFM(){}
        void processDataset();
        void performSFM();
        void loadImageExifData(std::string image_path);

    private:
        
        std::vector<ImageData> database;
        // ImageReader* imageReader;
        std::string image_directory;

};