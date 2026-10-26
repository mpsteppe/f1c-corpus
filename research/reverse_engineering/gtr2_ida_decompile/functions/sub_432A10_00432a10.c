int __thiscall sub_432A10(int this, int a2, int a3, int a4)
{
  int v5; // eax
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int result; // eax
  int v15; // [esp+14h] [ebp+4h]

  v5 = (a3 + 11 * a2) << 6;
  v7 = v5 + this + 176;
  v15 = *(_DWORD *)(v5 + this + 196);
  if ( a4 > 0 )
  {
    v8 = *(_DWORD *)(v5 + this + 192);
    if ( a4 < v8 )
      *(_DWORD *)(v7 + 20) = a4;
    else
      *(_DWORD *)(v7 + 20) = v8 - 1;
  }
  else
  {
    *(_DWORD *)(v5 + this + 196) = 0;
  }
  if ( *(_BYTE *)(this + 6953) )
  {
    sub_432080((_DWORD *)this, a2, a3);
    if ( a2 )
    {
      v9 = 0;
      if ( a2 != 1 )
      {
        LOBYTE(v9) = a2 == 2;
        v9 += 2;
      }
    }
    else
    {
      v9 = 1;
    }
    v10 = (a3 + 11 * v9) << 6;
    v11 = *(_DWORD *)(v10 + this + 192);
    v12 = v10 + this + 176;
    if ( *(_DWORD *)(v7 + 16) == v11 )
    {
      v13 = *(_DWORD *)(v7 + 20);
      if ( *(_DWORD *)(v12 + 20) != v13 )
      {
        *(_DWORD *)(v12 + 20) = v13;
        *(_BYTE *)(this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
  }
  sub_432080((_DWORD *)this, a2, a3);
  result = v15;
  if ( *(_DWORD *)(v7 + 20) != v15 )
  {
    *(_BYTE *)(this + 6952) = 1;
    *(_BYTE *)this = 1;
  }
  return result;
}
