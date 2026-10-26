double __thiscall sub_55FEB0(int this, double a2, double a3)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  float X_4; // [esp+4h] [ebp-8h]
  float X_4a; // [esp+4h] [ebp-8h]
  double X; // [esp+10h] [ebp+4h]

  if ( a3 <= a2 )
  {
    X = *(double *)(this + 24) / a2 * a3;
  }
  else
  {
    X = ((*(double *)(this + 16) / a2 + *(double *)(this + 8)) * (a3 - a2) + 1.0) * *(double *)(this + 24);
    X_4 = floor(X);
    sub_4015C0(X_4);
  }
  X_4a = floor(X);
  v4 = sub_4015C0(X_4a);
  v5 = *(_DWORD *)(this + 32);
  if ( v4 >= v5 )
    v4 = v5 - 1;
  return ((X * *(double *)(32 * v4 + *(_DWORD *)(this + 36)) + *(double *)(*(_DWORD *)(this + 36) + 32 * v4 + 8)) * X
        + *(double *)(*(_DWORD *)(this + 36) + 32 * v4 + 16))
       * X
       + *(double *)(*(_DWORD *)(this + 36) + 32 * v4 + 24);
}
