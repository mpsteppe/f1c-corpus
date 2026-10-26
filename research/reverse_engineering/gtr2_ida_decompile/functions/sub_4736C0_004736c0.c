int __thiscall sub_4736C0(int *this)
{
  int v1; // ecx
  int v2; // edx
  int v3; // esi
  _BYTE *v4; // ecx

  v1 = *this;
  v2 = *(_DWORD *)(v1 + 112884);
  v3 = 0;
  if ( v2 )
  {
    v4 = (_BYTE *)(v1 + 2752);
    do
    {
      if ( (*v4 & 2) != 0 )
        ++v3;
      v4 += 528;
      --v2;
    }
    while ( v2 );
  }
  return v3;
}
