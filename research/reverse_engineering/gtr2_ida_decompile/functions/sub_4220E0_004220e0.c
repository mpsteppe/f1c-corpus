char __thiscall sub_4220E0(int this)
{
  int v2; // eax

  sub_52C730(this + 19272);
  LOBYTE(v2) = *(_BYTE *)(this + 20908);
  if ( !(_BYTE)v2 )
  {
    v2 = *(_DWORD *)(this + 21496);
    if ( v2 < 35 )
      *(_DWORD *)(this + 21496) = ++v2;
  }
  if ( *(_DWORD *)dword_B640C8 == 6 )
    *(_DWORD *)(this + 20804) = 0;
  *(float *)(this + 20564) = dbl_FB1D18 + 4.0;
  return v2;
}
