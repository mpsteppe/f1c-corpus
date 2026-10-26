char __thiscall sub_4B0390(_DWORD *this, int a2, int a3)
{
  const char *v3; // edx
  const char *v4; // ecx

  v3 = (const char *)this[109];
  if ( !v3 )
    v3 = byte_5EA438;
  v4 = &v3[strlen(v3)];
  if ( v4 > v3 )
  {
    while ( *v4 != 92 )
    {
      if ( --v4 <= v3 )
        goto LABEL_8;
    }
    ++v4;
  }
LABEL_8:
  sub_587DD0(a2, v4, a3 - 1);
  *(_BYTE *)(a3 - 1 + a2) = 0;
  return 1;
}
