// f1c  0x0054fa00  size=74
int __thiscall sub_54FA00(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // edx
  int v4; // ecx
  _DWORD *v5; // eax

  v3 = this[120];
  v4 = *(_DWORD *)(v3 + 8);
  if ( v4 && a3 < *(_DWORD *)(v3 + 4) )
  {
    v5 = (_DWORD *)(v4 + 116 * a3);
    v5[1] = *a2;
    v5[2] = a2[1];
    v5[3] = a2[2];
    v5[7] = a2[3];
    v5[8] = a2[4];
    v5[9] = a2[5];
    *v5 |= 8u;
  }
  return 0;
}
