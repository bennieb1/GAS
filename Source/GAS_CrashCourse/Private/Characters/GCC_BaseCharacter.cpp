// CopyRight Brandon Marshall 


#include "GAS_CrashCourse/Public/Characters/GCC_BaseCharacter.h"
#include "AbilitySystemComponent.h"


// Sets default values
AGCC_BaseCharacter::AGCC_BaseCharacter()
{
	
	PrimaryActorTick.bCanEverTick = false;
	
	//Tick and Refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	
}

void AGCC_BaseCharacter::GiveStartupAbilities()
{
	
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	for (const auto& Ability : StartupAbilities)
	{
		
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
		
	}
	
}



