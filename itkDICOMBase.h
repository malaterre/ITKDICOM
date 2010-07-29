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
#ifndef __itkDICOMBase_h
#define __itkDICOMBase_h

#include "itkLightProcessObject.h"

#include <string>

namespace itk
{

/** \class DICOMBase
 * \brief Abstract superclass defines image DICOM interface.
 */
class ITK_EXPORT DICOMBase : public LightProcessObject
{
public:
  /** Standard class typedefs. */
  typedef DICOMBase        Self;
  typedef LightProcessObject Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMBase, Superclass);

  /* Parameters . */

  /** hostname of DICOM peer. */
  itkSetStringMacro(PeerHostname);
  itkGetStringMacro(PeerHostname);

  /** tcp/ip port number of peer */
  itkSetMacro(PortNumber, unsigned int);
  itkGetMacro(PortNumber, unsigned int);

  /* network options: **/
  /** query information model: */
  typedef  enum { Worklist, Patient, Study, PSOnly}  QueryInformationModelType;
  itkSetEnumMacro(QueryInformationModel, QueryInformationModelType);
  itkGetEnumMacro(QueryInformationModel, QueryInformationModelType);

  /** application entity titles: */
  /** set calling AE title */
  itkSetStringMacro(AETitle);
  itkGetStringMacro(AETitle);

  /** set called AE title */
  itkSetStringMacro(CalledAETitle);
  itkGetStringMacro(CalledAETitle);

  /** proposed transmission transfer syntaxes: */
  typedef enum {
    ImplicitVRLittleEndian = 1,
    ExplicitVRLittleEndian = 2,
    ExplicitVRBigEndian    = 4,
  } TransmissionTransferSyntaxType;
  itkSetEnumMacro(TransmissionTransferSyntax, TransmissionTransferSyntaxType);
  itkGetEnumMacro(TransmissionTransferSyntax, TransmissionTransferSyntaxType);

  /** other network options: */

  /// timeout for connection requests.
  /// 0 => unlimited
  itkSetMacro(Timeout, unsigned int);
  itkGetMacro(Timeout, unsigned int);

  /// timeout for ACSE messages
  itkSetMacro(ACSETimeout, unsigned int);
  itkGetMacro(ACSETimeout, unsigned int);

  /// timeout for DIMSE messages
  itkSetMacro(DIMSETimeout, unsigned int);
  itkGetMacro(DIMSETimeout, unsigned int);

  /// set max receive pdu to n bytes 
  itkSetMacro(MaxPDU, unsigned int);
  itkGetMacro(MaxPDU, unsigned int);

  /// repeat n times
  itkSetMacro(NumberOfRepeat, unsigned int);
  itkGetMacro(NumberOfRepeat, unsigned int);

  /// cancel after n responses
  itkSetMacro(CancelAfterNResponses, unsigned int);
  itkGetMacro(CancelAfterNResponses, unsigned int);

private:
  // FIXME: an abstract class should not have data member:
  std::string m_PeerHostname;
  unsigned int m_PortNumber;
  QueryInformationModelType m_QueryInformationModel;
  std::string m_AETitle;
  std::string m_CalledAETitle;
  TransmissionTransferSyntaxType m_TransmissionTransferSyntax;
  unsigned int m_Timeout;
  unsigned int m_ACSETimeout;
  unsigned int m_DIMSETimeout;
  unsigned int m_MaxPDU;
  unsigned int m_NumberOfRepeat;
  unsigned int m_CancelAfterNResponses;

private:
  DICOMBase(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMBase_h
