#include <gtest/gtest.h>
#include "types.h"

// 测试 loadImageExifData 函数
TEST(SimpleSFMTest, TestLoadImageExifData) {
    // 准备测试数据和对象
    std::string directory = "/server-w/3DPogress/710425af-096d-40d9-8b3e-c12c49caf0b8/photo/";  // 这里应该是你的实际测试目录
    simpleSFM sfm;

    // 假设你有一个测试图像文件的路径
    std::string imagePath = "/server-w/3DPogress/710425af-096d-40d9-8b3e-c12c49caf0b8/photo/4900258383430422529.jpg";  // 替换成你的测试图像路径

    // 运行函数并检查结果
    EXPECT_NO_THROW({
        sfm.loadImageExifData(imagePath);
    });
}