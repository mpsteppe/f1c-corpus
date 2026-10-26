void __thiscall sub_545860(int *this, int a2, float *a3, float *a4)
{
  float v5; // edx
  float v6; // eax
  double v8; // st7
  double v9; // st7
  float *v10; // eax
  float v11; // ecx
  float v12; // edx
  char *v13; // ebp
  long double v14; // st7
  int *v15; // edi
  int v16; // esi
  int v17; // eax
  char *v18; // ecx
  char *v19; // eax
  int v20; // eax
  char *v21; // ecx
  char *v22; // eax
  int v23; // eax
  char *v24; // ecx
  char *v25; // eax
  float v26; // [esp+0h] [ebp-58h]
  float v27; // [esp+0h] [ebp-58h]
  float v28; // [esp+0h] [ebp-58h]
  float v30; // [esp+18h] [ebp-40h] BYREF
  float v31; // [esp+1Ch] [ebp-3Ch]
  float v32; // [esp+20h] [ebp-38h]
  float v33; // [esp+24h] [ebp-34h]
  float v34; // [esp+28h] [ebp-30h]
  float v35; // [esp+2Ch] [ebp-2Ch]
  float v36[3]; // [esp+30h] [ebp-28h] BYREF
  float v37[7]; // [esp+3Ch] [ebp-1Ch] BYREF
  char *v38; // [esp+5Ch] [ebp+4h]
  float v39; // [esp+60h] [ebp+8h]
  int v40; // [esp+60h] [ebp+8h]
  char *v41; // [esp+64h] [ebp+Ch]

  if ( (unsigned __int8)sub_5210F0() )
  {
    v5 = a3[1];
    v6 = a3[2];
    v37[0] = *a3;
    v8 = v37[0] - *(float *)(a2 + 72);
    v37[1] = v5;
    v37[2] = v6;
    v33 = v8;
    v30 = v33;
    v34 = v5 - *(float *)(a2 + 76);
    v31 = v34;
    v35 = v6 - *(float *)(a2 + 80);
    v32 = v35;
    v9 = v35 * v35 + v34 * v34 + v33 * v33;
    v39 = v9;
    if ( v9 > 0.010000001 )
    {
      v10 = sub_401320(a4, &v30, v36);
      v11 = v10[1];
      v33 = *v10;
      v12 = v10[2];
      v34 = v11;
      v35 = v12;
      v13 = byte_FFFFFF;
      v38 = byte_FFFFFF;
      v41 = byte_FFFFFF;
      LODWORD(v37[6]) = byte_FFFFFF;
      v14 = 1.0 / sqrt(v39) * *(float *)(a2 + 24);
      v30 = v33 * v14;
      v37[3] = v30;
      v31 = v11 * v14;
      v37[4] = v31;
      v32 = v12 * v14;
      v37[5] = v32;
      if ( v39 < 400.0 )
      {
        v40 = 0;
        if ( this[14] > 0 )
        {
          v15 = this + 15;
          do
          {
            v16 = *v15;
            switch ( *(_DWORD *)(*v15 + 4) )
            {
              case 7:
                v28 = *(float *)(a2 + 28) * 254.0;
                v23 = sub_4015C0(v28);
                v24 = *(char **)(a2 + 100);
                v25 = &byte_FFFFFF[0x1000000 * v23];
                *(_DWORD *)(a2 + 96) = v24;
                LODWORD(v37[6]) = v25;
                v13 = v25;
                if ( v24 == byte_FFFFFF && v25 == v24 )
                  goto LABEL_18;
                break;
              case 8:
                v27 = *(float *)(a2 + 32) * 254.0;
                v20 = sub_4015C0(v27);
                v21 = *(char **)(a2 + 104);
                v22 = &byte_FFFFFF[0x1000000 * v20];
                *(_DWORD *)(a2 + 96) = v21;
                LODWORD(v37[6]) = v22;
                v38 = v22;
                if ( v21 == byte_FFFFFF && v22 == v21 )
                  goto LABEL_18;
                break;
              case 9:
                v26 = *(float *)(a2 + 36) * 63.5;
                v17 = sub_4015C0(v26);
                v18 = *(char **)(a2 + 108);
                v19 = &byte_FFFFFF[0x1000000 * v17];
                *(_DWORD *)(a2 + 96) = v18;
                LODWORD(v37[6]) = v19;
                v41 = v19;
                if ( v18 == byte_FFFFFF && v19 == v18 )
                  goto LABEL_18;
                break;
              default:
                goto LABEL_18;
            }
            sub_544CF0(v16, a2 + 72, (int)v37);
LABEL_18:
            ++v15;
            ++v40;
          }
          while ( v40 < this[14] );
        }
      }
      qmemcpy((void *)(a2 + 72), v37, 0x1Cu);
      *(_DWORD *)(a2 + 100) = v13;
      *(_DWORD *)(a2 + 104) = v38;
      *(_DWORD *)(a2 + 108) = v41;
    }
  }
}
