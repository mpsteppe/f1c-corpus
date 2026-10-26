void *__thiscall sub_65F766(_DWORD *this, int a2)
{
  const char *v2; // esi
  int v3; // edi
  const char *v5; // eax
  char v6; // dl
  int v7; // edx
  int v8; // edx
  int v9; // edx
  char v10; // cl
  int v12; // edx
  int v13; // edx
  int v14; // [esp-4h] [ebp-18h]
  int v15; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  v2 = *(const char **)(a2 + 8);
  v3 = 0;
  v15 = 0;
  v5 = v2;
  if ( !v2 || !*v2 )
    return &unk_E40000;
  for ( i = 16; i < 0x18; i += 2 )
  {
    v6 = *v5;
    if ( !*v5 )
      goto LABEL_13;
    if ( v6 > 119 )
    {
      v12 = v6 - 120;
      if ( !v12 )
        goto LABEL_11;
      v13 = v12 - 1;
      if ( !v13 )
      {
LABEL_22:
        v3 = 1;
        goto LABEL_12;
      }
      if ( v13 != 1 )
        goto LABEL_15;
LABEL_21:
      v14 = 2;
LABEL_17:
      v3 = v14;
      goto LABEL_12;
    }
    if ( v6 == 119 || (v7 = v6 - 97) == 0 )
    {
      v14 = 3;
      goto LABEL_17;
    }
    v8 = v7 - 1;
    if ( !v8 )
      goto LABEL_21;
    v9 = v8 - 5;
    if ( !v9 )
      goto LABEL_22;
    if ( v9 != 11 )
      goto LABEL_15;
LABEL_11:
    v3 = 0;
LABEL_12:
    ++v5;
LABEL_13:
    v10 = i;
    v15 |= v3 << v10;
  }
  if ( *v5 )
  {
LABEL_15:
    sub_65DD1F((_DWORD *)*this, a2, 2004, "invalid swizzle '%s'", v2);
    this[19] = 1;
    return 0;
  }
  return (void *)v15;
}
