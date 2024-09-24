// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonKeyKong_sis457EXGameMode.h"
#include "DonKeyKong_sis457EXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Plataforma.h"
#include "Proectil.h"
#include "EnemigoCubo.h"
#include "MuroElectrico.h"
#include "MuroExplosivo.h"
#include "MuroLadrillo.h"
#include "MuroPegajoso.h"

ADonKeyKong_sis457EXGameMode::ADonKeyKong_sis457EXGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADonKeyKong_sis457EXGameMode::BeginPlay()
{
    Super::BeginPlay();

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Actor Spawning"));

    // Inicializar las variables
    FVector posicionInicial = FVector(1180.0, -819.9, 760.0);
    FRotator rotacionInicial = FRotator(0.0f, 0.0f, 5.0f);
    FTransform SpawnLocationCP;

    float anchoComponentePlataforma = 600.0f;
    float incrementoAltoComponentePlataforma = -50.0f;
    float incrementoAltoEntrePisos = 900.0f;
    float incrementoInicioPiso = 500.0f;

    for (int npp = 0; npp < 7; npp++) {
        if (npp >= 0 && npp <= 4) {
            rotacionInicial.Roll = rotacionInicial.Roll * -1;
            incrementoInicioPiso = incrementoInicioPiso * -1;
            incrementoAltoComponentePlataforma = incrementoAltoComponentePlataforma * -1;
            SpawnLocationCP.SetRotation(FQuat(rotacionInicial));

            TArray<APlataforma*> componentesPlataforma;

            for (int ncp = 0; ncp < 8; ncp++) {
                // Actualizar la ubicación de SpawnLocationCP
                SpawnLocationCP.SetLocation(FVector(posicionInicial.X, posicionInicial.Y + anchoComponentePlataforma * ncp, posicionInicial.Z));

                APlataforma* nuevaPlataforma = GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), SpawnLocationCP);
                componentesPlataforma.Add(nuevaPlataforma);

                if (ncp == 7 ){
                    nuevaPlataforma->SetMovementType(1);  // Movimiento horizontal de derecha a izquierda
                   
                }
                if (ncp == 2) {
                    nuevaPlataforma->SetMovementType(2);  // Movimiento vertical
                }
                else {
                    nuevaPlataforma->SetMovementType(0);  // Movimiento horizontal o cualquier otro movimiento que tengas implementado
                }

                if (ncp < 6) {
                    posicionInicial.Z = posicionInicial.Z + incrementoAltoComponentePlataforma;
                }
            }

            // Agregar el array de componentes al TArray
            plataformasPorPiso.Add(componentesPlataforma);

            posicionInicial.Z = posicionInicial.Z + incrementoAltoEntrePisos;
            posicionInicial.Y = posicionInicial.Y + incrementoInicioPiso;
        }
    }


    SpawnCubosEnemigos();
    SpawClasesHijas();
    MoverJugadorALaUltimaPlataforma();
}


void ADonKeyKong_sis457EXGameMode::Tick(float DeltaTime)
{


    Super::Tick(DeltaTime);

  /* for (auto& Elem : plataformasPorPiso)
    {
        if (Elem.Value)
        {
            Elem.Value->MovePlatform(DeltaTime);
        }
    }*/
}

void ADonKeyKong_sis457EXGameMode::SpawnCubosEnemigos()
{

    for (int32 i = 0; i < plataformasPorPiso.Num(); ++i)
    {
        // Accede directamente al array de plataformas por piso
        TArray<APlataforma*>& PlataformasEnPiso = plataformasPorPiso[i];

        if (PlataformasEnPiso.Num() > 0)
        {
            // Seleccionar la plataforma del medio
            int32 PlataformaCentralIndex = PlataformasEnPiso.Num() / 2;
            APlataforma* Plataforma = PlataformasEnPiso[PlataformaCentralIndex];

            FTransform SpawnLocation;
            FVector NewLocation = Plataforma->GetActorLocation();

            // Ajuste para centrar el cubo en el piso
            float PlataformaAncho = 600.0f;  // Ajusta este valor según el ancho real de tus plataformas
            NewLocation.Y += PlataformaAncho / 2.0f;  // Centrar el cubo en el eje Y

            // Elevar el cubo ligeramente por encima de la plataforma
            float Elevacion = 100.0f;  // Ajusta este valor según la altura deseada por encima de la plataforma
            NewLocation.Z += Elevacion;

            // Aplicar la nueva ubicación
            SpawnLocation.SetLocation(NewLocation);
            SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));

            // Spawnear el cubo enemigo
            AEnemigoCubo* NuevoCubo = GetWorld()->SpawnActor<AEnemigoCubo>(AEnemigoCubo::StaticClass(), SpawnLocation);

            if (NuevoCubo)
            {
                NuevoCubo->AttachToActor(Plataforma, FAttachmentTransformRules::KeepWorldTransform);
            }

            CubosEnemigos.Add(NuevoCubo);
        }
    }

}

void ADonKeyKong_sis457EXGameMode::SpawClasesHijas()
{
    UWorld* World = GetWorld();
    if (World)
    {

        FVector  PosicionMuro1 = FVector(1180.0f, -300.0f, 950.0f);
        FVector  PosicionMuro2 = FVector(1180.0f, 569.9, 1490.0f);
        FVector  PosicionMuro3 = FVector(1180.0f, -500.0f, 2020.0f);
        FVector  PosicionMuro4 = FVector(1180.0f, 500.0f, 2630.0f);


        // Spawnear ClaseHija1 en PosicionHija1
        FActorSpawnParameters SpawnParams;
        AMuroElectrico* Hija1 = World->SpawnActor<AMuroElectrico>(AMuroElectrico::StaticClass(), PosicionMuro1, FRotator::ZeroRotator, SpawnParams);

        // Spawnear ClaseHija2 en PosicionHija2
        AMuroLadrillo* Hija2 = World->SpawnActor<AMuroLadrillo>(AMuroLadrillo::StaticClass(), PosicionMuro2, FRotator::ZeroRotator, SpawnParams);
    
        AMuroPegajoso* Hija3 = World->SpawnActor<AMuroPegajoso>(AMuroPegajoso::StaticClass(), PosicionMuro3, FRotator::ZeroRotator, SpawnParams);

        // Spawnear ClaseHija2 en PosicionHija2
        AMuroExplosivo* Hija4 = World->SpawnActor<AMuroExplosivo>(AMuroExplosivo::StaticClass(), PosicionMuro4, FRotator::ZeroRotator, SpawnParams);
    }
}
void ADonKeyKong_sis457EXGameMode::MoverJugadorALaUltimaPlataforma()
{
    //if (plataformasPorPiso.Num() > 0)
    //{
    //    // Obtener el último piso
    //    TArray<APlataforma*>& UltimoPiso = plataformasPorPiso.Last();

    //    if (UltimoPiso.Num() > 0)
    //    {
    //        // Obtener la última plataforma del último piso
    //        APlataforma* UltimaPlataforma = UltimoPiso.Last();

    //        if (UltimaPlataforma)
    //        {
    //            // Obtener la posición de la última plataforma
    //            FVector PosicionUltimaPlataforma = UltimaPlataforma->GetActorLocation();

    //            // Obtener el jugador (Character) y establecer su posición en la plataforma
    //            ADonKeyKong_sis457EXCharacter* Jugador = Cast<ADonKeyKong_sis457EXCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

    //            if (Jugador)
    //            {
    //                // Ajustar la posición del jugador para que esté por encima de la plataforma
    //                FVector NuevaPosicionJugador = PosicionUltimaPlataforma + FVector(0.0f, 0.0f, 150.0f); // Ajuste Z para evitar colisiones
    //                Jugador->SetActorLocation(NuevaPosicionJugador, false, nullptr, ETeleportType::TeleportPhysics);

    //                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Jugador movido a la última plataforma"));
    //            }
    //        }
    //    }
    //}
}
//  // spaneo de cubo
  ///* FTransform SpawnLocation;
  // SpawnLocation.SetLocation(FVector(1180.0, 300.0, 1060.0f));
  /* SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
   Cubo = GetWorld()->SpawnActor<AEnemigoCubo>(AEnemigoCubo::StaticClass(), SpawnLocation);*/


   // FVector BaseLocation = FVector(1180.0f,1550.0f, 1080.0f);
      //float OffsetZ = 900.0f;

      //for (int32 i = 0; i < plataformasPorPiso.Num(); ++i)
      //{
      //    // Accede directamente al array de plataformas por piso
      //    TArray<APlataforma*>& PlataformasEnPiso = plataformasPorPiso[i];

      //    if (PlataformasEnPiso.Num() > 0)
      //    {
      //        APlataforma* Plataforma = PlataformasEnPiso[0];

      //        FTransform SpawnLocation;
      //        FVector NewLocation = Plataforma->GetActorLocation();
      //        NewLocation.Y += 300.0f;
      //        SpawnLocation.SetLocation(NewLocation);
      //        SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));

      //        AEnemigoCubo* NuevoCubo = GetWorld()->SpawnActor<AEnemigoCubo>(AEnemigoCubo::StaticClass(), SpawnLocation);

      //        if (NuevoCubo)
      //        {
      //            NuevoCubo->AttachToActor(Plataforma, FAttachmentTransformRules::KeepWorldTransform);
      //        }

      //        CubosEnemigos.Add(NuevoCubo);
      //    }
      //}

