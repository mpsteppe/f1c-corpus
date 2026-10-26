void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  int v4; // [esp+0h] [ebp-14h]

  *(_DWORD *)this = &off_729DB8;
  if ( *((_DWORD *)this + 1) )
  {
    do
    {
      v2 = *(void (__thiscall ****)(_DWORD, int))(*((_DWORD *)this + 3) + 4 * *((_DWORD *)this + 1) - 4);
      if ( v2 )
        (**v2)(v2, 1);
    }
    while ( (*((_DWORD *)this + 1))-- != 1 );
  }
  *((_DWORD *)this + 4) = 0;
  sub_4F14D0(v4);
  sub_5A8D10(*((void **)this + 3));
}
