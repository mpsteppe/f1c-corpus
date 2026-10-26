int __thiscall sub_4A2220(_BYTE *this)
{
  void *v2; // eax
  int result; // eax
  int v4; // ecx
  void *v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebp
  void *v9; // [esp+8h] [ebp-4h]

  *(_WORD *)this = 0;
  this[2] = 1;
  this[3] = 0;
  this[4] = 0;
  *((_DWORD *)this + 17) = -1082130432;
  *((_DWORD *)this + 18) = -1;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  if ( dword_8AFE88 && *((_DWORD *)this + 25) )
    F_3DSoundSourceDestructor(*((_DWORD *)this + 25));
  v2 = (void *)*((_DWORD *)this + 27);
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  if ( v2 )
    FreeWrapper_7bcf(v2);
  result = *((_DWORD *)this + 29);
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  if ( result )
  {
    v4 = *(_DWORD *)(result - 4);
    v5 = (void *)(result - 4);
    v6 = result + 28 * v4;
    v7 = v4 - 1;
    v9 = (void *)(result - 4);
    if ( v7 >= 0 )
    {
      v8 = v7 + 1;
      do
      {
        v6 -= 28;
        ShortComputation_d4d0(v6);
        --v8;
      }
      while ( v8 );
      v5 = v9;
    }
    result = FreeWrapper_7bcf(v5);
  }
  *((_DWORD *)this + 29) = 0;
  return result;
}

