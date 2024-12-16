// Fill out your copyright notice in the Description page of Project Settings.


#include "ImGUIActor.h"
#include <imgui.h>
#include <NetImguiModule.h>
#include "Math/Rotator.h"

// Sets default values
AImGUIActor::AImGUIActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AImGUIActor::BeginPlay()
{
	Super::BeginPlay();
	if (clicked) {

	}
}

// Called every frame
void AImGUIActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ImGui::ShowDemoWindow();
	
#if NETIMGUI_ENABLED

	const FString Label = GetActorLabel();

	ImGui::Begin(TCHAR_TO_ANSI(*Label), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::Text("Below are a set of various test tools: ");
	ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
	ImGui::SliderFloat("Scale", &Scale, 0.1f, 5.0f);
	if (ImGui::Button("Spawn Sphere", ImVec2(50.0f, 20.0f)))
		clicked = true;

	//If the scale value has changed, then modify the actor's 3d scale
	if (Scale != OldScale) {
		OldScale = Scale;
		SetActorScale3D(FVector3d{ Scale });
	}

	//if the button has been clicked, spawn an actor at the player's location
	if (clicked)
	{
		ImGui::SameLine();
		ImGui::Text("Thanks for clicking me!");

		GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation());
		clicked = false;
	}

	ImGui::End();


#endif

}

