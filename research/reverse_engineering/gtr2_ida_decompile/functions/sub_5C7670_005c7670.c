char __thiscall sub_5C7670(_BYTE *this, int a2, int a3, int a4, char a5)
{
  unsigned int v5; // kr00_4
  __int32 v6; // eax
  int v7; // ebp
  _BYTE *v8; // esi
  int v9; // esi
  __int32 v10; // edi
  int v12; // eax
  void (__thiscall ***v13)(_DWORD); // edi
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  _DWORD *v18; // eax
  int v19; // ebx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  float v26; // ecx
  int v27; // ebx
  int v28; // eax
  int v29; // esi
  int v30; // ecx
  int v31; // eax
  int v32; // ebx
  void *v33; // eax
  int *v34; // eax
  int v35; // edi
  int v36; // ebx
  float *v37; // esi
  double v38; // st7
  double v39; // st6
  int v40; // eax
  double v41; // st7
  double v42; // st6
  int v43; // ecx
  int v44; // ecx
  float v45; // eax
  double v46; // st7
  int v47; // esi
  bool v48; // cc
  int v49; // [esp+4h] [ebp-118h]
  __int32 v50[5]; // [esp+Ch] [ebp-110h] BYREF
  int v51; // [esp+20h] [ebp-FCh]
  int v52; // [esp+24h] [ebp-F8h] BYREF
  _BYTE v53[4]; // [esp+28h] [ebp-F4h] BYREF
  int v54; // [esp+2Ch] [ebp-F0h]
  int v55; // [esp+30h] [ebp-ECh]
  int v56; // [esp+34h] [ebp-E8h]
  int v57; // [esp+38h] [ebp-E4h]
  int v58; // [esp+3Ch] [ebp-E0h]
  int v59; // [esp+40h] [ebp-DCh]
  _DWORD *v60; // [esp+44h] [ebp-D8h]
  int v61; // [esp+48h] [ebp-D4h]
  int v62; // [esp+4Ch] [ebp-D0h]
  char *v63; // [esp+50h] [ebp-CCh]
  int v64; // [esp+54h] [ebp-C8h] BYREF
  __int32 v65; // [esp+58h] [ebp-C4h]
  int v66; // [esp+5Ch] [ebp-C0h]
  int v67; // [esp+60h] [ebp-BCh]
  int v68; // [esp+64h] [ebp-B8h]
  int v69; // [esp+68h] [ebp-B4h]
  int v70; // [esp+6Ch] [ebp-B0h]
  _BYTE *v71; // [esp+70h] [ebp-ACh]
  int v72; // [esp+74h] [ebp-A8h]
  _UNKNOWN **v73; // [esp+78h] [ebp-A4h] BYREF
  void (__thiscall ***v74)(_DWORD); // [esp+7Ch] [ebp-A0h]
  float v75; // [esp+88h] [ebp-94h]
  int v76; // [esp+8Ch] [ebp-90h]
  float v77; // [esp+90h] [ebp-8Ch] BYREF
  float v78; // [esp+94h] [ebp-88h]
  float v79; // [esp+98h] [ebp-84h]
  float v80[9]; // [esp+9Ch] [ebp-80h] BYREF
  char v81[16]; // [esp+C0h] [ebp-5Ch] BYREF
  char v82[16]; // [esp+E0h] [ebp-3Ch] BYREF
  int v83; // [esp+118h] [ebp-4h]

  v7 = 0;
  v8 = this;
  v71 = this;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 4))(a2, &v64, 20);
    if ( v8[12] )
    {
      sub_643E40("- Mesh");
      if ( v8[12] )
      {
        sub_643E40("    + NodeNumber    = %d", v64);
        if ( v8[12] )
        {
          sub_643E40("    + NumOrgVerts   = %d", v65);
          if ( v8[12] )
          {
            sub_643E40("    + NumVerts      = %d", v66);
            if ( v8[12] )
            {
              sub_643E40("    + NumIndices    = %d", v67);
              if ( v8[12] )
                sub_643E40("    + NumSubMeshes  = %d", v68);
            }
          }
        }
      }
    }
    v60 = operator new(0x4Cu);
    v83 = 6;
    if ( v60 )
    {
      v50[0] = v65;
      v12 = sub_5C2FF0();
    }
    else
    {
      v12 = 0;
    }
    v83 = -1;
    v73 = &off_7296C4;
    v74 = 0;
    sub_5BD210(&v73, v12);
    v13 = v74;
    v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v64) + 296);
    v83 = 7;
    if ( v74 )
      (**v74)(v74);
    v15 = *(_DWORD *)(v14 + 4);
    *(_DWORD *)(v14 + 4) = v13;
    if ( v15 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 4))(v15);
    if ( v13 )
      v16 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
    else
      v16 = 0;
    v17 = *(_DWORD *)(v16 + 40);
    v18 = operator new(8u);
    v60 = v18;
    LOBYTE(v83) = 8;
    if ( v18 )
      v19 = sub_5D3490(v18, v17);
    else
      v19 = 0;
    LOBYTE(v83) = 7;
    if ( v13 )
      (*v13)[3](v13);
    v50[0] = v19;
    sub_5C3CB0();
    if ( v13 )
      v20 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
    else
      v20 = 0;
    v61 = *(_DWORD *)(v20 + 16);
    if ( v13 )
      v21 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
    else
      v21 = 0;
    v58 = *(_DWORD *)(v21 + 20);
    if ( v13 )
      v22 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
    else
      v22 = 0;
    v57 = *(_DWORD *)(v22 + 16) + 12 * *(_DWORD *)(v22 + 40);
    if ( v13 )
      v23 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
    else
      v23 = 0;
    v62 = *(_DWORD *)(v23 + 20) + 12 * *(_DWORD *)(v23 + 40);
    if ( v13 )
      v24 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
    else
      v24 = 0;
    v79 = *(float *)(v24 + 28);
    if ( v13 )
      v25 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
    else
      v25 = 0;
    v26 = *(float *)(v19 + 4);
    v60 = *(_DWORD **)(v25 + 32);
    v27 = 0;
    v75 = v26;
    v59 = 0;
    v56 = 0;
    v52 = 0;
    if ( v68 > 0 )
    {
      while ( 1 )
      {
        (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v53, 12);
        if ( v8[12] )
        {
          sub_643E40("    - Reading SubMesh");
          if ( v8[12] )
          {
            sub_643E40("       + Material ID   = %d", v53[0]);
            if ( v8[12] )
            {
              sub_643E40("       + NumOfIndices  = %d", v54);
              if ( v8[12] )
              {
                sub_643E40("       + NumOfVertices = %d", v55);
                if ( v8[12] )
                  sub_643E40("       + NumOfUVSets   = %d", v53[1]);
              }
            }
          }
        }
        v63 = (char *)operator new(0x1Cu);
        v28 = 0;
        LOBYTE(v83) = 9;
        if ( v63 )
        {
          if ( v13 )
            v28 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
          v28 = sub_5D3420(v28, v7, v27, v55, v54, v53[0]);
        }
        v51 = v28;
        LOBYTE(v83) = 7;
        if ( v13 )
          v29 = ((int (__thiscall *)(_DWORD))(*v13)[3])(v13);
        else
          v29 = 0;
        v30 = *(_DWORD *)(v29 + 8);
        v31 = *(_DWORD *)(v29 + 4) + 1;
        *(_DWORD *)(v29 + 4) = v31;
        if ( v30 < v31 )
        {
          v32 = v31 + 1;
          sub_4F14D0(v50[1]);
          v33 = sub_5A8CF0(*(void **)(v29 + 12), 4 * v32, 2, 16, 2);
          *(_DWORD *)(v29 + 8) = v32;
          v27 = v59;
          *(_DWORD *)(v29 + 12) = v33;
        }
        v34 = (int *)(*(_DWORD *)(v29 + 12) + 4 * (*(_DWORD *)(v29 + 4) - 1));
        if ( v34 )
          *v34 = v51;
        v51 = 0;
        if ( v55 > 0 )
        {
          v35 = 12 * v7 + v58 + 8;
          v36 = 12 * v7 + v62;
          v70 = v57 - v61;
          v37 = (float *)(12 * v7 + v61 + 4);
          v76 = v58 - v61;
          v69 = v62 - v61;
          LODWORD(v78) = v57 - v58;
          v63 = (char *)(v62 - v58);
          v72 = v57 - v62;
          do
          {
            (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, v80, 36);
            v38 = v80[1];
            v39 = v80[2];
            *(v37 - 1) = v80[0];
            *v37 = v38;
            v40 = v76;
            ++v7;
            v37[1] = v39;
            v41 = v80[4];
            v37 += 3;
            v42 = v80[5];
            *(float *)(v35 - 8) = v80[3];
            v43 = v72;
            *(float *)((char *)v37 + v40 - 12) = v41;
            v35 += 12;
            v36 += 12;
            *(float *)(v35 - 12) = v42;
            *(float *)(v43 + v36 - 12) = *(v37 - 4);
            *(float *)((char *)v37 + v70 - 12) = *(v37 - 3);
            *(float *)(LODWORD(v78) + v35 - 12) = *(v37 - 2);
            v44 = v69;
            *(_DWORD *)(v36 - 12) = *(_DWORD *)(v35 - 20);
            *(float *)((char *)v37 + v44 - 12) = *(float *)((char *)v37 + v40 - 12);
            *(_DWORD *)&v63[v35 - 12] = *(_DWORD *)(v35 - 12);
            v45 = v75;
            *(float *)(LODWORD(v79) + 4 * v7 - 4) = v80[8];
            v46 = v80[7];
            *(float *)(LODWORD(v45) + 8 * v7 - 8) = v80[6];
            *(float *)(LODWORD(v45) + 8 * v7 - 4) = v46;
            ++v51;
          }
          while ( v51 < v55 );
          v13 = v74;
          v27 = v59;
        }
        v47 = 0;
        if ( v54 > 0 )
        {
          do
          {
            (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &v77, 4);
            v60[v27++] = v56 + LODWORD(v77);
            ++v47;
          }
          while ( v47 < v54 );
          v59 = v27;
        }
        v48 = v52 + 1 < v68;
        v56 += v55;
        ++v52;
        if ( !v48 )
          break;
        v8 = v71;
      }
    }
    if ( a5 )
    {
      if ( v13 )
        (*v13)[3](v13);
      v50[0] = 0;
      sub_5C3690();
    }
    v83 = -1;
    if ( v13 )
      (*v13)[1](v13);
    return 1;
  }
  else
  {
    v52 = 2;
    sub_4050C0((int)"Passed actor seems to be not valid!");
    v83 = 1;
    v9 = sub_4050C0((int)off_90A2C0[0]);
    v10 = sub_4050C0((int)"::");
    v50[0] = v10;
    v5 = __readeflags();
    v6 = dword_16C6E04 + 1618205185;
    __writeeflags(v5);
    _InterlockedExchange(v50, v6);
    LOBYTE(v83) = 2;
    sub_4050C0(v50[0]);
    LOBYTE(v83) = 3;
    sub_5BE180(v9, (int)v82, v10);
    LOBYTE(v83) = 4;
    v50[0] = sub_5BE180(v9, (int)v81, v9);
    LOBYTE(v83) = 5;
    sub_5C6150((__int32)&v52, (int)&v73);
    sub_643D50(v49, &v52, v50[0]);
    LOBYTE(v83) = 4;
    sub_5A8840();
    LOBYTE(v83) = 3;
    sub_5A8840();
    LOBYTE(v83) = 2;
    sub_5A8840();
    LOBYTE(v83) = 1;
    sub_5A8840();
    LOBYTE(v83) = 0;
    sub_5A8840();
    v83 = -1;
    sub_5A8840();
    return 0;
  }
}
