// CopyRight Brandon Marshall 


#include "GAS_CrashCourse/Public/Characters/GCC_BaseCharacter.h"


// Sets default values
AGCC_BaseCharacter::AGCC_BaseCharacter()
{
	
	PrimaryActorTick.bCanEverTick = false;
	
	//Tick and Refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	
}



