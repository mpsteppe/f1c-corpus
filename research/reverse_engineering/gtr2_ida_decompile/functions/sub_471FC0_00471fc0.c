char __thiscall sub_471FC0(int this, float a2, int a3, char a4)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  double v20; // st7
  double v21; // st6
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  int v26; // edx
  double v27; // st7
  double v28; // st6
  double v29; // st6
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // ecx
  unsigned __int8 v35; // c0
  unsigned __int8 v36; // c2
  unsigned __int8 v38; // c0
  unsigned __int8 v39; // c2
  int v40; // [esp+18h] [ebp-44h]
  int v41[3]; // [esp+1Ch] [ebp-40h] BYREF
  double v42; // [esp+2Ch] [ebp-30h] BYREF
  double v43; // [esp+34h] [ebp-28h]
  double v44; // [esp+3Ch] [ebp-20h]
  double v45[3]; // [esp+44h] [ebp-18h] BYREF

  v5 = *(float *)(this + 32);
  *(float *)(this + 40) = a2;
  if ( v5 >= *(float *)(this + 36) )
    v6 = *(float *)(this + 36);
  else
    v6 = *(float *)(this + 32);
  if ( a2 <= v6 )
  {
    if ( !*(_DWORD *)(this + 216) )
      return 0;
    sub_470210((char *)this, 0.0125, a4);
    sub_470210((char *)this, 0.0125, a4);
    *(float *)&v40 = *(double *)(this + 248);
    v29 = *(double *)(this + 240);
    *(float *)v41 = v29;
    *(float *)a3 = *(double *)(this + 232);
    *(float *)(a3 + 4) = v29;
    *(float *)(a3 + 8) = *(float *)&v40;
    sub_43A2B0(this + 256, (int)v45);
    *(float *)&v42 = v45[0];
    *((float *)&v42 + 1) = v45[1];
    *(float *)&v43 = v45[2];
    sub_5DB2B0(*(_DWORD *)a3, v41[0], v40, *(float *)&v42, *((float *)&v42 + 1), *(float *)&v43);
    if ( *(double *)(this + 336) >= -100.0 )
    {
      if ( v35 | v36 )
      {
        if ( v38 | v39 )
        {
          *(double *)v41 = sub_43A230((double *)(this + 536)) * *(double *)(this + 408);
          sub_46FE60((double *)(this + 224), (double *)(this + 560), v45);
          if ( *(double *)v41 < 0.04000000000000001 && sub_43A230(v45) < 0.0004 )
          {
            v42 = 0.0;
            v43 = 0.0;
            v44 = 0.0;
            sub_416760((_DWORD *)(this + 224), &v42);
            sub_61B710(&v42);
            *(_DWORD *)(this + 36) = *(_DWORD *)(this + 40);
          }
        }
      }
      return 1;
    }
    else
    {
      v42 = 0.0;
      *(_DWORD *)(this + 328) = COERCE_UNSIGNED_INT64(0.0);
      v43 = 0.0;
      v30 = LODWORD(v43);
      *(_DWORD *)(this + 332) = HIDWORD(COERCE_UNSIGNED_INT64(0.0));
      v44 = 0.0;
      v31 = HIDWORD(v43);
      *(_DWORD *)(this + 336) = v30;
      v32 = LODWORD(v44);
      *(_DWORD *)(this + 340) = v31;
      v33 = HIDWORD(v44);
      *(_DWORD *)(this + 344) = v32;
      *(_DWORD *)(this + 348) = v33;
      sub_61B710(&v42);
      *(_DWORD *)(this + 36) = *(_DWORD *)(this + 40);
      return 1;
    }
  }
  else
  {
    v7 = flt_B72CD0 + *(float *)(this + 36);
    if ( v7 > *(float *)(this + 32) )
      v7 = *(float *)(this + 32);
    if ( a2 > v7 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)this + 4))(this) )
      {
        qmemcpy(v41, "(knN(knN(knN", sizeof(v41));
        sub_5DB150(1315859240, 1315859240, 1315859240);
        sub_5DB320(0, 0, 0);
        v42 = 0.0;
        v43 = 0.0;
        *(_DWORD *)(this + 328) = COERCE_UNSIGNED_INT64(0.0);
        v8 = LODWORD(v43);
        v44 = 0.0;
        *(_DWORD *)(this + 332) = HIDWORD(COERCE_UNSIGNED_INT64(0.0));
        v9 = HIDWORD(v43);
        *(_DWORD *)(this + 336) = v8;
        v10 = LODWORD(v44);
        *(_DWORD *)(this + 340) = v9;
        v11 = HIDWORD(v44);
        *(_DWORD *)(this + 344) = v10;
        *(_DWORD *)(this + 348) = v11;
        sub_61B710(&v42);
        v42 = 1000000000.0;
        v12 = HIDWORD(v42);
        v43 = 1000000000.0;
        *(_DWORD *)(this + 232) = LODWORD(v42);
        v13 = LODWORD(v43);
        v44 = 1000000000.0;
        *(_DWORD *)(this + 236) = v12;
        v14 = HIDWORD(v43);
        *(_DWORD *)(this + 240) = v13;
        v15 = LODWORD(v44);
        *(_DWORD *)(this + 244) = v14;
        v16 = HIDWORD(v44);
        *(_DWORD *)(this + 248) = v15;
        v17 = v41[0];
        *(_DWORD *)(this + 252) = v16;
        v18 = v41[1];
        *(_DWORD *)(this + 200) = v17;
        v19 = v41[2];
        *(_DWORD *)(this + 204) = v18;
        *(_DWORD *)(this + 208) = v19;
      }
      v20 = *(double *)(this + 248);
      v21 = *(double *)(this + 240);
      *(float *)a3 = *(double *)(this + 232);
      *(float *)(a3 + 4) = v21;
      *(float *)(a3 + 8) = v20;
      return 0;
    }
    v42 = 0.0;
    *(_DWORD *)(this + 328) = COERCE_UNSIGNED_INT64(0.0);
    v43 = 0.0;
    v23 = LODWORD(v43);
    *(_DWORD *)(this + 332) = HIDWORD(COERCE_UNSIGNED_INT64(0.0));
    v44 = 0.0;
    v24 = HIDWORD(v43);
    *(_DWORD *)(this + 336) = v23;
    v25 = LODWORD(v44);
    *(_DWORD *)(this + 340) = v24;
    v26 = HIDWORD(v44);
    *(_DWORD *)(this + 344) = v25;
    *(_DWORD *)(this + 348) = v26;
    sub_61B710(&v42);
    v27 = *(double *)(this + 248);
    v28 = *(double *)(this + 240);
    *(float *)a3 = *(double *)(this + 232);
    *(float *)(a3 + 4) = v28;
    *(float *)(a3 + 8) = v27;
    return 1;
  }
}
