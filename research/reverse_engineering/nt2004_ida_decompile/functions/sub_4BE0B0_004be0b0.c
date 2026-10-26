int __stdcall sub_4BE0B0(char *a1, int a2)
{
  char *v2; // ecx
  char *v3; // eax
  char *v4; // esi
  char v5; // cl
  unsigned int v6; // kr08_4
  char *i; // eax
  int result; // eax
  char *v9; // ecx
  char v10[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v11; // [esp+49h] [ebp-3h]
  char v12; // [esp+4Bh] [ebp-1h]

  v10[0] = byte_629120;
  memset(&v10[1], 0, 0x3Cu);
  v11 = 0;
  v12 = 0;
  v2 = &a1[strlen(a1)];
  if ( v2 > a1 )
  {
    while ( *v2 != 92 )
    {
      if ( --v2 <= a1 )
        goto LABEL_6;
    }
    ++v2;
  }
LABEL_6:
  v3 = v2;
  v4 = (char *)(v10 - v2);
  do
  {
    v5 = *v3;
    v3[(_DWORD)v4] = *v3;
    ++v3;
  }
  while ( v5 );
  v6 = strlen(a1) + 1;
  if ( (int)(v6 - 1) > 0 )
  {
    for ( i = &a1[v6 - 2]; i >= a1; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  strcat(a1, "PitCrewMaps\\");
  result = 0;
  strcat(a1, v10);
  v9 = &a1[strlen(a1)];
  if ( v9 > a1 )
  {
    while ( *v9 != 46 )
    {
      if ( --v9 <= a1 )
        return result;
    }
    *v9 = 0;
  }
  return result;
}
