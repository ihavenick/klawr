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

#include "ScriptPluginPrivatePCH.h"
#include "KlawrScriptContext.h"

FKlawrContext::FKlawrContext()
{
	ScriptObjectInfo.InstanceID = 0;
}

FKlawrContext::~FKlawrContext()
{
	DestroyScriptObject();
}

bool FKlawrContext::Initialize(const FString& Code, UObject* Owner)
{
	// TODO:
	// [editor-only] save the code out to a file
	// [editor-only][advanced] generate a C# class for each blueprint class in the inheritance hierarchy
	// [editor-only] update the .csproj
	// [editor-only] rebuild the .csproj
	// [editor-only] copy the assembly to a directory in the search path
	// [editor-only] reload the engine app domain

	// create an instance of the managed class
	return Klawr::IClrHost::Get()->CreateScriptObject(TEXT("Klawr.UnrealEngine.TestActor"), Owner, ScriptObjectInfo);
}

void FKlawrContext::DestroyScriptObject()
{
	if (ScriptObjectInfo.InstanceID != 0)
	{
		Klawr::IClrHost::Get()->DestroyScriptObject(ScriptObjectInfo.InstanceID);
		ScriptObjectInfo.InstanceID = 0;
	}
}

void FKlawrContext::BeginPlay()
{
	if (ScriptObjectInfo.BeginPlay)
	{
		ScriptObjectInfo.BeginPlay();
	}
}

void FKlawrContext::Tick(float DeltaTime)
{
	if (ScriptObjectInfo.Tick)
	{
		ScriptObjectInfo.Tick(DeltaTime);
	}
}

void FKlawrContext::Destroy()
{
	// clean up anything created in BeginPlay/Tick
	if (ScriptObjectInfo.Destroy)
	{
		ScriptObjectInfo.Destroy();
	}
	// the managed object will not be accessed from here on, so get rid of it now
	DestroyScriptObject();
}

bool FKlawrContext::CanTick()
{
	return ScriptObjectInfo.Tick != nullptr;
}

bool FKlawrContext::CallFunction(const FString& FunctionName)
{
	// TODO:
	return false;
}

bool FKlawrContext::SetFloatProperty(const FString& PropertyName, float NewValue)
{
	// TODO:
	return false;
}

float FKlawrContext::GetFloatProperty(const FString& PropertyName)
{
	// TODO:
	return 0.0f;
}

bool FKlawrContext::SetIntProperty(const FString& PropertyName, int32 NewValue)
{
	// TODO:
	return false;
}

int32 FKlawrContext::GetIntProperty(const FString& PropertyName)
{
	// TODO:
	return 0;
}

bool FKlawrContext::SetObjectProperty(const FString& PropertyName, UObject* NewValue)
{
	// TODO:
	return false;
}

UObject* FKlawrContext::GetObjectProperty(const FString& PropertyName)
{
	// TODO:
	return nullptr;
}

bool FKlawrContext::SetBoolProperty(const FString& PropertyName, bool NewValue)
{
	// TODO:
	return false;
}

bool FKlawrContext::GetBoolProperty(const FString& PropertyName)
{
	// TODO:
	return false;
}

bool FKlawrContext::SetStringProperty(const FString& PropertyName, const FString& NewValue)
{
	// TODO:
	return false;
}

FString FKlawrContext::GetStringProperty(const FString& PropertyName)
{
	// TODO:
	return FString();
}

void FKlawrContext::InvokeScriptFunction(FFrame& Stack, RESULT_DECL)
{
	P_FINISH;
	CallFunction(Stack.CurrentNativeFunction->GetName());
}

#if WITH_EDITOR
void FKlawrContext::GetScriptDefinedFields(TArray<FScriptField>& OutFields)
{
	// TODO
}
#endif // WITH_EDITOR
