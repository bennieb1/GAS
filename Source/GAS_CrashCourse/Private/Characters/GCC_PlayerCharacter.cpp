// CopyRight Brandon Marshall 


#include "GAS_CrashCourse/Public/Characters/GCC_PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/GCC_PlayerState.h"


AGCC_PlayerCharacter::AGCC_PlayerCharacter()
{
	
	PrimaryActorTick.bCanEverTick = false;
	
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 500.0f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.0f;
	CameraBoom->bUsePawnControlRotation = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	
}

UAbilitySystemComponent* AGCC_PlayerCharacter::GetAbilitySystemComponent() const
{
	AGCC_PlayerState* GCCPlayerState  = Cast<AGCC_PlayerState>(GetPlayerState());
	if (!IsValid(GCCPlayerState )) return nullptr;
	
	return GCCPlayerState ->GetAbilitySystemComponent();
}

void AGCC_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (!IsValid(ASC)) return;
    
	ASC->InitAbilityActorInfo(GetPlayerState(), this);

	if (HasAuthority())
	{
		GiveStartupAbilities();
	}
}

void AGCC_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (!IsValid(ASC)) return;
    
	ASC->InitAbilityActorInfo(GetPlayerState(), this);
	
}

