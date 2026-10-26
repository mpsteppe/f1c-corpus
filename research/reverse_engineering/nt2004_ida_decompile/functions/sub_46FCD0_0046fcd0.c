int __thiscall sub_46FCD0(_DWORD *this, int a2)
{
  int result; // eax

  sub_46FB70(this, a2);
  result = this[210];
  if ( result )
  {
    dword_76863C = 0;
    if ( dword_768644 <= 0 )
    {
      if ( dword_768648 < 0 )
        dword_76863C = dword_768648;
      return (*(int (__thiscall **)(_DWORD *))(*this + 180))(this);
    }
    else
    {
      dword_76863C = dword_768644;
      return (*(int (__thiscall **)(_DWORD *))(*this + 180))(this);
    }
  }
  return result;
}
