int __cdecl __isctype_mt(_DWORD *a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int result; // eax
  int v7; // [esp+0h] [ebp-4h] BYREF

  v7 = v3;
  if ( (unsigned int)(a2 + 1) <= 0x100 )
  {
    v4 = *(unsigned __int16 *)(a1[18] + 2 * a2);
    return a3 & v4;
  }
  if ( *(char *)(a1[18] + 2 * BYTE1(a2) + 1) >= 0 )
  {
    LOWORD(v7) = (unsigned __int8)a2;
    v5 = 1;
  }
  else
  {
    *(_WORD *)((char *)&v7 + 1) = (unsigned __int8)a2;
    LOBYTE(v7) = BYTE1(a2);
    v5 = 2;
  }
  result = __crtGetStringTypeA(1, &v7, v5, (char *)&a2 + 2, a1[1], a1[5], 1);
  if ( result )
  {
    v4 = HIWORD(a2);
    return a3 & v4;
  }
  return result;
}
