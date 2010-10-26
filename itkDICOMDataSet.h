/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkDICOMBase.h,v $
  Language:  C++
  Date:      $Date: 2009-11-29 15:51:11 $
  Version:   $Revision: 1.1 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkDICOMDataSet_h
#define __itkDICOMDataSet_h

#include "itkObject.h"

#include <string>

namespace itk
{

/** \class DICOMDataSet
 * \brief Abstract superclass defines dataset DICOM interface.
 */
class ITK_EXPORT DICOMDataSet : public Object
{
public:
  /** Standard class typedefs. */
  typedef DICOMDataSet        Self;
  typedef Object Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMDataSet, Superclass);

  // Sup 118 A.1.7 Examples
  // /DicomNativeModel/DicomAttribute[@keyword="ViewCodeSequence"]/Item[@number=1]//DicomAttribute[@keyword="CodeMeaning"]/Value[@number=1]
  // Return false when Attribute is not found.
  // value is the empty string when Attribute is found but value is empty.
  virtual bool GetDICOMAttributeValue( const std::string & query, std::string & value ) = 0;

protected:
  DICOMDataSet();
  ~DICOMDataSet();

private:
  DICOMDataSet(const Self&);   //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMBase_h
