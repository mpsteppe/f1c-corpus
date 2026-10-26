int __thiscall sub_49D3F0(_DWORD *this)
{
  int v2; // edi
  int v4; // [esp+0h] [ebp-8h]

  v2 = sub_435A40(&dword_B65FF8);
  if ( this[149] != v2 )
  {
    sub_48CB50(v4);
    this[149] = v2;
  }
  return 0;
}
