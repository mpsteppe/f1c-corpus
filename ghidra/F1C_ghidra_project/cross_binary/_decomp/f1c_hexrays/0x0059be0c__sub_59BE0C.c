// f1c  0x0059be0c  size=241
__int16 __cdecl sub_59BE0C(int a1)
{
  unsigned __int8 **v1; // esi
  char *v2; // eax
  bool v3; // sf
  int v4; // edi
  int v5; // eax
  __int16 result; // ax
  int v7; // eax
  CHAR v8[4]; // [esp+8h] [ebp-4h] BYREF

  v1 = (unsigned __int8 **)a1;
  if ( (*(_BYTE *)(a1 + 12) & 0x40) != 0
    || (*(_DWORD *)(a1 + 16) == -1
      ? (v2 = (char *)&unk_5E7898)
      : (v2 = (char *)(dword_8D4920[*(int *)(a1 + 16) >> 5] + 36 * (*(_DWORD *)(a1 + 16) & 0x1F))),
        v2[4] >= 0) )
  {
    v3 = *(_DWORD *)(a1 + 4) - 2 < 0;
    *(_DWORD *)(a1 + 4) -= 2;
    if ( v3 )
    {
      return sub_59C30E(v1);
    }
    else
    {
      result = *(_WORD *)*v1;
      *v1 += 2;
    }
  }
  else
  {
    v3 = --*(_DWORD *)(a1 + 4) < 0;
    v4 = 1;
    if ( v3 )
      v5 = sub_58C255(v1);
    else
      v5 = *(*v1)++;
    if ( v5 == -1 )
      return -1;
    v8[0] = v5;
    if ( off_5E69C8[0][(unsigned __int8)v5] < 0 )
    {
      v3 = (int)--v1[1] < 0;
      if ( v3 )
        v7 = sub_58C255(v1);
      else
        v7 = *(*v1)++;
      if ( v7 == -1 )
      {
        sub_59685F(v8[0], (unsigned int)v1);
        return -1;
      }
      v8[1] = v7;
      v4 = 2;
    }
    if ( sub_596716((LPWSTR)&a1 + 1, v8, v4) == -1 )
    {
      *(_DWORD *)sub_58AFCF() = 42;
      return -1;
    }
    return HIWORD(a1);
  }
  return result;
}
