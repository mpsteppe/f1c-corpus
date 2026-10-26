char __thiscall sub_5CC270(_BYTE *this, _DWORD *a2, int a3, int a4, int a5)
{
  int v7; // eax
  void *v8; // edi
  int v9; // edi
  _DWORD *v10; // esi
  int v11; // edx
  char *v12; // edi
  char v13; // dl
  unsigned int v14; // ecx
  int v15; // edx
  int v16; // edi
  char v17; // al
  int v18; // ecx
  unsigned int v19; // edi
  char v20; // dl
  unsigned int v21; // ecx
  int v22; // eax
  int v23; // edi
  char v24; // dl
  unsigned int v25; // ecx
  char *v26; // edi
  char v27; // al
  unsigned int v28; // ecx
  int v29; // [esp+0h] [ebp-180h]
  int v30; // [esp+0h] [ebp-180h]
  double v31; // [esp+Ch] [ebp-174h] BYREF
  int **v32; // [esp+14h] [ebp-16Ch]
  unsigned int v33; // [esp+18h] [ebp-168h] BYREF
  double v34; // [esp+1Ch] [ebp-164h]
  double v35; // [esp+24h] [ebp-15Ch] BYREF
  double v36; // [esp+2Ch] [ebp-154h] BYREF
  unsigned int v37; // [esp+34h] [ebp-14Ch] BYREF
  unsigned int v38; // [esp+38h] [ebp-148h] BYREF
  float **v39; // [esp+3Ch] [ebp-144h]
  int v40; // [esp+40h] [ebp-140h] BYREF
  double v41; // [esp+44h] [ebp-13Ch] BYREF
  int *v42; // [esp+4Ch] [ebp-134h] BYREF
  int v43; // [esp+50h] [ebp-130h]
  int v44; // [esp+54h] [ebp-12Ch] BYREF
  float *v45; // [esp+58h] [ebp-128h] BYREF
  double *v46; // [esp+5Ch] [ebp-124h] BYREF
  unsigned int v47; // [esp+60h] [ebp-120h] BYREF
  int v48; // [esp+64h] [ebp-11Ch] BYREF
  int v49; // [esp+68h] [ebp-118h]
  void *v50; // [esp+6Ch] [ebp-114h] BYREF
  int v51; // [esp+70h] [ebp-110h]
  void *Block; // [esp+74h] [ebp-10Ch] BYREF
  int v53; // [esp+78h] [ebp-108h]
  _BYTE v54[4]; // [esp+7Ch] [ebp-104h] BYREF
  int v55; // [esp+80h] [ebp-100h]
  unsigned int v56[2]; // [esp+84h] [ebp-FCh] BYREF
  _BYTE *v57; // [esp+8Ch] [ebp-F4h] BYREF
  double v58; // [esp+94h] [ebp-ECh] BYREF
  float v59; // [esp+9Ch] [ebp-E4h] BYREF
  int v60; // [esp+A0h] [ebp-E0h]
  int v61[23]; // [esp+A4h] [ebp-DCh] BYREF
  char v62[8]; // [esp+100h] [ebp-80h] BYREF
  _DWORD v63[2]; // [esp+108h] [ebp-78h] BYREF
  int v64; // [esp+110h] [ebp-70h]
  int v65; // [esp+118h] [ebp-68h]
  _DWORD v66[2]; // [esp+120h] [ebp-60h] BYREF
  _DWORD v67[2]; // [esp+128h] [ebp-58h] BYREF
  int v68; // [esp+130h] [ebp-50h]
  char v69; // [esp+140h] [ebp-40h]
  int v70; // [esp+144h] [ebp-3Ch]
  int v71; // [esp+150h] [ebp-30h]
  int v72; // [esp+154h] [ebp-2Ch]
  int v73; // [esp+158h] [ebp-28h]
  int v74; // [esp+15Ch] [ebp-24h]
  char v75; // [esp+168h] [ebp-18h]
  int v76; // [esp+16Ch] [ebp-14h]
  int v77; // [esp+174h] [ebp-Ch]

  v76 = dword_912B08;
  v57 = this;
  v53 = 0;
  if ( a3 )
  {
    v7 = *a2;
    v48 = 96;
    (*(void (__thiscall **)(_DWORD *, _DWORD *))(v7 + 4))(a2, v63);
    if ( this[12] )
    {
      sub_643E40("- Material name = '%s'", v62);
      if ( this[12] )
      {
        sub_643E40("  + Effect file       = '%s'", (const char *)v67);
        if ( this[12] )
        {
          sub_643E40("  + Num int params    = %d", v71);
          if ( this[12] )
          {
            sub_643E40("  + Num float params  = %d", v72);
            if ( this[12] )
            {
              sub_643E40("  + Num color params  = %d", v73);
              if ( this[12] )
                sub_643E40("  + Num bitmap params = %d", v74);
            }
          }
        }
      }
    }
    v8 = operator new(0x54u);
    v50 = v8;
    v77 = 0;
    if ( v8 )
    {
      sub_4050C0((int)v62);
      v45 = &v59;
      return off_16C9234(v8, a2, a3, a4, a5);
    }
    else
    {
      v77 = 2;
      HIDWORD(v58) = &off_7296CC;
      v59 = 0.0;
      sub_5BD2D0((_DWORD *)&v58 + 1, 0);
      v77 = 4;
      if ( (v51 & 1) != 0 )
        sub_5A8840();
      v9 = LODWORD(v59);
      if ( v59 == 0.0 )
        v51 = 0;
      else
        v51 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v59) + 12))(COERCE_FLOAT(LODWORD(v59)));
      v46 = (double *)((char *)&v58 + 4);
      v45 = 0;
      sub_5BD510();
      sub_4050C0((int)v66);
      v75 = 5;
      sub_5A8920((void **)(v48 + 68), v9, v55, v56[0]);
      v75 = 4;
      sub_5A8840();
      if ( *(_BYTE *)(v53 + 12) )
        sub_643E40("  + Parameters:");
      v47 = 0;
      if ( v70 <= 0 )
      {
        v10 = a2;
      }
      else
      {
        do
        {
          v10 = a2;
          v11 = *a2;
          v43 = 44;
          v42 = v61;
          (*(void (__thiscall **)(_DWORD *))(v11 + 4))(a2);
          if ( *(_BYTE *)(v51 + 12) )
            sub_643E40("    + int %s = %d", (const char *)&v59, v61[8]);
          v47 = (unsigned int)&off_6F197C;
          v48 = 0;
          v49 = 0;
          v50 = 0;
          sub_5A8860(&v47, strlen((const char *)&v59), 0);
          v12 = (char *)v46;
          if ( v46 )
          {
            v13 = v47;
            v14 = v47 >> 2;
            qmemcpy(v46, &v58, 4 * (v47 >> 2));
            qmemcpy(&v12[4 * v14], (char *)&v58 + 4 * v14, v13 & 3);
            v10 = a2;
          }
          v40 = v61[6];
          v39 = &v45;
          LOBYTE(v73) = 6;
          sub_5C7380();
          LOBYTE(v71) = 4;
          sub_5A8840();
          ++HIDWORD(v41);
        }
        while ( SHIDWORD(v41) < v67[1] );
        v9 = v53;
      }
      HIDWORD(v41) = 0;
      if ( v68 > 0 )
      {
        do
        {
          v15 = *v10;
          v38 = 44;
          v37 = (unsigned int)&v57;
          (*(void (__thiscall **)(_DWORD *))(v15 + 4))(v10);
          if ( *((_BYTE *)v45 + 12) )
            sub_643E40("    + float %s = %f", (const char *)v56, *(float *)&v61[2]);
          HIDWORD(v41) = &off_6F197C;
          v42 = 0;
          v43 = 0;
          v44 = 0;
          sub_5A8860((char *)&v41 + 4, strlen((const char *)v56), 0);
          v16 = LODWORD(v41);
          if ( LODWORD(v41) )
          {
            v17 = BYTE4(v41);
            v18 = HIDWORD(v41) >> 2;
            qmemcpy((void *)LODWORD(v41), v54, 4 * (HIDWORD(v41) >> 2));
            qmemcpy((void *)(v16 + 4 * v18), &v54[4 * v18], v17 & 3);
            v10 = a2;
          }
          v69 = 7;
          sub_5C7430((int)&v40, v61[0]);
          v69 = 4;
          sub_5A8840();
          ++v38;
        }
        while ( (int)v38 < v66[0] );
        v9 = v49;
      }
      v38 = 0;
      if ( v66[1] > 0 )
      {
        do
        {
          (*(void (__thiscall **)(_DWORD *, _BYTE *, int))(*v10 + 4))(v10, v54, 56);
          if ( *(_BYTE *)(HIDWORD(v41) + 12) )
            sub_643E40(
              "    + color %s = (%f, %f, %f, %f)",
              (const char *)&Block,
              v59,
              *(float *)&v60,
              *(float *)v61,
              *(float *)&v61[1]);
          v38 = (unsigned int)&off_6F197C;
          v39 = 0;
          v40 = 0;
          LODWORD(v41) = 0;
          sub_5A8860(&v38, strlen((const char *)&Block), 0);
          v19 = v37;
          if ( v37 )
          {
            v20 = v38;
            v21 = v38 >> 2;
            qmemcpy((void *)v37, &v50, 4 * (v38 >> 2));
            qmemcpy((void *)(v19 + 4 * v21), &v50 + v21, v20 & 3);
            v10 = a2;
          }
          v42 = (int *)LODWORD(v59);
          v33 = (unsigned int)&v41;
          v41 = v58;
          v32 = (int **)&v36 + 1;
          LOBYTE(v68) = 8;
          v43 = v60;
          sub_5C74E0();
          LOBYTE(v67[0]) = 4;
          sub_5A8840();
          ++HIDWORD(v34);
        }
        while ( SHIDWORD(v34) < v63[1] );
        v9 = v43;
      }
      HIDWORD(v34) = 0;
      if ( v64 > 0 )
      {
        do
        {
          v22 = *v10;
          HIDWORD(v31) = 80;
          (*(void (__thiscall **)(_DWORD *))(v22 + 4))(v10);
          if ( *(_BYTE *)(HIDWORD(v36) + 12) )
            sub_643E40("    + string %s = %s", (const char *)&v46, (const char *)v56);
          v37 = (unsigned int)&off_6F197C;
          v38 = 0;
          v39 = 0;
          v40 = 0;
          sub_5A8860(&v37, strlen((const char *)v56), 0);
          v23 = HIDWORD(v36);
          if ( HIDWORD(v36) )
          {
            v24 = v37;
            v25 = v37 >> 2;
            qmemcpy((void *)HIDWORD(v36), v54, 4 * (v37 >> 2));
            qmemcpy((void *)(v23 + 4 * v25), &v54[4 * v25], v24 & 3);
            v10 = a2;
          }
          LOBYTE(v65) = 9;
          v33 = (unsigned int)&off_6F197C;
          v34 = 0.0;
          LODWORD(v35) = 0;
          sub_5A8860(&v33, strlen((const char *)&v44), 0);
          v26 = (char *)v32;
          if ( v32 )
          {
            v27 = v33;
            v28 = v33 >> 2;
            qmemcpy(v32, &v42, 4 * (v33 >> 2));
            qmemcpy(&v26[4 * v28], &(&v42)[v28], v27 & 3);
            v10 = a2;
          }
          LOBYTE(v64) = 10;
          ((void (__thiscall *)(int *, char *, double *))dword_5C75A0)(&v48, (char *)&v31 + 4, &v35);
          LOBYTE(v63[0]) = 9;
          sub_5A8840();
          LOBYTE(v63[0]) = 4;
          sub_5A8840();
          v30 = v29 + 1;
        }
        while ( v30 < v61[19] );
        v9 = HIDWORD(v36);
      }
      v63[0] = -1;
      if ( v9 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(v9);
      return 1;
    }
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
