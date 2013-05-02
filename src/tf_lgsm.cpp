#include "tf_lgsm/tf_lgsm.h"

void tf::LgsmDisplacementToTransformTF(const Eigen::Displacementd& k, tf::Transform& t){
	t.setRotation( tf::Quaternion( k.qx(), k.qy(), k.qz(), k.qw() ) );
	t.setOrigin( tf::Vector3( k.x(), k.y(), k.z() ) );
}

void tf::TransformTFToLgsmDisplacement(const tf::Transform& t, Eigen::Displacementd& k){
	k.x() = t.getOrigin()[0];
	k.y() = t.getOrigin()[1];
	k.z() = t.getOrigin()[2];
	k.qx() = t.getRotation()[0];
	k.qy() = t.getRotation()[1];
	k.qz() = t.getRotation()[2];
	k.qw() = t.getRotation()[3];
}
