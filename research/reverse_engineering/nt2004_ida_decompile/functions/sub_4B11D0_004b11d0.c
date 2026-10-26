int __thiscall sub_4B11D0(_DWORD *this, int a2)
{
  int v3; // edx
  _DWORD *v4; // ecx
  int v5; // eax

  if ( !a2 )
    return -1;
  if ( *this )
  {
    if ( ((int (*)(void))sub_5A4730)() )
    {
      do
        v5 = ((int (*)(void))sub_5A4730)();
      while ( sub_5A4730(v5) );
    }
    sub_4B0E10(v4, v3);
    return 0;
  }
  else
  {
    *this = a2;
    return 0;
  }
}
