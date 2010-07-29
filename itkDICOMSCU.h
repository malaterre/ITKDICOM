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
#ifndef __itkDICOMSCU_h
#define __itkDICOMSCU_h

#include "itkDICOMBase.h"

#include <string>

namespace itk
{

/** \class DICOMBase
 * \brief Abstract superclass defines image DICOM interface.
 */
class ITK_EXPORT DICOMSCU : public DICOMBase
{
public:
  /** Standard class typedefs. */
  typedef DICOMSCU        Self;
  typedef DICOMBase Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMSCU, Superclass);

  /** proposed transmission transfer syntaxes: */
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
  itkSetEnumMacro(ProposedTransmissionTransferSyntax, TransmissionTransferSyntaxType);
  itkGetEnumMacro(ProposedTransmissionTransferSyntax, TransmissionTransferSyntaxType);

private:
  TransmissionTransferSyntaxType m_ProposedTransmissionTransferSyntax;

private:
  DICOMSCU(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMBase_h
