void __thiscall sub_406C30(int this, float *a2)
{
  double v2; // st7

  v2 = (*(float *)(*(_DWORD *)(this + 84) + 132) * a2[2]
      + *(float *)(*(_DWORD *)(this + 84) + 124) * *a2
      + *(float *)(*(_DWORD *)(this + 84) + 128) * a2[1]
      + 330.0)
     / (*(float *)(this + 60) * a2[2] + *(float *)(this + 56) * a2[1] + *(float *)(this + 52) * *a2 + 330.0)
     * *(float *)(this + 72);
  if ( v2 >= 0.125 )
  {
    if ( v2 <= 8.0 )
      *(float *)(this + 72) = v2;
    else
      *(_DWORD *)(this + 72) = 1090519040;
  }
  else
  {
    *(_DWORD *)(this + 72) = 1040187392;
  }
}
