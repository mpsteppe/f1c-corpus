void __thiscall sub_51E4D0(int this, int a2, int ArgList, char a4)
{
  _DWORD *v5; // ecx
  char **v6; // esi
  char *v7; // eax
  int v8; // eax
  _DWORD *v9; // ecx
  double *v10; // esi
  double v11; // st7
  double v12; // st5
  double v13; // st6
  double v14; // st7
  float v15; // [esp+0h] [ebp-18h]
  float v16; // [esp+4h] [ebp-14h]

  v5 = *(_DWORD **)(this + 18696);
  *(_DWORD *)(this + 18700) = ArgList;
  v6 = (char **)sub_5009C0(v5, ArgList);
  v7 = *v6;
  if ( !*v6 )
    v7 = &byte_629120;
  v8 = sub_4BFFC0(v7);
  v9 = (_DWORD *)(this + 1808);
  if ( v8 == 5 )
    sub_50C9A0(v9, 2);
  else
    sub_50C9A0(v9, 0);
  v10 = (double *)&v6[128 * a2 + 6];
  v11 = sub_4FFA70(v10, 190.0);
  if ( v11 <= 0.0 )
    *(_DWORD *)(248 * a2 + this + 17876) = 0;
  else
    *(float *)(248 * a2 + this + 17876) = v10[29] / v11;
  *(float *)(248 * a2 + this + 17836) = (50.0 / v10[4] * v10[5] + v10[4]) * 0.9800000190734863;
  v12 = v10[42] * 0.5;
  *(float *)(248 * a2 + this + 17852) = (v10[1] + *v10) * v12;
  v13 = v10[3] + v10[2];
  *(_DWORD *)(248 * a2 + this + 17868) = 1065353216;
  *(float *)(248 * a2 + this + 17856) = v12 * v13;
  v14 = *(float *)(248 * a2 + this + 17852);
  *(float *)(248 * a2 + this + 17848) = *(float *)(248 * a2 + this + 17852);
  *(float *)(248 * a2 + this + 17872) = v10[44] * flt_7D740C;
  *(float *)(248 * a2 + this + 17848) = v14 * *(float *)(this + 19356);
  if ( v10[43] <= 0.0 )
    *(_DWORD *)(248 * a2 + this + 17840) = 1099694080;
  else
    *(float *)(248 * a2 + this + 17840) = 1.0 / v10[43];
  v16 = v10[41];
  v15 = v10[40];
  sub_4FECD0((float *)(248 * a2 + this + 17860), v15, v16);
  if ( a4 )
    sub_513830(this, 0);
  if ( !*(_DWORD *)(this + 16500) )
  {
    dword_75FFAC = ArgList;
    sub_440480(&dbl_75E930, a2);
  }
}
