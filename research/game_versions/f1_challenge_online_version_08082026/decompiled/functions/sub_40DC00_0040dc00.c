char sub_40DC00()
{
  const char *v0; // edi
  unsigned int v1; // kr04_4
  unsigned int v2; // kr08_4
  char *v3; // esi
  char *v5; // eax
  int v6; // edi
  char *v7; // ecx
  char v8; // bl

  v0 = (const char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v0 = &byte_5EA438;
  v1 = strlen(v0) + 1;
  v2 = strlen((const char *)&off_5BEB4C) + 1;
  v3 = (char *)sub_587C03(v1 + v2);
  if ( !v3 )
    return 0;
  v5 = (char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v5 = &byte_5EA438;
  v6 = v1 + v2 - 1;
  sub_587DD0(v3, v5, v6);
  v3[v6] = 0;
  v7 = &v3[strlen(v3)];
  if ( v7 > v3 )
  {
    while ( *v7 != 46 )
    {
      if ( --v7 <= v3 )
        goto LABEL_12;
    }
    *v7 = 0;
  }
LABEL_12:
  *(_WORD *)&v3[strlen(v3)] = word_5BEB48;
  *(_DWORD *)&v3[strlen(v3)] = off_5BEB4C;
  v8 = sub_40DBE0((int)v3);
  sub_587BCF(v3);
  return v8;
}
