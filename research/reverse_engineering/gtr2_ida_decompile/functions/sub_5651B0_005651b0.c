int __thiscall sub_5651B0(float *this)
{
  char *v2; // edi
  unsigned int v3; // eax
  int v4; // eax
  char *v5; // edx
  char v6; // cl
  char *v7; // eax
  char v8; // dl
  char Buffer[128]; // [esp+8h] [ebp-80h] BYREF

  if ( this[4] < 0.0 )
    return 1;
  this[4] = this[4] - dbl_FB1D10;
  v2 = dword_91E07C;
  if ( dword_91E07C )
  {
    v3 = *((_DWORD *)dword_91E07C + 4831) - 1;
    if ( v3 <= 0x18 )
    {
      sprintf(Buffer, "%c", (char)(v3 + byte_903BA0));
      sub_562B70((int)Buffer, 100, 50, (int)byte_FFFFFF, 0, 7, 3.0, 3.0);
    }
    v4 = (int)&v2[108 * *((_DWORD *)v2 + 5447) + 21656];
    v5 = &Buffer[-v4];
    do
    {
      v6 = *(_BYTE *)v4;
      v5[v4] = *(_BYTE *)v4;
      ++v4;
    }
    while ( v6 );
    _strupr(Buffer);
    sub_562B70((int)Buffer, 210, 50, (int)byte_FFFFFF, 0, 0, 1.0, 1.0);
    v7 = v2 + 21872;
    do
    {
      v8 = *v7;
      v7[Buffer - (v2 + 21872)] = *v7;
      ++v7;
    }
    while ( v8 );
    _strupr(Buffer);
    sub_562B70((int)Buffer, 210, 90, (int)&loc_48AAB3, 0, 0, 1.0, 1.0);
  }
  return 0;
}
