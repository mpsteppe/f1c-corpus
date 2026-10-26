char __thiscall sub_45BA00(int this, float a2, int a3)
{
  double v4; // st7
  double v5; // st7
  double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st6
  double v11; // st7
  double v12; // st6
  long double v13; // st7
  long double v14; // st6
  long double v15; // st5
  int v16; // ecx
  double v17; // st7
  int v18; // eax
  void *v19; // edi
  _DWORD *v20; // ebx
  unsigned __int8 v22; // c0
  unsigned __int8 v23; // c2
  unsigned __int8 v25; // c0
  unsigned __int8 v26; // c2
  unsigned __int8 v28; // c0
  unsigned __int8 v29; // c2
  unsigned __int8 v31; // c0
  unsigned __int8 v32; // c2
  float v33; // [esp+10h] [ebp-60h]
  float v34; // [esp+14h] [ebp-5Ch]
  _BYTE v35[36]; // [esp+18h] [ebp-58h] BYREF
  double v36[3]; // [esp+3Ch] [ebp-34h] BYREF
  int v37; // [esp+54h] [ebp-1Ch]
  int v38; // [esp+58h] [ebp-18h]
  int v39; // [esp+5Ch] [ebp-14h]
  int v40; // [esp+60h] [ebp-10h]
  int v41; // [esp+6Ch] [ebp-4h]

  v4 = *(float *)(this + 28);
  *(float *)(this + 36) = a2;
  if ( *(float *)(this + 32) <= v4 )
    v5 = *(float *)(this + 32);
  else
    v5 = *(float *)(this + 28);
  if ( a2 <= v5 )
  {
    if ( *(_DWORD *)(this + 212) )
    {
      sub_45AC00(this, 0.0125);
      sub_45AC00(this, 0.0125);
      v33 = *(double *)(this + 236);
      v34 = *(double *)(this + 228);
      *(float *)a3 = *(double *)(this + 220);
      *(float *)(a3 + 4) = v34;
      *(float *)(a3 + 8) = v33;
      v13 = -asin(*(double *)(this + 284));
      if ( fabs(*(double *)(this + 284)) == 1.0 )
      {
        v14 = atan2(-*(double *)(this + 292), *(double *)(this + 244));
        v15 = 0.0;
      }
      else
      {
        v14 = atan2(*(double *)(this + 260), *(double *)(this + 308));
        v15 = atan2(*(double *)(this + 268), *(double *)(this + 276));
      }
      *(float *)v35 = v13;
      *(float *)&v35[4] = v14;
      *(float *)&v35[8] = v15;
      sub_59E170(*(_DWORD *)a3, SLODWORD(v34), SLODWORD(v33), *(float *)v35, *(float *)&v35[4], *(float *)&v35[8]);
      if ( !byte_769254 )
        goto LABEL_29;
      v16 = *(_DWORD *)(this + 208);
      v36[0] = *(float *)a3;
      v36[1] = *(float *)(a3 + 4);
      v17 = *(float *)(a3 + 8);
      v41 = v16;
      v36[2] = v17;
      v37 = 0;
      v38 = 1075052544;
      v39 = 0x40000000;
      v40 = 1201543096;
      v18 = sub_44E900(dbl_760B48, (int)v36);
      *(_DWORD *)(this + 208) = v18;
      if ( v18 )
      {
LABEL_29:
        if ( *(double *)(this + 324) < -100.0 || v22 | v23 && v25 | v26 && v28 | v29 && v31 | v32 )
        {
          memset(&v35[12], 0, 24);
          qmemcpy((void *)(this + 316), &v35[12], 0x18u);
          sub_57C010(&v35[12]);
          *(_DWORD *)(this + 32) = *(_DWORD *)(this + 36);
          return 1;
        }
        else
        {
          return 1;
        }
      }
      else
      {
        qmemcpy((void *)a3, "(knN(knN(knN", 12);
        sub_59E050(1315859240, 1315859240, 1315859240);
        sub_59ECC0(0, 0, 0, 0);
        memset(&v35[12], 0, 24);
        qmemcpy((void *)(this + 316), &v35[12], 0x18u);
        sub_57C010(&v35[12]);
        v19 = (void *)(this + 220);
        *(double *)&v35[12] = *(float *)a3;
        v20 = (_DWORD *)(this + 192);
        *(double *)&v35[20] = *(float *)(a3 + 4);
        *(double *)&v35[28] = *(float *)(a3 + 8);
        qmemcpy(v19, &v35[12], 0x18u);
        *v20 = *(_DWORD *)a3;
        v20[1] = *(_DWORD *)(a3 + 4);
        v20[2] = *(_DWORD *)(a3 + 8);
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v6 = flt_76920C + *(float *)(this + 32);
    if ( *(float *)(this + 28) < v6 )
      v6 = *(float *)(this + 28);
    if ( a2 <= v6 )
    {
      memset(&v35[12], 0, 24);
      qmemcpy((void *)(this + 316), &v35[12], 0x18u);
      sub_57C010(&v35[12]);
      v11 = *(double *)(this + 236);
      v12 = *(double *)(this + 228);
      *(float *)a3 = *(double *)(this + 220);
      *(float *)(a3 + 4) = v12;
      *(float *)(a3 + 8) = v11;
      return 1;
    }
    else
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)this + 4))(this) )
      {
        strcpy(v35, "(knN(knN(knN");
        sub_59E050(1315859240, 1315859240, 1315859240);
        sub_59ECC0(0, 0, 0, 0);
        memset(&v35[13], 0, 23);
        qmemcpy((void *)(this + 316), &v35[12], 0x18u);
        sub_57C010(&v35[12]);
        v7 = *(_DWORD *)&v35[4];
        *(_QWORD *)&v35[12] = 0x41CDCD6500000000LL;
        *(_QWORD *)&v35[20] = 0x41CDCD6500000000LL;
        *(_QWORD *)&v35[28] = 0x41CDCD6500000000LL;
        qmemcpy((void *)(this + 220), &v35[12], 0x18u);
        *(_DWORD *)(this + 192) = *(_DWORD *)v35;
        *(_DWORD *)(this + 196) = v7;
        *(_DWORD *)(this + 200) = *(_DWORD *)&v35[8];
      }
      v8 = *(double *)(this + 236);
      v9 = *(double *)(this + 228);
      *(float *)a3 = *(double *)(this + 220);
      *(float *)(a3 + 4) = v9;
      *(float *)(a3 + 8) = v8;
      return 0;
    }
  }
}
