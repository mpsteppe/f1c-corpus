int __thiscall sub_486E00(_DWORD *this)
{
  int v2; // edx
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // eax
  char **v7; // eax
  char *v8; // eax
  char *v9; // edi
  char v10; // cl
  char Destination[128]; // [esp+4h] [ebp-100h] BYREF
  char v13[128]; // [esp+84h] [ebp-80h] BYREF

  v2 = this[220];
  v3 = v2;
  if ( v2 < 0 || v2 >= this[219] )
    return sub_486F30(this);
  v4 = (_DWORD *)this[216];
  if ( v2 <= 0 )
  {
LABEL_6:
    if ( !v4 || !*v4 )
      return sub_486F30(this);
    v5 = v2;
    if ( v2 >= 0 && v2 < this[219] )
    {
      v6 = this[216];
      if ( v2 <= 0 )
      {
LABEL_13:
        if ( v6 )
        {
          v7 = *(char ***)v6;
          goto LABEL_16;
        }
      }
      else
      {
        while ( v6 )
        {
          v6 = *(_DWORD *)(v6 + 4);
          if ( --v5 <= 0 )
            goto LABEL_13;
        }
      }
    }
    v7 = 0;
LABEL_16:
    v8 = *v7;
    if ( !v8 )
      v8 = &byte_629120;
    sub_57B040(v8, 128);
    sub_4CD6E0(Destination, 127);
    strcat(Destination, v13);
    v9 = &Destination[strlen(Destination) + 1];
    v10 = aSvm[4];
    *(_DWORD *)--v9 = *(_DWORD *)aSvm;
    v9[4] = v10;
    sub_436C00((char **)&dword_75E8F0, (int)Destination, 1);
    return sub_486F30(this);
  }
  while ( v4 )
  {
    v4 = (_DWORD *)v4[1];
    if ( --v3 <= 0 )
      goto LABEL_6;
  }
  return sub_486F30(this);
}
