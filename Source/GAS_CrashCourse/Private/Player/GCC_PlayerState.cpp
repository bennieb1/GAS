// CopyRight Brandon Marshall 


#include "Player/GCC_PlayerState.h"
#include "AbilitySystemComponent.h"

AGCC_PlayerState::AGCC_PlayerState()
{
	
	SetNetUpdateFrequency(100.0f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	                      //How the GameplayEffects are replicated to clients, Middle mouse button click to see more info
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
}
