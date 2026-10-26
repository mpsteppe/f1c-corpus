int __thiscall sub_6B39F1(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // esi
  int v5; // eax

  v4 = *(_DWORD **)(this[5] + 4 * a2);
  v5 = v4[2];
  if ( v5 != -1 && (int)sub_6B39F1(v5, a3) < 0
    || sub_6B3700(this, (int)v4) < 0
    || (int)sub_6C9357(v4[4] + 4 * v4[3]) < 0 )
  {
    return -2147024882;
  }
  ++*(_DWORD *)(this[67] + 4 * a3);
  return 0;
}
