// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroCongelado.h"

AMuroCongelado::AMuroCongelado()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		MeshMuro->SetStaticMesh(MuroLadrilloAsset.Object);
	}
}

void AMuroCongelado::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroCongelado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
