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

int main(int argc, char *argv[])
{
  const char peer[] = "dicomserver";
  const int port    = 104;

  // Do a C-MOVE
  typedef itk::GDCMCMoveSCU CMoveImplementationType;
  CMoveImplementationType::Pointer gdcmCMove = CMoveImplementationType::New();
  gdcmCMove->SetPeer( peer );
  gdcmCMove->SetPort( port );

  typedef itk::DICOMCMove   CMoveType;
  CMoveType::Pointer cmove = CMoveType::New();

  cmove->SetImplementation( gdcmCMove );
  
  return EXIT_SUCCESS;
}
