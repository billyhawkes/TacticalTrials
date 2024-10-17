// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FIntValueChanged, int, OldValue, int, NewValue, int, MaxValue);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TACTICALTRIALS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	UHealthComponent();

public:
	UFUNCTION(BlueprintCallable, Category="Health")
	void SetHealth(float Value);

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetHealth();

	UFUNCTION(BlueprintCallable, Category="Health")
	void TakeDamage(int Value);

	UPROPERTY(BlueprintAssignable, Category="Health")
	FOnDeath OnDeath;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FIntValueChanged OnHealthChange;
	
private:
	UPROPERTY()
	int MaxHealth = 100;
	UPROPERTY(EditDefaultsOnly, Category="Health")
	int Health = 100;

	UPROPERTY()
	bool bIsDead = false;

	
};
