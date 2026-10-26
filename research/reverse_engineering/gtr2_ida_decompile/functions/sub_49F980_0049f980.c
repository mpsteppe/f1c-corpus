int __thiscall sub_49F980(_DWORD *this, int a2)
{
  int *v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v3 = (int *)this[211];
  v4 = *v3;
  if ( a2 == 1 )
    v5 = v4 + 1;
  else
    v5 = v4 - 1;
  if ( v5 >= 0 )
  {
    if ( v5 > 2 )
      v5 = 2;
  }
  else
  {
    v5 = 0;
  }
  *v3 = v5;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
        sub_615860("SIM_SERVER.txt");
    }
    else
    {
      sub_615860("SEMIPRO_SERVER.txt");
    }
  }
  else
  {
    sub_615860("ARCADE_SERVER.txt");
  }
  return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
}
