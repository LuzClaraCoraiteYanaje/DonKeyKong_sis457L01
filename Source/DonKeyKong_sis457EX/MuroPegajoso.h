// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroPegajoso.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_SIS457EX_API AMuroPegajoso : public AMuro
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UParticleSystemComponent* ParticleSystem;

public:
	AMuroPegajoso();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
