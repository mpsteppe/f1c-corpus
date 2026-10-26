int __thiscall sub_431E80(int this, int a2, char a3)
{
  double v4; // [esp+0h] [ebp-8h]

  if ( !a3 || *(_DWORD *)(a2 + 20) )
    v4 = ((double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2) * 0.001;
  else
    v4 = 0.0;
  if ( *(_DWORD *)(this + 4) == 1 )
    v4 = v4 * 5.710147155067049;
  return sprintf((char *const)(a2 + 30), "%d %s", (int)v4, (const char *)(this + 56));
}
