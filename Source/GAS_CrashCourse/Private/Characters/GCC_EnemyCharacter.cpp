// CopyRight Brandon Marshall 


#include "Characters/GCC_EnemyCharacter.h"

#include "AbilitySystemComponent.h"


// Sets default values
AGCC_EnemyCharacter::AGCC_EnemyCharacter()
{
	
	PrimaryActorTick.bCanEverTick = false;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
}

UAbilitySystemComponent* AGCC_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AGCC_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (!IsValid(ASC)) return;
	
	ASC->InitAbilityActorInfo(this, this);
	
	if (!HasAuthority()) return;
	
	GiveStartupAbilities();
	
}



