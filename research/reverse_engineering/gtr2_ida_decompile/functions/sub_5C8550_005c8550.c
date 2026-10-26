char __thiscall sub_5C8550(_BYTE *this, int a2, int a3, int a4, char a5)
{
  unsigned int v5; // kr00_4
  int v7; // esi
  int v8; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // esi
  int v13; // ecx
  int v14; // esi
  void *v15; // esi
  int v16; // edi
  int v17; // eax
  int v18; // esi
  bool v19; // cc
  int *v20; // esi
  int v21; // esi
  int *v22; // esi
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  _BYTE *v29; // esi
  int v30; // edi
  int v31; // eax
  int v32; // ebx
  int v33; // esi
  int v34; // ecx
  int v35; // eax
  int v36; // edi
  _DWORD *v37; // eax
  float *v38; // edi
  float *v39; // esi
  double v40; // st7
  double v41; // st6
  _DWORD *v42; // eax
  int v43; // ebx
  double v44; // st7
  double v45; // st6
  int v46; // ecx
  int j; // ebx
  float v48; // edx
  int v49; // eax
  int v50; // esi
  int v51; // edi
  int v52; // esi
  int v53; // [esp+14h] [ebp-124h]
  int v54; // [esp+1Ch] [ebp-11Ch]
  int v55; // [esp+1Ch] [ebp-11Ch]
  int v56; // [esp+20h] [ebp-118h]
  int v57; // [esp+20h] [ebp-118h]
  int v58; // [esp+2Ch] [ebp-10Ch] BYREF
  int v59; // [esp+30h] [ebp-108h]
  int i; // [esp+34h] [ebp-104h]
  int v61; // [esp+38h] [ebp-100h]
  int v62; // [esp+3Ch] [ebp-FCh]
  void *Block; // [esp+40h] [ebp-F8h]
  int v64; // [esp+44h] [ebp-F4h] BYREF
  int v65; // [esp+48h] [ebp-F0h]
  int v66; // [esp+4Ch] [ebp-ECh]
  int v67; // [esp+50h] [ebp-E8h] BYREF
  int v68; // [esp+54h] [ebp-E4h]
  void *v69; // [esp+58h] [ebp-E0h]
  int v70; // [esp+60h] [ebp-D8h] BYREF
  int v71; // [esp+64h] [ebp-D4h]
  void *v72; // [esp+68h] [ebp-D0h]
  int v73; // [esp+70h] [ebp-C8h]
  int v74; // [esp+74h] [ebp-C4h]
  void *v75; // [esp+78h] [ebp-C0h]
  _DWORD v76[4]; // [esp+7Ch] [ebp-BCh] BYREF
  int v77; // [esp+8Ch] [ebp-ACh]
  int v78; // [esp+90h] [ebp-A8h]
  int v79; // [esp+94h] [ebp-A4h]
  _UNKNOWN **v80; // [esp+98h] [ebp-A0h] BYREF
  int v81; // [esp+9Ch] [ebp-9Ch]
  int v82; // [esp+A8h] [ebp-90h]
  int v83; // [esp+ACh] [ebp-8Ch]
  int v84; // [esp+B0h] [ebp-88h]
  int v85; // [esp+B4h] [ebp-84h]
  int v86; // [esp+B8h] [ebp-80h]
  int v87; // [esp+BCh] [ebp-7Ch]
  int v88; // [esp+C0h] [ebp-78h]
  int v89; // [esp+C4h] [ebp-74h] BYREF
  float v90; // [esp+C8h] [ebp-70h]
  int v91; // [esp+CCh] [ebp-6Ch]
  _BYTE *v92; // [esp+D0h] [ebp-68h]
  float v93[2]; // [esp+D4h] [ebp-64h] BYREF
  _DWORD v94[7]; // [esp+DCh] [ebp-5Ch] BYREF
  int v95; // [esp+134h] [ebp-4h]

  v92 = this;
  if ( !a3 )
  {
    v58 = 2;
    sub_4050C0((int)"Passed actor seems to be not valid!");
    v5 = __readeflags();
    __writeeflags(v5);
    v54 = *(_DWORD *)(*(_DWORD *)((char *)&loc_45A536 + 1) + dword_16C6C48);
    v95 = 3;
    v7 = sub_4050C0(v54);
    v8 = sub_4050C0((int)"::");
    sub_4050C0((int)"MeshChunkProcessor3");
    sub_5BE180(v7, (int)&v80, v8);
    LOBYTE(v95) = 4;
    v55 = sub_5BE180(v7, (int)&v70, v7);
    LOBYTE(v95) = 5;
    sub_5C6150((__int32)&v58, (int)&v67);
    sub_643D50(v53, &v58, v55);
    LOBYTE(v95) = 4;
    sub_5A8840();
    LOBYTE(v95) = 3;
    sub_5A8840();
    LOBYTE(v95) = 2;
    sub_5A8840();
    LOBYTE(v95) = 1;
    sub_5A8840();
    LOBYTE(v95) = 0;
    sub_5A8840();
    v95 = -1;
    sub_5A8840();
    return 0;
  }
  (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)a2 + 4))(a2, v76, 28);
  if ( this[12] )
  {
    sub_643E40("- Mesh");
    if ( this[12] )
    {
      sub_643E40("    + NodeNumber      = %d", v76[0]);
      if ( this[12] )
      {
        sub_643E40("    + NumOrgVerts     = %d", v76[1]);
        if ( this[12] )
        {
          sub_643E40("    + NumVerts        = %d", v76[2]);
          if ( this[12] )
          {
            sub_643E40("    + NumIndices      = %d", v76[3]);
            if ( this[12] )
            {
              sub_643E40("    + NumSubMeshes    = %d", v77);
              if ( this[12] )
              {
                sub_643E40("    + NumUVSets       = %d", v78);
                if ( this[12] )
                  sub_643E40("    + IsCollisionMesh = %d", (unsigned __int8)v79);
              }
            }
          }
        }
      }
    }
  }
  Block = operator new(0x4Cu);
  v95 = 6;
  if ( Block )
    v10 = sub_5C2FF0();
  else
    v10 = 0;
  v95 = -1;
  v80 = &off_7296C4;
  v81 = 0;
  sub_5BD210(&v80, v10);
  v95 = 7;
  if ( (_BYTE)v79 )
  {
    v11 = v81;
    v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v76[0]) + 320);
    if ( v81 )
      (**(void (__thiscall ***)(int))v81)(v81);
    v13 = *(_DWORD *)(v12 + 4);
    *(_DWORD *)(v12 + 4) = v11;
    if ( !v13 )
      goto LABEL_24;
  }
  else
  {
    v11 = v81;
    v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v76[0]) + 296);
    if ( v81 )
      (**(void (__thiscall ***)(int))v81)(v81);
    v13 = *(_DWORD *)(v14 + 4);
    *(_DWORD *)(v14 + 4) = v11;
    if ( !v13 )
      goto LABEL_24;
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 4))(v13);
LABEL_24:
  v67 = 0;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v72 = 0;
  LOBYTE(v95) = 9;
  for ( i = 0; i < v78; ++i )
  {
    v15 = operator new(8u);
    Block = v15;
    LOBYTE(v95) = 10;
    if ( v15 )
    {
      if ( v11 )
      {
        v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
        v16 = sub_5D3490(v15, *(_DWORD *)(v17 + 40));
      }
      else
      {
        v16 = sub_5D3490(v15, MEMORY[0x28]);
      }
    }
    else
    {
      v16 = 0;
    }
    v61 = v16;
    LOBYTE(v95) = 9;
    if ( v11 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
    sub_5C3CB0();
    v18 = v67 + 1;
    v19 = v68 < ++v67;
    if ( v19 )
    {
      sub_4F14D0(v56);
      v68 = v18 + 1;
      v16 = v61;
      v69 = sub_5A8CF0(v69, 4 * (v18 + 1), 2, 16, 2);
    }
    v20 = (int *)((char *)v69 + 4 * v18 - 4);
    if ( v20 )
      *v20 = v16;
    v21 = v70 + 1;
    v19 = v71 < v70 + 1;
    v58 = *(_DWORD *)(v16 + 4);
    ++v70;
    if ( v19 )
    {
      sub_4F14D0(v56);
      v72 = sub_5A8CF0(v72, 4 * (v21 + 1), 2, 16, 2);
      v71 = v21 + 1;
    }
    v22 = (int *)((char *)v72 + 4 * v21 - 4);
    if ( v22 )
      *v22 = v58;
  }
  if ( v11 )
    v23 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
  else
    v23 = 0;
  v90 = *(float *)(v23 + 16);
  if ( v11 )
    v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
  else
    v24 = 0;
  v88 = *(_DWORD *)(v24 + 20);
  if ( v11 )
    v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
  else
    v25 = 0;
  v74 = *(_DWORD *)(v25 + 16) + 12 * *(_DWORD *)(v25 + 40);
  if ( v11 )
    v26 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
  else
    v26 = 0;
  v91 = *(_DWORD *)(v26 + 20) + 12 * *(_DWORD *)(v26 + 40);
  if ( v11 )
    v27 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
  else
    v27 = 0;
  v86 = *(_DWORD *)(v27 + 28);
  if ( v11 )
    v28 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11);
  else
    v28 = 0;
  Block = *(void **)(v28 + 32);
  v59 = 0;
  i = 0;
  v61 = 0;
  v58 = 0;
  if ( v77 > 0 )
  {
    do
    {
      (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 4))(a2, &v64, 12);
      v29 = v92;
      if ( v92[12] )
      {
        sub_643E40("    - Reading SubMesh");
        if ( v29[12] )
        {
          sub_643E40("       + Material ID   = %d", (char)v64);
          if ( v29[12] )
          {
            sub_643E40("       + NumOfIndices  = %d", v65);
            if ( v29[12] )
              sub_643E40("       + NumOfVertices = %d", v66);
          }
        }
      }
      v75 = operator new(0x1Cu);
      v30 = v81;
      LOBYTE(v95) = 11;
      if ( v75 )
      {
        if ( v81 )
          v31 = (*(int (__thiscall **)(int))(*(_DWORD *)v81 + 12))(v81);
        else
          v31 = 0;
        v32 = sub_5D3420(v31, v59, i, v66, v65, (char)v64);
      }
      else
      {
        v32 = 0;
      }
      LOBYTE(v95) = 9;
      if ( v30 )
        v33 = (*(int (__thiscall **)(int))(*(_DWORD *)v30 + 12))(v30);
      else
        v33 = 0;
      v34 = *(_DWORD *)(v33 + 8);
      v35 = *(_DWORD *)(v33 + 4) + 1;
      *(_DWORD *)(v33 + 4) = v35;
      if ( v34 < v35 )
      {
        v36 = v35 + 1;
        sub_4F14D0(v56);
        *(_DWORD *)(v33 + 12) = sub_5A8CF0(*(void **)(v33 + 12), 4 * v36, 2, 16, 2);
        *(_DWORD *)(v33 + 8) = v36;
      }
      v37 = (_DWORD *)(*(_DWORD *)(v33 + 12) + 4 * (*(_DWORD *)(v33 + 4) - 1));
      if ( v37 )
        *v37 = v32;
      v73 = 0;
      if ( v66 > 0 )
      {
        v62 = 12 * v59 + v91;
        v87 = v74 - LODWORD(v90);
        v83 = v88 - LODWORD(v90);
        v38 = (float *)(12 * v59 + v88 + 8);
        v39 = (float *)(12 * v59 + LODWORD(v90) + 4);
        v84 = v91 - LODWORD(v90);
        v82 = v74 - v88;
        v75 = (void *)(v91 - v88);
        v85 = v74 - v91;
        do
        {
          (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)a2 + 4))(a2, v94, 28);
          v40 = *(float *)&v94[2];
          v41 = *(float *)&v94[3];
          *(v39 - 1) = *(float *)&v94[1];
          *v39 = v40;
          v42 = (_DWORD *)v62;
          v43 = v85;
          v39[1] = v41;
          v44 = *(float *)&v94[5];
          v45 = *(float *)&v94[6];
          *(v38 - 2) = *(float *)&v94[4];
          v46 = v83;
          *(float *)((char *)v39 + v83) = v44;
          *v38 = v45;
          *(_DWORD *)((char *)v42 + v43) = *((_DWORD *)v39 - 1);
          *(float *)((char *)v39 + v87) = *v39;
          *(float *)((char *)v38 + v82) = v39[1];
          *v42 = *((_DWORD *)v38 - 2);
          *(float *)((char *)v39 + v84) = *(float *)((char *)v39 + v46);
          *(float *)((char *)v38 + (_DWORD)v75) = *v38;
          *(_DWORD *)(v86 + 4 * v59) = v94[0];
          for ( j = 0; j < v78; ++j )
          {
            (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, v93, 8);
            v48 = v93[0];
            v49 = 8 * v59 + *((_DWORD *)v72 + j);
            *(float *)(v49 + 4) = v93[1];
            *(float *)v49 = v48;
          }
          v39 += 3;
          v38 += 3;
          v19 = v73 + 1 < v66;
          ++v59;
          v62 += 12;
          ++v73;
        }
        while ( v19 );
      }
      v50 = 0;
      if ( v65 > 0 )
      {
        v51 = i;
        do
        {
          (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 4))(a2, &v89, 4);
          *((_DWORD *)Block + v51++) = v61 + v89;
          ++v50;
        }
        while ( v50 < v65 );
        i = v51;
      }
      v19 = v58 + 1 < v77;
      v61 += v66;
      ++v58;
    }
    while ( v19 );
  }
  v52 = v81;
  if ( a5 )
  {
    if ( v81 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v81 + 12))(v81);
    sub_5C3690();
  }
  LOBYTE(v95) = 8;
  sub_4F14D0(v56);
  sub_5A8D10(v72);
  LOBYTE(v95) = 7;
  sub_4F14D0(v57);
  sub_5A8D10(v69);
  v95 = -1;
  if ( v52 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v52 + 4))(v52);
  return 1;
}
