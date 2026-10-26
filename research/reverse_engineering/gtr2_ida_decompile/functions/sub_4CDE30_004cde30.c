int __thiscall sub_4CDE30(_DWORD *this)
{
  int v2; // edi
  int v3; // edi

  if ( (int)this[67] >= 0 )
  {
    v2 = this[67] + (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v2 > (*(int (__thiscall **)(_DWORD *))(*this + 12))(this) )
    {
      v3 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
      this[67] = v3 - (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    }
  }
  else
  {
    this[67] = 0;
  }
  return (*(int (__thiscall **)(_DWORD *))(*this + 160))(this);
}
