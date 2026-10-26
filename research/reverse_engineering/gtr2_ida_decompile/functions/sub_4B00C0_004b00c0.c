char __thiscall sub_4B00C0(int this)
{
  int v2; // kr00_4
  int v3; // eax
  int v4; // edi
  const char *v5; // eax
  char String2[128]; // [esp+8h] [ebp-80h] BYREF

  *(_BYTE *)(this + 524) = 0;
  if ( sub_436600() )
    sub_617A70(128);
  else
    String2[0] = 0;
  v2 = strlen(String2);
  if ( v2 > 0 && String2[v2 - 1] == 92 )
    String2[v2 - 1] = 0;
  sub_437780();
  sub_437830();
  sub_49D250();
  v3 = *(_DWORD *)(this + 148);
  v4 = 0;
  if ( v3 > 0 )
  {
    while ( 1 )
    {
      v5 = (const char *)sub_4CE2D0(v4);
      if ( v5 )
      {
        if ( !_stricmp(v5, String2) )
          break;
      }
      v3 = *(_DWORD *)(this + 148);
      if ( ++v4 >= v3 )
        return v3;
    }
    sub_4D4060(v4 + 1, 1);
    LOBYTE(v3) = sub_48CA60((_DWORD *)this);
  }
  return v3;
}
