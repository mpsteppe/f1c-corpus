int __thiscall sub_6CC409(_DWORD *this)
{
  int result; // eax

  result = sub_6CB0CE((int)this, 42);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
    if ( result >= 0 )
    {
      result = sub_6C64E6(this);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}
