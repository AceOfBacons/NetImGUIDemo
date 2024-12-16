// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImGUIActor.generated.h"

UCLASS()
class NETIMGUIDEMO_API AImGUIActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AImGUIActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float Scale = 1.0f;
	float OldScale = 1.0f;
	bool clicked = false;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> ActorToSpawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
