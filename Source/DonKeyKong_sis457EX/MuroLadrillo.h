// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroLadrillo.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_SIS457EX_API AMuroLadrillo : public AMuro
{
	GENERATED_BODY()

public:
	AMuroLadrillo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UParticleSystemComponent* ParticleSystem;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
