// CopyRight Brandon Marshall 

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "GCC_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAS_CRASHCOURSE_API AGCC_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	
	virtual void SetupInputComponent() override;
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	

	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Input")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Input")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Input")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Input")
	TObjectPtr<UInputAction> PrimaryAbilityAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Input")
	TObjectPtr<UInputAction> SecondaryAbilityAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Crash|Input")
	TObjectPtr<UInputAction> TertiaryAbilityAction;
	
	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Primary();
	void Secondary();
	void Tertiary();
	void ActivateAbility(const FGameplayTag& AbilityTag) const;
	
};
