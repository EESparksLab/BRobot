// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_roboclaw_driver:srv/ResetEncoders.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__STRUCT_HPP_
#define ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Request __declspec(deprecated)
#endif

namespace ros2_roboclaw_driver
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetEncoders_Request_
{
  using Type = ResetEncoders_Request_<ContainerAllocator>;

  explicit ResetEncoders_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = 0ll;
      this->right = 0ll;
    }
  }

  explicit ResetEncoders_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = 0ll;
      this->right = 0ll;
    }
  }

  // field types and members
  using _left_type =
    int64_t;
  _left_type left;
  using _right_type =
    int64_t;
  _right_type right;

  // setters for named parameter idiom
  Type & set__left(
    const int64_t & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__right(
    const int64_t & _arg)
  {
    this->right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Request
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Request
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetEncoders_Request_ & other) const
  {
    if (this->left != other.left) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetEncoders_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetEncoders_Request_

// alias to use template instance with default allocator
using ResetEncoders_Request =
  ros2_roboclaw_driver::srv::ResetEncoders_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_roboclaw_driver


#ifndef _WIN32
# define DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Response __declspec(deprecated)
#endif

namespace ros2_roboclaw_driver
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetEncoders_Response_
{
  using Type = ResetEncoders_Response_<ContainerAllocator>;

  explicit ResetEncoders_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ok = false;
    }
  }

  explicit ResetEncoders_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ok = false;
    }
  }

  // field types and members
  using _ok_type =
    bool;
  _ok_type ok;

  // setters for named parameter idiom
  Type & set__ok(
    const bool & _arg)
  {
    this->ok = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Response
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_roboclaw_driver__srv__ResetEncoders_Response
    std::shared_ptr<ros2_roboclaw_driver::srv::ResetEncoders_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetEncoders_Response_ & other) const
  {
    if (this->ok != other.ok) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetEncoders_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetEncoders_Response_

// alias to use template instance with default allocator
using ResetEncoders_Response =
  ros2_roboclaw_driver::srv::ResetEncoders_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_roboclaw_driver

namespace ros2_roboclaw_driver
{

namespace srv
{

struct ResetEncoders
{
  using Request = ros2_roboclaw_driver::srv::ResetEncoders_Request;
  using Response = ros2_roboclaw_driver::srv::ResetEncoders_Response;
};

}  // namespace srv

}  // namespace ros2_roboclaw_driver

#endif  // ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__STRUCT_HPP_
