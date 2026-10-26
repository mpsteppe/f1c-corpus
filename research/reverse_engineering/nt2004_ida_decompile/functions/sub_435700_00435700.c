char __thiscall sub_435700(char **this, char *Source)
{
  CHAR *v3; // esi
  const char *v4; // edi
  unsigned int v5; // kr04_4
  _BYTE v7[256]; // [esp+Ch] [ebp-100h] BYREF

  sub_57B040(Source, 256);
  sub_578560(v7);
  v3 = (CHAR *)*((_DWORD *)*this + 2);
  v4 = v3;
  if ( !v3 )
    v4 = &byte_629120;
  v5 = strlen(v4) + 1;
  if ( (int)(v5 - 1) > 0 )
  {
    if ( !v3 )
      v3 = &byte_629120;
    if ( v3[v5 - 2] != 92 )
      sub_578560(word_5FB9F4);
  }
  sub_434B40(*this, 0);
  return 1;
}
