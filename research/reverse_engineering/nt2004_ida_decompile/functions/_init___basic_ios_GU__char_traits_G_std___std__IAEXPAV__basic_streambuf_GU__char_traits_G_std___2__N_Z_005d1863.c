void __thiscall std::basic_ios<unsigned short>::init(std::ios_base *this, int a2, char a3)
{
  int v4; // eax

  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = a2;
  *((_WORD *)this + 24) = btowc(32);
  std::ios_base::_Init(this);
  if ( !*((_DWORD *)this + 10) )
  {
    v4 = *((_DWORD *)this + 1);
    LOBYTE(v4) = v4 | 4;
    std::ios_base::clear(this, v4, 0);
  }
  if ( a3 )
    std::ios_base::_Addstd(this);
}
