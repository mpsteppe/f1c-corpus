void __thiscall sub_486F30(_DWORD *this)
{
  int v1; // esi
  int v2; // edx
  _DWORD *v3; // eax
  int v4; // edx
  int v5; // eax
  char **v6; // eax
  char *v7; // eax

  v1 = this[220];
  v2 = v1;
  if ( v1 < 0 || v1 >= this[219] )
    return;
  v3 = (_DWORD *)this[216];
  if ( v1 <= 0 )
  {
LABEL_6:
    if ( !v3 || !*v3 )
      return;
    v4 = this[220];
    if ( v1 >= 0 && v1 < this[219] )
    {
      v5 = this[216];
      if ( v1 <= 0 )
      {
LABEL_13:
        if ( v5 )
        {
          v6 = *(char ***)v5;
          goto LABEL_16;
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = *(_DWORD *)(v5 + 4);
          if ( --v4 <= 0 )
            goto LABEL_13;
        }
      }
    }
    v6 = 0;
LABEL_16:
    v7 = *v6;
    if ( !v7 )
      v7 = &byte_629120;
    sub_4A1AC0(v7);
    return;
  }
  while ( v3 )
  {
    v3 = (_DWORD *)v3[1];
    if ( --v2 <= 0 )
      goto LABEL_6;
  }
}
