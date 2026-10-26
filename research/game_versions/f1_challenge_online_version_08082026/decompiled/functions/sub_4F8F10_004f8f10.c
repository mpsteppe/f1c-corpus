void __thiscall sub_4F8F10(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax

  if ( *this )
  {
    v3 = this[6];
    this[1] = a2;
    sub_556440(v3);
    this[3] = 0;
    if ( !a2 )
    {
      v4 = sub_53D1F0(aFtframerate);
      if ( v4 )
        sub_5528F0(v4);
    }
  }
}
