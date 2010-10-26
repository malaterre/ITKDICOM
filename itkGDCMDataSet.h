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
#ifndef __itkGDCMDataSet_h
#define __itkGDCMDataSet_h

#include "itkDICOMDataSet.h"
#include <string>

namespace itk
{

class GDCMDataSetInternal;
/** \class GDCMDataSet
 * \brief GDCM implementation of DICOMDataSet interface.
 */
class ITK_EXPORT GDCMDataSet : public DICOMDataSet
{
public:
  /** Standard class typedefs. */
  typedef GDCMDataSet        Self;
  typedef DICOMDataSet Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(GDCMDataSet, Superclass);

  /// Fetch an Attribute Value from a XPath query
  bool GetDICOMAttributeValue( const std::string & query, std::string & value );

protected:
  GDCMDataSet();
  ~GDCMDataSet();

private:
  GDCMDataSetInternal *Internals;
private:
  GDCMDataSet(const Self&);   //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMBase_h
