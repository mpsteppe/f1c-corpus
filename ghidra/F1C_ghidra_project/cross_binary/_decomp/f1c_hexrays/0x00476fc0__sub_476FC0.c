// f1c  0x00476fc0  size=185
unsigned int __thiscall sub_476FC0(_DWORD *this, int a2, char *a3, unsigned int a4)
{
  char *v4; // eax
  const char *v6; // eax
  unsigned int result; // eax
  char *v8; // eax
  const char *v9; // edi

  v4 = (char *)dword_7D0D5C[7 * a2];
  if ( !v4 )
    v4 = byte_5EA438;
  sub_587DD0(a3, v4, a4 - 1);
  a3[a4 - 1] = 0;
  v6 = (const char *)this[98];
  if ( !v6 )
    v6 = byte_5EA438;
  result = strlen(v6) + strlen(a3) + 1;
  if ( result < a4 )
  {
    *(_WORD *)&a3[strlen(a3)] = word_5C32D8;
    v8 = (char *)this[98];
    if ( !v8 )
      v8 = byte_5EA438;
    v9 = v8;
    result = 0;
    strcat(a3, v9);
  }
  return result;
}
