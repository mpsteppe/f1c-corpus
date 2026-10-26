// f1c  0x0042caa0  size=833
void sub_42CAA0()
{
  int v0; // ebp
  int v1; // edi
  float *v2; // ecx
  int v3; // edx
  double v4; // st7
  int v5; // edx
  double v6; // st6
  float *v7; // esi
  float *v8; // eax
  int v9; // ebx
  double v10; // st7
  double v11; // st7
  long double v12; // st6
  double v14; // st7
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c2
  int v17; // ebx
  long double v18; // st7
  long double v19; // st6
  int v20; // esi
  int i; // edi
  int v22; // edx
  float *v23; // ecx
  unsigned __int8 v25; // c0
  unsigned __int8 v26; // c3
  unsigned __int8 v28; // c0
  unsigned __int8 v29; // c3
  double v30; // st5
  double v31; // st5
  double v32; // st5
  double v33; // st3
  double v34; // st2
  long double v35; // st5
  long double v36; // st4
  double v37; // st2
  long double v38; // st5
  int v39; // eax
  float v40; // [esp+10h] [ebp-EC4h]
  float v41; // [esp+10h] [ebp-EC4h]
  float v42; // [esp+14h] [ebp-EC0h]
  float v43; // [esp+14h] [ebp-EC0h]
  float v44; // [esp+18h] [ebp-EBCh]
  float v45; // [esp+20h] [ebp-EB4h]
  float v46; // [esp+24h] [ebp-EB0h]
  float v47; // [esp+28h] [ebp-EACh]
  float v48; // [esp+30h] [ebp-EA4h]
  _DWORD v49[3]; // [esp+48h] [ebp-E8Ch] BYREF
  char v50; // [esp+54h] [ebp-E80h] BYREF

  v0 = dword_5C329C;
  v1 = 0;
  if ( dword_5C329C > 0 )
  {
    v2 = (float *)&v50;
    do
    {
      v3 = dword_7C54F0[v1];
      v4 = *(float *)(v3 + 13568);
      v5 = v3 + 12;
      v6 = *(float *)(v5 + 13548);
      v7 = (float *)(v5 + 13524);
      v8 = v2 - 8;
      *v8 = *(float *)(v5 + 13524);
      v9 = *(_DWORD *)(v5 + 13532);
      v8[1] = *(float *)(v5 + 13528);
      v46 = v6 * v6 + v4 * v4;
      *((_DWORD *)v8 + 2) = v9;
      v40 = sqrt(v46);
      *(v2 - 5) = v40;
      *(v2 - 4) = fabs(v40 * 1.1);
      if ( v40 != 0.0 )
      {
        v10 = 1.0 / v40;
        v42 = v10 * *(float *)(v5 + 13548);
        v11 = v10 * *(float *)(v5 + 13556);
        v12 = (v11 * *(float *)(v5 + 13620) - v42 * *(float *)(v5 + 13628)) * 0.25;
        if ( v12 == 0.0 )
          *v2 = 1000000.0;
        else
          *v2 = v46 / fabs(v12);
        v14 = v11 * *v2;
        if ( v15 | v16 )
        {
          *(v2 - 2) = *v7 - v14;
          *(v2 - 1) = v42 * *v2 + *(float *)(v5 + 13532);
          *(v2 - 5) = -v40;
        }
        else
        {
          *(v2 - 2) = v14 + *v7;
          *(v2 - 1) = *(float *)(v5 + 13532) - v42 * *v2;
        }
        *(v2 - 3) = atan2(*v7 - *(v2 - 2), *(float *)(v5 + 13532) - *(v2 - 1));
      }
      v0 = dword_5C329C;
      ++v1;
      v2 += 9;
    }
    while ( v1 < dword_5C329C );
  }
  v17 = 0;
  if ( v0 > 0 )
  {
    do
    {
      v18 = 0.0;
      v19 = 0.0;
      v44 = *(float *)(dword_7C54F0[v17] + 13536);
      v45 = *(float *)(dword_7C54F0[v17] + 13544);
      v20 = 0;
      for ( i = v17; ; i = v0 )
      {
        if ( v20 < i )
        {
          v22 = i - v20;
          v23 = (float *)&v49[9 * v20];
          v20 = i;
          do
          {
            if ( !(v25 | v26) )
            {
              v41 = atan2(v44 - v23[1], v45 - v23[2]);
              if ( v28 | v29 )
              {
                v31 = v41;
                if ( v41 < (double)*v23 )
                  v31 = v31 + 6.2831855;
                v30 = v31 - *v23;
              }
              else if ( v41 <= (double)*v23 )
              {
                v30 = *v23 - v41;
              }
              else
              {
                v30 = *v23 - (v41 - 6.2831855);
              }
              v32 = v30 * v23[3];
              v43 = v32;
              if ( v32 < *(v23 - 1) )
              {
                v33 = v23[2] - v45;
                v34 = v23[1] - v44;
                v35 = fabs(v23[3] - sqrt(v33 * v33 + v34 * v34));
                v36 = v43 * 0.0625 + 1.8;
                if ( v35 < v36 )
                {
                  v37 = 1.0 - v43 / *(v23 - 1);
                  v38 = (1.0 - v35 / v36) * (v37 * v37 * (v37 * v37)) * *(v23 - 2) * 0.125;
                  v18 = v18 + cos(v41) * v38;
                  v19 = v19 - sin(v41) * v38;
                }
              }
            }
            v23 += 9;
            --v22;
          }
          while ( v22 );
        }
        if ( i != v17 )
          break;
        ++v20;
      }
      v48 = v19;
      v39 = dword_7C54F0[v17] + 14948;
      v47 = v18;
      *(float *)v39 = v47;
      *(_DWORD *)(v39 + 4) = 0;
      *(float *)(v39 + 8) = v48;
      v0 = dword_5C329C;
      ++v17;
    }
    while ( v17 < dword_5C329C );
  }
}
