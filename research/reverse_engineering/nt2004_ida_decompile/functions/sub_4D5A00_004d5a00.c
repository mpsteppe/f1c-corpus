int __thiscall sub_4D5A00(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  void *v4; // ebx
  _DWORD *v5; // esi
  int v6; // ecx
  int v7; // edi

  result = this[330];
  if ( result )
  {
    v3 = *(_DWORD *)(result - 4);
    v4 = (void *)(result - 4);
    v5 = (_DWORD *)(result + (v3 << 7));
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 32;
        sub_4D3650(v5);
        --v7;
      }
      while ( v7 );
    }
    sub_5BE8AE(v4);
    result = 0;
    this[330] = 0;
    this[331] = 0;
  }
  return result;
}
