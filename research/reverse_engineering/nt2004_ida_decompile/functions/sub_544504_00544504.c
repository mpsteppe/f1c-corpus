int __thiscall sub_544504(_DWORD *this, int a2)
{
  int v3; // edi
  void *v4; // ebx
  void *v5; // eax

  if ( this[2] != *(_DWORD *)(a2 + 8) )
  {
    v3 = this[1046];
    v4 = operator new(16 * v3);
    v5 = 0;
    if ( v4 )
    {
      sub_53D688((int)v4, 16, v3, (int (__thiscall *)(int))sub_53D5B2);
      v5 = v4;
    }
    this[1043] = v5;
    if ( !v5 )
      return -2147024882;
    this[1042] = *(_DWORD *)(a2 + 8);
  }
  return 0;
}
