int __thiscall sub_643D50(int *this, int a2, int a3, int a4)
{
  int result; // eax
  int i; // esi
  int v7; // ecx

  result = *this;
  for ( i = 0; i < *this; ++i )
  {
    v7 = *(_DWORD *)(this[2] + 4 * i);
    if ( v7 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 4))(v7, a2);
    result = *this;
  }
  return result;
}
