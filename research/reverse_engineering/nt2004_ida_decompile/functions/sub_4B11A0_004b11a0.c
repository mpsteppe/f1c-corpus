void __thiscall sub_4B11A0(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  while ( *this )
  {
    *this = sub_5A4730();
    if ( v2 )
      (**v2)(v2, 1);
  }
}
