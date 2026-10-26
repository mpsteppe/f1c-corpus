int __stdcall sub_5A9920(int a1)
{
  float *v1; // ebx
  int v2; // eax
  float *v3; // edx
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  int v8; // eax
  int v9; // eax
  int v10; // edi
  int result; // eax
  float v12; // [esp+0h] [ebp-2Ch]
  float v13; // [esp+0h] [ebp-2Ch]
  float v14; // [esp+14h] [ebp-18h]
  BOOL v15; // [esp+18h] [ebp-14h]
  BOOL v16; // [esp+1Ch] [ebp-10h]
  float *v17; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  int v19[7]; // [esp+2Ch] [ebp+0h] BYREF
  int v20[7]; // [esp+48h] [ebp+1Ch] BYREF

  v1 = (float *)a1;
  v2 = 0;
  v3 = (float *)&unk_61BB94;
  v18 = 0;
  v17 = (float *)&unk_61BB94;
  while ( 1 )
  {
    switch ( v2 )
    {
      case 0:
      case 1:
        v4 = *v1 * *(v3 - 3) + *v3;
        *(float *)&a1 = v4;
        v15 = v4 > 0.0;
        v5 = v1[7] * *(v3 - 3);
        goto LABEL_5;
      case 2:
      case 3:
        v6 = v1[1] * *(v3 - 2) + *v3;
        *(float *)&a1 = v6;
        v15 = v6 > 0.0;
        v5 = v1[8] * *(v3 - 2);
LABEL_5:
        v7 = v5 + *v3;
        v14 = v7;
        v16 = v7 > 0.0;
        break;
      default:
        break;
    }
    v8 = v15 + 2 * v16;
    if ( !v8 )
    {
      qmemcpy(v19, v1, sizeof(v19));
      goto LABEL_12;
    }
    v9 = v8 - 1;
    if ( v9 )
      break;
    v13 = (*v3 - *(float *)&a1) / (v14 - *(float *)&a1);
    sub_5A9AA0((int)v1, (int)(v1 + 7), (int)v19, v13);
    v3 = v17;
LABEL_12:
    qmemcpy(v20, v1 + 7, sizeof(v20));
LABEL_13:
    v3 += 4;
    v10 = v18 + 1;
    v1 = (float *)v19;
    result = 2;
    ++v18;
    v17 = v3;
    if ( (int)v3 >= (int)flt_61BBD4 )
      return result;
    v2 = v10;
  }
  if ( v9 == 1 )
  {
    qmemcpy(v19, v1, sizeof(v19));
    v12 = (*v3 - *(float *)&a1) / (v14 - *(float *)&a1);
    sub_5A9AA0((int)v1, (int)(v1 + 7), (int)v20, v12);
    v3 = v17;
    goto LABEL_13;
  }
  return 0;
}
