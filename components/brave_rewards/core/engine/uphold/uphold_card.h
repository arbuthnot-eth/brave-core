/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_REWARDS_CORE_ENGINE_UPHOLD_UPHOLD_CARD_H_
#define BRAVE_COMPONENTS_BRAVE_REWARDS_CORE_ENGINE_UPHOLD_UPHOLD_CARD_H_

#include <string>

#include "base/functional/callback_forward.h"
#include "base/memory/raw_ref.h"
#include "brave/components/brave_rewards/core/engine/endpoint/uphold/uphold_server.h"
#include "brave/components/brave_rewards/core/mojom/rewards.mojom.h"

namespace brave_rewards::internal {
class RewardsEngine;

namespace uphold {

inline constexpr char kCardName[] = "Brave Browser";

using CreateCardCallback =
    base::OnceCallback<void(mojom::Result, std::string&& id)>;

class UpholdCard {
 public:
  explicit UpholdCard(RewardsEngine& engine);

  ~UpholdCard();

  void CreateBATCardIfNecessary(const std::string& access_token,
                                CreateCardCallback) const;

 private:
  void OnGetBATCardId(CreateCardCallback,
                      const std::string& access_token,
                      mojom::Result,
                      std::string&& id) const;

  void OnCreateBATCard(CreateCardCallback,
                       const std::string& access_token,
                       mojom::Result,
                       std::string&& id) const;

  void OnUpdateBATCardSettings(CreateCardCallback,
                               std::string&& id,
                               mojom::Result) const;

  const raw_ref<RewardsEngine> engine_;
  endpoint::UpholdServer uphold_server_;
};

}  // namespace uphold
}  // namespace brave_rewards::internal
#endif  // BRAVE_COMPONENTS_BRAVE_REWARDS_CORE_ENGINE_UPHOLD_UPHOLD_CARD_H_
