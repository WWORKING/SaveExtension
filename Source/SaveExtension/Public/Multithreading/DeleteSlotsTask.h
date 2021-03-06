// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "FileAdapter.h"
#include "Multithreading/Delegates.h"
#include "SlotInfo.h"

#include <CoreMinimal.h>
#include <Async/AsyncWork.h>


class USaveManager;

/**
 * FDeleteSlotsTask
 * Async task to remove an specific or all slots
 */
class FDeleteSlotsTask : public FNonAbandonableTask {
protected:

	const USaveManager* const Manager = nullptr;
	FString SpecificSlotName;

public:

	bool bSuccess = false;

	/** All infos Constructor */
	explicit FDeleteSlotsTask(const USaveManager* InManager, FName SlotName = {});

	void DoWork();

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FDeleteSlotsTask, STATGROUP_ThreadPoolAsyncTasks);
	}

private:

	USlotInfo* LoadInfoFromFile(const FString Name) const;
};
