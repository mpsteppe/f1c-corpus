// Address: 0x004d0cf0
// Size: 290 bytes
// Name: sub_4D0CF0
// Type: int __cdecl(unsigned __int8 *, unsigned __int8 *)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_4D0CF0(unsigned __int8 *a1, unsigned __int8 *a2)
{
  char *v2; // edx
  int v3; // edi
  char *v4; // ecx
  int v5; // eax
  int v6; // esi
  bool v7; // cc
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // esi

  v2 = (char *)&unk_5F070C + 18624 * *a1;
  v3 = *((_DWORD *)v2 + 12);
  v4 = (char *)&unk_5F070C + 18624 * *a2;
  if ( v3 != 3 )
  {
    v9 = *((_DWORD *)v4 + 12);
    if ( v9 != 3 )
    {
      v10 = *((_DWORD *)v4 + 2);
      v11 = *((_DWORD *)v2 + 2);
      if ( v11 <= v10 )
      {
        if ( v11 < v10 )
          return 1;
        if ( v3 == 1 )
        {
          if ( v9 != 1 )
            return 1;
          if ( *((float *)v4 + 33) > (double)*((float *)v2 + 33) )
            return -1;
          if ( *((float *)v4 + 33) >= (double)*((float *)v2 + 33) )
          {
LABEL_15:
            v12 = *((_DWORD *)v4 + 11);
            v13 = *((_DWORD *)v2 + 11);
            v7 = v13 <= v12;
            if ( v13 < v12 )
              return -1;
            goto LABEL_4;
          }
          return 1;
        }
        if ( v9 != 1 )
        {
          v14 = *((_DWORD *)v4 + 3);
          v15 = *((_DWORD *)v2 + 3);
          if ( v15 <= v14 )
          {
            if ( v15 < v14 )
              return 1;
            if ( *((float *)v4 + 4) < (double)*((float *)v2 + 4) )
              return -1;
            if ( *((float *)v4 + 4) <= (double)*((float *)v2 + 4) )
              goto LABEL_15;
            return 1;
          }
        }
      }
    }
    return -1;
  }
  if ( *((_DWORD *)v4 + 12) != 3 )
    return 1;
  v5 = *((_DWORD *)v4 + 11);
  v6 = *((_DWORD *)v2 + 11);
  v7 = v6 <= v5;
  if ( v6 < v5 )
    return -1;
LABEL_4:
  if ( !v7 )
    return 1;
  if ( v4 > v2 )
    return -1;
  return v4 < v2;
}
