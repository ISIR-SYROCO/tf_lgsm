#include<tf_lgsm/tf_lgsm.h>
#include<Eigen/Core>
#include<Eigen/Lgsm>
#include<tf/tf.h>
#include <stdio.h>

void printTransform(tf::Transform& t){
	for(int i=0; i<3; i++){
		std::cout << t.getOrigin()[i] << "\t";
	}
	std::cout << t.getRotation()[3] << "\t";
	for(int i=0; i<3; i++){
		std::cout << t.getRotation()[i] << "\t";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv){

	tf::Transform t1;
	Eigen::Displacementd k1(1., 2., 3., 1., 0., 0., 0.);

	tf::LgsmDisplacementToTransformTF(k1, t1);
	std::cout << "Displacement:\n" << k1 << std::endl;
	std::cout << "Conversion to TF:\n" ;
	printTransform(t1);
	std::cout << std::endl;

	tf::Transform t2;
	Eigen::Displacementd k2(1., 2., 3., 1., 0., 0., 0.);
    t2.setOrigin( tf::Vector3( 3., 4., 5. ) );
	t2.setRotation(tf::Quaternion( 0., 0.707, 0., 0.707 ) );

	tf::TransformTFToLgsmDisplacement(t2, k2);
	std::cout << "Transform:\n";
	printTransform(t2);
	std::cout << "Conversion to Displacement:\n" << k2 << std::endl;

	return 1;
}

