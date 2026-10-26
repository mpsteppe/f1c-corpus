int __thiscall sub_67FA0C(_DWORD *this)
{
  int *v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 0;
  v2 = &v6;
  while ( this )
  {
    if ( this[1] != 1 )
    {
      *v2 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      return v6;
    }
    v3 = (_DWORD *)sub_65B229(20);
    if ( v3 )
      v4 = sub_67ED05(v3);
    else
      v4 = 0;
    *v2 = (int)v4;
    if ( !v4 )
      return v6;
    v4[4] = this[4];
    if ( this[2] )
    {
      *(_DWORD *)(*v2 + 8) = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[2] + 4))(this[2]);
      if ( !*(_DWORD *)(*v2 + 8) )
      {
        *v2 = 0;
        return v6;
      }
    }
    this = (_DWORD *)this[3];
    v2 = (int *)(*v2 + 12);
  }
  return v6;
}
