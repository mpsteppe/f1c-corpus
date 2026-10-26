// f1c  0x00588f8b  size=204
int __cdecl sub_588F8B(_BYTE *a1, char *a2)
{
  char *v2; // esi
  signed int v4; // eax
  char v5; // bl
  char *v6; // edi
  _BYTE *v7; // eax
  char *v8; // [esp-8h] [ebp-14h]
  unsigned int v9; // [esp-4h] [ebp-10h]
  int i; // [esp+18h] [ebp+Ch]

  sub_58BB10(a1, 0, 136);
  v2 = a2;
  if ( !*a2 )
    return 0;
  if ( *a2 == 46 && a2[1] )
  {
    sub_58FCA0(a1 + 128);
    return 0;
  }
  for ( i = 0; ; ++i )
  {
    v4 = sub_58FC20(v2, "_.,");
    if ( !v4 )
      break;
    v5 = v2[v4];
    v6 = &v2[v4];
    if ( i )
    {
      if ( i == 1 )
      {
        if ( v4 >= 64 || v5 == 95 )
          return -1;
        v9 = v4;
        v8 = v2;
        v7 = a1 + 64;
      }
      else
      {
        if ( i != 2 || v5 && v5 != 44 )
          return -1;
        v9 = v4;
        v8 = v2;
        v7 = a1 + 128;
      }
      sub_587DD0(v7, v8, v9);
    }
    else
    {
      if ( v4 >= 64 || v5 == 46 )
        return -1;
      sub_587DD0(a1, v2, v4);
    }
    if ( v5 == 44 || !v5 )
      return 0;
    v2 = v6 + 1;
  }
  return -1;
}
