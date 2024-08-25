#pragma once

UENUM(BlueprintType)
enum class EPlayerMovementCPP : uint8
{
	Default UMETA(DisplayName = "DefaultCPP"),
	Idle UMETA(DisplayName = "IdleCPP"),
	Run UMETA(DisplayName = "RunCPP"),
	Jump UMETA(DisplayName = "JumpCPP"),
	Fall UMETA(DisplayName = "FallCPP")
};