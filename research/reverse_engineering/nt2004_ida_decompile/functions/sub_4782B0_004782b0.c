int __thiscall sub_4782B0(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  char v4; // al
  void *v5; // ebp

  *this = &off_5D70E8;
  ((void (*)(void))((char *)&loc_47681F + 1))();
  v2 = this[104];
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = (void *)*v3;
      if ( *v3 )
      {
        sub_506920(*v3);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  this[104] = 0;
  this[105] = 0;
  this[106] = 0;
  this[107] = 0;
  return sub_49F5B0(this);
}
