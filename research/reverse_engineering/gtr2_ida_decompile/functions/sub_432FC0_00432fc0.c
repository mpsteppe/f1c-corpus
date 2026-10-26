int __thiscall sub_432FC0(int this, int a2, double a3)
{
  double v3; // st7
  double v4; // st7
  char *v5; // edx
  const char *v7; // [esp+8h] [ebp-4h]

  v3 = (double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2;
  if ( a3 != 0.0 )
    v3 = v3
       + ((double)*(int *)(this + 3268) * *(double *)(this + 3256) + *(double *)(this + 3248))
       * *(double *)(this + 6944)
       * a3;
  v4 = v3 * 100.0;
  v7 = (const char *)(this + 24);
  v5 = (char *)(a2 + 30);
  if ( *(_DWORD *)(this + 4) )
    return sprintf(v5, "%.3f %s", v4 * 0.3937007874015748, v7);
  else
    return sprintf(v5, "%.1f %s", v4, v7);
}
