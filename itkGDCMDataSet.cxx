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
#include "itkGDCMDataSet.h"

#include "gdcmFile.h"
#include "gdcmStringFilter.h"

namespace itk
{

class GDCMDataSetInternal
{
public:
  gdcm::File F;
};

GDCMDataSet::GDCMDataSet():Internals( new GDCMDataSetInternal )
{
}

GDCMDataSet::~GDCMDataSet()
{
  delete Internals;
}

bool GDCMDataSet::GetDICOMAttributeValue( const std::string & query,
  std::string & value )
{
  gdcm::StringFilter sf;
  sf.SetFile( Internals->F );
  bool ret = sf.ExecuteQuery( query, value );

  return ret;
}

} // end namespace itk
