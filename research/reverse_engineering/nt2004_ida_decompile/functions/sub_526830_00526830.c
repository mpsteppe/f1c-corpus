void __thiscall sub_526830(_DWORD *this, int a2)
{
  int v3; // eax

  if ( *this )
  {
    this[1] = a2;
    sub_5AC740(1);
    this[3] = 0;
    if ( !a2 )
    {
      v3 = sub_592CD0(aFtframerate);
      if ( v3 )
        sub_5A3330(v3);
    }
  }
}
