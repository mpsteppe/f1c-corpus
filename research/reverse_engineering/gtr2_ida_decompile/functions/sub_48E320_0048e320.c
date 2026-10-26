void __thiscall sub_48E320(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // edx
  int i; // edi
  int v6; // eax

  v2 = sub_4DEE50(this[12]);
  sub_615860(v2);
  if ( !strstr(WindowName, "PHOTO SHOP") )
  {
    v3 = *this;
    this[78] = 255;
    (*(void (__thiscall **)(_DWORD *, int))(v3 + 40))(this, 1);
    v4 = *this;
    this[81] = 0;
    (*(void (__thiscall **)(_DWORD *))(v4 + 164))(this);
    for ( i = 0; i < sub_4CF920(this); ++i )
    {
      v6 = sub_4CF930(i);
      sub_4E40C0(v6);
    }
    *((_BYTE *)this + 316) = 0;
    this[82] = 1036831949;
    this[81] = 1058642330;
  }
}
