int __thiscall sub_4AFF60(_DWORD **this)
{
  int v1; // eax
  int v2; // eax
  float v4; // [esp+14h] [ebp-108h]
  char v5[256]; // [esp+1Ch] [ebp-100h] BYREF

  v1 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 49);
  if ( v1 )
  {
    if ( sub_4CE170(v1) )
    {
      sub_4ABA50();
      v4 = (float)dword_B6DB10;
      CGarageOnline::Rate((CGarageOnline *)dword_B6CBB4, (char *)(dword_B6CBB0 + 305), v5, v4, byte_B6DDF0);
      v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 49);
      if ( v2 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 144))(v2);
    }
  }
  return 0;
}
