void __thiscall sub_4E6360(int this, float a2)
{
  double v2; // st7
  double v3; // st7
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  int v7; // [esp+0h] [ebp-4h]

  v7 = *(_DWORD *)(this + 44);
  *(_DWORD *)(this + 44) = v7 + 1;
  v2 = (double)v7 * *(float *)(this + 80) + a2;
  if ( v7 == -1 )
    *(_DWORD *)(this + 44) = 1;
  v3 = v2 / (double)*(int *)(this + 44);
  *(float *)(this + 80) = v3;
  if ( v5 | v6 )
  {
    *(_DWORD *)(this + 80) = 1116471296;
  }
  else if ( v3 > 120.0 )
  {
    *(_DWORD *)(this + 80) = 1123024896;
  }
}
