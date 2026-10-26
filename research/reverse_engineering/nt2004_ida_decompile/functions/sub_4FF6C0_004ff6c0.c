double __thiscall sub_4FF6C0(int this, double a2, double a3)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  float v7; // [esp+4h] [ebp-10h]
  double X; // [esp+Ch] [ebp-8h]

  if ( a3 <= a2 )
  {
    X = a3 / a2 * *(double *)(this + 24);
  }
  else
  {
    X = ((*(double *)(this + 16) / a2 + *(double *)(this + 8)) * (a3 - a2) + 1.0) * *(double *)(this + 24);
    floor(X);
  }
  v7 = floor(X);
  v4 = (int)v7;
  v5 = *(_DWORD *)(this + 32);
  if ( v4 >= v5 )
    v4 = v5 - 1;
  return ((X * *(double *)(32 * v4 + *(_DWORD *)(this + 36)) + *(double *)(*(_DWORD *)(this + 36) + 32 * v4 + 8)) * X
        + *(double *)(*(_DWORD *)(this + 36) + 32 * v4 + 16))
       * X
       + *(double *)(*(_DWORD *)(this + 36) + 32 * v4 + 24);
}
