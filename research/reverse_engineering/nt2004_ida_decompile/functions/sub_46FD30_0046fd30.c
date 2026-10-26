int __thiscall sub_46FD30(_DWORD *this, int a2)
{
  sub_46FB70(this, a2);
  dword_768450 = 0;
  if ( dword_768458 <= 0 )
  {
    if ( dword_76845C < 0 )
      dword_768450 = dword_76845C;
    return (*(int (__thiscall **)(_DWORD *))(*this + 180))(this);
  }
  else
  {
    dword_768450 = dword_768458;
    return (*(int (__thiscall **)(_DWORD *))(*this + 180))(this);
  }
}
