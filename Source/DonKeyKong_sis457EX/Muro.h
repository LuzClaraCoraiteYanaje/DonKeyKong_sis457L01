// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro.generated.h"

UCLASS()
class DONKEYKONG_SIS457EX_API AMuro : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMuro();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UStaticMeshComponent* MeshMuro;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//class UBoxComponent* ParedCollision;

	//UFUNCTION()
	//virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//virtual void Mensaje()

};
