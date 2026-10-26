int __cdecl _resetstkoflw()
{
  unsigned int v0; // kr00_4
  int v1; // eax
  char *AllocationBase; // ebx
  char *v3; // edi
  char *v4; // esi
  char v6[12]; // [esp+0h] [ebp-58h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [esp+Ch] [ebp-4Ch] BYREF
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+30h] [ebp-28h] BYREF
  DWORD flOldProtect; // [esp+4Ch] [ebp-Ch] BYREF
  SIZE_T dwSize; // [esp+50h] [ebp-8h]
  LPCVOID lpAddress; // [esp+54h] [ebp-4h]

  sub_631BD0(4u, v6[0]);
  if ( !VirtualQuery(v6, &Buffer, 0x1Cu) )
    return 0;
  AllocationBase = (char *)Buffer.AllocationBase;
  GetSystemInfo(&SystemInfo);
  v0 = __readeflags();
  v1 = *(_DWORD *)((char *)off_16C6D9C + (_DWORD)off_16F1852);
  __writeeflags(v0);
  v3 = (char *)(((unsigned int)v6 & ~(SystemInfo.dwPageSize - 1)) - SystemInfo.dwPageSize);
  v4 = &AllocationBase[SystemInfo.dwPageSize * (v1 != 1 ? 2 : 17)];
  dwSize = SystemInfo.dwPageSize;
  if ( v3 < v4 )
    return 0;
  if ( v1 != 1 )
  {
    lpAddress = AllocationBase;
    while ( VirtualQuery(lpAddress, &Buffer, 0x1Cu) )
    {
      lpAddress = (char *)lpAddress + Buffer.RegionSize;
      if ( (Buffer.State & 0x1000) != 0 )
      {
        lpAddress = Buffer.BaseAddress;
        if ( (Buffer.Protect & 0x100) != 0 )
          return 1;
        if ( v3 >= Buffer.BaseAddress )
        {
          if ( Buffer.BaseAddress < v4 )
            lpAddress = v4;
          VirtualAlloc((LPVOID)lpAddress, dwSize, 0x1000u, 4u);
          v1 = dword_FB8194;
          return VirtualProtect((LPVOID)lpAddress, dwSize, v1 != 1 ? 260 : 1, &flOldProtect);
        }
        return 0;
      }
    }
    return 0;
  }
  lpAddress = (LPCVOID)(((unsigned int)v6 & ~(SystemInfo.dwPageSize - 1)) - SystemInfo.dwPageSize);
  return VirtualProtect((LPVOID)lpAddress, dwSize, v1 != 1 ? 260 : 1, &flOldProtect);
}
