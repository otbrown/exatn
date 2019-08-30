/** ExaTN::Numerics: Tensor operation: Adds a tensor to another tensor
REVISION: 2019/08/30

Copyright (C) 2018-2019 Dmitry I. Lyakh (Liakh)
Copyright (C) 2018-2019 Oak Ridge National Laboratory (UT-Battelle) **/

/** Rationale:
 (a) Adds a tensor to another tensor inside the processing backend.
**/

#ifndef EXATN_NUMERICS_TENSOR_OP_ADD_HPP_
#define EXATN_NUMERICS_TENSOR_OP_ADD_HPP_

#include "tensor_basic.hpp"
#include "tensor_operation.hpp"

namespace exatn{

namespace numerics{

class TensorOpAdd: public TensorOperation{
public:

 TensorOpAdd();

 TensorOpAdd(const TensorOpAdd &) = default;
 TensorOpAdd & operator=(const TensorOpAdd &) = default;
 TensorOpAdd(TensorOpAdd &&) noexcept = default;
 TensorOpAdd & operator=(TensorOpAdd &&) noexcept = default;
 virtual ~TensorOpAdd() = default;

 /** Returns TRUE iff the tensor operation is fully set. **/
 virtual bool isSet() const override;

 /** Accepts tensor node executor which will execute this tensor operation. **/
 virtual int accept(runtime::TensorNodeExecutor & node_executor,
                    runtime::TensorOpExecHandle * exec_handle) override;

 /** Create a new polymorphic instance of this subclass. **/
 static std::unique_ptr<TensorOperation> createNew();

private:

};

} //namespace numerics

} //namespace exatn

#endif //EXATN_NUMERICS_TENSOR_OP_ADD_HPP_
