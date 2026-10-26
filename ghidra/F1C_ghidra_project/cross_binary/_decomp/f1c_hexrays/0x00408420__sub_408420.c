// f1c  0x00408420  size=47
void __thiscall sub_408420(int this, float a2)
{
  *(_DWORD *)(this + 4) = 1065353216;
  if ( a2 > 0.0 )
    *(float *)(this + 8) = 1.0 / a2;
  else
    *(_DWORD *)(this + 8) = 1065353216;
}
