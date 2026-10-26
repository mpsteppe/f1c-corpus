int __thiscall sub_432EE0(const char *this, int a2, char a3)
{
  double v3; // st7
  int v4; // eax
  const char *v6; // [esp+8h] [ebp-8h]

  if ( !a3 || *(_DWORD *)(a2 + 20) )
    v3 = ((double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2) * 0.001;
  else
    v3 = 0.0;
  if ( *((_DWORD *)this + 1) == 1 )
    v3 = v3 * 5.710147155067049;
  v6 = this + 56;
  v4 = sub_431910(v3);
  return sprintf((char *const)(a2 + 30), "%d %s", v4, v6);
}
