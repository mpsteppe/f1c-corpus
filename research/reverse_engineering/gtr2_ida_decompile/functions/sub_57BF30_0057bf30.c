void __thiscall sub_57BF30(int this, float a2)
{
  double v2; // st7
  double v3; // st7
  float v4; // [esp+4h] [ebp+4h]

  v2 = a2 * 0.22499999 + *(float *)(this + 17428);
  *(float *)(this + 17428) = v2;
  v4 = *(float *)(this + 17440) + 0.44999999;
  if ( v2 > v4 )
    *(float *)(this + 17428) = v4;
  if ( *(float *)(this + 17440) + 0.15000001 < *(float *)(this + 17428) )
  {
    if ( !*(_DWORD *)(this + 18412) )
      *(_DWORD *)(this + 18412) = 1;
    v3 = (*(float *)(this + 17448) + *(float *)(this + 17432)) * 0.5;
    if ( v3 < *(float *)(this + 17432) )
      *(float *)(this + 17432) = v3;
  }
  if ( *(float *)(this + 17440) + 0.30000001 < *(float *)(this + 17428) )
    *(_DWORD *)(this + 17432) = *(_DWORD *)(this + 17448);
  sub_579710(this, 0);
}
