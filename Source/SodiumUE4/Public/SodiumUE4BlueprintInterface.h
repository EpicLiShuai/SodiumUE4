#pragma once

//#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"
#include "SodiumUE4BlueprintInterface.generated.h"

UCLASS()
class USodiumUE4PluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:


	//////////////////////////////////////////////////////////////////////////
	// Utility methods
	//////////////////////////////////////////////////////////////////////////

	UFUNCTION(BlueprintCallable, Category = "Sodium|Utility")
	static bool SodiumTest();
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Sodium|Utility")
	static TArray<uint8> RandomBytes(int32 len);

	UFUNCTION(BlueprintCallable, Category = "Sodium|Utility")
	static FString ToBase64(TArray<uint8> data);

	UFUNCTION(BlueprintCallable, Category = "Sodium|Utility")
	static FString ToBase64S(FString data);

	UFUNCTION(BlueprintCallable, Category = "Sodium|Utility")
	static TArray<uint8> FromBase64(FString data, bool& success);

	UFUNCTION(BlueprintCallable, Category = "Sodium|Utility")
	static FString FromBase64S(FString data, bool& success);


	//////////////////////////////////////////////////////////////////////////
	// Core functionality
	//////////////////////////////////////////////////////////////////////////

	UFUNCTION(BlueprintCallable, Category = "Sodium|Core")
	static void GenerateKeyPair(TArray<uint8>& publicKey, TArray<uint8>& privateKey);

	UFUNCTION(BlueprintCallable, Category = "Sodium|Core")
	static void EncryptString(FString s, TArray<uint8> publicKey, TArray<uint8>& encrypted, bool& success);

	UFUNCTION(BlueprintCallable, Category = "Sodium|Core")
	static void DecryptString(TArray<uint8> encrypted, TArray<uint8> publicKey, TArray<uint8> privateKey, FString& decrypted, bool& success);


};