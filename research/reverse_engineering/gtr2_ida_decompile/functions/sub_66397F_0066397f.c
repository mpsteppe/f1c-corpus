int __thiscall sub_66397F(_DWORD *this, int a2, _DWORD *a3)
{
  int v4; // eax
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  _DWORD v12[3]; // [esp+4h] [ebp-1Ch] BYREF
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned int v16; // [esp+1Ch] [ebp-4h]

  v13 = 0;
  v16 = -1;
  v14 = 0;
  v4 = this[1];
  if ( !v4 || *(_DWORD *)(v4 + 4) != 4 )
    return 0;
  for ( i = *(_DWORD *)(v4 + 28); i; i = *(_DWORD *)(i + 12) )
  {
    v5 = *(_DWORD **)(i + 8);
    if ( v5 )
    {
      if ( v5[1] == 6 && v5[4] == 2 )
      {
        v6 = a2;
        if ( a2 )
        {
          do
          {
            if ( v5[9] == *(_DWORD *)(*(_DWORD *)(v6 + 8) + 24) )
              break;
            v6 = *(_DWORD *)(v6 + 12);
          }
          while ( v6 );
          if ( v6 )
          {
            v7 = v5[6];
            if ( *(_DWORD *)(v7 + 60) )
            {
              v8 = *(_DWORD *)(v7 + 28);
              v9 = 0;
              if ( v8 )
              {
                if ( sub_6460B4(*(const char **)(v8 + 24), 0, v12) < 0 )
                  v9 = -1;
                else
                  v9 = v12[1];
              }
              if ( ((v9 & 0xFFFF0000) == 0 || (v9 & 0xFFFF0000) == (this[4] & 0xFFFF0000))
                && (!(_WORD)v9 || (unsigned __int16)v9 == (unsigned __int16)this[4])
                && (v16 == -1 || v9 > v16) )
              {
                v10 = *(_DWORD *)(v5[5] + 24);
                v13 = v7;
                v16 = v9;
                v14 = v10;
              }
            }
          }
        }
      }
    }
  }
  if ( a3 )
    *a3 = v14;
  return v13;
}
