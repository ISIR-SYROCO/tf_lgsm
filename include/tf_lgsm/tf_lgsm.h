#ifndef CONVERSIONS_TF_LGSM_H
#define CONVERSIONS_TF_LGSM_H

#include<Eigen/Core>
#include<Eigen/Lgsm>
#include <tf/tf.h>

namespace tf {

	void LgsmDisplacementToTransformTF(const Eigen::Displacementd& k, tf::Transform& t);
    void TransformTFToLgsmDisplacement(const tf::Transform& t, Eigen::Displacementd& k);
}

#endif
