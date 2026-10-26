int __thiscall sub_6BFA68(_DWORD *this)
{
  unsigned int i; // ebx
  int v3; // eax
  _DWORD *v4; // ecx
  int v5; // esi
  _DWORD *v6; // eax
  int v7; // edx

  for ( i = 0; i < this[2]; ++i )
  {
    v3 = this[5];
    v4 = *(_DWORD **)(v3 + 4 * i);
    v5 = v4[14];
    if ( v5 != -1 )
    {
      v6 = *(_DWORD **)(v3 + 4 * v5);
      v7 = v4[14];
      while ( v6[14] != -1 )
      {
        v4[15] |= v6[15];
        v7 = v6[14];
        v6 = *(_DWORD **)(this[5] + 4 * v7);
      }
      if ( v5 != v7 )
      {
        v4[14] = v7;
        sub_681692(v4, v6);
      }
    }
  }
  return 0;
}
