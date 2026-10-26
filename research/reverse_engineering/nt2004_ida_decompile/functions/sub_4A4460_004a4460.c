int __thiscall sub_4A4460(_DWORD *this)
{
  int result; // eax

  result = dword_7656E0;
  if ( !dword_7656E0 )
  {
    sub_4AD000(this[12]);
    return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  return result;
}
