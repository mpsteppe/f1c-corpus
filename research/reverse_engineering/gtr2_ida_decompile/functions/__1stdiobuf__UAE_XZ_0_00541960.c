void __thiscall stdiobuf::~stdiobuf(stdiobuf *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  *(_DWORD *)this = &off_71E674;
  v2 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 7);
  if ( v2 )
  {
    (**v2)(v2, 1);
    *((_DWORD *)this + 7) = 0;
  }
  *(_DWORD *)this = &off_71E634;
}
