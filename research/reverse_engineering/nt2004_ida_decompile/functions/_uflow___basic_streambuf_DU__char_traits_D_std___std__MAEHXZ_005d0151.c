int __thiscall std::streambuf::uflow(void *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 16))(this);
  if ( result != -1 )
    return *(unsigned __int8 *)std::streambuf::_Gninc(this);
  return result;
}
