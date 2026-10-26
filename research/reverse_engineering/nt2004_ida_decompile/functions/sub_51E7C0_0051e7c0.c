void __thiscall sub_51E7C0(int this, float a2, float a3, float a4, float a5)
{
  if ( *(_DWORD *)(this + 16500) )
  {
    *(float *)(this + 17920) = a2;
    *(float *)(this + 18168) = a3;
    *(float *)(this + 18416) = a4;
    *(float *)(this + 18664) = a5;
  }
  else
  {
    sub_445230((int)&dbl_75E930, a2, a3, a4, a5);
  }
}
