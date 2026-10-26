int __thiscall sub_595AC0(int this, float a2, float a3)
{
  int result; // eax

  if ( a2 >= 0.0 )
    *(float *)(this + 420) = a2;
  if ( a3 < (double)*(float *)(this + 420) )
  {
    result = *(_DWORD *)(this + 420);
    *(_DWORD *)(this + 424) = result;
    *(_DWORD *)(this + 240) |= 0x10000u;
  }
  else
  {
    result = *(_DWORD *)(this + 240) | 0x10000;
    *(float *)(this + 424) = a3;
    *(_DWORD *)(this + 240) = result;
  }
  return result;
}
