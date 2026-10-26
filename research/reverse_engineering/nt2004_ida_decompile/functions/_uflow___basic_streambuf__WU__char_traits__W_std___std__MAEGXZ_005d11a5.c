__int16 __thiscall std::wstreambuf::uflow(void *this)
{
  if ( (*(unsigned __int16 (__thiscall **)(void *))(*(_DWORD *)this + 16))(this) == 0xFFFF )
    return -1;
  else
    return *(_WORD *)std::basic_streambuf<unsigned short>::_Gninc(this);
}
