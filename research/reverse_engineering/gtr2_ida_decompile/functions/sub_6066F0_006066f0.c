int __stdcall sub_6066F0(_DWORD *a1)
{
  if ( (*(_BYTE *)a1 & 4) != 0 )
  {
    sub_5E71A0(a1, 0, 4);
    *a1 &= ~4u;
  }
  if ( (*(_BYTE *)a1 & 8) != 0 )
  {
    sub_5E71A0(a1, 0, 8);
    *a1 &= ~8u;
  }
  if ( (*(_BYTE *)a1 & 1) != 0 )
  {
    sub_5E7180(a1, 0, 1);
    *a1 &= ~1u;
  }
  if ( (*(_BYTE *)a1 & 2) != 0 )
  {
    sub_5E7180(a1, 0, 2);
    *a1 &= ~2u;
  }
  return 0;
}
