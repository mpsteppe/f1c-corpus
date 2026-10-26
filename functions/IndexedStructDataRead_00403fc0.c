int __thiscall sub_403FC0(_DWORD *this, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v5; // esi
  _DWORD *v6; // ecx
  int result; // eax

  v5 = (_DWORD *)(this[86] + 28 * (a2 + a3 * this[89]));
  *a4 = *v5;
  a4[1] = v5[1];
  a4[2] = v5[2];
  v6 = (_DWORD *)(28 * (a2 + a3 * this[89]) + this[86] + 12);
  *a5 = *v6;
  result = v6[1];
  a5[1] = result;
  a5[2] = v6[2];
  return result;
}
