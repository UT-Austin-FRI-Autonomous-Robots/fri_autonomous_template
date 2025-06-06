#include <spatial_utils/transform_util.h>

/*
    For this one.
        Make a 4x4 Identity matrix using Eigen::MatrixXd::Identity
        Set the right column to the translation, as in the class notes.
        Set the upper-left 3x3 to the rotation matrix.
        You can use Eigen::Quaterniond to turn the quaternion from the
            TransformStamped into a rotation matrix.
            Quaterniond, then .toRotationMatrix
        You can use .block to refer to to the upper-left 3x3 submatrix of your
            4x4 rigid transformation.
*/
Eigen::MatrixXd transformToMatrix(const geometry_msgs::msg::TransformStamped &transform) {
    Eigen::MatrixXd matrix = Eigen::MatrixXd::Identity(4,4);
    return matrix;
}

/*
    Converting your 4x4 rigid transformation into a TransformStamped works like
        this.
    Set the header.frame_id to the parent frame,
        and the child_frame_id to the child frame.
    Take the right column as transform.translation.
    Use block to get the 3x3 upper left rotation matrix from the
        rigid transformation.
    Stick that into Eigen::Quaterniond, then pull off the quaternion terms. 
        Put those into the terms of transform.rotation.
    
*/
geometry_msgs::msg::TransformStamped matrixToTransform(
    const Eigen::MatrixXd &matrix, const std::string &parent_frame, const std::string &child_frame) {
    geometry_msgs::msg::TransformStamped transform_msg;
    return transform_msg;
}

void printTransform(const rclcpp::Logger &logger, geometry_msgs::msg::TransformStamped &transform) {
    RCLCPP_INFO_STREAM(logger,
        "Transform Received:\n" <<
        "  Timestamp: " << transform.header.stamp.sec << "." << transform.header.stamp.nanosec <<

        "  Parent Frame: " << transform.header.frame_id << "\n" <<
        "  Child Frame: " << transform.child_frame_id << "\n" <<
        "  Translation: [" << transform.transform.translation.x << ", "
                           << transform.transform.translation.y << ", "
                           << transform.transform.translation.z << "]\n" <<
        "  Rotation: [" << transform.transform.rotation.x << ", "
                        << transform.transform.rotation.y << ", "
                        << transform.transform.rotation.z << ", "
                        << transform.transform.rotation.w << "]"
    );
}