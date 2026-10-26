int __fastcall sub_54EB40(int a1, float **a2, float *a3)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // esi
  double v7; // st7
  double v8; // st6
  double v9; // st5
  int result; // eax
  float *v11; // ecx
  float *v12; // edx
  float *v13; // esi
  double v14; // st7
  float *v15; // edx
  float *v16; // ecx
  float *v17; // esi
  float *v18; // ecx
  float *v19; // edx
  float *v20; // esi

  switch ( a1 )
  {
    case 0:
      v4 = a2[1];
      v5 = *a2;
      if ( (v4[2] - (*a2)[2]) * (a3[1] - (*a2)[1]) - (v4[1] - (*a2)[1]) * (a3[2] - (*a2)[2]) < 0.0 )
        goto LABEL_28;
      v6 = a2[2];
      if ( (v6[2] - v4[2]) * (a3[1] - v4[1]) - (v6[1] - v4[1]) * (a3[2] - v4[2]) < 0.0 )
        goto LABEL_28;
      v7 = (v5[2] - v6[2]) * (a3[1] - v6[1]);
      v8 = v5[1] - v6[1];
      v9 = a3[2] - v6[2];
      goto LABEL_5;
    case 1:
      v11 = a2[1];
      v12 = *a2;
      if ( (v11[2] - (*a2)[2]) * (a3[1] - (*a2)[1]) - (v11[1] - (*a2)[1]) * (a3[2] - (*a2)[2]) > 0.0 )
        goto LABEL_28;
      v13 = a2[2];
      if ( (v13[2] - v11[2]) * (a3[1] - v11[1]) - (v13[1] - v11[1]) * (a3[2] - v11[2]) > 0.0 )
        goto LABEL_28;
      v14 = (v12[2] - v13[2]) * (a3[1] - v13[1]) - (v12[1] - v13[1]) * (a3[2] - v13[2]);
      goto LABEL_27;
    case 2:
      v15 = *a2;
      v16 = a2[1];
      if ( (a3[2] - (*a2)[2]) * (*v16 - **a2) - (v16[2] - (*a2)[2]) * (*a3 - **a2) >= 0.0 )
      {
        v17 = a2[2];
        if ( (*v17 - *v16) * (a3[2] - v16[2]) - (v17[2] - v16[2]) * (*a3 - *v16) >= 0.0 )
        {
          v7 = (a3[2] - v17[2]) * (*v15 - *v17);
          v8 = v15[2] - v17[2];
          v9 = *a3 - *v17;
LABEL_5:
          if ( v7 - v8 * v9 >= 0.0 )
            goto LABEL_6;
        }
      }
      goto LABEL_28;
    case 3:
      v18 = a2[1];
      v19 = *a2;
      if ( (*v18 - **a2) * (a3[2] - (*a2)[2]) - (v18[2] - (*a2)[2]) * (*a3 - **a2) > 0.0 )
        goto LABEL_28;
      v20 = a2[2];
      if ( (a3[2] - v18[2]) * (*v20 - *v18) - (v20[2] - v18[2]) * (*a3 - *v18) > 0.0 )
        goto LABEL_28;
      v14 = (*v19 - *v20) * (a3[2] - v20[2]) - (v19[2] - v20[2]) * (*a3 - *v20);
      goto LABEL_27;
    case 4:
      if ( sub_54EE90(a2[1], 0, 1) < 0.0 )
        return 0;
      if ( sub_54EE90(a2[2], 0, 1) < 0.0 )
        return 0;
      if ( sub_54EE90(*a2, 0, 1) >= 0.0 )
        goto LABEL_6;
      result = 0;
      break;
    case 5:
      if ( sub_54EE90(a2[1], 0, 1) <= 0.0 )
      {
        if ( sub_54EE90(a2[2], 0, 1) <= 0.0 )
        {
          v14 = sub_54EE90(*a2, 0, 1);
LABEL_27:
          if ( v14 <= 0.0 )
LABEL_6:
            result = 1;
          else
LABEL_28:
            result = 0;
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
      break;
    default:
      goto LABEL_6;
  }
  return result;
}
