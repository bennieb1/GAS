// CopyRight Brandon Marshall 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "GCC_PlayerState.generated.h"


class UAbilitySystemComponent;

UCLASS()
class GAS_CRASHCOURSE_API AGCC_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	
	AGCC_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	
private:
	
	UPROPERTY(VisibleAnywhere, Category = "Crash|Abilites")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
