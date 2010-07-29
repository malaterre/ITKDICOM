cmake_minimum_required(VERSION 2.8)
project(ITKDICOM)

option(BUILD_SHARED_LIBS "shared ?" ON)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

set(ITKDICOM_SRCS
  itkDICOMBase.cxx
  )

add_library(ITKDICOM
  ${ITKDICOM_SRCS}
  )
target_link_libraries(ITKDICOM ITKIO)
