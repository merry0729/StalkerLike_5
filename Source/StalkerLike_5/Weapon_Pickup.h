// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_Pickup.generated.h"

UCLASS()
class STALKERLIKE_5_API AWeapon_Pickup : public AActor
{
	GENERATED_BODY()
	
public:
    // Sets default values for this actor's properties
    AWeapon_Pickup();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Function to handle pickup
    UFUNCTION()
    void OnPickup(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // Collider for pickup
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
    class UBoxComponent* PickupCollider;

    // Mesh for the weapon
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
    class UStaticMeshComponent* WeaponMesh;
};