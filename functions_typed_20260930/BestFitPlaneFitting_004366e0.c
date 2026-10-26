long double *__fastcall sub_4366E0(int a1, int a2, long double *a3, long double *a4)
{
  int v5; // esi
  double *v6; // edx
  int v7; // ecx
  double v8; // st7
  int v9; // eax
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st3
  double v14; // st2
  double v15; // st1
  double v16; // st0
  long double *result; // eax
  long double v18; // st7
  _DWORD v20[3]; // [esp+14h] [ebp-6Ch] BYREF
  double v21[12]; // [esp+20h] [ebp-60h] BYREF

  v5 = 0;
  v6 = v21;
  memset(v21, 0, sizeof(v21));
  do
  {
    v20[v5++] = v6;
    v6 += 4;
  }
  while ( v5 < 3 );
  v7 = a2;
  if ( a2 > 0 )
  {
    v8 = v21[0];
    v9 = a1 + 16;
    v10 = v21[1];
    v11 = v21[2];
    v12 = v21[3];
    v13 = v21[4];
    v14 = v21[5];
    do
    {
      v15 = *(double *)(v9 - 16);
      v9 += 28;
      --v7;
      v8 = v8 + v15 * v15;
      v16 = *(double *)(v9 - 28) * *(double *)(v9 - 44);
      v10 = v10 + v16;
      v11 = v11 + *(double *)(v9 - 44);
      v12 = v12 + *(double *)(v9 - 36) * *(double *)(v9 - 44);
      v13 = v13 + v16;
      v14 = v14 + *(double *)(v9 - 28) * *(double *)(v9 - 28);
      v21[6] = *(double *)(v9 - 28) + v21[6];
      v21[7] = *(double *)(v9 - 28) * *(double *)(v9 - 36) + v21[7];
      v21[8] = v21[8] + *(double *)(v9 - 44);
      v21[9] = *(double *)(v9 - 28) + v21[9];
      v21[10] = v21[10] + 1.0;
      v21[11] = *(double *)(v9 - 36) + v21[11];
    }
    while ( v7 );
    v21[5] = v14;
    v21[4] = v13;
    v21[3] = v12;
    v21[2] = v11;
    v21[1] = v10;
    v21[0] = v8;
  }
  if ( sub_5677B0(v20, 3) )
  {
    *(_DWORD *)a3 = 0;
    *((_DWORD *)a3 + 1) = 0;
    *((_DWORD *)a3 + 2) = 0;
    *((_DWORD *)a3 + 3) = 1072693248;
    *((_DWORD *)a3 + 4) = 0;
    *((_DWORD *)a3 + 5) = 0;
    result = a4;
    *(_DWORD *)a4 = *(_DWORD *)(a1 + 8);
    *((_DWORD *)a4 + 1) = *(_DWORD *)(a1 + 12);
  }
  else
  {
    v18 = 1.0 / sqrt(v21[7] * v21[7] + v21[3] * v21[3] + 1.0);
    *a3 = -(v21[3] * v18);
    a3[1] = v18;
    a3[2] = -(v21[7] * v18);
    result = a4;
    *a4 = v18 * v21[11];
  }
  return result;
}

