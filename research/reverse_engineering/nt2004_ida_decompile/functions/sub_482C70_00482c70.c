int __thiscall sub_482C70(_DWORD *this)
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
  dword_7674E4 = v2;
  if ( v2 >= dword_7674EC )
  {
    if ( v2 > dword_7674F0 )
      dword_7674E4 = dword_7674F0;
    return 0;
  }
  else
  {
    dword_7674E4 = dword_7674EC;
    return 0;
  }
}
