void __thiscall sub_546DC0(float *this, int a2)
{
  int *v3; // eax
  int v4; // ebp
  double v5; // st7
  double v6; // st6
  double v7; // st6
  double v8; // st7
  long double v9; // st7
  int v10; // ecx
  long double v11; // st7
  bool v12; // c0
  long double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st4
  int v17; // ebx
  int v18; // ebp
  int v19; // edi
  int v20; // edi
  float *v21; // ecx
  double v22; // st7
  int v23; // eax
  float v24; // edx
  int v25; // eax
  double v26; // st7
  float v27; // [esp+Ch] [ebp-30h]
  float v28; // [esp+Ch] [ebp-30h]
  float v29; // [esp+Ch] [ebp-30h]
  float v30; // [esp+10h] [ebp-2Ch]
  float v31; // [esp+10h] [ebp-2Ch]
  float v32; // [esp+14h] [ebp-28h]
  float v33; // [esp+14h] [ebp-28h]
  float v34; // [esp+18h] [ebp-24h]
  float v35; // [esp+1Ch] [ebp-20h]
  float v36; // [esp+20h] [ebp-1Ch]
  float v37; // [esp+24h] [ebp-18h] BYREF
  float v38; // [esp+28h] [ebp-14h]
  float v39; // [esp+2Ch] [ebp-10h]
  float v40; // [esp+30h] [ebp-Ch]
  float v41; // [esp+34h] [ebp-8h]
  float v42; // [esp+38h] [ebp-4h]

  if ( a2 )
  {
    if ( *(int *)(a2 + 544) > 0 )
    {
      v3 = *(int **)(a2 + 532);
      if ( v3 )
      {
        v4 = *v3;
        if ( *v3 )
        {
          *(_DWORD *)this = a2;
          sub_56C0A0(&v37);
          sub_5DA7A0(this + 1, this + 2, this + 3);
          v27 = v34 + v37;
          v30 = v38 + v35;
          v32 = v36 + v39;
          v28 = v27 * 0.5;
          v40 = v28;
          v31 = v30 * 0.5;
          v41 = v31;
          v33 = v32 * 0.5;
          v42 = v33;
          this[1] = v28 + this[1];
          this[2] = v41 + this[2];
          this[3] = v42 + this[3];
          v40 = v37 - v34;
          v41 = v38 - v35;
          v42 = v39 - v36;
          this[4] = sqrt(v42 * v42 + v41 * v41 + v40 * v40) * 0.5;
          v5 = v38 - v35;
          if ( v5 > 0.0 )
          {
            v6 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.15000001;
            this[7] = 0.00094;
            this[6] = v6 + 1.0;
            v7 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.40000001;
            this[8] = (v7 + 2.8) * 6.283185307179586 / (v5 + 3.0);
            v8 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.5;
            v9 = v8 + 0.69999999;
            v10 = dword_BE08A0 + 1;
            v40 = cos(v9);
            v11 = sin(v9);
            v12 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] < 0.2;
            v13 = v11;
            if ( v12 )
            {
              v14 = -v40;
            }
            else
            {
              v13 = -v11;
              v14 = v40;
            }
            v15 = flt_BE0CA4[(unsigned __int8)v10];
            dword_BE08A0 = v10 + 1;
            this[9] = v40;
            v16 = v15 * 0.2 + 0.5;
            v29 = v16 * v13;
            this[11] = v29;
            this[10] = v11;
            this[12] = v16 * v14;
            v17 = 0;
            v18 = sub_5EA5B0(v4);
            v19 = 0;
            for ( this[13] = 0.0; v19 < v18; ++v19 )
            {
              if ( *(float *)(sub_5EB140(v19, 1) + 4) > (double)v35 )
                ++*((_DWORD *)this + 13);
            }
            *((_DWORD *)this + 14) = operator new(20 * *((_DWORD *)this + 13));
            if ( v18 > 0 )
            {
              v20 = 0;
              do
              {
                v21 = (float *)sub_5EB140(v17, 1);
                if ( v21[1] > (double)v35 )
                {
                  *(_DWORD *)(v20 + *((_DWORD *)this + 14)) = v21;
                  v22 = v21[2];
                  v23 = *((_DWORD *)this + 14);
                  v24 = *v21;
                  *(float *)(v20 + v23 + 8) = v21[1];
                  v25 = v20 + v23 + 4;
                  *(float *)(v25 + 8) = v22;
                  *(float *)v25 = v24;
                  v26 = v21[1] - v35;
                  v20 += 20;
                  *(float *)(v20 + *((_DWORD *)this + 14) - 4) = v26 * v26;
                }
                ++v17;
              }
              while ( v17 < v18 );
            }
          }
        }
      }
    }
  }
}
