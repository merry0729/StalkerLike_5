// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon_Pickup.h"
#include "Components/BoxComponent.h"

// Sets default values
AWeapon_Pickup::AWeapon_Pickup()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Create and attach the pickup collider
    PickupCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupCollider"));
    RootComponent = PickupCollider;
    PickupCollider->SetBoxExtent(FVector(50.f, 50.f, 50.f));
    PickupCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    PickupCollider->SetGenerateOverlapEvents(true);
    PickupCollider->SetSimulatePhysics(false);
    PickupCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

    // Create and attach the weapon mesh
    WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
    WeaponMesh->SetupAttachment(PickupCollider);
    WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    WeaponMesh->SetSimulatePhysics(false);

    // Bind the overlap event
    PickupCollider->OnComponentBeginOverlap.AddDynamic(this, &AWeapon_Pickup::OnPickup);
}

// Called when the game starts or when spawned
void AWeapon_Pickup::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AWeapon_Pickup::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Function to handle pickup
void AWeapon_Pickup::OnPickup(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        ACharacter* Character = Cast<ACharacter>(OtherActor);
        if (Character)
        {
            // Add your logic to give the weapon to the character
            // Example: Character->AddWeapon(this);

            // Destroy the pickup actor after it has been picked up
            Destroy();
        }
    }
}