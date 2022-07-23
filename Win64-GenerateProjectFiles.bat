:: Copyright to Avram Traian. 2022 - 2022.
:: File created on July 22 2022.

@ECHO OFF
PUSHD "%~dp0"

CALL "Moonlit\ThirdParty\premake\Binaries\Win64\premake5.exe" --file="Moonlit/Build/Dev-Workspace.lua" vs2022

POPD
PAUSE