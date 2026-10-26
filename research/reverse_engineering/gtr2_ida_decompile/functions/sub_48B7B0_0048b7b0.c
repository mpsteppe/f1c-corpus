int __thiscall sub_48B7B0(char *lpLibFileName)
{
  HMODULE LibraryA; // eax
  FARPROC NP_GetSignature; // eax
  char v4[200]; // [esp+10h] [ebp-320h] BYREF
  char v5[200]; // [esp+D8h] [ebp-258h] BYREF
  char v6[200]; // [esp+1A0h] [ebp-190h] BYREF
  char v7[200]; // [esp+268h] [ebp-C8h] BYREF

  strcat(lpLibFileName, "NPClient.dll");
  LibraryA = LoadLibraryA(lpLibFileName);
  hModule = LibraryA;
  if ( !LibraryA )
    return 4;
  NP_GetSignature = GetProcAddress(LibraryA, "NP_GetSignature");
  strcpy(
    v4,
    "precise head tracking\n put your head into the game\n now go look around\n\n Copyright EyeControl Technologies");
  strcpy(v5, "hardware camera\n software processing data\n track user movement\n\n Copyright EyeControl Technologies");
  dword_B6D698 = (int)NP_GetSignature;
  if ( !NP_GetSignature || ((int (__stdcall *)(char *))NP_GetSignature)(v6) || strcmp(v4, v6) || strcmp(v5, v7) )
    return 4;
  NP_RegisterWindowHandle = (int (__stdcall *)(_DWORD))GetProcAddress(hModule, "NP_RegisterWindowHandle");
  NP_UnregisterWindowHandle = (int)GetProcAddress(hModule, "NP_UnregisterWindowHandle");
  NP_RegisterProgramProfileID = (int (__stdcall *)(_DWORD))GetProcAddress(hModule, "NP_RegisterProgramProfileID");
  NP_QueryVersion = (int (__stdcall *)(_DWORD))GetProcAddress(hModule, "NP_QueryVersion");
  NP_RequestData = (int (__stdcall *)(_DWORD))GetProcAddress(hModule, "NP_RequestData");
  NP_GetData = (int (__stdcall *)(_DWORD))GetProcAddress(hModule, "NP_GetData");
  NP_StartCursor = (int)GetProcAddress(hModule, "NP_StartCursor");
  NP_StopCursor = (int)GetProcAddress(hModule, "NP_StopCursor");
  NP_ReCenter = GetProcAddress(hModule, "NP_ReCenter");
  NP_StartDataTransmission = GetProcAddress(hModule, "NP_StartDataTransmission");
  NP_StopDataTransmission = GetProcAddress(hModule, "NP_StopDataTransmission");
  return 0;
}
