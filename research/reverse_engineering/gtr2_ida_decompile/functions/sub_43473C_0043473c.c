// local variable allocation has failed, the output may be wrong!
double __userpurge sub_43473C@<st0>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        double a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        char a18,
        int a19,
        int a20,
        double a21,
        int a22,
        int a23,
        int a24,
        int a25,
        char a26)
{
  double *v27; // edi
  double *v28; // eax
  double v29; // st7
  int v30; // edi
  double v31; // st7
  double v33; // [esp+18h] [ebp-3Ch]
  __int128 v34; // [esp+20h] [ebp-34h]
  _BYTE v35[24]; // [esp+30h] [ebp-24h] BYREF
  double v36; // [esp+4Ch] [ebp-8h] OVERLAPPED BYREF
  int retaddr; // [esp+54h] [ebp+0h] OVERLAPPED
  double v39; // [esp+58h] [ebp+4h]
  _BYTE v40[24]; // [esp+5Ch] [ebp+8h]
  double v41; // [esp+70h] [ebp+1Ch]
  double v42; // [esp+84h] [ebp+30h]

  if ( !sub_560950(&dword_FAE908, &unk_FAF650) )
    return 0.0;
  v27 = (double *)sub_560800(*(_DWORD *)(a1 + 3012));
  if ( !v27 )
    return 0.0;
  v28 = (double *)sub_560800(*(_DWORD *)(a1 + 3076));
  if ( !v28 )
    return 0.0;
  *(double *)&v40[8] = (double)*(int *)(a1 + 3204) * *(double *)(a1 + 3192) + *(double *)(a1 + 3184);
  v36 = 1.0 - *(double *)&v40[8];
  if ( dword_FB0A90 )
  {
    if ( dword_FB0A90 == 1 )
    {
      retaddr = 4;
      *(double *)v40 = 0.5
                     / (v36 * 0.8200000000000001 + *(double *)&v40[8] * 1.18)
                     * (*(double *)&v40[8] * v28[190] * 1.18 + v36 * v27[66] * 0.8200000000000001);
      *(double *)&v35[4] = (v28[201] + v27[77]) * 0.5;
      *(double *)((char *)&v34 + 4) = (v28[199] + v27[75]) * 0.5;
      sub_55F390(&a26);
      v29 = 1.0;
    }
    else
    {
      if ( dword_FB0A90 != 2 )
        return 0.0;
      retaddr = 2;
      *(double *)v40 = v27[66];
      *(double *)&v35[4] = v27[77];
      *(double *)((char *)&v34 + 4) = v27[75];
      sub_55F390(&a26);
      v29 = *(double *)&v35[4];
    }
  }
  else
  {
    retaddr = 2;
    *(double *)v40 = v28[190];
    *(double *)&v35[4] = v28[201];
    *(double *)((char *)&v34 + 4) = v28[199];
    sub_55F390(&a26);
    v29 = v36;
  }
  *(double *)&retaddr = v29;
  *(double *)&v40[16] = a8 * 0.98;
  if ( *(double *)&v40[16] <= 0.0 )
    return 0.0;
  sub_434330(a1, (int)&unk_FAF5C8, (float *)&v36, (float *)&v35[4]);
  v42 = ((double)*(int *)(a1 + 3332) * *(double *)(a1 + 3320) + *(double *)(a1 + 3312)) * 0.74 + dbl_FAF608;
  *(double *)&v35[12] = (double)*(int *)&v35[12];
  sub_431AB0(
    &a21,
    (v42 * *(double *)v40 * 9.81 - *(float *)&v35[4] * *(double *)&retaddr * *(double *)(a2 + 8) * *(double *)(a2 + 8))
  / *(double *)&v35[12]);
  v30 = 45;
  v31 = 0.0;
  *(double *)&v40[8] = 0.0;
  do
  {
    if ( !*(_BYTE *)((v30 << 6) + a1 + 3020) )
      break;
    LODWORD(v34) = v30;
    sub_4318C0();
    v39 = v31;
    if ( v31 <= 0.0 )
      return 0.0;
    v41 = 1.0 / *(double *)&v40[12];
    *(double *)v35 = v41 * v31 * *(double *)(a2 + 8);
    *(double *)&v35[16] = (double)*(int *)(a1 + 5572) * *(double *)(a1 + 5560) + *(double *)(a1 + 5552);
    v31 = *(double *)v35;
    if ( *(double *)v35 <= *(double *)&v35[16] )
    {
      HIDWORD(v33) = (char *)&v36 + 4;
      LODWORD(v33) = &a18;
      sub_585E70(&unk_FAF5C8, *(_DWORD *)v35, *(_DWORD *)&v35[4]);
      if ( v30 == 45 )
      {
        *(double *)v35 = (*(double *)v35 - dbl_FAFD28) * 0.1000000014901161 + dbl_FAFD28;
        if ( (*(double *)v35 - *(double *)&v34) * 0.1 > 0.0 )
        {
          *((double *)&v34 + 1) = *(double *)&v34;
          if ( *(double *)&v34 <= *(double *)v35 )
          {
            do
            {
              sub_585E70(&unk_FAF5C8, v30, DWORD1(v34));
              if ( *(double *)v35 < *(double *)&v40[12] )
                *(double *)v35 = *(double *)&v40[12];
              v33 = v33 + v41;
            }
            while ( v33 <= *(double *)&v34 );
          }
        }
      }
      v31 = *(double *)((char *)&v36 + 4) * *(double *)v35 * *(double *)&v35[8];
      if ( v31 > v39 )
        v31 = v39;
      if ( *(double *)&v35[16] < v31 )
        *(double *)&v35[16] = v31;
    }
    ++v30;
  }
  while ( v30 <= 51 );
  return (*(double *)&v35[16] - *((float *)&v34 + 2) * *(double *)(a2 + 8) * *(double *)(a2 + 8)) / *(double *)&v40[4];
}
