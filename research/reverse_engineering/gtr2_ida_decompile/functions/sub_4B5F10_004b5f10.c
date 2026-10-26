int __thiscall sub_4B5F10(_DWORD *this, int a2)
{
  int *v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = (int *)this[212];
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
  v6 = dword_B71D88;
  dword_B71D80 = 0;
  if ( dword_B71D88 > 0 || (v6 = dword_B71D8C, dword_B71D8C < 0) )
    dword_B71D80 = v6;
  return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
}
