int __stdcall sub_5F52C0(float *a1)
{
  float *v2; // eax
  int v3; // ecx
  double v4; // st7
  float *v5; // ebx
  float *v6; // ebp
  double v7; // st7
  float *v8; // eax
  double v9; // st7
  double v10; // st7
  int v11; // ecx
  int v12; // ecx
  double v13; // st6
  double v14; // st6
  float *v15; // esi
  int v16; // ebp
  float v18; // [esp+Ch] [ebp-48h]
  BOOL v19; // [esp+10h] [ebp-44h]
  BOOL v20; // [esp+14h] [ebp-40h]
  int v21; // [esp+18h] [ebp-3Ch]
  char v22; // [esp+1Ch] [ebp-38h] BYREF
  float *v23; // [esp+58h] [ebp+4h]

  v2 = (float *)&unk_910F0C;
  v3 = 0;
  v23 = (float *)&unk_910F0C;
  v4 = COERCE_FLOAT(&unk_910F0C);
  v5 = (float *)&v22;
  v21 = 0;
  while ( 1 )
  {
    v6 = a1 + 7;
    switch ( v3 )
    {
      case 0:
      case 1:
        v7 = *(v2 - 3) * *a1 + *v2;
        v18 = v7;
        v19 = v7 > 0.0;
        v8 = v23;
        v9 = *(v23 - 3) * *v6;
        goto LABEL_4;
      case 2:
      case 3:
        v10 = a1[1] * *(v2 - 2) + *v2;
        v18 = v10;
        v19 = v10 > 0.0;
        v8 = v23;
        v9 = a1[8] * *(v23 - 2);
LABEL_4:
        v4 = v9 + *v8;
        v2 = v23;
        v20 = v4 > 0.0;
        break;
      default:
        break;
    }
    v11 = v19 + 2 * v20;
    if ( !v11 )
    {
      qmemcpy(v5, a1, 0x1Cu);
      goto LABEL_12;
    }
    v12 = v11 - 1;
    if ( !v12 )
    {
      v14 = (*v2 - v18) / (v4 - v18);
      *v5 = (*v6 - *a1) * v14 + *a1;
      v5[1] = (a1[8] - a1[1]) * v14 + a1[1];
LABEL_12:
      qmemcpy(v5 + 7, v6, 0x1Cu);
      goto LABEL_13;
    }
    if ( v12 != 1 )
      return 0;
    qmemcpy(v5, a1, 0x1Cu);
    v13 = (*v2 - v18) / (v4 - v18);
    v5[7] = (*v6 - *a1) * v13 + *a1;
    v5[8] = (a1[8] - a1[1]) * v13 + a1[1];
LABEL_13:
    v2 += 4;
    v15 = a1;
    v16 = v21 + 1;
    a1 = v5;
    v5 = v15;
    ++v21;
    v23 = v2;
    if ( (int)v2 >= (int)flt_910F4C )
      return 2;
    v3 = v16;
  }
}
