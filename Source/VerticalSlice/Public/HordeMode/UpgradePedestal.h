// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GM_HordeMode.h"
#include "../VerticalSliceCharacter.h"
#include "../Mech.h"
#include "../interactableVolume.h"
#include "UpgradePedestal.generated.h"

class AGM_HordeMode;
class UTextRenderComponent;

enum MechUpgrades {
	Boosters,
	Shotgun,
	Dash,
	GroundPound,
	NoChargeRegenDelay,
	HPRegen,
	HPPotion,
	Flamethrower,
	RocketLauncher,
	MaxAmmo,
	MaxHealth,
	RifleDamage,
	RifleReload,
	RifleClipSize,
	RifleReserveAmmo,
	ShotgunDamage,
	ShotgunCharges,
	ShotgunPellets,
	ShotgunRange,
	MechMaxHP,
	MechMaxCharge,
	MechHPRegen,
	MechChargeRegen,
	FlamethrowerDamage,
	FlamethrowerFireDamage,
	RocketAmount,
	RocketRadius
};

UCLASS()
class VERTICALSLICE_API AUpgradePedestal : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* UpgradeMesh;
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere)
		AInteractableVolume* Interactable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextRenderComponent* Text;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Sets default values for this actor's properties
	AUpgradePedestal();
	void SetUpgrade();
private:

	TArray<FString> Upgrades;

	float fUpgradeCost;
	int iCurrentUpgrade;
	bool bSinglePurchase;
	float fBaseCost;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnBoxEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	void PopulateUpgradeArray();
	void CanPurchase();
	void ConfirmPurchase(AGM_HordeMode* const& GameMode);
	void UpgradeMech(int _iChoosenUpgade);
};
