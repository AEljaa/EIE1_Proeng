#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct Point{
    double x;
    double y;
};

double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

std::string point_to_s(Point p){
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}

// idxp1 and idxp2 are output parameters
// after the function call they will contain
// the indices of the two closest points in vp
// if vp contains two points or more
// (otherwise they will just contain uninitialised values)

void closest_points(const std::vector<Point>& vp, int& idxp1, int& idxp2){
    // TODO:
    // complete this function
    // (make use of function distance_points)
    std::vector<double> dist;

    for(int i=0;i<vp.size();i++){


        for(int j=0;j<vp.size();j++){
            dist.push_back(distance_points(vp[i],vp[j]));
            if(vp[i].x != vp[j].x && vp[i].y != vp[j].y) {


            }

        }
    }
    double smallest=9999999;
    int ind;
    //gets smallest non 0 distance between two points
    for(int i=0;i<dist.size();i++){

        if (smallest > dist[i] && dist[i]!=0) {
            smallest = dist[i];
            ind=i;
        }
    }


    idxp1=(dist.size()/ind-1);
    idxp2=vp.size()%ind-1;

    std::cout<<point_to_s(vp[idxp1])<<std::endl;
    std::cout<<point_to_s(vp[idxp2])<<std::endl;


}

int main(){
    std::ifstream infile;
    infile.open("points.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Point> points;
    Point tmp;

    while(infile >> tmp.x >> tmp.y){
        points.push_back(tmp);
    }

    infile.close();

    if(points.size() == 0){
        std::cout << "there are no points in the file" << std::endl;
    }

    else if(points.size() == 1){
        std::cout << "there is only one point in the file" << std::endl;
    }

    else{
        int idxp1, idxp2;
        closest_points(points, idxp1, idxp2);
        // TODO:
        // print the two points
    }


}