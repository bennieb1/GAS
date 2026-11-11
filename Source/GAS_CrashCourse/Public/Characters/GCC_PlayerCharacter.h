// CopyRight Brandon Marshall 

#pragma once

#include "CoreMinimal.h"
#include "GCC_BaseCharacter.h"
#include "GCC_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class GAS_CRASHCOURSE_API AGCC_PlayerCharacter : public AGCC_BaseCharacter
{
	GENERATED_BODY()

public:

	AGCC_PlayerCharacter();
	
private:
	
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

};
