/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "Examplelaplacian.h"

/**
 * This function defines the valid parameters for
 * this Kernel and their default values
 */
template<>
InputParameters validParams<Examplelaplacian>()
{
  InputParameters params = validParams<Kernel>();
  //params.addRequiredParam<RealVectorValue>("velocity", "Velocity Vector");
  return params;
}

Examplelaplacian::Examplelaplacian(const InputParameters & parameters) :
  // You must call the constructor of the base class first
  Kernel(parameters),
   _kappa(1.0)
{}

Real Examplelaplacian::computeQpResidual()
{
  // velocity * _grad_u[_qp] is actually doing a dot product
  //return _test[_i][_qp]*(_kappa*_grad_u[_qp]);
	Real k = 1./sqrt(1. + _grad_u[_qp] * _grad_u[_qp]);
	return  k * _grad_u[_qp] * _grad_test[_i][_qp]+ _kappa * _u[_qp]*_test[_i][_qp] ;
}

Real Examplelaplacian::computeQpJacobian()
{
   // the partial derivative of _grad_u is just _grad_phi[_j]
	Real k = 1. / sqrt(1. + _grad_u[_qp]*_grad_u[_qp]);
	return (k * _grad_phi[_j][_qp] * _grad_test[_i][_qp] + _kappa * _phi[_j][_qp] *_test[_i][_qp] );
	//Real dkdu = -std::pow() 
  //return 0; 
}
