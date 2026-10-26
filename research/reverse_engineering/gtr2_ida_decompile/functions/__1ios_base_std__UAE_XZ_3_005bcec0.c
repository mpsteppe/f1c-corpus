void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  void (__thiscall ***v2)(_DWORD, int); // eax

  *(_DWORD *)this = off_7296D0;
  if ( sub_4FB7D0(this) )
  {
    v2 = (void (__thiscall ***)(_DWORD, int))(*(int (__thiscall **)(std::ios_base *))(*(_DWORD *)this + 12))(this);
    if ( v2 )
      (**v2)(v2, 1);
  }
  *(_DWORD *)this = off_729664;
}
