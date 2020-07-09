#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "QuestStruct.generated.h"

USTRUCT(BlueprintType)
struct FQuestStruct : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString QuestDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ObjectiveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int typeInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UsesValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ObjectiveCompleteValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UsesLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LocationActivationRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasMoreObjectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName NextObjectiveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName NextQuestId;
};