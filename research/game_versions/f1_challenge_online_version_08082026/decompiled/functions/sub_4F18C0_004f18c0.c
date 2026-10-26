void __thiscall sub_4F18C0(int this, unsigned int a2, int a3, char a4)
{
  _DWORD *v5; // ecx
  char **v6; // edi
  char *v7; // eax
  int v8; // eax
  double *v9; // esi
  double v10; // st7
  double v11; // st5
  double v12; // st6
  double v13; // st7
  float v14; // [esp+0h] [ebp-18h]
  float v15; // [esp+4h] [ebp-14h]

  v5 = *(_DWORD **)(this + 14700);
  *(_DWORD *)(this + 14704) = a3;
  v6 = (char **)sub_4D7570(v5, a3);
  v7 = *v6;
  if ( !*v6 )
    v7 = byte_5EA438;
  v8 = sub_4A4830(v7);
  sub_4E2370((_BYTE *)(this + 1764), v8);
  v9 = (double *)(v6 + 88);
  if ( a2 <= 1 )
    v9 = (double *)(v6 + 6);
  v10 = sub_4D6AE0(v9, 190.0);
  if ( v10 <= 0.0 )
    *(_DWORD *)(248 * a2 + this + 13880) = 0;
  else
    *(float *)(248 * a2 + this + 13880) = v9[22] / v10;
  *(float *)(248 * a2 + this + 13840) = (50.0 / v9[4] * v9[5] + v9[4]) * 0.9800000190734863;
  v11 = v9[32] * 0.5;
  *(float *)(248 * a2 + this + 13856) = (v9[1] + *v9) * v11;
  v12 = v9[3] + v9[2];
  *(_DWORD *)(248 * a2 + this + 13872) = 1065353216;
  *(float *)(248 * a2 + this + 13860) = v11 * v12;
  v13 = *(float *)(248 * a2 + this + 13856);
  *(float *)(248 * a2 + this + 13852) = *(float *)(248 * a2 + this + 13856);
  *(float *)(248 * a2 + this + 13876) = v9[34];
  *(float *)(248 * a2 + this + 13852) = v13 * *(float *)(this + 15348);
  if ( v9[33] <= 0.0 )
    *(_DWORD *)(248 * a2 + this + 13844) = 1099694080;
  else
    *(float *)(248 * a2 + this + 13844) = 1.0 / v9[33];
  v15 = v9[31];
  v14 = v9[30];
  sub_4D5EA0((float *)(248 * a2 + this + 13864), v14, v15);
  if ( a4 )
    sub_4E8010(this, 0);
  if ( !*(_DWORD *)(this + 12988) )
  {
    dword_7C8884 = a3;
    sub_43DA10(&dbl_7C7428, a2);
  }
}
