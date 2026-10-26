// f1c  0x004ee230  size=145
void __thiscall sub_4EE230(int this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st6
  double v4; // st6

  v1 = *(float *)(this + 14740) / *(float *)(this + 14744);
  *(_DWORD *)(this + 1916) = *(_DWORD *)(this + 15688);
  v2 = v1 * (v1 * *(float *)(this + 13680) * v1) * 0.5;
  if ( *(float *)(this + 15688) == -789.0 )
    *(float *)(this + 1916) = v2;
  v3 = *(float *)(this + 15692);
  *(_DWORD *)(this + 1936) = *(_DWORD *)(this + 15692);
  if ( v3 == -789.0 )
    *(float *)(this + 1936) = v2;
  v4 = *(float *)(this + 15696);
  *(_DWORD *)(this + 1956) = *(_DWORD *)(this + 15696);
  if ( v4 == -789.0 )
    *(float *)(this + 1956) = v2;
}
