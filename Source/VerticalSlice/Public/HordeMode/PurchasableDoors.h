// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GM_HordeMode.h"
#include "../VerticalSliceCharacter.h"
#include "../interactableVolume.h"
#include "PurchasableDoors.generated.h"

class UTextRenderComponent;

UCLASS()
class VERTICALSLICE_API APurchasableDoors : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* DoorMesh;
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere)
		AInteractableVolume* Interactable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextRenderComponent* Text;

	// Sets default values for this actor's properties
	APurchasableDoors();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float fDoorCost;

	void CanPurchase();
	void ConfirmPurchase(AGM_HordeMode* const& GameMode);
	void SetDoorCost(float _newCost);
	UFUNCTION()
		void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
