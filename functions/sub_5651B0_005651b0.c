int __thiscall sub_5651B0(const char *this)
{
  char *v1; // ebp
  unsigned int v2; // kr10_4
  signed int i; // edi
  char v4; // al
  char v5; // bl
  WORD v6; // si
  signed int j; // edx
  const char *v8; // esi
  int result; // eax
  unsigned int v10; // ecx
  char v11; // dl
  bool v12; // zf
  char v13; // [esp+11h] [ebp-197h]
  bool v14; // [esp+12h] [ebp-196h]
  char v15; // [esp+13h] [ebp-195h]
  int v16; // [esp+14h] [ebp-194h]
  int v17; // [esp+18h] [ebp-190h]
  int v18; // [esp+1Ch] [ebp-18Ch]
  const char *v19; // [esp+24h] [ebp-184h]
  char v20[384]; // [esp+28h] [ebp-180h] BYREF

  v1 = (char *)(this + 408);
  v19 = this;
  v2 = strlen(this + 408) + 1;
  v18 = 0;
  v17 = 0;
  v14 = 0;
  v13 = 0;
  v15 = 0;
  v16 = 0;
  for ( i = 0; sub_589BF3(v1[i]) && v1[i]; ++i )
    ;
  for ( ; i < (int)(v2 - 1); ++i )
  {
    if ( v15 )
      break;
    v4 = v1[i];
    v5 = 1;
    if ( v4 == 34 )
      v14 = !v14;
    if ( !v14 )
    {
      if ( v4 != 47 )
        v13 = 0;
      v6 = v4;
      switch ( v4 )
      {
        case 10:
        case 13:
          continue;
        case 40:
          ++v17;
          break;
        case 41:
          --v17;
          break;
        case 47:
          if ( v13 )
          {
            v15 = 1;
            v18 = 3;
            --v16;
            continue;
          }
          v13 = 1;
          break;
        default:
          if ( v17 && sub_589BF3(v4) )
            v5 = 0;
          v4 = sub_589A35(v6);
          if ( v5 )
            break;
          continue;
      }
    }
    v20[v16++] = v4;
  }
  v20[v16] = 0;
  strcpy(v1, v20);
  for ( j = strlen(v1) - 1; j > 0; --j )
  {
    if ( v1[j] != 32 )
      break;
  }
  v8 = v19;
  result = 0;
  v19[j + 409] = 0;
  v10 = strlen(v1) + 1;
  if ( v18 == 3 )
  {
    if ( v10 != 1 )
      return result;
    return v18;
  }
  if ( v10 == 1 )
    return 1;
  v11 = v8[j + 408];
  if ( v11 == 32 )
    return 1;
  if ( v11 == 125 )
    return 2;
  v12 = StrlenFormatCallWrapper(v1, "%s", v20) == -1;
  result = 4;
  if ( !v12 )
    return v18;
  return result;
}
