// f1c  0x004ed0f0  size=195
void __thiscall sub_4ED0F0(int this, float a2)
{
  double v2; // st7
  double v3; // st7
  float v4; // [esp+4h] [ebp+4h]

  v2 = a2 * 0.22499999 + *(float *)(this + 14956);
  *(float *)(this + 14956) = v2;
  v4 = *(float *)(this + 14968) + 0.44999999;
  if ( v2 > v4 )
    *(float *)(this + 14956) = v4;
  if ( *(float *)(this + 14968) + 0.15000001 < *(float *)(this + 14956) )
  {
    if ( !*(_DWORD *)(this + 15712) )
      *(_DWORD *)(this + 15712) = 1;
    v3 = (*(float *)(this + 14976) + *(float *)(this + 14960)) * 0.5;
    if ( v3 < *(float *)(this + 14960) )
      *(float *)(this + 14960) = v3;
  }
  if ( *(float *)(this + 14968) + 0.30000001 < *(float *)(this + 14956) )
    *(_DWORD *)(this + 14960) = *(_DWORD *)(this + 14976);
  sub_4E8010(this, 0);
}
