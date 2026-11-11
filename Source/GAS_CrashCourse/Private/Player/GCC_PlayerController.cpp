// CopyRight Brandon Marshall 


#include "Player/GCC_PlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "GameplayTags/GCC_Tags.h"

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
	EnhancedInputComponent->BindAction(PrimaryAbilityAction, ETriggerEvent::Started, this, &ThisClass::Primary);
	EnhancedInputComponent->BindAction(SecondaryAbilityAction, ETriggerEvent::Started, this, &ThisClass::Secondary);
	EnhancedInputComponent->BindAction(TertiaryAbilityAction, ETriggerEvent::Started, this, &ThisClass::Tertiary);

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

void AGCC_PlayerController::Primary()
{
	
	ActivateAbility(GCCTags::GCCAbilites::Primary);
	
}

void AGCC_PlayerController::Secondary()
{
	
	ActivateAbility(GCCTags::GCCAbilites::Secondary);
	
}

void AGCC_PlayerController::Tertiary()
{
	
	ActivateAbility(GCCTags::GCCAbilites::Tertiary);
	
}

void AGCC_PlayerController::ActivateAbility(const FGameplayTag& AbilityTag) const
{
	
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn());
	
	if (!IsValid(ASC)) return;

	ASC->TryActivateAbilitiesByTag(AbilityTag.GetSingleTagContainer());

}
