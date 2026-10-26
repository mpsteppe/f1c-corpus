double __stdcall sub_440E80(int a1, int a2)
{
  float v4; // [esp+0h] [ebp-74h]
  float v5; // [esp+4h] [ebp-70h]
  float v6; // [esp+4h] [ebp-70h]
  float v7; // [esp+8h] [ebp-6Ch]
  float v8; // [esp+8h] [ebp-6Ch]
  float v9; // [esp+8h] [ebp-6Ch]
  double v10; // [esp+24h] [ebp-50h]
  int v11; // [esp+30h] [ebp-44h] BYREF
  int v12; // [esp+34h] [ebp-40h] BYREF
  int v13; // [esp+38h] [ebp-3Ch] BYREF
  int v14; // [esp+3Ch] [ebp-38h] BYREF
  int v15; // [esp+40h] [ebp-34h] BYREF
  int v16; // [esp+44h] [ebp-30h] BYREF
  int v17; // [esp+48h] [ebp-2Ch] BYREF
  int v18; // [esp+4Ch] [ebp-28h] BYREF
  int v19[3]; // [esp+50h] [ebp-24h] BYREF
  int v20[3]; // [esp+5Ch] [ebp-18h] BYREF
  int v21[3]; // [esp+68h] [ebp-Ch] BYREF

  v10 = ((double)*(int *)(a1 + 324) * *(double *)(a1 + 312)
       + *(double *)(a1 + 304)
       + (double)*(int *)(a1 + 1028) * *(double *)(a1 + 1016)
       + *(double *)(a1 + 1008)
       + (double)*(int *)(a1 + 1732) * *(double *)(a1 + 1720)
       + *(double *)(a1 + 1712)
       + (double)*(int *)(a1 + 2436) * *(double *)(a1 + 2424)
       + *(double *)(a1 + 2416))
      * 0.1;
  v7 = (double)*(int *)(a1 + 3652) * *(double *)(a1 + 3640) + *(double *)(a1 + 3632);
  sub_585DC0(v7, (int)&v17, (int)&v16);
  v8 = (double)*(int *)(a1 + 3716) * *(double *)(a1 + 3704) + *(double *)(a1 + 3696);
  sub_585DC0(v8, (int)&v18, (int)&v15);
  *(float *)&v10 = v10;
  v5 = (double)*(int *)(a1 + 4804) * *(double *)(a1 + 4792) + *(double *)(a1 + 4784);
  sub_586060(v5, *(float *)&v10, (int)v19, (int)&v14);
  v9 = (double)*(int *)(a1 + 4868) * *(double *)(a1 + 4856) + *(double *)(a1 + 4848);
  sub_586100(v9, (int)v20, (int)&v13);
  v6 = (double)*(int *)(a1 + 4932) * *(double *)(a1 + 4920) + *(double *)(a1 + 4912);
  v4 = (double)*(int *)(a1 + 4996) * *(double *)(a1 + 4984) + *(double *)(a1 + 4976);
  sub_586190(v4, v6, *(float *)&v10, (int)v21, (int)&v12);
  sub_586200(*(float *)&v10, (int)&v11);
  return *(float *)&v11 + *(float *)&v12 + *(float *)&v13 + *(float *)&v14 + *(float *)&v15 + *(float *)&v16;
}
