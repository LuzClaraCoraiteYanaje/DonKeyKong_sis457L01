// Fill out your copyright notice in the Description page of Project Settings.


#include "Proectil.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProectil::AProectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Projectile(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Projectile"));
	ProjectileMesh->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	ProjectileMesh->SetStaticMesh(Projectile.Object);
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProectil::OnHit);
	SetRootComponent(ProjectileMesh);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement_Projectile"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 2500.f;
	ProjectileMovement->MaxSpeed = 2500.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f;

	InitialLifeSpan = 2.f;

}

// Called when the game starts or when spawned
void AProectil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProectil::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	this->Destroy();
}

