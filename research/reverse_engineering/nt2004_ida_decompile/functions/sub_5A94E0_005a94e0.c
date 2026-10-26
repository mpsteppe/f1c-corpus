int __thiscall sub_5A94E0(int *this, int a2, int a3, int a4, int a5, int a6)
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
  dword_7E8CE8 = a2;
  dword_7E8CEC = a3;
  dword_7E8CF8 = a4;
  dword_7E8D00 = a5 & 1;
  if ( sub_5A4F00((int)&unk_7E6B48, this, dword_7E8E40, a2, a3, a4, a5, a6) )
    return -1;
  sub_5A78A0(1);
  return 0;
}
