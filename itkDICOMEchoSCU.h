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
#ifndef __itkDICOMEchoSCU_h
#define __itkDICOMEchoSCU_h

#include "itkDICOMBase.h"

#include <string>

namespace itk
{

/** \class DICOMEchoSCU
 * \brief
 */
class ITK_EXPORT DICOMEchoSCU : public DICOMBase
{
public:
  /** Standard class typedefs. */
  typedef DICOMEchoSCU       Self;
  typedef DICOMBase          Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMEchoSCU, Superclass);

private:
  DICOMBase(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMEchoSCU_h
