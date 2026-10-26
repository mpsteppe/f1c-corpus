int __thiscall sub_4474F0(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  int result; // eax
  int v5; // ecx
  double *v6; // esi
  double *v7; // eax
  _DWORD *v8; // ecx
  double *v9; // edx
  double *v10; // edi
  double *v11; // eax
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st7
  double v16; // st6
  double v17; // st5
  double v18; // st7
  double v19; // st6
  double v20; // st5
  bool v21; // cc
  int v22; // edi
  int v23; // [esp+10h] [ebp-10h]
  int v25; // [esp+18h] [ebp-8h]
  int v26; // [esp+1Ch] [ebp-4h]

  v2 = this;
  v3 = (int)&this[320 * a2 + 178];
  *(double *)(v3 + 472) = 0.0;
  v26 = v3;
  *(double *)(v3 + 480) = 0.0;
  *(_BYTE *)(v3 + 457) = 1;
  sub_446A80();
  result = 0;
  v25 = 0;
  if ( (int)v2[1565] > 0 )
  {
    v23 = 0;
    while ( 1 )
    {
      v5 = v2[1566];
      v6 = *(double **)(v3 + 352);
      v7 = *(double **)(v5 + v23 + 4);
      v8 = (_DWORD *)(v23 + v5);
      if ( v7 == v6 )
        break;
      if ( (double *)v8[3] == v6 )
      {
        v9 = (double *)v8[4];
        v10 = (double *)v8[2];
LABEL_7:
        if ( v9 && v10 )
        {
          v11 = *(double **)(v3 + 356);
          if ( (v23 == 112 || v23 == 168) && this[1458] )
            v11 = (double *)this[1458];
          v12 = v6[6] * v9[2] + v6[5] * v9[1] + v6[4] * *v9;
          v13 = v6[9] * v9[2] + v6[8] * v9[1] + v6[7] * *v9;
          v14 = v6[12] * v9[2] + v6[11] * v9[1] + v6[10] * *v9;
          *v10 = v14 * v11[10] + v13 * v11[7] + v12 * v11[4];
          v10[1] = v14 * v11[11] + v13 * v11[8] + v12 * v11[5];
          v10[2] = v14 * v11[12] + v13 * v11[9] + v12 * v11[6];
          v15 = v6[6] * v9[5] + v6[5] * v9[4] + v9[3] * v6[4];
          v16 = v6[7] * v9[3] + v6[9] * v9[5] + v6[8] * v9[4];
          v17 = v6[10] * v9[3] + v6[12] * v9[5] + v6[11] * v9[4];
          v10[3] = v17 * v11[10] + v16 * v11[7] + v15 * v11[4];
          v10[4] = v17 * v11[11] + v16 * v11[8] + v15 * v11[5];
          v10[5] = v17 * v11[12] + v16 * v11[9] + v15 * v11[6];
          v18 = v6[6] * v9[8] + v6[5] * v9[7] + v9[6] * v6[4];
          v19 = v6[7] * v9[6] + v6[9] * v9[8] + v6[8] * v9[7];
          v20 = v6[10] * v9[6] + v6[12] * v9[8] + v6[11] * v9[7];
          v10[6] = v20 * v11[10] + v19 * v11[7] + v18 * v11[4];
          v10[7] = v20 * v11[11] + v19 * v11[8] + v18 * v11[5];
          v10[8] = v20 * v11[12] + v19 * v11[9] + v18 * v11[6];
          sub_61D020();
          v3 = v26;
        }
        v2 = this;
      }
      result = v25 + 1;
      v21 = ++v25 < v2[1565];
      v23 += 56;
      if ( !v21 )
        goto LABEL_16;
    }
    v9 = (double *)v8[2];
    v10 = (double *)v8[4];
    goto LABEL_7;
  }
LABEL_16:
  *(_BYTE *)(v3 + 457) = 0;
  *(double *)(v3 + 488) = 0.0;
  v22 = v2[2348];
  if ( *(_DWORD *)(v22 + 19384) == 4 )
    *(_DWORD *)(v22 + 19384) = 0;
  return result;
}
