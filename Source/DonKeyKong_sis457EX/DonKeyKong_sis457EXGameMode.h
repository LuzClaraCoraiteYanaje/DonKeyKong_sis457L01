// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonKeyKong_sis457EXGameMode.generated.h"
 

class APlataforma;
class AProectil;
class AEnemigoCubo;

UCLASS(minimalapi)
class ADonKeyKong_sis457EXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonKeyKong_sis457EXGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public: 

	//TMap<int32, TArray<APlataforma*>> plataformasPorPiso;
	TArray<TArray<APlataforma*>> plataformasPorPiso;
//	TMap<int32, APlataforma*> ComponentePlataformaMap;

	//AProectil* Projectile01;
	 
	 AEnemigoCubo* Cubo;
	TArray<AActor*> CubosEnemigos;
	void SpawnCubosEnemigos();
	void SpawClasesHijas();
	void MoverJugadorALaUltimaPlataforma();
		
}; 



