// f1c  0x005116d4  size=151
int __cdecl sub_5116D4(int a1, int a2)
{
  _DWORD *v2; // eax
  int v3; // edx
  char *v4; // ecx
  int v5; // ecx
  int v6; // esi
  char **v7; // ecx
  char v8; // dl
  char *i; // esi

  v2 = *(_DWORD **)a1;
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 20);
  if ( v3 <= 0 || v3 > v2[29] )
  {
    v5 = v2[30];
    if ( !v5 )
      goto LABEL_9;
    v6 = v2[31];
    if ( v3 < v6 || v3 > v2[32] )
      goto LABEL_9;
    v4 = *(char **)(v5 + 4 * (v3 - v6));
  }
  else
  {
    v4 = *(char **)(v2[28] + 4 * v3);
  }
  if ( !v4 )
  {
LABEL_9:
    v7 = (char **)v2[28];
    v2[6] = v3;
    v4 = *v7;
  }
  v8 = *v4;
  for ( i = v4; ; v8 = *i )
  {
    if ( !v8 )
      return sub_58815F(a2, v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
    ++i;
    if ( v8 == 37 )
      break;
  }
  if ( *i != 115 )
    return sub_58815F(a2, v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
  return sub_58815F(a2, v4, v2 + 6);
}
