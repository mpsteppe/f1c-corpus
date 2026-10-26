void __thiscall std::locale::_Locimp::~_Locimp(std::locale::_Locimp *this)
{
  int i; // esi
  void (__thiscall ***v3)(_DWORD, int); // ecx
  int v4; // esi
  void (__thiscall ***v5)(_DWORD, int); // ebx

  *(_DWORD *)this = &off_712E60;
  for ( i = *((_DWORD *)this + 15); i; *((_DWORD *)this + 15) = i )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 15);
    i = *(_DWORD *)(i + 56);
    if ( v3 )
      (**v3)(v3, 1);
  }
  v4 = *((_DWORD *)this + 16);
  while ( v4 )
  {
    v5 = (void (__thiscall ***)(_DWORD, int))v4;
    v4 = sub_4CD340();
    (**v5)(v5, 1);
  }
  sub_4E3C60(this);
}
