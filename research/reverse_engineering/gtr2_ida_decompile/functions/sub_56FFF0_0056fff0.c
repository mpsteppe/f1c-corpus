void __thiscall sub_56FFF0(int this, float a2)
{
  double v2; // st7
  float v3; // [esp+0h] [ebp-4h]

  if ( a2 != *(float *)(this + 3052) )
  {
    v2 = a2 / *(float *)(this + 3052);
    *(float *)(this + 3052) = a2;
    v3 = v2;
    sub_56FC30(*(_DWORD **)(this + 8), v3, 1);
  }
}
