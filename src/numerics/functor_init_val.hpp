/** ExaTN::Numerics: Tensor Functor: Initialization to a scalar value
REVISION: 2019/09/20

Copyright (C) 2018-2019 Dmitry I. Lyakh (Liakh)
Copyright (C) 2018-2019 Oak Ridge National Laboratory (UT-Battelle) **/

/** Rationale:
 (A) This tensor functor (method) is used to initialize a Tensor to a scalar value,
     with the default of zero.
**/

#ifndef EXATN_NUMERICS_FUNCTOR_INIT_VAL_HPP_
#define EXATN_NUMERICS_FUNCTOR_INIT_VAL_HPP_

#include "Identifiable.hpp"

#include "tensor_basic.hpp"

#include "tensor_method.hpp"

#include <complex>
#include <string>

namespace exatn{

namespace numerics{

class FunctorInitVal: public talsh::TensorFunctor<Identifiable>{
public:

 FunctorInitVal(): init_val_(0.0){};

 template<typename NumericType>
 FunctorInitVal(NumericType value): init_val_(value){}
 virtual ~FunctorInitVal() = default;

 virtual const std::string name() const override
  {return "TensorFunctorInitVal";}

 virtual const std::string description() const override
  {return "Initializes a tensor to a scalar value";}

 virtual void pack(BytePacket & packet) override
 {
  appendToBytePacket(&packet,init_val_.real());
  appendToBytePacket(&packet,init_val_.imag());
  return;
 }

 virtual void unpack(BytePacket & packet) override
 {
  double real,imag;
  extractFromBytePacket(&packet,real);
  extractFromBytePacket(&packet,imag);
  init_val_ = std::complex<double>{real,imag};
  return;
 }

 virtual int apply(talsh::Tensor & local_tensor) override;

private:

 std::complex<double> init_val_; //scalar initialization value
};

} //namespace numerics

} //namespace exatn

#endif //EXATN_NUMERICS_FUNCTOR_INIT_VAL_HPP_
