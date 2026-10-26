BOOL __usercall sub_4D5885@<eax>(const char *a1@<eax>)
{
  const char *v1; // ecx
  const char *v2; // eax
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+0h] [ebp-154h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-144h] BYREF
  CHAR CommandLine[256]; // [esp+54h] [ebp-100h] BYREF

  v1 = a1;
  if ( !a1 )
    v1 = byte_5EA438;
  v2 = (const char *)dword_7CEA18;
  if ( !dword_7CEA18 )
    v2 = byte_5EA438;
  sub_58815F(CommandLine, "\"%s\" %s", v2, v1);
  memset(&StartupInfo, 0, sizeof(StartupInfo));
  StartupInfo.cb = 68;
  return CreateProcessA(0, CommandLine, 0, 0, 0, 0x20u, 0, 0, &StartupInfo, &ProcessInformation);
}
