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
class ITK_EXPORT DICOMBase : virtual public Object
{
public:
  /** Standard class typedefs. */
  typedef DICOMBase        Self;
  typedef LightProcessObject Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMBase, Superclass);

  /* Implementation detail: User power-two enums to allow combining them */
  typedef enum {
    ImplicitVRLittleEndian = 1, // Implicit VR Little Endian: Default Transfer Syntax for DICOM
    ExplicitVRLittleEndian = 2, // Explicit VR Little Endian
    DeflatedExplicitVRLittleEndian = 4, // Deflated Explicit VR Little Endian
    ExplicitVRBigEndian    = 8, // Explicit VR Big Endian
    JPEGBaselineProcess1   = 16, // JPEG Baseline (Process 1): Default Transfer Syntax for Lossy JPEG 8 Bit Image Compression
    JPEGExtendedProcess24  = 32, // JPEG Extended (Process 2 & 4): Default Transfer Syntax for Lossy JPEG 12 Bit Image Compression (Process 4 only)
    JPEGLosslessNonHierarchicalProcess14 = 64, // JPEG Lossless, Non-Hierarchical (Process 14)
    JPEGLosslessNonHierarchicalFirstOrderPrediction = 128, // JPEG Lossless, Non-Hierarchical, First-Order Prediction (Process 14 [Selection Value 1]): Default Transfer Syntax for Lossless JPEG Image Compression
    JPEGLSLosslessImageCompression = 256, // JPEG-LS Lossless Image Compression
    JPEGLSLossyNearLosslessImageCompression = 512, // JPEG-LS Lossy (Near-Lossless) Image Compression
    JPEG2000ImageCompressionLosslessOnly = 1024, // JPEG 2000 Image Compression (Lossless Only)
    JPEG2000ImageCompression = 2048, // JPEG 2000 Image Compression
    MPEG2MainProfileMainLevel = 4096, // MPEG2 Main Profile @ Main Level
    RLELossless = 8192, // RLE Lossless
  } TransmissionTransferSyntaxType;

  /* Parameters . */

  /** hostname of DICOM peer. */
  itkSetStringMacro(PeerHostname);
  itkGetStringMacro(PeerHostname);

  /** tcp/ip port number of peer */
  itkSetMacro(PortNumber, unsigned int);
  itkGetMacro(PortNumber, unsigned int);

  /** application entity titles: */
  /** set calling AE title */
  itkSetStringMacro(AETitle);
  itkGetStringMacro(AETitle);

  /** set called AE title */
  itkSetStringMacro(CalledAETitle);
  itkGetStringMacro(CalledAETitle);

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

private:
  // FIXME: an abstract class should not have data member:
  std::string m_PeerHostname;
  unsigned int m_PortNumber;
  std::string m_AETitle;
  std::string m_CalledAETitle;
  unsigned int m_Timeout;
  unsigned int m_ACSETimeout;
  unsigned int m_DIMSETimeout;
  unsigned int m_MaxPDU;

private:
  DICOMBase(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMBase_h
