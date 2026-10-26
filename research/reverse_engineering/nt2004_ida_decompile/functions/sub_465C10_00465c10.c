char __thiscall sub_465C10(int *this, int a2, _DWORD *a3, float a4)
{
  int v5; // esi
  char v7; // bl
  int v8; // ecx
  float v10; // [esp+14h] [ebp+4h]

  v5 = 6326 * a2;
  v10 = *((float *)&unk_6310C4 + 6326 * a2);
  v7 = sub_52EE00(a4, a2, (int)a3, v10, 0);
  if ( v7 )
  {
    sub_45FE40(*this, (int)a3, a3);
    sub_52E740((int)a3, v10);
    v8 = a3[3];
    if ( (dword_632238[v5] & 2) != 0 )
    {
      a3[3] = v8 | 0x1000000;
      return v7;
    }
    a3[3] = v8 & 0xFEFFFFFF;
  }
  return v7;
}
