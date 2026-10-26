int __thiscall sub_59FE60(int *this, float a2, int a3, int a4, int a5, float a6, float a7, float a8, int a9, int a10)
{
  int v10; // esi
  int v12; // ebx
  float v13; // ebp
  __int64 v14; // rax
  double v15; // st7
  double v16; // st7
  double v17; // st6
  __int64 v18; // rax
  double v19; // st6
  __int64 v20; // rax
  double v21; // st6
  int result; // eax
  float v23; // [esp+10h] [ebp-4h]

  v10 = a4;
  if ( a10 >= 0 )
  {
    v16 = (double)this[7];
    v17 = (double)this[8];
    a10 = (__int64)(a2 * v16);
    v23 = v17;
    v18 = (__int64)(v17 * *(float *)&a3);
    v19 = (double)*(int *)(a4 + 28);
    a2 = *(float *)&v18;
    v20 = (__int64)(v19 * *(float *)&a5);
    v21 = (double)*(int *)(a4 + 32);
    v12 = v20;
    a4 = v20;
    LODWORD(v13) = (__int64)(v21 * a6);
    a6 = v13;
    v14 = (__int64)(v16 * a7);
    v15 = v23 * a8;
  }
  else
  {
    a10 = (__int64)a2;
    LODWORD(a2) = (__int64)*(float *)&a3;
    v12 = (__int64)*(float *)&a5;
    a4 = v12;
    LODWORD(v13) = (__int64)a6;
    a6 = v13;
    v14 = (__int64)a7;
    v15 = a8;
  }
  a3 = v14;
  a5 = (__int64)v15;
  if ( v12 < 0 )
    a10 -= v12;
  if ( v13 < 0.0 )
    LODWORD(a2) -= LODWORD(v13);
  sub_5A00B0(&a10, &a2, &a3, &a5);
  sub_5A00B0(&a4, &a6, &a3, &a5);
  result = a3;
  if ( a3 > 0 && a5 > 0 )
  {
    result = sub_5A72D0(this, a10, LODWORD(a2), v10, a4, LODWORD(a6), a3, a5, a9);
    *(_DWORD *)(v10 + 56) &= ~0x400u;
  }
  return result;
}
