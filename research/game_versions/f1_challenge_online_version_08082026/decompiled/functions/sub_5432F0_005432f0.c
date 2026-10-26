int __thiscall sub_5432F0(
        _DWORD *this,
        float a2,
        int a3,
        _DWORD *a4,
        int a5,
        int a6,
        float a7,
        float a8,
        int a9,
        int a10)
{
  _DWORD *v10; // esi
  int v12; // ebx
  int v13; // ebp
  int v14; // eax
  double v15; // st7
  double v16; // st7
  int v17; // eax
  double v18; // st6
  int result; // eax
  float v20; // [esp+10h] [ebp-4h]

  v10 = a4;
  if ( a10 >= 0 )
  {
    v16 = (double)(int)this[7];
    v17 = sub_587BDC(v16);
    v18 = (double)(int)this[8];
    a10 = v17;
    v20 = v18;
    a2 = COERCE_FLOAT(sub_587BDC(v16));
    v12 = sub_587BDC(v16);
    a4 = (_DWORD *)v12;
    v13 = sub_587BDC(v16);
    a6 = v13;
    v14 = sub_587BDC(v16 * a7);
    v15 = v20 * a8;
  }
  else
  {
    a10 = sub_587BDC(a2);
    a2 = COERCE_FLOAT(sub_587BDC(*(float *)&a3));
    v12 = sub_587BDC(*(float *)&a5);
    a4 = (_DWORD *)v12;
    v13 = sub_587BDC(*(float *)&a6);
    a6 = v13;
    v14 = sub_587BDC(a7);
    v15 = a8;
  }
  a3 = v14;
  *(float *)&a5 = COERCE_FLOAT(sub_587BDC(v15));
  if ( v12 < 0 )
    a10 -= v12;
  if ( v13 < 0 )
    LODWORD(a2) -= v13;
  sub_543540(&a10, &a2, &a3, &a5);
  sub_543540(&a4, &a6, &a3, &a5);
  result = a3;
  if ( a3 > 0 && a5 > 0 )
  {
    result = sub_540250(dword_8B78A0, this, a10, SLODWORD(a2), v10, (int)a4, a6, a3, a5, a9);
    v10[6] &= ~0x400u;
  }
  return result;
}
