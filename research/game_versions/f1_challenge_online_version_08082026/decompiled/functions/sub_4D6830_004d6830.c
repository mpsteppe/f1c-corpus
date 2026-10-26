double __thiscall sub_4D6830(int this, double a2, double a3)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  double v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+14h] [ebp+Ch]

  v7 = a3 / a2 * *(double *)(this + 8);
  sub_5895A2(v7);
  v8 = v7;
  v4 = (int)v8;
  v5 = *(_DWORD *)(this + 16);
  if ( v4 >= v5 )
    v4 = v5 - 1;
  return ((v7 * *(double *)(32 * v4 + *(_DWORD *)(this + 20)) + *(double *)(*(_DWORD *)(this + 20) + 32 * v4 + 8)) * v7
        + *(double *)(*(_DWORD *)(this + 20) + 32 * v4 + 16))
       * v7
       + *(double *)(*(_DWORD *)(this + 20) + 32 * v4 + 24);
}
