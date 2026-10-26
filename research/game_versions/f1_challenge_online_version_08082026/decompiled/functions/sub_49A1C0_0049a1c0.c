int __thiscall sub_49A1C0(_DWORD *this, int a2)
{
  _DWORD *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  _DWORD *v7; // eax

  if ( !a2 )
    return -1;
  v4 = (_DWORD *)*this;
  if ( *this )
  {
    if ( sub_499E00(v4) )
    {
      do
        v7 = (_DWORD *)sub_499E00(v6);
      while ( sub_499E00(v7) );
    }
    sub_499DF0(v6, v5);
    return 0;
  }
  else
  {
    *this = a2;
    return 0;
  }
}
