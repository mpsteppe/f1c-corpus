char __thiscall sub_4FA7F0(_DWORD *this, int a2)
{
  int v2; // eax
  int i; // edx
  int v5; // edx
  int v6; // edi
  _WORD *v7; // edx
  int v8; // edx

  LOBYTE(v2) = *(_BYTE *)(a2 + 2) & 0x3F;
  if ( (_BYTE)v2 == 10 )
  {
    v2 = this[66];
    for ( i = 0; i < v2; i = v5 + 1 )
    {
      sub_4F8D70((_DWORD *)(this[67] + 8 * i), 0);
      v2 = this[66];
    }
  }
  v6 = (*(_DWORD *)a2 >> 7) & 0x1FF;
  if ( v6 )
  {
    v7 = (_WORD *)(a2 + 8);
    do
    {
      LOBYTE(v2) = sub_4F8D70((_DWORD *)(this[67] + 8 * ((unsigned __int16)*v7 >> 6)), *v7 & 0x3F);
      v7 = (_WORD *)(v8 + 2);
      --v6;
    }
    while ( v6 );
  }
  return v2;
}
