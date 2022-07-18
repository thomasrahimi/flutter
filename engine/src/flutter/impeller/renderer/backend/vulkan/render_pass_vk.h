// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "flutter/fml/macros.h"
#include "impeller/renderer/render_pass.h"
#include "impeller/renderer/render_target.h"

namespace impeller {

class RenderPassVK final : public RenderPass {
 public:
  // |RenderPass|
  ~RenderPassVK() override;

 private:
  friend class CommandBufferVK;

  RenderPassVK(RenderTarget target);

  // |RenderPass|
  bool IsValid() const override;

  // |RenderPass|
  void OnSetLabel(std::string label) override;

  // |RenderPass|
  bool EncodeCommands(
      const std::shared_ptr<Allocator>& transients_allocator) const override;

  FML_DISALLOW_COPY_AND_ASSIGN(RenderPassVK);
};

}  // namespace impeller
