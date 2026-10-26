void __thiscall sub_46F020(int this, float a2)
{
  double v2; // st7
  float v3; // [esp+4h] [ebp+4h]
  float v4; // [esp+4h] [ebp+4h]

  if ( *(_BYTE *)(this + 286) )
  {
    *(float *)(this + 292) = *(float *)(this + 292) - a2;
    if ( dword_768948 )
    {
      v4 = *(float *)(this + 296) + *(float *)(this + 296);
      v2 = *(float *)(this + 300) * 0.1;
      if ( v2 <= *(float *)(this + 292) )
      {
        if ( *(float *)(this + 292) > (double)v4 )
          *(float *)(this + 292) = v4;
      }
      else
      {
        *(float *)(this + 292) = v2;
      }
    }
    else
    {
      v3 = *(float *)(this + 296);
      if ( *(float *)(this + 300) <= (double)*(float *)(this + 292) )
      {
        if ( *(float *)(this + 292) > (double)v3 )
          *(float *)(this + 292) = v3;
      }
      else
      {
        *(float *)(this + 292) = *(float *)(this + 300);
      }
    }
  }
}
