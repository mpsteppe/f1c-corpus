int __thiscall sub_432F40(const char *this, int a2)
{
  double v3; // st7
  int v4; // eax
  const char *v5; // [esp+8h] [ebp-8h]

  if ( !byte_B724A8 )
    return sprintf((char *const)(a2 + 30), "%d", *(_DWORD *)(a2 + 20) + 1);
  v5 = this + 72;
  v3 = (double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2;
  if ( *((_DWORD *)this + 1) )
    return sprintf((char *const)(a2 + 30), "%.1f %s", v3 * 0.00571014715506705, v5);
  v4 = sub_431910(v3);
  return sprintf((char *const)(a2 + 30), "%d %s", v4, v5);
}
