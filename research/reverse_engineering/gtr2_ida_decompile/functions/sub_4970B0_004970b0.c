int __thiscall sub_4970B0(_DWORD *this)
{
  int result; // eax

  result = this[69];
  if ( result == 846 || result == 847 )
  {
    result = (*(int (__thiscall **)(_DWORD *))(*this + 148))(this);
    if ( !result )
      return sub_4CD5A0(this, *((unsigned __int8 *)this + 273));
  }
  return result;
}
