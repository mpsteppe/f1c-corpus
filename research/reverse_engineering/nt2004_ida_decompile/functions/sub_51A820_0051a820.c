void __thiscall sub_51A820(int this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st6
  double v4; // st6

  v1 = *(float *)(this + 18736) / *(float *)(this + 18740);
  *(_DWORD *)(this + 1968) = *(_DWORD *)(this + 19696);
  v2 = v1 * (v1 * *(float *)(this + 17676) * v1) * 0.5;
  if ( *(float *)(this + 19696) == -789.0 )
    *(float *)(this + 1968) = v2;
  v3 = *(float *)(this + 19700);
  *(_DWORD *)(this + 1988) = *(_DWORD *)(this + 19700);
  if ( v3 == -789.0 )
    *(float *)(this + 1988) = v2;
  v4 = *(float *)(this + 19704);
  *(_DWORD *)(this + 2008) = *(_DWORD *)(this + 19704);
  if ( v4 == -789.0 )
    *(float *)(this + 2008) = v2;
}
