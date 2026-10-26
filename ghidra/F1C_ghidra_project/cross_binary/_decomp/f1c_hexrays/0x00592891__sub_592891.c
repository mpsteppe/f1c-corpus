// f1c  0x00592891  size=147
int __cdecl sub_592891(int a1)
{
  int v1; // esi
  void *v2; // eax
  DWORD LastError; // esi

  if ( a1 < uNumber )
  {
    v1 = 36 * (a1 & 0x1F);
    if ( (*(_BYTE *)(dword_8D4920[a1 >> 5] + v1 + 4) & 1) != 0 )
    {
      sub_595A61(a1);
      if ( (*(_BYTE *)(dword_8D4920[a1 >> 5] + v1 + 4) & 1) != 0 )
      {
        v2 = (void *)sub_595A1F(a1);
        if ( FlushFileBuffers(v2) )
          LastError = 0;
        else
          LastError = GetLastError();
        if ( !LastError )
          goto LABEL_10;
        *(_DWORD *)sub_58AFD8() = LastError;
      }
      *(_DWORD *)sub_58AFCF() = 9;
      LastError = -1;
LABEL_10:
      sub_595AC0(a1);
      return LastError;
    }
  }
  *(_DWORD *)sub_58AFCF() = 9;
  return -1;
}
