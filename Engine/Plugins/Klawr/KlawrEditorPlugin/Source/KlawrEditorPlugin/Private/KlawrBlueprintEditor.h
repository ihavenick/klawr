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
#pragma once

#include "Editor/Kismet/Public/BlueprintEditor.h"
#include "BlueprintEditorModes.h"

/**
 * @brief Editor for Klawr Blueprints.
 * Currently the only difference between this editor and the standard Blueprint editor is that
 * this editor only allows the user to access the Defaults page, the Components and Graph pages
 * are currently inaccessible.
 */
class FKlawrBlueprintEditor : public FBlueprintEditor
{
public:
	typedef FBlueprintEditor Super;

	virtual ~FKlawrBlueprintEditor() {}

	void InitBlueprintEditor(
		const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost,
		const TArray<UBlueprint*>& InBlueprints
	)
	{
		Super::InitBlueprintEditor(Mode, InitToolkitHost, InBlueprints, true);
	}

protected:
	virtual void AddApplicationMode(FName ModeName, TSharedRef<FApplicationMode> Mode) override
	{
		if (ModeName == FBlueprintEditorApplicationModes::BlueprintDefaultsMode)
		{
			FBlueprintEditor::AddApplicationMode(ModeName, Mode);
		}
	}
};
