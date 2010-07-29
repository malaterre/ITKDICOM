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
#ifndef __itkDICOMSCP_h
#define __itkDICOMSCP_h

#include "itkDICOMBase.h"

#include <string>

namespace itk
{

/** \class DICOMBase
 * \brief Abstract superclass defines image DICOM interface.
 */
class ITK_EXPORT DICOMSCP : public DICOMBase
{
public:
  /** Standard class typedefs. */
  typedef DICOMBase        Self;
  typedef LightProcessObject Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMBase, Superclass);

  /** preferred transmission transfer syntaxes: */
  itkSetEnumMacro(PreferredTransmissionTransferSyntax, TransmissionTransferSyntaxType);
  itkGetEnumMacro(PreferredTransmissionTransferSyntax, TransmissionTransferSyntaxType);

private:
  TransmissionTransferSyntaxType m_PreferredTransmissionTransferSyntax;

private:
  DICOMSCP(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMBase_h
