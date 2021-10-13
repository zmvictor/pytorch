#pragma once

#include "lazy_tensor_core/csrc/tensor.h"

namespace torch_lazy_tensors {

class LazyGraphExecutor {
 public:
  static LazyGraphExecutor* Get();

  void RegisterTensor(std::shared_ptr<LazyTensor::Data> data);
  void UnregisterTensor(LazyTensor::Data* data);

  // Seed for random generator
  ir::Value GetRngSeed(const Device& device);
  lazy_tensors::uint64 GetRunningSeed(const Device& device);
  void SetRngSeed(const Device& device, lazy_tensors::uint64 seed);

  std::vector<LazyTensor> GetLiveTensors(const Device* device);

  void MarkStep(const Device& device);

 private:
  LazyGraphExecutor() {}
};

}  // namespace torch_lazy_tensors