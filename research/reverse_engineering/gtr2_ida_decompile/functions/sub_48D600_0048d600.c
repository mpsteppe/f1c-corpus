int __thiscall sub_48D600(_DWORD *this, int a2)
{
  int *v2; // edx
  int v3; // eax
  int v4; // eax

  v2 = (int *)this[211];
  v3 = *v2;
  if ( a2 == 1 )
    v4 = v3 + 1;
  else
    v4 = v3 - 1;
  if ( v4 >= 1 )
  {
    if ( v4 > 4 )
      v4 = 4;
    *v2 = v4;
    return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  else
  {
    *v2 = 1;
    return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
}
