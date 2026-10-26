// f1c  0x0059bbd9  size=249
__int16 __cdecl sub_59BBD9(WCHAR a1, int a2)
{
  _DWORD *v2; // esi
  char *v3; // eax
  int v4; // eax
  __int16 result; // ax
  bool v6; // sf
  int v7; // eax
  int v8; // eax

  v2 = (_DWORD *)a2;
  if ( (*(_BYTE *)(a2 + 12) & 0x40) != 0
    || (*(_DWORD *)(a2 + 16) == -1
      ? (v3 = (char *)&unk_5E7898)
      : (v3 = (char *)(dword_8D4920[*(int *)(a2 + 16) >> 5] + 36 * (*(_DWORD *)(a2 + 16) & 0x1F))),
        v3[4] >= 0) )
  {
    v6 = *(_DWORD *)(a2 + 4) - 2 < 0;
    *(_DWORD *)(a2 + 4) -= 2;
    if ( v6 )
      return sub_59C1E7(a1, v2);
    result = a1;
    *(_WORD *)*v2 = a1;
    *v2 += 2;
    return result;
  }
  v4 = sub_596030((LPSTR)&a2, a1);
  if ( v4 == -1 )
  {
    *(_DWORD *)sub_58AFCF() = 42;
    return -1;
  }
  if ( v4 == 1 )
  {
    v6 = --v2[1] < 0;
    if ( v6 )
    {
      v7 = sub_58CF35(a2, v2);
      goto LABEL_14;
    }
    *(_BYTE *)*v2 = a2;
    v7 = (unsigned __int8)a2;
  }
  else
  {
    v6 = --v2[1] < 0;
    if ( v6 )
    {
      v8 = sub_58CF35(a2, v2);
    }
    else
    {
      *(_BYTE *)(*v2)++ = a2;
      v8 = (unsigned __int8)a2;
    }
    if ( v8 == -1 )
      return -1;
    v6 = --v2[1] < 0;
    if ( v6 )
    {
      v7 = sub_58CF35(BYTE1(a2), v2);
      goto LABEL_14;
    }
    *(_BYTE *)*v2 = BYTE1(a2);
    v7 = BYTE1(a2);
  }
  ++*v2;
LABEL_14:
  if ( v7 == -1 )
    return -1;
  return a1;
}
