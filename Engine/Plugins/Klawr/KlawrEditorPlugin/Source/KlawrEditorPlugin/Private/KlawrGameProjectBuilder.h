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

namespace Klawr {

/**
 * Utility functions to generate and build a VS project containing user provided C# scripts.
 * FIXME: This should be a singleton instead of a bunch of static functions.
 */
class FGameProjectBuilder
{
public:
	/** Get the path to the game scripts .csproj file. */
	static const FString& GetProjectFilename();
	static bool GenerateProject();
	/**
	 * Add the given source file to the .csproj.
	 * @return true if the project file was modified, false otherwise
	 */
	static bool AddSourceFileToProject(const FString& SourceFilename);
	/**
	 * Add the given source files to the .csproj.
	 * @return true if the project file was modified, false otherwise
	 */
	static bool AddSourceFilesToProject(const TArray<FString>& SourceFiles);
	static FString GetTemplatesDir();
	static void GetSourceDirs(TArray<FString>& SourceDirs);
	static const FString& GetProjectRootNamespace();
	static const FString& GetProjectAssemblyName();
	static const FString& GetProjectAssemblyFilename();
	static const FString& GetOutputDir();
	static bool BuildProject(FFeedbackContext* Warn);
	/** Copy private referenced assemblies to a location they can be loaded from at runtime. */
	static void CopyPrivateReferencedAssemblies();
};

} // Klawr
