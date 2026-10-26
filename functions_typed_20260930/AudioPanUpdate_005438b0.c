int __thiscall sub_5438B0(int this, float a2, float a3)
{
  int result; // eax

  if ( a2 >= 0.0 )
    *(float *)(this + 404) = a2;
  if ( a3 < (double)*(float *)(this + 404) )
  {
    result = *(_DWORD *)(this + 404);
    *(_DWORD *)(this + 408) = result;
    *(_DWORD *)(this + 236) |= 0x10000u;
  }
  else
  {
    result = *(_DWORD *)(this + 236) | 0x10000;
    *(float *)(this + 408) = a3;
    *(_DWORD *)(this + 236) = result;
  }
  return result;
}

