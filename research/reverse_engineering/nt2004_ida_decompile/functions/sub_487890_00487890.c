int __thiscall sub_487890(_DWORD *this, int a2)
{
  int *v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v2 = (int *)this[218];
  v3 = *v2;
  if ( a2 == 1 )
    v4 = v3 + 1;
  else
    v4 = v3 - 1;
  if ( v4 >= 0 )
  {
    if ( v4 > 2 )
      v4 = 2;
  }
  else
  {
    v4 = 0;
  }
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
        *v2 = 2;
    }
    else
    {
      *v2 = 1;
    }
  }
  else
  {
    *v2 = 0;
  }
  dword_768450 = 0;
  if ( dword_768458 <= 0 )
  {
    if ( dword_76845C < 0 )
      dword_768450 = dword_76845C;
    return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  else
  {
    dword_768450 = dword_768458;
    return (*(int (__fastcall **)(_DWORD *, int))(*this + 152))(this, dword_76845C);
  }
}
