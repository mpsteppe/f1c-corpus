const char *__thiscall sub_4B1520(_DWORD *this, int a2, const char *a3, unsigned int a4)
{
  char *v4; // eax
  const char *result; // eax
  const char *v6; // edx
  unsigned int v7; // ecx

  v4 = (char *)this[7 * a2 + 2609];
  if ( !v4 )
    v4 = byte_5EA438;
  sub_587DD0(a3, v4, a4 - 1);
  a3[a4 - 1] = 0;
  result = (const char *)ConditionalDispatch_81f0(aGameFilter);
  v6 = result;
  if ( result )
  {
    result = 0;
    if ( strlen(v6) + 1 + strlen(a3) < a4 )
    {
      *(_WORD *)&a3[strlen(a3)] = word_5C32D8;
      result = 0;
      v7 = strlen(v6) + 1;
      qmemcpy((void *)&a3[strlen(a3)], v6, v7);
    }
  }
  return result;
}
