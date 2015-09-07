#include <iostream>

#include <Eigen/Dense>

#include <QApplication>
#include "QCustomPlot/qcustomplot.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>


int main(int argc, char *argv[]) {
    std::cout << "Hello world" << std::endl;

    Eigen::Matrix3f mat = Eigen::Matrix3f::Identity();
    std::cout << mat << std::endl;


    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    std::string cloudFile = "/home/smichaud/Workspace/Prototype/misc/cloud.pcd";
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(cloudFile, *cloud) == -1) {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
    std::cout << "Loaded "
        << cloud->width * cloud->height
        << " data points"
        << std::endl;


    QApplication app(argc, argv);
    QCustomPlot customPlot;
    std::string fileName = "/home/smichaud/Workspace/Prototype/misc/testPlot.pdf";
    QVector<double> a(101), b(101);
    for (int i=0; i<101; ++i) {
        a[i] = i/50.0 - 1;
        b[i] = a[i]*a[i];
    }

    customPlot.addGraph();
    customPlot.graph(0)->setData(a, b);
    customPlot.xAxis->setLabel("x");
    customPlot.yAxis->setLabel("y");
    customPlot.xAxis->setRange(-1, 1);
    customPlot.yAxis->setRange(0, 1);
    //window.customPlot.show();
    //window.customPlot.replot();
    customPlot.savePdf(QString::fromStdString(fileName));


    cv::Mat image;
    image = cv::imread("/home/smichaud/Workspace/Prototype/misc/image.jpg",
            CV_LOAD_IMAGE_COLOR);
    if(image.data) {
        cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
        cv::imshow("Display window", image);

        cv::waitKey(0);
    }

    return 0;
}
