// f1c  0x004c8830  size=102
void __thiscall sub_4C8830(int this, float a2)
{
  if ( *(_BYTE *)(this + 16) && dword_8AC4C8 && *(float *)(dword_8AC4C8 + 4) != flt_7CF380 && flt_7CF380 != 0.0 )
  {
    *(_DWORD *)(this + 20) = 1;
    if ( a2 <= 0.0 )
      *(float *)(this + 24) = flt_7CF380;
    else
      *(float *)(this + 24) = flt_7CF380 / a2;
  }
}
