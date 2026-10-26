int sub_528870()
{
  int result; // eax
  char *v1; // eax
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  char *i; // eax
  int v6; // ecx
  char v8[512]; // [esp+2h] [ebp-200h] BYREF

  if ( sub_500F90(&unk_7D7920, 2, aDDevNascar2004_26, 1587) )
    sub_500FE0((int)&unk_7D7920, aEnteredVidmanP);
  sub_5267C0((void **)&dword_7DA7C8);
  sub_5983E0(dword_7DA9B8);
  dword_7DA9B8 = 0;
  sub_592EF0(0);
  result = 400 * dword_7D6B54 + dword_7D6B58;
  if ( result )
  {
    v1 = (char *)(result + 4);
    v2 = (char *)(v8 - v1);
    do
    {
      v3 = *v1;
      v1[(_DWORD)v2] = *v1;
      ++v1;
    }
    while ( v3 );
    v4 = strlen(v8);
    if ( v4 > 0 )
    {
      for ( i = &v8[v4 - 1]; i >= v8; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v6 = strlen(v8);
    if ( v6 > 0 && v8[v6 - 1] == 92 )
      v8[v6 - 1] = 0;
    return sub_592030(v8);
  }
  return result;
}
