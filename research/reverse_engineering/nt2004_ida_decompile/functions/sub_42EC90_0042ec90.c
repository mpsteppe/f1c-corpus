int sub_42EC90()
{
  float *v0; // esi
  double v1; // st7
  __int16 v2; // fps
  bool v3; // c0
  char v4; // c2
  bool v5; // c3
  int result; // eax
  double v7; // st7
  int v8; // edx
  float *v9; // ecx
  double v10; // st7
  double v11; // st6
  __int16 v12; // fps
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c2
  __int16 v15; // fps
  bool v16; // c0
  char v17; // c2
  bool v18; // c3
  double v19; // st6
  __int16 v20; // fps
  double v21; // st5
  bool v22; // c0
  char v23; // c2
  bool v24; // c3
  double v25; // st5
  float v26; // [esp+4h] [ebp-10h]
  float v27; // [esp+8h] [ebp-Ch]
  int v28; // [esp+Ch] [ebp-8h]
  int v29; // [esp+10h] [ebp-4h]
  float v30; // [esp+10h] [ebp-4h]

  v28 = 0;
  v0 = &flt_75ABA8;
  do
  {
    v1 = (double)v28;
    v26 = 0.06666667 * v1 + 1.0;
    v3 = v1 < 16.0;
    v4 = 0;
    v5 = v1 == 16.0;
    LOWORD(result) = v2;
    if ( v1 >= 16.0 )
      v7 = (v1 - 16.0) * 0.0089285718;
    else
      v7 = (16.0 - v1) * 0.0625;
    v8 = 0;
    v29 = 0;
    v9 = v0;
    v10 = (1.0 - v7) * (1.0 - v7) * 0.19499999;
    do
    {
      if ( v0 == (float *)&unk_75CB68 || v8 == 15 )
        goto LABEL_17;
      v11 = (double)v29;
      v27 = v11;
      LOWORD(result) = v12;
      if ( v13 | v14 )
      {
        *v9 = (1.0 - v11 / v26) * v10;
        goto LABEL_18;
      }
      v30 = v26 + 5.0;
      v16 = v11 < v30;
      v17 = 0;
      v18 = v11 == v30;
      LOWORD(result) = v15;
      if ( v11 >= v30 )
      {
LABEL_17:
        *v9 = 0.0;
      }
      else
      {
        v19 = 3.0 / v26 * v10;
        if ( v19 > v10 )
          v19 = v10;
        v21 = v26 + 2.5;
        v22 = v21 < v27;
        v23 = 0;
        v24 = v21 == v27;
        LOWORD(result) = v20;
        if ( v21 <= v27 )
          v25 = (v30 - v27) * v19 * -0.40000001;
        else
          v25 = (v27 - v26) * v19 * -0.40000001;
        *v9 = v25;
      }
LABEL_18:
      ++v8;
      ++v9;
      v29 = v8;
    }
    while ( v8 < 16 );
    v0 += 16;
    ++v28;
  }
  while ( (int)v0 < (int)&dword_75CBA8 );
  return result;
}
