// f1c  0x0056c640  size=248
int __fastcall sub_56C640(double *a1, double *a2, double *a3, int a4)
{
  double v4; // st7
  double v5; // st6
  long double v6; // st5
  int result; // eax
  long double v8; // rt0
  double v9; // [esp+0h] [ebp-38h]
  double v10; // [esp+8h] [ebp-30h]
  double v11; // [esp+10h] [ebp-28h]
  double v12; // [esp+18h] [ebp-20h]
  double v13; // [esp+20h] [ebp-18h]
  double v14; // [esp+28h] [ebp-10h]
  double v15; // [esp+30h] [ebp-8h]

  v10 = *a1 - *a2;
  v11 = a1[1] - a2[1];
  v12 = a1[2] - a2[2];
  v13 = *a3 - *a2;
  v14 = a3[1] - a2[1];
  v15 = a3[2] - a2[2];
  v4 = v11 * v15 - v14 * v12;
  *(double *)a4 = v4;
  v9 = v12 * v13 - v10 * v15;
  *(double *)(a4 + 8) = v9;
  v5 = v14 * v10 - v11 * v13;
  *(double *)(a4 + 16) = v5;
  v6 = v5 * v5 + v9 * v9 + v4 * v4;
  if ( v6 <= 0.0 )
  {
    *(_DWORD *)a4 = 0;
    *(_DWORD *)(a4 + 4) = 0;
    *(_DWORD *)(a4 + 8) = 0;
    *(_DWORD *)(a4 + 16) = 0;
    *(_DWORD *)(a4 + 20) = 0;
    *(_DWORD *)(a4 + 12) = 1072693248;
    return -1;
  }
  else
  {
    result = 0;
    v8 = 1.0 / sqrt(v6);
    *(long double *)a4 = v4 * v8;
    *(long double *)(a4 + 8) = v9 * v8;
    *(long double *)(a4 + 16) = v5 * v8;
  }
  return result;
}
