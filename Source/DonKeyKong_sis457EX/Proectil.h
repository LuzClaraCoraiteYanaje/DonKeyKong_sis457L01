// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proectil.generated.h"

UCLASS()
class DONKEYKONG_SIS457EX_API AProectil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProectil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* ProjectileMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UProjectileMovementComponent* ProjectileMovement;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
