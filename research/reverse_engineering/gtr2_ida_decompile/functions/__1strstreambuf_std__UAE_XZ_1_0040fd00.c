void __thiscall std::strstreambuf::~strstreambuf(std::strstreambuf *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  *(_DWORD *)this = &off_6F2014;
  v2 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 3);
  if ( v2 )
  {
    if ( *(v2 - 1) )
      (**v2)(v2, 3);
    else
      j_j__free(v2 - 1);
  }
  *(_DWORD *)this = &off_6F1F7C;
}
