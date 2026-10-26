// f1c  0x0059b650  size=264
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
    sub_595A61(a1);
    v2 = *(_BYTE *)(dword_8D4920[a1 >> 5] + v1 + 4);
    v3 = sub_595801();
    if ( v3 == -1 )
    {
      *(_DWORD *)sub_58AFCF() = 24;
      *(_DWORD *)sub_58AFD8() = 0;
      sub_595AC0(a1);
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
      sub_595AC0(v3);
      sub_595AC0(a1);
      if ( !LastError )
      {
        *(_BYTE *)(dword_8D4920[v3 >> 5] + 36 * (v3 & 0x1F) + 4) = v2 & 0xEF;
        return v3;
      }
      sub_58AF5C(LastError);
    }
  }
  else
  {
    *(_DWORD *)sub_58AFCF() = 9;
    *(_DWORD *)sub_58AFD8() = 0;
  }
  return -1;
}
