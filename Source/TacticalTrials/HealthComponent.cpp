// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"


UHealthComponent::UHealthComponent()
{
	MaxHealth = Health;
}

void UHealthComponent::SetHealth(float Value)
{
	if (bIsDead)
	{
		return;
	}
	
	int OldValue = Health;
	Health = Value;

	if (Health <= 0)
	{
		bIsDead = true;
		OnDeath.Broadcast();
	}

	OnHealthChange.Broadcast(OldValue, Health, MaxHealth);
}

float UHealthComponent::GetHealth()
{
	return Health;
}

void UHealthComponent::TakeDamage(int Value)
{
	this->SetHealth(Health-Value);
}
