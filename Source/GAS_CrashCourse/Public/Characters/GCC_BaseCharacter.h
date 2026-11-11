// CopyRight Brandon Marshall 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/Character.h"
#include "GCC_BaseCharacter.generated.h"

UCLASS(Abstract)
class GAS_CRASHCOURSE_API AGCC_BaseCharacter : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AGCC_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return nullptr; }

protected:
	
	void GiveStartupAbilities();
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;



};
