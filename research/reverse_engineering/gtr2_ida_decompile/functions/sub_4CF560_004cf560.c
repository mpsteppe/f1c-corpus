int __thiscall sub_4CF560(void *this)
{
  int result; // eax

  result = dword_B6E198;
  if ( !dword_B6E198 )
  {
    sub_4DED90();
    return (*(int (__thiscall **)(void *))(*(_DWORD *)this + 152))(this);
  }
  return result;
}
