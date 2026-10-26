void __thiscall sub_535250(int this, float a2)
{
  double v3; // st7
  double v4; // st7
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2
  int v8; // [esp+4h] [ebp-4h]

  sub_533800((_DWORD *)(this + 156), a2);
  v8 = *(_DWORD *)(this + 44);
  *(_DWORD *)(this + 44) = v8 + 1;
  v3 = (double)v8 * *(float *)(this + 80) + a2;
  if ( v8 == -1 )
    *(_DWORD *)(this + 44) = 1;
  v4 = v3 / (double)*(int *)(this + 44);
  *(float *)(this + 80) = v4;
  if ( v6 | v7 )
  {
    *(_DWORD *)(this + 80) = 1116471296;
  }
  else if ( v4 > 120.0 )
  {
    *(_DWORD *)(this + 80) = 1123024896;
  }
}
