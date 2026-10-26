int __thiscall sub_4A34A0(_DWORD *this, char a2)
{
  int v3; // ebx
  int result; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int i; // edi
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // ecx

  v3 = 0;
  result = this[3];
  if ( !a2 )
  {
    if ( result <= 0 )
      return result;
    for ( i = 0; ; i += 120 )
    {
      v11 = this[4];
      v12 = *(_DWORD *)(v11 + i + 72);
      v13 = i + v11;
      if ( v12 == -1 )
        goto LABEL_19;
      v14 = *(_DWORD *)(v13 + 100);
      if ( !v14 )
        goto LABEL_19;
      if ( *(int *)(v13 + 112) > 0 && **(float **)(v13 + 116) == 99999.0 )
      {
        if ( *(_BYTE *)(v13 + 2) )
          goto LABEL_18;
      }
      else if ( !*(_BYTE *)(v13 + 2) )
      {
LABEL_18:
        BitClear(v14);
        goto LABEL_19;
      }
      Bit12FlagSet(v14);
LABEL_19:
      result = this[3];
      if ( ++v3 >= result )
        return result;
    }
  }
  if ( result > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this[4];
      v7 = *(_DWORD *)(v6 + v5 + 72);
      v8 = v5 + v6;
      if ( v7 != -1 )
      {
        v9 = *(_DWORD *)(v8 + 100);
        if ( v9 )
          BitClear(v9);
      }
      result = this[3];
      ++v3;
      v5 += 120;
    }
    while ( v3 < result );
  }
  return result;
}
