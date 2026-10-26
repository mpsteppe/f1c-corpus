int __thiscall sub_4D17A0(_DWORD *this)
{
  bool v2; // zf
  char v3; // al
  int v4; // eax

  sub_4DF030(this);
  v2 = sub_4DE2F0(this[12]) == (_DWORD)this;
  v3 = *((_BYTE *)this + 268);
  if ( v2 )
  {
    if ( !v3 || !*((_BYTE *)this + 269) )
      *((_BYTE *)this + 268) = 1;
  }
  else if ( v3 && *((_BYTE *)this + 269) )
  {
    v4 = *this;
    *((_BYTE *)this + 268) = 0;
    (*(void (__thiscall **)(_DWORD *))(v4 + 168))(this);
  }
  return (*(int (__thiscall **)(_DWORD *))(*this + 144))(this);
}
