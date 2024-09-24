// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoCubo.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Proectil.h"
#include  "Plataforma.h"

// Sets default values
AEnemigoCubo::AEnemigoCubo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	MeshCubo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshCubo->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshCubo;

	Fire = FVector(0.f, 90.f, 0.f);
	FireRate = 0.5f;
	bCanFire = true;

	// valores para el movimiento

	Movimiento = FVector(0.0f, 50.0f, 0.0f);
}

// Called when the game starts or when spawned
void AEnemigoCubo::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemigoCubo::Desaparecer, 15.0f, false);
	
}

// Called every frame
void AEnemigoCubo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FireShot();

	// Movimiento 
	/*FVector NuevaPosicion = GetActorLocation() + Movimiento * DeltaTime;
	SetActorLocation(NuevaPosicion);*/

	// Obtener la plataforma donde está el cubo (esto puede ser una referencia que se haya asignado cuando se spawnean los cubos)
	APlataforma* PlataformaActual = Cast<APlataforma>(GetAttachParentActor()); // Asegúrate de que el cubo esté adjunto a la plataforma.

	if (PlataformaActual)
	{
		// Obtener la inclinación de la plataforma
		FRotator PlataformaRotacion = PlataformaActual->GetActorRotation();

		// Convertir la rotación a un vector de dirección
		FVector DireccionMovimiento = FRotationMatrix(PlataformaRotacion).GetUnitAxis(EAxis::Y); // X o el eje que necesites

		// Escalar el movimiento para que sea acorde a la inclinación
		Movimiento = DireccionMovimiento * 100.0f; // Ajustar este valor según la velocidad deseada

		// Aplicar el movimiento en la dirección de la inclinación
		FVector NuevaPosicion = GetActorLocation() + Movimiento * DeltaTime;
		SetActorLocation(NuevaPosicion);
	}

}
//
//void AEnemigoCubo::FireShot()
//{
//	if (bCanFire == true) {
//		FVector DirectionRight = FVector(0.f, -1.f, 0.f);
//		FVector DirectionLeft = FVector(0.f, 1.f, 0.f);
//		const FRotator FireRotationRight = DirectionRight.Rotation();
//		const FRotator FireRotationLeft = DirectionLeft.Rotation();
//		const FVector SpawnLocationRight = GetActorLocation() + FireRotationRight.RotateVector(Fire);
//		const FVector SpawnLocationLeft = GetActorLocation() + FireRotationLeft.RotateVector(Fire);
//		UWorld* const World1 = GetWorld();
//		if (World1 != nullptr) {
//			//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Spawneo")));
//			World1->SpawnActor<AProectil>(SpawnLocationRight, FireRotationRight);
//			World1->SpawnActor<AProectil>(SpawnLocationLeft, FireRotationLeft);
//		}
//		bCanFire = false;
//		World1->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoCubo::ShotTimer, FireRate);
//	}
//}
void AEnemigoCubo::FireShot()
{
	if (bCanFire == true)
	{
		// Generar una dirección aleatoria en el espacio 3D
		FVector DireccionAleatoria = FVector(
			FMath::RandRange(-1.0f, 1.0f),  // Componente X
			FMath::RandRange(-1.0f, 1.0f),  // Componente Y
			FMath::RandRange(-1.0f, 1.0f)   // Componente Z
		).GetSafeNormal(); // Asegurarse de que la dirección sea de longitud 1

		// Convertir la dirección aleatoria en una rotación
		FRotator RotacionAleatoria = DireccionAleatoria.Rotation();

		// Calcular la ubicación de spawn para el proyectil
		FVector SpawnLocation = GetActorLocation() + RotacionAleatoria.RotateVector(Fire);

		UWorld* const World1 = GetWorld();
		if (World1 != nullptr)
		{
			// Disparar el proyectil en la dirección aleatoria
			World1->SpawnActor<AProectil>(SpawnLocation, RotacionAleatoria);
		}

		// Deshabilitar disparos hasta que se cumpla el tiempo de recarga
		bCanFire = false;
		World1->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoCubo::ShotTimer, FireRate);
	}
}


void AEnemigoCubo::ShotTimer()
{
	bCanFire = true;

}

void AEnemigoCubo::Desaparecer()
{

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemigoCubo::Reaparecer, 5.0f, false);
}

//void AEnemigoCubo::Reaparecer()
//{
//	FVector NuevaPosicion = FVector(1180.0f, FMath::RandRange(-1000.0f, 1000.0f), GetActorLocation().Z);
//	SetActorLocation(NuevaPosicion);
//	SetActorHiddenInGame(false);
//	SetActorEnableCollision(true);
//	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemigoCubo::Desaparecer, 15.0f, false);
//}
void AEnemigoCubo::Reaparecer()
{
	// Obtener la plataforma a la que el cubo está adjunto
	APlataforma* PlataformaActual = Cast<APlataforma>(GetAttachParentActor());

	if (PlataformaActual)
	{
		// Obtener la posición y rotación de la plataforma
		FVector PlataformaPosicion = PlataformaActual->GetActorLocation();
		FRotator PlataformaRotacion = PlataformaActual->GetActorRotation();

		// Generar un desplazamiento aleatorio en el eje Y (o X, dependiendo de la disposición de las plataformas)
		float DesplazamientoAleatorio = FMath::RandRange(-400.0f, 400.0f);

		// Calcular la nueva posición, aleatoria en el eje Y y 10 unidades más arriba en el eje Z
		FVector NuevaPosicion = PlataformaPosicion + FVector(0.0f, DesplazamientoAleatorio, 40.0f);

		// Aplicar la nueva posición y la rotación de la plataforma al cubo
		SetActorLocationAndRotation(NuevaPosicion, PlataformaRotacion);
	}

	// Volver a hacer visible y habilitar la colisión
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	// Reiniciar el temporizador para desaparecer de nuevo
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemigoCubo::Desaparecer, 15.0f, false);
}


