void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  *(_DWORD *)this = &off_71E644;
  v2 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 8);
  if ( v2 )
  {
    (**v2)(v2, 1);
    *((_DWORD *)this + 8) = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 9);
  if ( v3 )
  {
    (**v3)(v3, 1);
    *((_DWORD *)this + 9) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 10);
  if ( v4 )
  {
    (**v4)(v4, 1);
    *((_DWORD *)this + 10) = 0;
  }
  *(_DWORD *)this = &off_71E634;
}
