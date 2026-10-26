BOOL sub_4FE6B0()
{
  const char *v0; // ecx
  const char *v1; // eax
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+0h] [ebp-154h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-144h] BYREF
  char Buffer[256]; // [esp+54h] [ebp-100h] BYREF

  v0 = dword_766B44;
  if ( !dword_766B44 )
    v0 = &byte_629120;
  v1 = (const char *)dword_766B28;
  if ( !dword_766B28 )
    v1 = &byte_629120;
  sprintf(Buffer, "\"%s\" %s", v1, v0);
  memset(&StartupInfo, 0, sizeof(StartupInfo));
  StartupInfo.cb = 68;
  return CreateProcessA(0, Buffer, 0, 0, 0, 0x20u, 0, 0, &StartupInfo, &ProcessInformation);
}
