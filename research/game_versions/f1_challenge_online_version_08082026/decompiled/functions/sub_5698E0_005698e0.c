int __thiscall sub_5698E0(_DWORD *this, int a2, int a3, char a4, int a5)
{
  int v5; // esi

  v5 = this[142] + 132 * this[141]++;
  *(_DWORD *)(v5 + 120) = a5;
  *(_DWORD *)(v5 + 124) = a3;
  *(_BYTE *)(v5 + 128) = a4;
  sub_56C3A0(v5 + 24, v5 + 48);
  return v5;
}
