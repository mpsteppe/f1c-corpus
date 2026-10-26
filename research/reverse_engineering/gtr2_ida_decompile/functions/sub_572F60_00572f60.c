char __thiscall sub_572F60(int this)
{
  char result; // al
  double v2; // st7

  result = *(_BYTE *)(this + 188);
  if ( !result )
  {
    v2 = *(float *)(this + 240);
    *(_BYTE *)(this + 188) = 1;
    *(float *)(this + 240) = v2 * 0.28;
    *(float *)(this + 244) = *(float *)(this + 244) * 4.0;
    *(float *)(this + 160) = *(float *)(this + 160) * 0.30000001;
    *(float *)(this + 164) = *(float *)(this + 164) * 0.30000001;
    *(float *)(this + 156) = *(float *)(this + 156) * 0.30000001;
  }
  return result;
}
