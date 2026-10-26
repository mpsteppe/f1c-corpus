int __thiscall sub_482B50(_DWORD *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // edi

  v2 = 2;
  sub_46FBE0(this);
  v3 = this[216];
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
        v2 = 0;
    }
    else
    {
      v2 = 3;
    }
  }
  else
  {
    v2 = 2;
  }
  dword_767574 = v2;
  if ( v2 >= dword_76757C )
  {
    if ( v2 > dword_767580 )
      dword_767574 = dword_767580;
    return 0;
  }
  else
  {
    dword_767574 = dword_76757C;
    return 0;
  }
}
