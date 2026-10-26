void __usercall sub_54D1C0(int a1@<ecx>, float a2@<ebx>, int a3@<ebp>, float a4@<edi>)
{
  double v5; // st7
  long double v6; // st6
  double v7; // st7
  int v8; // ebx
  int v9; // ebp
  int v10; // edi
  double v11; // st7
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // eax
  long double v16; // st6
  double v17; // st7
  int v18; // ebx
  int v19; // ebp
  int v20; // edi
  int v21; // eax
  int v22; // ecx
  _BYTE v23[4]; // [esp+0h] [ebp-5Ch] BYREF
  int v24; // [esp+4h] [ebp-58h]
  float *v25; // [esp+8h] [ebp-54h]
  int v26; // [esp+Ch] [ebp-50h]
  float v27; // [esp+10h] [ebp-4Ch]
  int v28; // [esp+14h] [ebp-48h]
  float v29; // [esp+18h] [ebp-44h]
  int v30; // [esp+1Ch] [ebp-40h]
  float v31; // [esp+20h] [ebp-3Ch] BYREF
  int v32; // [esp+24h] [ebp-38h]
  float v33; // [esp+28h] [ebp-34h] BYREF
  float v34[8]; // [esp+2Ch] [ebp-30h] BYREF
  char v35; // [esp+4Ch] [ebp-10h]
  int v36; // [esp+58h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 220) || *(_DWORD *)(a1 + 60) )
  {
    v5 = flt_BE08A4[(unsigned __int8)dword_BE08A0];
    v31 = a2;
    v30 = a3;
    ++dword_BE08A0;
    v29 = a4;
    *(float *)(a1 + 228) = v5 * 0.050000001;
    sub_5BFC10(v34);
    v6 = *(float *)(a1 + 12);
    v7 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    v8 = *(_DWORD *)(a1 + 60);
    v36 = 0;
    v35 = 1;
    v34[0] = fabs(v6) * 0.10000001 + v7 * 0.050000001 + 0.2;
    if ( !v8 )
      goto LABEL_11;
    v9 = *(_DWORD *)(a1 + 48);
    v10 = *(_DWORD *)(a1 + 64);
    v33 = *(float *)(v9 + 8);
    v28 = v10;
    if ( (unsigned __int8)sub_405250() )
    {
      if ( !*(_BYTE *)(v10 + 81) )
        goto LABEL_9;
      v11 = *(float *)(v10 + 32);
      v27 = 0.0;
      v26 = v10;
      v33 = (1.0 - v11) * v33;
      sub_5BC080(*(_DWORD *)(v9 + 8), v10, 0);
      v12 = *(_DWORD *)(*(_DWORD *)(a1 + 48) + 8);
      v13 = *(_DWORD *)(a1 + 60);
      v25 = &v31;
      v24 = v13;
    }
    else
    {
      v27 = COERCE_FLOAT(&v33);
      v12 = v32;
      v26 = v8;
    }
    *(_DWORD *)(a1 + 64) = sub_5BBFE0(v12);
LABEL_9:
    v14 = *(_DWORD *)(a1 + 68);
    if ( v14 )
    {
      (*(void (__thiscall **)(int, int, int, float *))(*(_DWORD *)v14 + 20))(v14, 1, v24, v25);
      v15 = *(_DWORD **)(a1 + 72);
      v15[3] = *(_DWORD *)(a1 + 244);
      v15[4] = *(_DWORD *)(a1 + 248);
      v15[5] = *(_DWORD *)(a1 + 252);
    }
LABEL_11:
    v16 = *(float *)(a1 + 12);
    v17 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    v18 = *(_DWORD *)(a1 + 220);
    v32 = 1;
    v29 = fabs(v16) * 0.14999998 + v17 * 0.050000001 + 0.30000001;
    if ( v18 )
    {
      v19 = *(_DWORD *)(a1 + 208);
      v20 = *(_DWORD *)(a1 + 224);
      v27 = *(float *)(v19 + 8);
      if ( (unsigned __int8)sub_405250() )
      {
        v21 = *(_DWORD *)(v20 + 48);
        if ( v21 == -1 || *(_DWORD *)(v20 + 44) < v21 )
          goto LABEL_18;
        v27 = (1.0 - *(float *)(v20 + 32)) * v27;
        sub_5BC080(*(_DWORD *)(v19 + 8), v20, 0);
        v22 = *(_DWORD *)(*(_DWORD *)(a1 + 208) + 8);
      }
      else
      {
        v22 = v26;
      }
      *(_DWORD *)(a1 + 224) = sub_5BBFE0(v22);
    }
LABEL_18:
    v34[0] = NAN;
    nullsub_7(v23);
  }
}
