void __thiscall sub_5ADB50(_DWORD *this)
{
  int i; // esi

  for ( i = this[79]; i; i = *(_DWORD *)(i + 36) )
  {
    if ( *(_DWORD *)(i + 28) )
      sub_5AD8A0(i, (int)this);
  }
}
