// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroExplosivo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

AMuroExplosivo::AMuroExplosivo()
{

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		MeshMuro->SetStaticMesh(MuroLadrilloAsset.Object);
	}

}

void AMuroExplosivo::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroExplosivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
