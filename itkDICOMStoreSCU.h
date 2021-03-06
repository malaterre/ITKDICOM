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
#ifndef __itkDICOMStoreSCU_h
#define __itkDICOMStoreSCU_h

#include "itkDICOMSCU.h"

#include <string>

namespace itk
{

/** \class DICOMStoreSCU
 * \brief
 */
class ITK_EXPORT DICOMStoreSCU : public DICOMSCU
{
public:
  /** Standard class typedefs. */
  typedef DICOMStoreSCU       Self;
  typedef DICOMBase          Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMStoreSCU, Superclass);

  /** input files */
  typedef std::vector< std::string >           FileNamesContainer;
  void SetFileNames (const FileNamesContainer &name);
  const FileNamesContainer  & GetFileNames() const;

  /** user identity negotiation: */
  /** authenticate using user name */
  itkSetStringMacro(UserName);
  itkGetStringMacro(UserName);

  /** authenticate using password */
  itkSetStringMacro(Password);
  itkGetStringMacro(Password);

private:
  FileNamesContainer m_FileNames;
  std::string m_UserName;
  std::string m_Password;

private:
  DICOMStoreSCU(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMStoreSCU_h
