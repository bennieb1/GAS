// CopyRight Brandon Marshall 


#include "Player/GCC_PlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

void AGCC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* InPutSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if(!IsValid(InPutSubsystem)) return;
	
	for (UInputMappingContext* Context : InputMappingContexts)
	{
			
		InPutSubsystem->AddMappingContext(Context, 0);
			
	}
	

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent)) return;
	
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	// EnhancedInputComponent->BindAction(PrimaryAbilityAction, ETriggerEvent::Started, this, &ThisClass::Primary);

}

void AGCC_PlayerController::Jump()
{
	
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->Jump();
	
}

void AGCC_PlayerController::StopJumping()
{
	
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->StopJumping();
	
}

void AGCC_PlayerController::Move(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn())) return;
	
	const FVector2D MovementVector = Value.Get<FVector2D>();
	
	//Find out which way is forward
	
	const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection, MovementVector.X);
	
}

void AGCC_PlayerController::Look(const FInputActionValue& Value)
{
	
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
	
	
}

// void AGCC_PlayerController::Primary()
// {
// 	
// 	UE_LOG(LogTemp, Log, TEXT("Primary Ability Pressed"));
// 	
// }
