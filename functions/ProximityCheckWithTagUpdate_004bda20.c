int __thiscall sub_4BDA20(_DWORD *this, int a2, int a3, int a4, float a5)
{
  int i; // ebx
  _DWORD *v7; // ecx
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c2
  int result; // eax
  int j; // ebx
  _DWORD *v13; // ecx
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c2

  for ( i = 0; i < this[1]; ++i )
  {
    v7 = *(_DWORD **)(this[2] + 4 * i);
    if ( !(v9 | v10) && a3 != v7[8] && v7[1] != a2 )
    {
      v7[1] = a2;
      SwitchBasedStateHandler(v7, a3);
    }
  }
  result = this[4];
  for ( j = 0; j < result; ++j )
  {
    v13 = *(_DWORD **)(this[5] + 4 * j);
    if ( !(v15 | v16) && v13[1] != a2 )
    {
      v13[1] = a2;
      SwitchBasedStateHandler(v13, a3);
    }
    result = this[4];
  }
  return result;
}
