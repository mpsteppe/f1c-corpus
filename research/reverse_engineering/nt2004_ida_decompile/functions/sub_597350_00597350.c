int __thiscall sub_597350(void *this, _DWORD *a2, int a3, int a4, int a5)
{
  void *v6; // eax
  _DWORD *v7; // esi

  if ( a2 )
    *a2 = 0;
  v6 = operator new(0x240u);
  if ( v6 )
    v7 = (_DWORD *)sub_59D4D0(v6);
  else
    v7 = 0;
  v7[15] = a5;
  if ( sub_59D610((char *)v7, a3, a4) )
  {
    sub_59D5F0(v7);
    sub_5BE8AE();
    return -1;
  }
  else
  {
    v7[141] = this;
    if ( a2 )
      *a2 = v7;
    return 0;
  }
}
