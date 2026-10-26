void __thiscall sub_551760(_DWORD *this)
{
  int i; // esi

  for ( i = this[79]; i; i = *(_DWORD *)(i + 36) )
  {
    if ( *(_DWORD *)(i + 28) )
      sub_5514C0((float *)i, (int)this);
  }
}
