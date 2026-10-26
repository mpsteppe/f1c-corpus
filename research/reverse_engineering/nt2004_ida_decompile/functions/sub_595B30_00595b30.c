void __thiscall sub_595B30(int this, float a2)
{
  if ( a2 >= 0.0 && a2 <= 1.0 )
  {
    *(float *)(this + 416) = a2;
    *(_DWORD *)(this + 240) |= 0x10000u;
  }
}
