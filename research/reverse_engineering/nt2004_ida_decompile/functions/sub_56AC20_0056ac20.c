void __thiscall sub_56AC20(_DWORD *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // esi
  int v5; // edi

  *this = &off_5F6254;
  v2 = this[6];
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) )
      sub_5BE8AE();
    sub_5BE8AE();
  }
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  v4 = this[2];
  while ( v4 )
  {
    v5 = v4;
    v4 = *(_DWORD *)(v4 + 4);
    if ( *(_BYTE *)(v5 + 8) )
      sub_5BE8AE();
    sub_5BE8AE();
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  *this = &off_5F6278;
}
