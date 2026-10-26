int __thiscall sub_4CDFB0(_DWORD *this)
{
  int v2; // edi

  if ( this[33] == 1 && *((_BYTE *)this + 280) )
  {
    v2 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
    this[67] += (v2 - (*(int (__thiscall **)(_DWORD *))(*this + 4))(this)) * this[71] / -100;
    sub_4CDE30(this);
    (*(void (__thiscall **)(_DWORD *))(*this + 172))(this);
  }
  return 0;
}
