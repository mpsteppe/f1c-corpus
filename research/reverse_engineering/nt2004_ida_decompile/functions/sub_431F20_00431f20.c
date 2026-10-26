int __thiscall sub_431F20(int this, int a2, double a3)
{
  double v3; // st7
  char *v4; // edx
  const char *v6; // [esp+8h] [ebp-4h]
  double v7; // [esp+14h] [ebp+8h]

  v3 = (double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2;
  if ( a3 != 0.0 )
    v3 = v3
       + ((double)*(int *)(this + 3204) * *(double *)(this + 3192) + *(double *)(this + 3184))
       * *(double *)(this + 6556)
       * a3;
  v4 = (char *)(a2 + 30);
  v7 = v3 * 100.0;
  v6 = (const char *)(this + 24);
  if ( *(_DWORD *)(this + 4) )
    return sprintf(v4, "%.3f %s", v7 * 0.3937007874015748, v6);
  else
    return sprintf(v4, "%.1f %s", v7, v6);
}
