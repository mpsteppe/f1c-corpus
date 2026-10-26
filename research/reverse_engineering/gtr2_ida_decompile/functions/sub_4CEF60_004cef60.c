int __thiscall sub_4CEF60(_DWORD *this)
{
  _DWORD *v2; // eax
  int v4; // edi

  if ( *((_BYTE *)this + 280) )
  {
    if ( *((_BYTE *)this + 288) )
    {
      v2 = (_DWORD *)(*(int (__thiscall **)(_DWORD *))(*this + 188))(this);
      if ( v2 )
      {
        --*v2;
        (*(void (__thiscall **)(_DWORD *))(*this + 172))(this);
        return 0;
      }
    }
    else
    {
      v4 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
      this[67] += (v4 - (*(int (__thiscall **)(_DWORD *))(*this + 4))(this)) * this[71] / -100;
      sub_4CDE30(this);
    }
    (*(void (__thiscall **)(_DWORD *))(*this + 172))(this);
  }
  return 0;
}
