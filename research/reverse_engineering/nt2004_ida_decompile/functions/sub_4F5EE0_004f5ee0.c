char __thiscall sub_4F5EE0(int *this, int a2, float a3, int a4, float *a5, int a6, int a7)
{
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  float v20; // edx
  int v21; // eax
  double v22; // st7
  double v23; // st6
  int v24; // eax
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  float v30; // [esp-1Ch] [ebp-5Ch]
  int *i; // [esp+4h] [ebp-3Ch]
  int v32; // [esp+8h] [ebp-38h]
  int v34; // [esp+10h] [ebp-30h] BYREF
  int v35; // [esp+14h] [ebp-2Ch]
  float v36; // [esp+18h] [ebp-28h]
  int v37; // [esp+1Ch] [ebp-24h] BYREF
  float v38; // [esp+20h] [ebp-20h]
  float v39; // [esp+24h] [ebp-1Ch]
  int v40; // [esp+28h] [ebp-18h]
  float v41; // [esp+2Ch] [ebp-14h]
  float v42; // [esp+30h] [ebp-10h]
  int v43; // [esp+34h] [ebp-Ch]
  float v44; // [esp+38h] [ebp-8h]
  float v45; // [esp+3Ch] [ebp-4h]

  LOBYTE(v8) = sub_4DA2C0(&dword_7D5DA4);
  if ( (_BYTE)v8 )
  {
    v8 = this[14];
    v32 = 0;
    if ( v8 > 0 )
    {
      for ( i = this + 15; ; ++i )
      {
        v9 = *i;
        v10 = *(_DWORD *)(*i + 4);
        if ( !v10 )
        {
          if ( *(float *)(a2 + 44) == 0.0 || dword_767CA0 <= 2 && dword_7D5DA4 != 2 && dword_75AB98 % 16 )
            goto LABEL_38;
          if ( fabs(a3 - *(float *)(a2 + 68)) <= 0.15000001 )
          {
            v23 = *(float *)(a4 + 8) - *(float *)(a2 + 64);
            v22 = *(float *)a4 - *(float *)(a2 + 56);
            if ( v23 * v23 + v22 * v22 <= 1.0 )
              goto LABEL_38;
          }
          *(_DWORD *)(a2 + 56) = *(_DWORD *)a4;
          *(_DWORD *)(a2 + 60) = *(_DWORD *)(a4 + 4);
          v24 = *(_DWORD *)(a4 + 8);
          *(float *)(a2 + 68) = a3;
          *(_DWORD *)(a2 + 64) = v24;
          v25 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
          v35 = *(_DWORD *)(a4 + 4);
          *(float *)&v34 = v25 * 0.25 + *(float *)a4;
          v26 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
          v36 = v26 * 0.25 + *(float *)(a4 + 8);
          *(float *)&v43 = *a5 * 0.1;
          v27 = a5[1];
          v37 = v43;
          v44 = v27 * 0.1;
          v28 = a5[2];
          v38 = v44;
          v45 = v28 * 0.1;
          v39 = v45;
          if ( byte_767DCC )
          {
            if ( byte_767DE4 )
            {
              v21 = 48;
LABEL_36:
              v20 = *(float *)(a2 + 44);
              goto LABEL_37;
            }
          }
          else if ( !byte_767DE4 )
          {
            v21 = -1;
            goto LABEL_36;
          }
          v21 = a7;
          goto LABEL_36;
        }
        v11 = v10 - 2;
        if ( v11 )
        {
          if ( v11 == 3 && *(float *)(a2 + 48) != 0.0 && (dword_767CA0 > 1 || dword_7D5DA4 == 2 || !(dword_75AB98 % 16)) )
          {
            v12 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
            v35 = *(_DWORD *)(a4 + 4);
            *(float *)&v34 = v12 * 0.25 + *(float *)a4;
            v13 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
            v30 = *(float *)(a2 + 48);
            v36 = v13 * 0.25 + *(float *)(a4 + 8);
            sub_4F2BC0(v9, a3, (float *)&v34, a5, v30, a6, a7, 0xFFFFFF);
          }
          goto LABEL_38;
        }
        if ( *(float *)(a2 + 40) == 0.0 || dword_767CA0 <= 2 && dword_7D5DA4 != 2 && dword_75AB98 % 16 )
          goto LABEL_38;
        if ( fabs(a3 - *(float *)(a2 + 68)) <= 0.15000001 )
        {
          v15 = *(float *)(a4 + 8) - *(float *)(a2 + 64);
          v14 = *(float *)a4 - *(float *)(a2 + 56);
          if ( v15 * v15 + v14 * v14 <= 1.0 )
            goto LABEL_38;
        }
        *(_DWORD *)(a2 + 56) = *(_DWORD *)a4;
        *(_DWORD *)(a2 + 60) = *(_DWORD *)(a4 + 4);
        *(_DWORD *)(a2 + 64) = *(_DWORD *)(a4 + 8);
        *(float *)(a2 + 68) = a3;
        v16 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        v35 = *(_DWORD *)(a4 + 4);
        *(float *)&v34 = v16 * 0.25 + *(float *)a4;
        v17 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        v36 = v17 * 0.25 + *(float *)(a4 + 8);
        *(float *)&v40 = *a5 * 0.1;
        v18 = a5[1];
        v37 = v40;
        v41 = v18 * 0.1;
        v19 = a5[2];
        v38 = v41;
        v42 = v19 * 0.1;
        v39 = v42;
        if ( !byte_767DCC )
          break;
        if ( !byte_767DE4 )
          goto LABEL_22;
        v20 = *(float *)(a2 + 40);
        v21 = 48;
LABEL_37:
        sub_4F3200(v9, a3, (float *)&v34, (float *)&v37, v20, a6, 1, v21, 0xFFFFFF);
LABEL_38:
        LOBYTE(v8) = ++v32;
        if ( v32 >= this[14] )
          return v8;
      }
      if ( !byte_767DE4 )
      {
        v20 = *(float *)(a2 + 40);
        v21 = -1;
        goto LABEL_37;
      }
LABEL_22:
      v21 = a7;
      v20 = *(float *)(a2 + 40);
      goto LABEL_37;
    }
  }
  return v8;
}
