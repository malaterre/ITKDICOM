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
#ifndef __itkDICOMStoreSCP_h
#define __itkDICOMStoreSCP_h

#include "itkDICOMSCP.h"

#include <string>

namespace itk
{

/** \class DICOMStoreSCP
 * \brief
 */
class ITK_EXPORT DICOMStoreSCP : public DICOMSCP
{
public:
  /** Standard class typedefs. */
  typedef DICOMStoreSCP       Self;
  typedef DICOMBase          Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMStoreSCP, Superclass);

private:
  DICOMStoreSCP(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMStoreSCP_h
