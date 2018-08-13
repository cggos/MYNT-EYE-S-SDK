// Copyright 2018 Slightech Co., Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef MYNTEYE_DISPARITY_PROCESSOR_H_  // NOLINT
#define MYNTEYE_DISPARITY_PROCESSOR_H_
#pragma once

#include <string>

#include <opencv2/calib3d/calib3d.hpp>

#include "api/processor/processor.h"

namespace cv {

class StereoBM;

}  // namespace cv

MYNTEYE_BEGIN_NAMESPACE

class DisparityProcessor : public Processor {
 public:
  static const char NAME[];

  explicit DisparityProcessor(std::int32_t proc_period = 0);
  virtual ~DisparityProcessor();

  std::string Name() override;

 protected:
  Object *OnCreateOutput() override;
  bool OnProcess(
      Object *const in, Object *const out, Processor *const parent) override;

 private:
  cv::Ptr<cv::StereoBM> bm_;
};

MYNTEYE_END_NAMESPACE

#endif  // MYNTEYE_DISPARITY_PROCESSOR_H_  NOLINT
