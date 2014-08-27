//-------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2014 Vadim Macagon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-------------------------------------------------------------------------------

#include "KlawrEditorPluginPrivatePCH.h"
#include "KlawrBlueprintCompiler.h"
#include "KlawrBlueprintGeneratedClass.h"
#include "KismetReinstanceUtilities.h"

namespace Klawr {

FBlueprintCompiler::FBlueprintCompiler(
	UKlawrBlueprint* Source, FCompilerResultsLog& OutResultsLog,
	const FKismetCompilerOptions& CompilerOptions, TArray<UObject*>* ObjLoaded
)	: Super(Source, OutResultsLog, CompilerOptions, ObjLoaded)
{
}

FBlueprintCompiler::~FBlueprintCompiler()
{
}

void FBlueprintCompiler::Compile()
{
	// TODO: create script context

	Super::Compile();
}

void FBlueprintCompiler::SpawnNewClass(const FString& NewClassName)
{
	Super::NewClass = FindObject<UKlawrBlueprintGeneratedClass>(
		Super::Blueprint->GetOutermost(), *NewClassName
	);
	
	if (Super::NewClass)
	{
		FBlueprintCompileReinstancer Reinstancer(Super::NewClass);
	}
	else
	{
		Super::NewClass = ConstructObject<UKlawrBlueprintGeneratedClass>(
			UKlawrBlueprintGeneratedClass::StaticClass(), Super::Blueprint->GetOutermost(),
			FName(*NewClassName), RF_Public | RF_Transactional
		);
	}
}

void FBlueprintCompiler::EnsureProperGeneratedClass(UClass*& GeneratedClass)
{
	if (GeneratedClass && Cast<UObject>(GeneratedClass)->IsA<UKlawrBlueprintGeneratedClass>())
	{
		FKismetCompilerUtilities::ConsignToOblivion(
			GeneratedClass, Super::Blueprint->bIsRegeneratingOnLoad
		);
		GeneratedClass = nullptr;
	}
}

void FBlueprintCompiler::CleanAndSanitizeClass(UBlueprintGeneratedClass* ClassToClean, UObject*& OldCDO)
{
	Super::CleanAndSanitizeClass(ClassToClean, OldCDO);

	check(ClassToClean == Super::NewClass);
}

void FBlueprintCompiler::FinishCompilingClass(UClass* GeneratedClass)
{
	Super::FinishCompilingClass(GeneratedClass);
}

bool FBlueprintCompiler::ValidateGeneratedClass(UBlueprintGeneratedClass* GeneratedClass)
{
	return Super::ValidateGeneratedClass(GeneratedClass)
		&& UKlawrBlueprint::ValidateGeneratedClass(GeneratedClass);
}

} // namespace Klawr
