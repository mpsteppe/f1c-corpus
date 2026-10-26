int __thiscall sub_42F180(int this, int a2)
{
  double v3; // [esp+0h] [ebp-8h]

  v3 = ((double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2) * 0.001;
  if ( *(_DWORD *)(this + 4) == 1 )
    v3 = v3 * 5.710147155067049;
  return StringFormatWithBufferOverflowCheck(a2 + 30, "%d %s", (int)v3, (const char *)(this + 56));
}
