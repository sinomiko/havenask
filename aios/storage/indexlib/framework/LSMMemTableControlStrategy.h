/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <memory>

#include "autil/Log.h"
#include "indexlib/base/MemoryQuotaSynchronizer.h"
#include "indexlib/config/TabletOptions.h"
#include "indexlib/framework/DefaultMemoryControlStrategy.h"
#include "indexlib/framework/TabletInfos.h"
#include "indexlib/framework/TabletMetrics.h"

namespace indexlibv2::framework {

class LSMMemTableControlStrategy : public indexlibv2::framework::DefaultMemoryControlStrategy
{
public:
    LSMMemTableControlStrategy(
        const std::shared_ptr<indexlibv2::config::TabletOptions>& options,
        const std::shared_ptr<indexlibv2::MemoryQuotaSynchronizer>& buildMemoryQuotaSynchronizer);
    ~LSMMemTableControlStrategy();

public:
    indexlibv2::framework::MemoryStatus CheckRealtimeIndexMemoryQuota(
        const std::shared_ptr<indexlibv2::framework::TabletMetrics>& tabletMetrics) const override;
    void SyncMemoryQuota(const std::shared_ptr<indexlibv2::framework::TabletMetrics>& tabletMetrics) override;

private:
    AUTIL_LOG_DECLARE();
};

} // namespace indexlibv2::framework
