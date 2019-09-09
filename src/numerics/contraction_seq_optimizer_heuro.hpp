/** ExaTN::Numerics: Tensor contraction sequence optimizer: Heuristics
REVISION: 2019/09/09

Copyright (C) 2018-2019 Dmitry I. Lyakh (Liakh)
Copyright (C) 2018-2019 Oak Ridge National Laboratory (UT-Battelle) **/

/** Rationale:
**/

#ifndef EXATN_NUMERICS_CONTRACTION_SEQ_OPTIMIZER_HEURO_HPP_
#define EXATN_NUMERICS_CONTRACTION_SEQ_OPTIMIZER_HEURO_HPP_

#include "contraction_seq_optimizer.hpp"

namespace exatn{

namespace numerics{

class ContractionSeqOptimizerHeuro: public ContractionSeqOptimizer{

public:

 virtual double determineContractionSequence(const TensorNetwork & network,
                                             std::list<ContrTriple> & contr_seq,
                                             unsigned int intermediate_num_begin) override;

 static std::unique_ptr<ContractionSeqOptimizer> createNew();
};

} //namespace numerics

} //namespace exatn

#endif //EXATN_NUMERICS_CONTRACTION_SEQ_OPTIMIZER_HEURO_HPP_