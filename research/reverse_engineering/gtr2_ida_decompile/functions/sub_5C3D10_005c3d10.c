void __thiscall sub_5C3D10(_DWORD *this, int a2, int a3, double a4)
{
  int i; // esi
  int v6; // ecx
  int v7; // [esp+14h] [ebp-4h]

  v7 = this[1];
  if ( v7 > 0 )
  {
    sub_5C26F0();
    for ( i = 0; i < v7; ++i )
    {
      if ( sub_5BFC80(*(_BYTE **)(this[3] + 4 * i)) )
      {
        v6 = *(_DWORD *)(this[3] + 4 * i);
        (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v6 + 4))(
          v6,
          a2,
          a3,
          LODWORD(a4),
          HIDWORD(a4));
      }
    }
  }
}
