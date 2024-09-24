// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values

AMuro::AMuro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshMuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	MeshMuro->SetRelativeScale3D(FVector(3.0f, 0.5f, 2.0f));
	RootComponent = MeshMuro;

	/*ParedCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Pared_collision"));
	ParedCollision->SetVisibility(true);
	ParedCollision->SetRelativeScale3D(FVector(2.f, 4.f, 1.60f));
	ParedCollision->SetCollisionProfileName(TEXT("Triger"));
	ParedCollision->SetupAttachment(GetRootComponent());

	ParedCollision->OnComponentBeginOverlap.AddDynamic(this, &AMuro::OnOverlapBegin);

	InitialLifeSpan = 2.f;*/

}

// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AMuro::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor && (OtherActor != this)) {
//		Mensaje();
//	}
//}
//
//void AMuro::Mensaje()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue,
//		FString::Printf(TEXT("Esta es una pared normal")));
//}

