void __thiscall std::ios_base::_Init(std::ios_base *this)
{
  std::locale *v2; // ecx

  v2 = (std::ios_base *)((char *)this + 32);
  if ( v2 )
    std::locale::locale(v2);
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 513;
  *((_DWORD *)this + 4) = 6;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  std::ios_base::clear(this, 0, 0);
}
