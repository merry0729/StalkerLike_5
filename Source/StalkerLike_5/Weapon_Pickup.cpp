// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon_Pickup.h"
#include "Components/BoxComponent.h"

// Sets default values
AWeapon_Pickup::AWeapon_Pickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	CollisionBox->SetCollisionProfileName(TEXT("OverlapAll"));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AWeapon_Pickup::OnPickup);
	RootComponent = CollisionBox;

	Weapon = nullptr;

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

void AWeapon_Pickup::OnPickup(
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{

}

//void AWeapon_Pickup::OnPickup(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//    if (OtherActor && (OtherActor != this) && OtherComp)
//    {
//         Check if the overlapping actor is the player (or any specific class)
//         Example: if (OtherActor->IsA(AMyCharacter::StaticClass()))
//         {
//             AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
//             if (MyCharacter)
//             {
//                 // Spawn the weapon for the character
//                 MyCharacter->AddWeapon(Weapon);
//                 Destroy();
//             }
//         }
//    }
//}
