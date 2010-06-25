/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Copyright Projet LAAS/CNRS, 2009
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * File:      feature-vector3.h
 * Project:   SOT
 * Author:    Nicolas Mansard
 *
 * Version control
 * ===============
 *
 *  $Id$
 *
 * Description
 * ============
 *
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


#ifndef __SOT_FEATURE_VECTOR3_HH__
#define __SOT_FEATURE_VECTOR3_HH__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* SOT */
#include <sot-core/feature-abstract.h>
#include <sot-core/exception-task.h>
#include <sot-core/matrix-homogeneous.h>

/* --------------------------------------------------------------------- */
/* --- API ------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

#if defined (WIN32)
#  if defined (sotFeatureVector3_EXPORTS)
#    define SOTFEATUREVECTOR3_EXPORT __declspec(dllexport)
#  else
#    define SOTFEATUREVECTOR3_EXPORT __declspec(dllimport)
#  endif
#else
#  define SOTFEATUREVECTOR3_EXPORT
#endif

/* --------------------------------------------------------------------- */
/* --- CLASS ----------------------------------------------------------- */
/* --------------------------------------------------------------------- */

namespace sot {

/*!
  \class FeatureVector3
  \brief Class that defines point-3d control feature
*/
class SOTFEATUREVECTOR3_EXPORT FeatureVector3
: public FeatureAbstract
{

 public:
  static const std::string CLASS_NAME;
  virtual const std::string& getClassName( void ) const { return CLASS_NAME; }

 protected:

  /* --- SIGNALS ------------------------------------------------------------ */
 public:
  SignalPtr< ml::Vector,int > vectorSIN;
  SignalPtr< MatrixHomogeneous,int > positionSIN;
  SignalPtr< ml::Matrix,int > articularJacobianSIN;
  SignalPtr< ml::Vector,int > positionRefSIN;

  using FeatureAbstract::desiredValueSIN;
  using FeatureAbstract::selectionSIN;

  using FeatureAbstract::jacobianSOUT;
  using FeatureAbstract::errorSOUT;
  using FeatureAbstract::activationSOUT;

 public:
  FeatureVector3( const std::string& name );
  virtual ~FeatureVector3( void ) {}

  virtual unsigned int& getDimension( unsigned int & dim, int time );

  virtual ml::Vector& computeError( ml::Vector& res,int time );
  virtual ml::Matrix& computeJacobian( ml::Matrix& res,int time );
  virtual ml::Vector& computeActivation( ml::Vector& res,int time );

  virtual void display( std::ostream& os ) const;

  virtual void commandLine( const std::string& cmdLine,
			    std::istringstream& cmdArgs,
			    std::ostream& os );

} ;

} // namespace sot


#endif // #ifndef __SOT_FEATURE_VECTOR3_HH__

/*
 * Local variables:
 * c-basic-offset: 2
 * End:
 */