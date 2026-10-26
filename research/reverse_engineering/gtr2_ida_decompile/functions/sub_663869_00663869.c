int __thiscall sub_663869(_DWORD *this, const char *a2)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v5; // edi
  int v6; // eax
  unsigned int v7; // ecx
  _DWORD v9[3]; // [esp+4h] [ebp-18h] BYREF
  int v10; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  unsigned int v12; // [esp+18h] [ebp-4h]

  v10 = 0;
  v12 = -1;
  v3 = this[1];
  if ( !v3 || *(_DWORD *)(v3 + 4) != 4 )
    return 0;
  for ( i = *(_DWORD *)(v3 + 28); i; i = *(_DWORD *)(i + 12) )
  {
    v4 = *(_DWORD **)(i + 8);
    if ( v4 )
    {
      if ( v4[1] == 6 && v4[4] == 2 && !strcmp(*(const char **)(v4[5] + 24), a2) )
      {
        v5 = v4[6];
        if ( *(_DWORD *)(v5 + 60) )
        {
          if ( (*(_BYTE *)(v5 + 24) & 2) == 0 )
          {
            v6 = *(_DWORD *)(v5 + 28);
            v7 = 0;
            if ( v6 )
            {
              if ( sub_6460B4(*(const char **)(v6 + 24), 0, v9) < 0 )
                v7 = -1;
              else
                v7 = v9[1];
            }
            if ( ((v7 & 0xFFFF0000) == 0 || (v7 & 0xFFFF0000) == (this[4] & 0xFFFF0000))
              && (!(_WORD)v7 || (unsigned __int16)v7 == (unsigned __int16)this[4])
              && (v12 == -1 || v7 > v12) )
            {
              v10 = v5;
              v12 = v7;
            }
          }
        }
      }
    }
  }
  return v10;
}
