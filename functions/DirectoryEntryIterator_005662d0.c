unsigned int __thiscall sub_5662D0(int *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // eax
  const char *v5; // edx
  int v6; // eax
  char *v7; // edx
  int v8; // edx
  const char *v9; // eax
  unsigned int v10; // kr04_4

  v2 = *this;
  v3 = *(int **)(v2 + 8);
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !v4 )
    return 0;
  v5 = *(const char **)(v4 + 324);
  if ( !v5 )
    v5 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v2 + 16, "%s%s", v5, (const char *)(v4 + 48));
  v6 = *this;
  if ( !*(_BYTE *)(*this + 536) )
    return v6 + 16;
  v7 = *(char **)(v6 + 528);
  if ( !v7 )
    v7 = byte_5EA438;
  v8 = sub_566810(v6 + 16, v7);
  if ( !v8 )
    return 0;
  v9 = *(const char **)(*this + 528);
  if ( !v9 )
    v9 = byte_5EA438;
  v10 = strlen(v9) + 1;
  return v8 + v10 - 1 + (*(_BYTE *)(v10 - 1 + v8) == 92);
}
