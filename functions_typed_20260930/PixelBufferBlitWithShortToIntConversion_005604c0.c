void __cdecl __spoils<ecx> PixelBufferBlitWithShortToIntConversion(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        __int16 a11)
{
  _WORD *v11; // esi
  int v12; // eax
  _DWORD *v13; // edi
  int v14; // ecx
  __int32 v15; // ebx
  bool v16; // cc
  __int16 v17; // [esp+Ah] [ebp-2h]
  int v18; // [esp+20h] [ebp+14h]

  v17 = a11;
  a9 *= 2;
  v11 = (_WORD *)(a2 + a2 + a3 * a4 + a1);
  v12 = a6 + a6 + a7 * a8;
  v13 = (_DWORD *)(v12 + a5);
  v14 = a9;
  v18 = a4 - a9;
  v15 = _InterlockedExchange(&a8, 2 * (a8 - a9));
  while ( 1 )
  {
    if ( v17 != *v11 )
    {
      LOWORD(v12) = *v11;
      v12 <<= 16;
      LOWORD(v12) = *v11;
      *v13 = v12;
      *(_DWORD *)((char *)v13 + v15) = v12;
    }
    ++v11;
    ++v13;
    v16 = v14 <= 2;
    v14 -= 2;
    if ( v16 )
    {
      v14 = a9;
      v11 = (_WORD *)((char *)v11 + v18);
      v13 = (_DWORD *)((char *)v13 + a8);
      v16 = a10-- <= 1;
      if ( v16 )
        break;
    }
  }
}

