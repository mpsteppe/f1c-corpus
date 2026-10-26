int __cdecl sub_42D4D0(
        float a1,
        float a2,
        float a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        float a11,
        int a12,
        int a13,
        int a14,
        int a15,
        float a16,
        float a17,
        float a18,
        int a19,
        int a20,
        char a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        char a29)
{
  int result; // eax
  int v30; // esi
  int v31; // ebx
  char *v32; // ecx
  int v33; // edx
  float *v34; // esi
  double v35; // st5
  char *v36; // eax
  double v37; // st4
  int v38; // edi
  double v39; // st7
  __int16 v40; // fps
  bool v41; // c0
  char v42; // c2
  bool v43; // c3
  double v44; // st7
  double v45; // st7
  long double v46; // st6
  long double v47; // st5
  __int16 v48; // fps
  double v49; // st7
  unsigned __int8 v50; // c0
  unsigned __int8 v51; // c2
  int v52; // edx
  int *v53; // eax
  int v54; // ecx
  int v55; // ecx
  int v56; // ebp
  float *v57; // ebx
  long double v58; // st7
  long double v59; // st7
  double v60; // st6
  double v61; // st4
  long double v62; // st7
  int v63; // esi
  int v64; // eax
  int v65; // edi
  double v66; // st7
  int v67; // ecx
  long double v68; // st7
  __int16 v69; // fps
  bool v70; // c0
  char v71; // c2
  bool v72; // c3
  float *v73; // ecx
  long double v74; // st7
  float vars0; // [esp+18h] [ebp+0h]
  float vars0a; // [esp+18h] [ebp+0h]
  float vars0b; // [esp+18h] [ebp+0h]
  float vars0c; // [esp+18h] [ebp+0h]
  float retaddr; // [esp+1Ch] [ebp+4h]
  float v80; // [esp+20h] [ebp+8h]
  float v81; // [esp+20h] [ebp+8h]
  float v82; // [esp+24h] [ebp+Ch]
  float v83; // [esp+24h] [ebp+Ch]
  float v84; // [esp+28h] [ebp+10h]
  float v85; // [esp+28h] [ebp+10h]
  float v86; // [esp+2Ch] [ebp+14h]
  float v87; // [esp+2Ch] [ebp+14h]
  float v88; // [esp+30h] [ebp+18h]
  float v89; // [esp+34h] [ebp+1Ch]
  float v90; // [esp+34h] [ebp+1Ch]
  int v91; // [esp+38h] [ebp+20h]
  int v92; // [esp+3Ch] [ebp+24h]
  int v93; // [esp+40h] [ebp+28h]
  int v94; // [esp+44h] [ebp+2Ch]
  float v95; // [esp+48h] [ebp+30h]
  int v96; // [esp+58h] [ebp+40h]
  float v97; // [esp+5Ch] [ebp+44h]
  float v98; // [esp+60h] [ebp+48h]
  float v99; // [esp+64h] [ebp+4Ch]

  result = sub_631BD0();
  v30 = dword_757C10;
  v31 = 0;
  if ( dword_757C10 > 0 )
  {
    v32 = &a29;
    do
    {
      v33 = *(&dword_91E088 + v31);
      if ( *(_DWORD *)(v33 + 14820) != 4 )
      {
        v34 = (float *)(v33 + 15988);
        v35 = *(float *)(v33 + 16012) * *(float *)(v33 + 16012);
        v36 = v32 - 40;
        v37 = *(float *)(v33 + 16020);
        *(_DWORD *)v36 = *(_DWORD *)(v33 + 15988);
        v38 = *(_DWORD *)(v33 + 15996);
        *((_DWORD *)v36 + 1) = *(_DWORD *)(v33 + 15992);
        *((_DWORD *)v36 + 2) = v38;
        v82 = v35 + v37 * v37;
        retaddr = sqrt(v82);
        HIWORD(result) = HIWORD(retaddr);
        *((float *)v32 - 7) = retaddr;
        v80 = sqrt(retaddr) * 0.82499999;
        v39 = retaddr * 1.39;
        vars0 = v39;
        *((float *)v32 - 6) = v39 * vars0 + v80 * v80;
        v41 = retaddr < 0.0;
        v42 = 0;
        v43 = retaddr == 0.0;
        LOWORD(result) = v40;
        if ( retaddr != 0.0 )
        {
          if ( v80 == 0.0 )
            *((_DWORD *)v32 - 5) = 0;
          else
            *((float *)v32 - 5) = 16.0 / v80;
          if ( vars0 == 0.0 )
            *((_DWORD *)v32 - 4) = 0;
          else
            *((float *)v32 - 4) = 137.0 / vars0;
          v44 = 1.0 / retaddr;
          vars0a = v44 * *(float *)(v33 + 16012);
          v45 = v44 * *(float *)(v33 + 16020);
          v46 = (v45 * *(float *)(v33 + 16088) - vars0a * *(float *)(v33 + 16096)) * 0.25;
          if ( v46 == 0.0 || (v47 = v82 / fabs(v46), *(float *)v32 = v47, v47 > 1000000.0) )
            *(_DWORD *)v32 = 1232348160;
          v49 = v45 * *(float *)v32;
          LOWORD(result) = v48;
          if ( v50 | v51 )
          {
            *((float *)v32 - 2) = *v34 - v49;
            *((float *)v32 - 1) = vars0a * *(float *)v32 + *(float *)(v33 + 15996);
            *((float *)v32 - 7) = -retaddr;
          }
          else
          {
            *((float *)v32 - 2) = v49 + *v34;
            *((float *)v32 - 1) = *(float *)(v33 + 15996) - vars0a * *(float *)v32;
          }
          *((float *)v32 - 3) = atan2(*v34 - *((float *)v32 - 2), *(float *)(v33 + 15996) - *((float *)v32 - 1));
        }
      }
      v30 = dword_757C10;
      ++v31;
      v32 += 44;
    }
    while ( v31 < dword_757C10 );
  }
  v52 = 0;
  v96 = 0;
  if ( v30 > 0 )
  {
    do
    {
      result = *(&dword_91E088 + v52);
      if ( *(_DWORD *)(result + 14820) != 4 )
      {
        v53 = (int *)(result + 15988);
        v92 = *v53;
        v54 = v53[1];
        result = v53[2];
        v93 = v54;
        v55 = v52;
        v94 = result;
        v86 = 0.0;
        v89 = 0.0;
        retaddr = 0.0;
        v83 = 0.0;
        v56 = 0;
        v91 = v52;
        while ( 1 )
        {
          if ( v56 < v55 )
          {
            v57 = (float *)(&a21 + 44 * v56);
            do
            {
              result = *(&dword_91E088 + v56);
              if ( *(_DWORD *)(result + 14820) != 4 )
              {
                v97 = *(float *)&v92 - *(v57 - 2);
                v98 = *(float *)&v93 - *(v57 - 1);
                v99 = *(float *)&v94 - *v57;
                HIWORD(result) = HIWORD(v99);
                if ( v99 * v99 + v98 * v98 + v97 * v97 < v57[2] )
                {
                  v81 = atan2(*(float *)&v92 - v57[6], *(float *)&v94 - v57[7]);
                  if ( v57[1] <= 0.0 )
                    v58 = v81 - v57[5];
                  else
                    v58 = v57[5] - v81;
                  if ( fabs(v58) > 3.1415927 )
                  {
                    if ( v58 < 0.0 )
                      v58 = v58 + 6.2831855;
                    else
                      v58 = v58 - 6.2831855;
                  }
                  v59 = v58 * v57[8] * v57[4] + 25.002501;
                  vars0b = v59;
                  if ( v59 >= 0.0 && vars0b < 136.0 )
                  {
                    v60 = v57[7] - *(float *)&v94;
                    v61 = v57[6] - *(float *)&v92;
                    v62 = fabs(v57[8] - sqrt(v60 * v60 + v61 * v61)) * v57[3];
                    v95 = v62;
                    if ( v62 < 15.0 )
                    {
                      v84 = floor(vars0b);
                      vars0c = vars0b - v84;
                      v63 = sub_4015C0(v84);
                      v85 = floor(v95);
                      v64 = sub_4015C0(v85);
                      v65 = 16 * (v63 + 1);
                      v63 *= 16;
                      v66 = (flt_91E240[v65 + v64] - flt_91E240[v63 + v64]) * vars0c + flt_91E240[v63 + v64];
                      v67 = v63 + v64 + 1;
                      result = v65 + v64 + 1;
                      v68 = (v66
                           + ((flt_91E240[result] - flt_91E240[v67]) * vars0c + flt_91E240[v67] - v66) * (v95 - v85))
                          * v57[1];
                      v86 = cos(v81) * v68 + v86;
                      v89 = v89 - sin(v81) * v68;
                      retaddr = fabs(v68) + retaddr;
                      v55 = v91;
                      v52 = v96;
                      v83 = v68 * v68 + v83;
                    }
                  }
                }
              }
              ++v56;
              v57 += 11;
            }
            while ( v56 < v55 );
            v30 = dword_757C10;
          }
          if ( v55 != v52 )
            break;
          ++v56;
          v91 = v30;
          v55 = v30;
        }
        v70 = retaddr < 0.0;
        v71 = 0;
        v72 = retaddr == 0.0;
        LOWORD(result) = v69;
        if ( retaddr > 0.0 )
        {
          v73 = (float *)(*(&dword_91E088 + v52) + 17424);
          v74 = sqrt(v83) / retaddr;
          v87 = v86 * v74;
          *v73 = v87;
          v88 = 0.0 * v74;
          v73[1] = v88;
          v90 = v74 * v89;
          result = LODWORD(v90);
          v73[2] = v90;
        }
      }
      v30 = dword_757C10;
      v96 = ++v52;
    }
    while ( v52 < dword_757C10 );
  }
  return result;
}
