int __thiscall sub_684E45(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, int a5)
{
  int result; // eax
  _DWORD *v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  unsigned int i; // [esp+1Ch] [ebp+14h]

  result = sub_684DF7(this, a2, a3, a5);
  for ( i = 0; i < this[3]; result = i )
  {
    v8 = *(_DWORD **)(this[6] + 4 * i);
    v9 = 0;
    if ( !v8[9] && v8[5] )
    {
      do
      {
        v10 = *(_DWORD *)(this[6] + 4 * *(_DWORD *)(v8[6] + 4 * v9));
        if ( a5 == v8[14] )
        {
          if ( *(_DWORD *)(v10 + 36) )
            *a4 -= 0x10000;
        }
        else if ( a5 == *(_DWORD *)(v10 + 56) )
        {
          *a4 += 0x10000;
        }
        ++v9;
      }
      while ( v9 < v8[5] );
    }
    ++i;
  }
  return result;
}
