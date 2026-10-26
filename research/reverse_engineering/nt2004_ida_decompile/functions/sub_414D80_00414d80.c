char sub_414D80()
{
  const char *v0; // edi
  unsigned int v1; // kr04_4
  unsigned int v2; // kr08_4
  char *v3; // esi
  const char *v5; // eax
  size_t v6; // edi
  char *v7; // ecx
  char v8; // bl

  v0 = dword_766578;
  if ( !dword_766578 )
    v0 = &byte_629120;
  v1 = strlen(v0) + 1;
  v2 = strlen((const char *)&off_5FC808) + 1;
  v3 = (char *)operator new(v1 + v2);
  if ( !v3 )
    return 0;
  v5 = dword_766578;
  if ( !dword_766578 )
    v5 = &byte_629120;
  v6 = v1 + v2 - 1;
  strncpy(v3, v5, v6);
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
  *(_WORD *)&v3[strlen(v3)] = *(_WORD *)word_5FC804;
  *(_DWORD *)&v3[strlen(v3)] = off_5FC808;
  v8 = sub_414D60(v3);
  sub_5BE8AE(v3);
  return v8;
}
