int __thiscall sub_5BD570(_DWORD *this)
{
  int result; // eax
  int v3; // ebx
  int v4; // ecx
  int v5; // esi
  _DWORD *i; // eax
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax

  result = this[102];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = this[104];
    v5 = 0;
    do
    {
      for ( i = (_DWORD *)(v5 + v4); *(_DWORD *)(v5 + v4); i = (_DWORD *)(v5 + v4) )
      {
        sub_5BD2D0((_DWORD *)(i[2] + 8 * *i - 8), 0);
        v7 = this[104];
        v8 = *(_DWORD *)(v7 + v5);
        v9 = (_DWORD *)(v5 + v7);
        *v9 = --v8;
        (**(void (__thiscall ***)(int, _DWORD))(v9[2] + 8 * v8))(v9[2] + 8 * v8, 0);
        v4 = this[104];
      }
      result = this[102];
      ++v3;
      v5 += 12;
    }
    while ( v3 < result );
  }
  return result;
}
