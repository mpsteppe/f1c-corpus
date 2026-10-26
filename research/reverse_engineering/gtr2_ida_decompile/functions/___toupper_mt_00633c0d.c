int __cdecl __toupper_mt(_DWORD *a1, int a2)
{
  int v2; // ebx
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int result; // eax
  unsigned __int16 v8; // ax
  _BYTE v9[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = a2;
  v3 = a1;
  if ( a1[5] && (!a1[9] || (unsigned int)a2 > 0x7F) )
  {
    if ( (unsigned int)a2 >= 0x100
      || ((int)a1[10] <= 1 ? (v4 = *(_BYTE *)(a1[18] + 2 * a2) & 2) : (v4 = __isctype_mt(a1, a2, 2)), v4) )
    {
      if ( *(char *)(v3[18] + 2 * BYTE1(v2) + 1) >= 0 )
      {
        LOWORD(a1) = (unsigned __int8)v2;
        v5 = 1;
      }
      else
      {
        LOBYTE(a1) = BYTE1(v2);
        *(_WORD *)((char *)&a1 + 1) = (unsigned __int8)v2;
        v5 = 2;
      }
      v6 = __crtLCMapStringA(v3[5], 512, &a1, v5, v9, 3, v3[1], 1);
      if ( v6 )
      {
        if ( v6 == 1 )
          return v9[0];
        LOBYTE(v8) = 0;
        HIBYTE(v8) = v9[0];
        return v9[1] | v8;
      }
    }
    return v2;
  }
  if ( a2 < 97 )
    return v2;
  result = a2 - 32;
  if ( a2 > 122 )
    return v2;
  return result;
}
