// f1c  0x005117c8  size=135
_BYTE *__cdecl sub_5117C8(int a1, const void *a2)
{
  int v2; // ecx
  _BYTE *result; // eax
  int i; // esi
  int v5; // edx
  _BYTE *v6; // eax
  _BYTE *v7; // eax

  result = 0;
  for ( i = 0; i < 4; ++i )
  {
    v5 = *(unsigned __int8 *)(a1 + i + 268);
    if ( v5 < 41 || v5 > 122 || v5 > 90 && v5 < 97 )
    {
      result[v2] = 91;
      v6 = result + 1;
      v6[v2] = byte_5AF210[(v5 >> 4) & 0xF];
      (++v6)[v2] = byte_5AF210[v5 & 0xF];
      result = v6 + 1;
      result[v2] = 93;
    }
    else
    {
      result[v2] = v5;
    }
    ++result;
  }
  if ( a2 )
  {
    result[v2] = 58;
    v7 = result + 1;
    v7[v2] = 32;
    result = &v7[v2 + 1];
    qmemcpy(result, a2, 0x40u);
    result[63] = 0;
  }
  else
  {
    result[v2] = 0;
  }
  return result;
}
