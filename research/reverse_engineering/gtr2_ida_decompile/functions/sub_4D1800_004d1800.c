int __thiscall sub_4D1800(_DWORD *this)
{
  bool v2; // zf
  char v3; // al
  int v4; // eax

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
    (*(void (__thiscall **)(_DWORD *))(*this + 164))(this);
    return 0;
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 164))(this);
  return 0;
}
