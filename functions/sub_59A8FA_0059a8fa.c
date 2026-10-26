void __thiscall sub_59A8FA(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  unsigned int v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  sub_59A54D(v5);
  if ( this[9] < 8u )
  {
    do
    {
      v2 = this[9];
      v3 = dword_8D4618[v2];
      if ( !v3 )
        break;
      if ( (_DWORD *)v3 == this )
        break;
      v4 = v2 + 1;
      this[9] = v4;
    }
    while ( v4 < 8 );
  }
  dword_8D4618[this[9]] = (int)this;
  ++byte_8D463C[this[9]];
  sub_59A5E9();
}
