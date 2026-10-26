void __thiscall sub_5770E0(int this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st6
  double v4; // st6

  v1 = *(float *)(this + 17212) / *(float *)(this + 17216);
  *(_DWORD *)(this + 2852) = *(_DWORD *)(this + 18388);
  v2 = v1 * (v1 * *(float *)(this + 16132) * v1) * 0.5;
  if ( -789.0 == *(float *)(this + 18388) )
    *(float *)(this + 2852) = v2;
  v3 = *(float *)(this + 18392);
  *(_DWORD *)(this + 2872) = *(_DWORD *)(this + 18392);
  if ( -789.0 == v3 )
    *(float *)(this + 2872) = v2;
  v4 = *(float *)(this + 18396);
  *(_DWORD *)(this + 2892) = *(_DWORD *)(this + 18396);
  if ( -789.0 == v4 )
    *(float *)(this + 2892) = v2;
}
