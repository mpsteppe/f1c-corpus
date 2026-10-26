void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  void *v2; // edi
  int v3; // eax
  void (__thiscall ***v4)(_DWORD, int); // ecx
  int v5; // edi

  *(_DWORD *)this = &off_712EE8;
  if ( *((_DWORD *)this + 16) )
  {
    sub_4E2E50();
    v2 = (void *)*((_DWORD *)this + 16);
    if ( v2 )
    {
      sub_48D1E0();
      j__free(v2);
    }
  }
  if ( *((_DWORD *)this + 13) )
  {
    do
    {
      v3 = sub_4CD340();
      v4 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 13);
      v5 = v3;
      if ( v4 )
        (**v4)(v4, 1);
      *((_DWORD *)this + 13) = v5;
    }
    while ( v5 );
  }
  if ( *((_DWORD *)this + 23) )
    j_j__free(*((void **)this + 23));
  if ( *((_DWORD *)this + 21) )
    j_j__free(*((void **)this + 21));
  if ( *((_DWORD *)this + 19) )
    j_j__free(*((void **)this + 19));
  sub_4E3C60(this);
}
