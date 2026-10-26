void __thiscall sub_5ACBB0(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // edi

  v2 = this[2];
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 - 4);
    v4 = v2 + 8 * v3;
    v5 = v3 - 1;
    if ( v5 >= 0 )
    {
      v6 = v5 + 1;
      do
      {
        v4 -= 8;
        sub_5ACBA0();
        --v6;
      }
      while ( v6 );
    }
    sub_5BE8AE();
  }
  nullsub_6(this);
}
