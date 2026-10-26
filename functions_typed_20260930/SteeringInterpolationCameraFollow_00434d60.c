int __thiscall sub_434D60(int this, char a2)
{
  int result; // eax
  int v4; // edi
  int v5; // ebp
  float *v6; // ebx
  int v7; // eax
  double v8; // st7
  float v9; // ecx
  float v10; // edx
  float v11; // eax
  double v12; // st7
  double v13; // st7
  int v14; // eax
  double v15; // st7
  double v16; // st7
  int v17; // eax
  double v18; // st6
  double v19; // st7
  int v20; // edi
  int v21; // ebp
  float *v22; // eax
  double v23; // st7
  double v24; // st6
  char v25; // al
  int v26; // eax
  float v27; // ecx
  float *v28; // ecx
  double v29; // st7
  int v30; // [esp+Ch] [ebp-84h]
  float v31; // [esp+14h] [ebp-7Ch]
  float v32; // [esp+18h] [ebp-78h]
  float v33; // [esp+20h] [ebp-70h] BYREF
  float v34; // [esp+24h] [ebp-6Ch]
  float v35; // [esp+28h] [ebp-68h] BYREF
  float v36; // [esp+2Ch] [ebp-64h]
  float v37; // [esp+30h] [ebp-60h] BYREF
  float v38; // [esp+34h] [ebp-5Ch]
  float v39; // [esp+38h] [ebp-58h]
  float v40; // [esp+3Ch] [ebp-54h] BYREF
  float v41; // [esp+40h] [ebp-50h]
  float v42; // [esp+44h] [ebp-4Ch]
  float v43; // [esp+48h] [ebp-48h] BYREF
  float v44; // [esp+4Ch] [ebp-44h]
  float v45; // [esp+50h] [ebp-40h]
  _DWORD v46[3]; // [esp+54h] [ebp-3Ch] BYREF
  float v47; // [esp+60h] [ebp-30h]
  float v48; // [esp+64h] [ebp-2Ch]
  float v49; // [esp+68h] [ebp-28h]
  _DWORD v50[4]; // [esp+6Ch] [ebp-24h] BYREF
  float v51; // [esp+7Ch] [ebp-14h]
  float v52; // [esp+80h] [ebp-10h]
  float v53; // [esp+88h] [ebp-8h]
  float v54; // [esp+8Ch] [ebp-4h]

  result = *(_DWORD *)(this + 12);
  if ( result && *(_DWORD *)(result + 176) )
  {
    v30 = *(_DWORD *)(this + 44) - 1;
    v36 = *(float *)(result + 188);
    v4 = StridedArrayElementPointer(v30);
    v5 = StridedArrayElementPointer(*(_DWORD *)(this + 44));
    v6 = (float *)StridedArrayElementPointer(*(_DWORD *)(this + 44) + 1);
    v33 = -1.0;
    if ( v4 && v5 )
    {
      v33 = (*(float *)(v5 + 24) - *(float *)(*(_DWORD *)(this + 12) + 188))
          / (*(float *)(v5 + 24) - *(float *)(v4 + 24));
      v34 = v33 * *(float *)(this + 48);
    }
    v7 = *(_DWORD *)(this + 28);
    memset(v50, 0, 12);
    if ( v7 < 0 || *(int *)(this + 24) < 0 || v7 >= dword_5C329C || *(_DWORD *)(this + 4) == 5 )
    {
      if ( StridedArrayElementPointer(4) && StridedArrayElementPointer(4) )
      {
        v20 = StridedArrayElementPointer(4);
        v21 = StridedArrayElementPointer(4);
        v22 = (float *)StridedArrayElementPointer(4);
        v23 = -*(float *)(v20 + 8);
        v24 = -*(float *)(v21 + 4);
        v37 = -*v22;
        v38 = v24;
        v39 = v23;
      }
      else
      {
        sub_403CD0(dword_5EA2C0, 0, &v37, v46);
      }
    }
    else
    {
      F_3DTransformPointByMatrixAndTranslation(&v40, v46);
      sub_403CD0(dword_5EA2C0, *(_DWORD *)(this + 24), &v43, v46);
      if ( dword_5EB978[*(_DWORD *)(this + 28)] )
      {
        if ( v33 <= 0.0 || v33 > 1.0 )
        {
          if ( v33 <= 1.0 )
          {
            v9 = v40;
            v10 = v41;
            v11 = v42;
          }
          else
          {
            v9 = v43;
            v10 = v44;
            v11 = v45;
          }
        }
        else
        {
          v8 = 1.0 - v33;
          v53 = v41 * v8;
          v54 = v42 * v8;
          v51 = v44 * v33;
          v52 = v45 * v33;
          v47 = v43 * v33 + v40 * v8;
          v9 = v47;
          v48 = v51 + v53;
          v10 = v48;
          v49 = v52 + v54;
          v11 = v49;
        }
        v37 = v9;
        v38 = v10;
        v39 = v11;
        DualFieldGetter(&v33, &v35);
        if ( v33 > (double)*(float *)(this + 20) )
        {
          v12 = v33 - dbl_8AFE98 * 5.0;
          v33 = v12;
          if ( v12 < *(float *)(this + 20) )
            v33 = *(float *)(this + 20);
        }
        v13 = v35;
        v14 = *(_DWORD *)(this + 12);
        *(float *)(v14 + 56) = v33;
        *(float *)(v14 + 60) = v13;
        F_3DTransformPointByMatrixAndTranslation(&v40, v46);
      }
      else
      {
        if ( v6 )
        {
          v47 = -*v6;
          v48 = -v6[1];
          v15 = v6[2];
          v37 = v47;
          v38 = v48;
          v49 = -v15;
          v39 = v49;
        }
        DualFieldGetter(&v35, &v33);
        v16 = v35;
        if ( v35 < (double)*(float *)(this + 16) )
        {
          v16 = v16 + dbl_8AFE98 * 20.0;
          if ( v16 > *(float *)(this + 16) )
            v16 = *(float *)(this + 16);
        }
        v17 = *(_DWORD *)(this + 12);
        v18 = v16;
        v19 = v33;
        *(float *)(v17 + 56) = v18;
        *(float *)(v17 + 60) = v19;
      }
    }
    GuardedFunctionWithFlagSet(v36);
    v25 = *(_BYTE *)(this + 1);
    v35 = dbl_8AFE98;
    if ( v25 )
    {
      v26 = *(_DWORD *)(this + 12);
      v27 = *(float *)(v26 + 168);
      *(_DWORD *)(v26 + 168) = 0;
      v36 = v27;
      (*(void (__thiscall **)(_DWORD, float *, _DWORD *, _DWORD *, int, int))(**(_DWORD **)(this + 12) + 24))(
        *(_DWORD *)(this + 12),
        &v37,
        v46,
        v50,
        1148846080,
        1148846080);
      *(float *)(*(_DWORD *)(this + 12) + 168) = v36;
      *(_BYTE *)(this + 1) = 0;
    }
    v28 = *(float **)(this + 12);
    if ( !a2 )
    {
      v32 = 0.0;
LABEL_46:
      v31 = dbl_8AFE90;
      return (*(int (__thiscall **)(float *, float *, _DWORD *, _DWORD *, _DWORD, float))(*(_DWORD *)v28 + 24))(
               v28,
               &v37,
               v46,
               v50,
               LODWORD(v31),
               COERCE_FLOAT(LODWORD(v32)));
    }
    v29 = v28[42];
    v33 = v28[42];
    if ( v33 >= (double)v34 )
    {
      if ( v33 > (double)v34 )
      {
        v29 = v33 - v35 * 1.5;
        if ( v29 < v34 )
          goto LABEL_39;
      }
    }
    else
    {
      v29 = v33 + v35;
      if ( v29 > v34 )
LABEL_39:
        v29 = v34;
    }
    v35 = *(float *)(this + 48);
    if ( v29 >= 0.0 )
    {
      if ( v29 > v35 )
        v29 = v35;
    }
    else
    {
      v29 = 0.0;
    }
    v28[42] = v29;
    v28 = *(float **)(this + 12);
    v32 = dbl_8AFE98;
    goto LABEL_46;
  }
  return result;
}

