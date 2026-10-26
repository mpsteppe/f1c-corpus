void __thiscall sub_543920(int this, float a2)
{
  if ( a2 >= 0.0 && a2 <= 1.0 )
  {
    *(float *)(this + 400) = a2;
    *(_DWORD *)(this + 236) |= 0x10000u;
  }
}

