int __thiscall sub_55BD20(int *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // eax
  int v7; // ebp

  v6 = (_DWORD *)this[72];
  v7 = 0;
  if ( !v6 )
    return -1;
  while ( v6[2] != a2 || v6[3] != a3 || v6[5] != a4 || a6 && v6[6] != a6 )
  {
    v6 = (_DWORD *)v6[8];
    ++v7;
    if ( !v6 )
      return -1;
  }
  this[70] = v7;
  dword_8B8DD4 = a2;
  dword_8B8DD8 = a3;
  dword_8B8DE4 = a4;
  dword_8B8DEC = a5 & 1;
  if ( sub_53E070((int)dword_8B78A0, this, dword_8B8F0C, a2, a3, a4, a5, a6) )
    return -1;
  sub_55C440(1);
  return 0;
}
