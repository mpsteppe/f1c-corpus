CHAR *__thiscall sub_47DB00(char *Source, int a2)
{
  CHAR *v3; // eax
  CHAR *v4; // edx
  const char *v5; // edi
  unsigned int v6; // kr04_4
  char *v7; // ecx
  CHAR *result; // eax
  CHAR *v9; // [esp+Ch] [ebp-88h]
  char Destination[128]; // [esp+14h] [ebp-80h] BYREF

  v9 = (CHAR *)operator new(0x80u);
  *v9 = 0;
  v3 = sub_435600((CHAR ***)dword_75E8E8);
  sub_578600(v3);
  v4 = v9;
  v5 = v9;
  if ( !v9 )
    v5 = &byte_629120;
  v6 = strlen(v5) + 1;
  if ( (int)(v6 - 1) > 0 )
  {
    if ( !v9 )
      v4 = &byte_629120;
    if ( v4[v6 - 2] != 92 )
      sub_578560(word_5FB9F4);
  }
  strncpy(Destination, Source, 0x7Fu);
  Destination[127] = 0;
  sub_57AF80(Destination);
  sub_578560(Destination);
  sub_578560(aSvm);
  v7 = v9;
  if ( !v9 )
    v7 = &byte_629120;
  sub_57B040(v7, a2);
  result = v9;
  if ( v9 )
    return (CHAR *)sub_5BE8AE(v9);
  return result;
}
