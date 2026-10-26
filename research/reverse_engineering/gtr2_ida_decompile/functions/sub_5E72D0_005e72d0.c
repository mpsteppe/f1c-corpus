int __thiscall sub_5E72D0(int *this, int a2, int a3, int a4, int a5, int a6)
{
  if ( sub_5E71D0((int)this, a4, a6) )
    return -1;
  if ( a2 > 0 && a3 > 0 )
  {
    this[1] = a2;
    this[2] = a3;
  }
  *this = a6;
  if ( (a6 & 0xF) != 0
    && (*(int (__thiscall **)(int, int *, int))(*(_DWORD *)dword_FB27A4 + 216))(dword_FB27A4, this, this[5]) )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}
