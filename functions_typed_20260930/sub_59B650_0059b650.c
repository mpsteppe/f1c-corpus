int __cdecl sub_59B650(int a1)
{
  int v1; // esi
  char v2; // bl
  int v3; // edi
  HANDLE v4; // eax
  DWORD LastError; // esi
  void *v7; // [esp-18h] [ebp-28h]
  HANDLE CurrentProcess; // [esp-14h] [ebp-24h]
  HANDLE TargetHandle; // [esp+Ch] [ebp-4h] BYREF

  if ( a1 < uNumber && (v1 = 36 * (a1 & 0x1F), (*(_BYTE *)(dword_8D4920[a1 >> 5] + v1 + 4) & 1) != 0) )
  {
    CriticalSectionEnterWithLazyInit(a1);
    v2 = *(_BYTE *)(dword_8D4920[a1 >> 5] + v1 + 4);
    v3 = sub_595801();
    if ( v3 == -1 )
    {
      *(_DWORD *)TLSOffsetGetter() = 24;
      *(_DWORD *)TLSOffsetGetter_afd8() = 0;
      FileCriticalSectionLeave(a1);
    }
    else
    {
      CurrentProcess = GetCurrentProcess();
      v7 = (void *)sub_595A1F(a1);
      v4 = GetCurrentProcess();
      if ( DuplicateHandle(v4, v7, CurrentProcess, &TargetHandle, 0, 1, 2u) )
      {
        sub_595924(v3, TargetHandle);
        LastError = 0;
      }
      else
      {
        LastError = GetLastError();
      }
      FileCriticalSectionLeave(v3);
      FileCriticalSectionLeave(a1);
      if ( !LastError )
      {
        *(_BYTE *)(dword_8D4920[v3 >> 5] + 36 * (v3 & 0x1F) + 4) = v2 & 0xEF;
        return v3;
      }
      ErrorIDLookupTable(LastError);
    }
  }
  else
  {
    *(_DWORD *)TLSOffsetGetter() = 9;
    *(_DWORD *)TLSOffsetGetter_afd8() = 0;
  }
  return -1;
}

