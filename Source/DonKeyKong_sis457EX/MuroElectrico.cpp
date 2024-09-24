// Fill out your copyright notice in the Description page of Project Settings.
#include "MuroElectrico.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

AMuroElectrico::AMuroElectrico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		MeshMuro->SetStaticMesh(MuroLadrilloAsset.Object);
	}

}

void AMuroElectrico::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroElectrico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//
//void AMuroElectrico::OnCharacterOverlap(AActor* OverlappedActor, AActor* OtherActor)
//{
//}
//
//void AMuroElectrico::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//
//	if (OtherActor && (OtherActor != this)) {
//		Mensaje();
//	}
//}
//
//void AMuroElectrico::Mensaje()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Emerald,
//		FString::Printf(TEXT("Esta es una pared electrica")));
//}
