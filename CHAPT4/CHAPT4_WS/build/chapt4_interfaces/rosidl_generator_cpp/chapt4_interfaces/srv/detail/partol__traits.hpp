// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from chapt4_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice

#ifndef CHAPT4_INTERFACES__SRV__DETAIL__PARTOL__TRAITS_HPP_
#define CHAPT4_INTERFACES__SRV__DETAIL__PARTOL__TRAITS_HPP_

#include "chapt4_interfaces/srv/detail/partol__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<chapt4_interfaces::srv::Partol_Request>()
{
  return "chapt4_interfaces::srv::Partol_Request";
}

template<>
inline const char * name<chapt4_interfaces::srv::Partol_Request>()
{
  return "chapt4_interfaces/srv/Partol_Request";
}

template<>
struct has_fixed_size<chapt4_interfaces::srv::Partol_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<chapt4_interfaces::srv::Partol_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<chapt4_interfaces::srv::Partol_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<chapt4_interfaces::srv::Partol_Response>()
{
  return "chapt4_interfaces::srv::Partol_Response";
}

template<>
inline const char * name<chapt4_interfaces::srv::Partol_Response>()
{
  return "chapt4_interfaces/srv/Partol_Response";
}

template<>
struct has_fixed_size<chapt4_interfaces::srv::Partol_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<chapt4_interfaces::srv::Partol_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<chapt4_interfaces::srv::Partol_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<chapt4_interfaces::srv::Partol>()
{
  return "chapt4_interfaces::srv::Partol";
}

template<>
inline const char * name<chapt4_interfaces::srv::Partol>()
{
  return "chapt4_interfaces/srv/Partol";
}

template<>
struct has_fixed_size<chapt4_interfaces::srv::Partol>
  : std::integral_constant<
    bool,
    has_fixed_size<chapt4_interfaces::srv::Partol_Request>::value &&
    has_fixed_size<chapt4_interfaces::srv::Partol_Response>::value
  >
{
};

template<>
struct has_bounded_size<chapt4_interfaces::srv::Partol>
  : std::integral_constant<
    bool,
    has_bounded_size<chapt4_interfaces::srv::Partol_Request>::value &&
    has_bounded_size<chapt4_interfaces::srv::Partol_Response>::value
  >
{
};

template<>
struct is_service<chapt4_interfaces::srv::Partol>
  : std::true_type
{
};

template<>
struct is_service_request<chapt4_interfaces::srv::Partol_Request>
  : std::true_type
{
};

template<>
struct is_service_response<chapt4_interfaces::srv::Partol_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CHAPT4_INTERFACES__SRV__DETAIL__PARTOL__TRAITS_HPP_
