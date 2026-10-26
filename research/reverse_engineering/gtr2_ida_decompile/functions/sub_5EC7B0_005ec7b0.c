int __usercall sub_5EC7B0@<eax>(int a1@<eax>, float **a2@<edx>, float *a3@<ecx>)
{
  float *v3; // esi
  float *v4; // edi
  float *v5; // edx
  double v6; // st7
  double v7; // st6
  double v8; // st5
  float *v9; // esi
  float *v10; // edi
  float *v11; // edx
  double v12; // st7
  double v13; // st6
  double v14; // st5
  float *v16; // edi
  float *v17; // esi
  float *v18; // edx
  float *v19; // edi
  float *v20; // esi
  float *v21; // edx
  float *v22; // esi
  float *v23; // edi
  float *v24; // edx
  float *v25; // esi
  float *v26; // edi
  float *v27; // edx

  switch ( a1 )
  {
    case 0:
      v3 = a2[1];
      v4 = *a2;
      if ( (v3[2] - (*a2)[2]) * (a3[1] - (*a2)[1]) - (v3[1] - (*a2)[1]) * (a3[2] - (*a2)[2]) < 0.0 )
        return 0;
      v5 = a2[2];
      if ( (v5[2] - v3[2]) * (a3[1] - v3[1]) - (v5[1] - v3[1]) * (a3[2] - v3[2]) < 0.0 )
        return 0;
      v6 = (v4[2] - v5[2]) * (a3[1] - v5[1]);
      v7 = v4[1] - v5[1];
      v8 = a3[2] - v5[2];
      return v6 - v7 * v8 >= 0.0;
    case 1:
      v9 = a2[1];
      v10 = *a2;
      if ( (v9[2] - (*a2)[2]) * (a3[1] - (*a2)[1]) - (v9[1] - (*a2)[1]) * (a3[2] - (*a2)[2]) > 0.0 )
        return 0;
      v11 = a2[2];
      if ( (v11[2] - v9[2]) * (a3[1] - v9[1]) - (v11[1] - v9[1]) * (a3[2] - v9[2]) > 0.0 )
        return 0;
      v12 = (v10[2] - v11[2]) * (a3[1] - v11[1]);
      v13 = v10[1] - v11[1];
      v14 = a3[2] - v11[2];
      return v12 - v13 * v14 <= 0.0;
    case 2:
      v16 = *a2;
      v17 = a2[1];
      if ( (a3[2] - (*a2)[2]) * (*v17 - **a2) - (v17[2] - (*a2)[2]) * (*a3 - **a2) < 0.0 )
        return 0;
      v18 = a2[2];
      if ( (a3[2] - v17[2]) * (*v18 - *v17) - (v18[2] - v17[2]) * (*a3 - *v17) < 0.0 )
        return 0;
      v6 = (a3[2] - v18[2]) * (*v16 - *v18);
      v7 = v16[2] - v18[2];
      v8 = *a3 - *v18;
      return v6 - v7 * v8 >= 0.0;
    case 3:
      v19 = *a2;
      v20 = a2[1];
      if ( (a3[2] - (*a2)[2]) * (*v20 - **a2) - (v20[2] - (*a2)[2]) * (*a3 - **a2) > 0.0 )
        return 0;
      v21 = a2[2];
      if ( (a3[2] - v20[2]) * (*v21 - *v20) - (v21[2] - v20[2]) * (*a3 - *v20) > 0.0 )
        return 0;
      return (a3[2] - v21[2]) * (*v19 - *v21) - (v19[2] - v21[2]) * (*a3 - *v21) <= 0.0;
    case 4:
      v22 = a2[1];
      v23 = *a2;
      if ( (v22[1] - (*a2)[1]) * (*a3 - **a2) - (*v22 - **a2) * (a3[1] - (*a2)[1]) < 0.0 )
        return 0;
      v24 = a2[2];
      if ( (v24[1] - v22[1]) * (*a3 - *v22) - (*v24 - *v22) * (a3[1] - v22[1]) < 0.0 )
        return 0;
      v6 = (v23[1] - v24[1]) * (*a3 - *v24);
      v7 = *v23 - *v24;
      v8 = a3[1] - v24[1];
      return v6 - v7 * v8 >= 0.0;
    case 5:
      v25 = a2[1];
      v26 = *a2;
      if ( (v25[1] - (*a2)[1]) * (*a3 - **a2) - (*v25 - **a2) * (a3[1] - (*a2)[1]) > 0.0 )
        return 0;
      v27 = a2[2];
      if ( (v27[1] - v25[1]) * (*a3 - *v25) - (*v27 - *v25) * (a3[1] - v25[1]) > 0.0 )
        return 0;
      v12 = (v26[1] - v27[1]) * (*a3 - *v27);
      v13 = *v26 - *v27;
      v14 = a3[1] - v27[1];
      return v12 - v13 * v14 <= 0.0;
    default:
      return 1;
  }
}
