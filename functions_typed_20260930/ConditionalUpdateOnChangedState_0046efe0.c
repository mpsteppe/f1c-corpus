int __thiscall ConditionalUpdateOnChangedState(_DWORD *this)
{
  int v2; // edi

  v2 = VtableGetterAtOffset0x1c(dword_7C73E0);
  if ( this[93] != v2 )
  {
    ExtensionStripperForAllListEntries(this);
    this[93] = v2;
  }
  return 0;
}

