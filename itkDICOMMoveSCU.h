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
#ifndef __itkDICOMMoveSCU_h
#define __itkDICOMMoveSCU_h

#include "itkDICOMSCU.h"
#include "itkDICOMSCP.h"

#include <string>

namespace itk
{

/** \class DICOMMoveSCU
 * \brief
 * - SCU  for  the  Query/Retrieve Service Class 
 * - SCP for the Storage Service Class
 */
class ITK_EXPORT DICOMMoveSCU : public DICOMSCU, public DICOMSCP
{
public:
  /** Standard class typedefs. */
  typedef DICOMMoveSCU       Self;
  typedef DICOMBase          Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMMoveSCU, Superclass);

private:
  DICOMMoveSCU(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMMoveSCU_h
