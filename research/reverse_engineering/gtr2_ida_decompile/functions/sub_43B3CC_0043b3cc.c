int __userpurge sub_43B3CC@<eax>(
        double **a1@<ecx>,
        int a2@<ebp>,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        double a17,
        double a18,
        double a19,
        double a20,
        double a21,
        double a22,
        double a23,
        double a24,
        double a25,
        double a26,
        double a27,
        double a28,
        double a29,
        double a30,
        double a31,
        double a32,
        float a33,
        float a34,
        double a35,
        float a36,
        float a37,
        double a38,
        double a39,
        double a40,
        double a41,
        double a42)
{
  int result; // eax
  double *v44; // esi
  double *v45; // edx
  double *v46; // ecx
  double v47; // st7
  double v48; // st6
  double v49; // st7
  double v50; // st6
  double v51; // st5
  double v52; // st4
  double v53; // st3
  double v54; // st2
  double v55; // st1
  double v56; // st3
  int v57; // ebx
  long double v58; // st7
  long double v59; // st7
  double v60; // st7
  double v61; // st5
  double *v62; // edx
  bool v63; // cc
  double v64; // [esp+10h] [ebp+4h]
  double v65; // [esp+18h] [ebp+Ch]
  double v66; // [esp+20h] [ebp+14h]
  int v67; // [esp+2Ch] [ebp+20h]
  double v68; // [esp+30h] [ebp+24h]
  int v69; // [esp+3Ch] [ebp+30h]
  double v70; // [esp+40h] [ebp+34h]

  result = 0;
  if ( *a1 )
  {
    v69 = 0;
    if ( (int)a1[39] > 0 )
    {
      v44 = *(double **)(a2 + 8);
      v67 = 0;
      do
      {
        v45 = &a1[40][v67];
        v46 = *a1;
        a17 = (*a1)[6] * v45[6] + (*a1)[5] * v45[5] + (*a1)[4] * v45[4];
        a18 = v46[9] * v45[6] + v46[8] * v45[5] + v46[7] * v45[4];
        a19 = v46[12] * v45[6] + v46[11] * v45[5] + v46[10] * v45[4];
        v47 = a19 * v46[17] - a18 * v46[18];
        v48 = a17 * v46[18] - a19 * v46[16];
        a35 = a18 * v46[16] - a17 * v46[17];
        a32 = v47 + v46[13];
        v49 = v48 + v46[14];
        v50 = a35 + v46[15];
        v51 = a17 + v46[1];
        v52 = a18 + v46[2];
        *(double *)&STACK[0x160] = a19 + v46[3];
        v53 = v44[6] * v45[9] + v44[5] * v45[8] + v44[4] * v45[7];
        v54 = v44[9] * v45[9] + v44[8] * v45[8] + v44[7] * v45[7];
        v55 = v44[12] * v45[9] + v44[11] * v45[8] + v44[10] * v45[7];
        *(double *)&STACK[0x118] = v55;
        a20 = v55 * v44[17] - v54 * v44[18];
        a21 = v53 * v44[18] - *(double *)&STACK[0x118] * v44[16];
        a22 = v54 * v44[16] - v53 * v44[17];
        a20 = a20 + v44[13];
        a21 = a21 + v44[14];
        a22 = a22 + v44[15];
        *(double *)&STACK[0x138] = v53 + v44[1];
        v56 = v54 + v44[2];
        *(double *)&STACK[0x148] = *(double *)&STACK[0x118] + v44[3];
        a23 = *(double *)&STACK[0x138] - v51;
        a24 = v56 - v52;
        a25 = *(double *)&STACK[0x148] - *(double *)&STACK[0x160];
        a26 = a20 - a32;
        v57 = *(_DWORD *)v45;
        a27 = a21 - v49;
        a28 = a22 - v50;
        if ( v57 )
        {
          v64 = a23;
          v65 = a24;
          v66 = a25;
          v58 = v66 * v66 + v65 * v65 + v64 * v64;
          if ( v58 > 0.0 )
          {
            v59 = 1.0 / sqrt(v58);
            v64 = a23 * v59;
            v65 = a24 * v59;
            v66 = a25 * v59;
          }
        }
        else
        {
          v64 = v44[6] * v45[3] + v44[5] * v45[2] + v44[4] * v45[1];
          v65 = v44[9] * v45[3] + v44[8] * v45[2] + v44[7] * v45[1];
          v66 = v44[12] * v45[3] + v44[11] * v45[2] + v44[10] * v45[1];
        }
        v70 = v66 * a25 + v65 * a24 + v64 * a23;
        if ( v45[10] > 0.0 && fabs(v70) < v45[10] )
          goto LABEL_19;
        if ( v57 == 2 )
        {
          v60 = v45[12];
          a38 = a27 * v60;
          a39 = a28 * v60;
          v61 = v70 * v45[11];
          v62 = &a40;
          a29 = v64 * v61;
          a30 = v65 * v61;
          a31 = v66 * v61;
          a40 = a29 + a26 * v60;
          a41 = a30 + a38;
          a42 = a31 + a39;
        }
        else
        {
          v68 = (v66 * a28 + v65 * a27 + v64 * a26) * v45[12] + v70 * v45[11];
          if ( v45[10] > 0.0 && (v70 > 0.0 && v68 < 0.0 || v70 < 0.0 && v68 > 0.0) )
            goto LABEL_19;
          v62 = (double *)&STACK[0x120];
          *(double *)&STACK[0x120] = v64 * v68;
          *(double *)&STACK[0x128] = v65 * v68;
          *(double *)&STACK[0x130] = v66 * v68;
        }
        sub_619450(&a17, v62);
LABEL_19:
        result = v69 + 1;
        v63 = ++v69 < (int)a1[39];
        v67 += 13;
      }
      while ( v63 );
    }
  }
  return result;
}
