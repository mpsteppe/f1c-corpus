void __thiscall sub_4FEFC0(int this, int a2)
{
  *(_DWORD *)(this + 168) = a2;
  if ( *(float *)(this + 168) >= 0.0099999998 )
  {
    if ( *(float *)(this + 168) > 0.99000001 )
      *(_DWORD *)(this + 168) = 1065185444;
  }
  else
  {
    *(_DWORD *)(this + 168) = 1008981770;
  }
  *(float *)(this + 172) = 1.0 / *(float *)(this + 168);
  *(float *)(this + 176) = 1.0 / (1.0 - *(float *)(this + 168));
}

