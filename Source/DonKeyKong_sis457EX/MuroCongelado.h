// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroCongelado.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_SIS457EX_API AMuroCongelado : public AMuro
{
	GENERATED_BODY()
	
public:
	AMuroCongelado();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UParticleSystemComponent* ParticleSystem;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
