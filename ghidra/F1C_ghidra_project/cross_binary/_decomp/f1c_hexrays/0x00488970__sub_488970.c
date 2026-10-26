// f1c  0x00488970  size=90
int __thiscall sub_488970(_DWORD *this)
{
  int v2; // edi
  int v3; // edi

  if ( (int)this[56] >= 0 )
  {
    v2 = this[56] + (*(int (__thiscall **)(_DWORD *))(*this + 24))(this);
    if ( v2 > (*(int (__thiscall **)(_DWORD *))(*this + 32))(this) )
    {
      v3 = (*(int (__thiscall **)(_DWORD *))(*this + 32))(this);
      this[56] = v3 - (*(int (__thiscall **)(_DWORD *))(*this + 24))(this);
    }
  }
  else
  {
    this[56] = 0;
  }
  return (*(int (__thiscall **)(_DWORD *))(*this + 168))(this);
}
