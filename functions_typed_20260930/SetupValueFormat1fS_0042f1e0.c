int __thiscall sub_42F1E0(int this, int a2)
{
  double v3; // [esp+0h] [ebp-8h]

  v3 = (double)*(int *)(a2 + 20) * *(double *)(a2 + 8) + *(double *)a2;
  if ( *(_DWORD *)(this + 4) )
    return StringFormatWithBufferOverflowCheck(a2 + 30, "%.1f %s", v3 * 0.00571014715506705, (const char *)(this + 72));
  else
    return StringFormatWithBufferOverflowCheck(a2 + 30, "%d %s", (int)v3, (const char *)(this + 72));
}

