int __thiscall sub_476ED0(_DWORD *this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi

  v2 = this[13];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          sub_5BE8AE(*v5);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  sub_49D5B0(aCurrentSetup, -1);
  return 0;
}
