char __thiscall sub_5C7DB0(_BYTE *this, int a2, int a3, int a4, char a5)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  int v7; // ebp
  int v9; // esi
  int v10; // edi
  int v12; // eax
  int v13; // esi
  int v14; // edi
  int v15; // ecx
  int v16; // edi
  _DWORD *v17; // edi
  int v18; // edi
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  float v26; // ecx
  _BYTE *v27; // esi
  int v28; // edi
  int v29; // eax
  int v30; // ebx
  int v31; // esi
  int v32; // ecx
  int v33; // eax
  int v34; // edi
  _DWORD *v35; // eax
  int v36; // edi
  int v37; // ebx
  float *v38; // esi
  double v39; // st7
  double v40; // st6
  int v41; // eax
  double v42; // st7
  double v43; // st6
  int v44; // ecx
  int v45; // ecx
  float v46; // eax
  double v47; // st7
  int v48; // esi
  int v49; // edi
  bool v50; // cc
  int v51; // esi
  int v52; // [esp+8h] [ebp-11Ch]
  int v53; // [esp+10h] [ebp-114h]
  int v54; // [esp+14h] [ebp-110h]
  int v55; // [esp+24h] [ebp-100h] BYREF
  _BYTE v56[4]; // [esp+28h] [ebp-FCh] BYREF
  int v57; // [esp+2Ch] [ebp-F8h]
  int v58; // [esp+30h] [ebp-F4h]
  int v59; // [esp+34h] [ebp-F0h]
  int v60; // [esp+38h] [ebp-ECh]
  int v61; // [esp+3Ch] [ebp-E8h]
  _DWORD *v62; // [esp+40h] [ebp-E4h]
  int v63; // [esp+44h] [ebp-E0h]
  char *v64; // [esp+48h] [ebp-DCh]
  int v65; // [esp+4Ch] [ebp-D8h]
  _UNKNOWN **v66; // [esp+50h] [ebp-D4h] BYREF
  int v67; // [esp+54h] [ebp-D0h]
  _DWORD v68[4]; // [esp+60h] [ebp-C4h] BYREF
  int v69; // [esp+70h] [ebp-B4h]
  int v70; // [esp+74h] [ebp-B0h]
  int v71; // [esp+78h] [ebp-ACh]
  int v72; // [esp+7Ch] [ebp-A8h]
  int v73; // [esp+80h] [ebp-A4h]
  _BYTE *v74; // [esp+84h] [ebp-A0h]
  int v75; // [esp+88h] [ebp-9Ch]
  float v76; // [esp+8Ch] [ebp-98h]
  float v77; // [esp+90h] [ebp-94h]
  int v78; // [esp+94h] [ebp-90h]
  float v79; // [esp+98h] [ebp-8Ch] BYREF
  float v80; // [esp+9Ch] [ebp-88h]
  float v81; // [esp+A0h] [ebp-84h]
  float v82[9]; // [esp+A4h] [ebp-80h] BYREF
  char v83[16]; // [esp+C8h] [ebp-5Ch] BYREF
  char v84[16]; // [esp+E8h] [ebp-3Ch] BYREF
  int v85; // [esp+120h] [ebp-4h]

  v7 = 0;
  v74 = this;
  if ( !a3 )
  {
    v55 = 2;
    sub_4050C0((int)"Passed actor seems to be not valid!");
    v5 = __readeflags();
    v6 = *(_DWORD *)__ROR4__(off_16C6CAC, *(char *)sub_4736F0);
    __writeeflags(v5);
    v85 = 3;
    v9 = sub_4050C0(v6);
    v10 = sub_4050C0((int)"::");
    sub_4050C0((int)"MeshChunkProcessor2");
    sub_5BE180(v9, (int)v84, v10);
    LOBYTE(v85) = 4;
    v53 = sub_5BE180(v9, (int)v83, v9);
    LOBYTE(v85) = 5;
    sub_5C6150((__int32)&v55, (int)&v66);
    sub_643D50(v52, &v55, v53);
    LOBYTE(v85) = 4;
    sub_5A8840();
    LOBYTE(v85) = 3;
    sub_5A8840();
    LOBYTE(v85) = 2;
    sub_5A8840();
    LOBYTE(v85) = 1;
    sub_5A8840();
    LOBYTE(v85) = 0;
    sub_5A8840();
    v85 = -1;
    sub_5A8840();
    return 0;
  }
  (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)a2 + 4))(a2, v68, 24);
  if ( this[12] )
  {
    sub_643E40("- Mesh");
    if ( this[12] )
    {
      sub_643E40("    + NodeNumber      = %d", v68[0]);
      if ( this[12] )
      {
        sub_643E40("    + NumOrgVerts     = %d", v68[1]);
        if ( this[12] )
        {
          sub_643E40("    + NumVerts        = %d", v68[2]);
          if ( this[12] )
          {
            sub_643E40("    + NumIndices      = %d", v68[3]);
            if ( this[12] )
            {
              sub_643E40("    + NumSubMeshes    = %d", v69);
              if ( this[12] )
                sub_643E40("    + IsCollisionMesh = %d", (unsigned __int8)v70);
            }
          }
        }
      }
    }
  }
  v62 = operator new(0x4Cu);
  v85 = 6;
  if ( v62 )
    v12 = sub_5C2FF0();
  else
    v12 = 0;
  v85 = -1;
  v66 = &off_7296C4;
  v67 = 0;
  sub_5BD210(&v66, v12);
  v13 = v67;
  v85 = 7;
  if ( (_BYTE)v70 )
  {
    v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v68[0]) + 320);
    if ( v67 )
      (**(void (__thiscall ***)(int))v67)(v67);
    v15 = *(_DWORD *)(v14 + 4);
    *(_DWORD *)(v14 + 4) = v13;
    if ( !v15 )
      goto LABEL_23;
  }
  else
  {
    v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v68[0]) + 296);
    if ( v67 )
      (**(void (__thiscall ***)(int))v67)(v67);
    v15 = *(_DWORD *)(v16 + 4);
    *(_DWORD *)(v16 + 4) = v13;
    if ( !v15 )
      goto LABEL_23;
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 4))(v15);
LABEL_23:
  v17 = operator new(8u);
  v62 = v17;
  LOBYTE(v85) = 8;
  if ( v17 )
  {
    if ( v13 )
    {
      v19 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
      v18 = sub_5D3490(v17, *(_DWORD *)(v19 + 40));
    }
    else
    {
      v18 = sub_5D3490(v17, MEMORY[0x28]);
    }
  }
  else
  {
    v18 = 0;
  }
  LOBYTE(v85) = 7;
  if ( v13 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
  sub_5C3CB0();
  if ( v13 )
    v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
  else
    v20 = 0;
  v75 = *(_DWORD *)(v20 + 16);
  if ( v13 )
    v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
  else
    v21 = 0;
  v60 = *(_DWORD *)(v21 + 20);
  if ( v13 )
    v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
  else
    v22 = 0;
  v59 = *(_DWORD *)(v22 + 16) + 12 * *(_DWORD *)(v22 + 40);
  if ( v13 )
    v23 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
  else
    v23 = 0;
  v78 = *(_DWORD *)(v23 + 20) + 12 * *(_DWORD *)(v23 + 40);
  if ( v13 )
    v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
  else
    v24 = 0;
  v81 = *(float *)(v24 + 28);
  if ( v13 )
    v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
  else
    v25 = 0;
  v26 = *(float *)(v18 + 4);
  v62 = *(_DWORD **)(v25 + 32);
  v77 = v26;
  v63 = 0;
  v61 = 0;
  v55 = 0;
  if ( v69 > 0 )
  {
    do
    {
      (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v56, 12);
      v27 = v74;
      if ( v74[12] )
      {
        sub_643E40("    - Reading SubMesh");
        if ( v27[12] )
        {
          sub_643E40("       + Material ID   = %d", v56[0]);
          if ( v27[12] )
          {
            sub_643E40("       + NumOfIndices  = %d", v57);
            if ( v27[12] )
            {
              sub_643E40("       + NumOfVertices = %d", v58);
              if ( v27[12] )
                sub_643E40("       + NumOfUVSets   = %d", v56[1]);
            }
          }
        }
      }
      v64 = (char *)operator new(0x1Cu);
      v28 = v67;
      LOBYTE(v85) = 9;
      if ( v64 )
      {
        if ( v67 )
          v29 = (*(int (__thiscall **)(int))(*(_DWORD *)v67 + 12))(v67);
        else
          v29 = 0;
        v30 = sub_5D3420(v29, v7, v63, v58, v57, v56[0]);
      }
      else
      {
        v30 = 0;
      }
      LOBYTE(v85) = 7;
      if ( v28 )
        v31 = (*(int (__thiscall **)(int))(*(_DWORD *)v28 + 12))(v28);
      else
        v31 = 0;
      v32 = *(_DWORD *)(v31 + 8);
      v33 = *(_DWORD *)(v31 + 4) + 1;
      *(_DWORD *)(v31 + 4) = v33;
      if ( v32 < v33 )
      {
        v34 = v33 + 1;
        sub_4F14D0(v54);
        *(_DWORD *)(v31 + 12) = sub_5A8CF0(*(void **)(v31 + 12), 4 * v34, 2, 16, 2);
        *(_DWORD *)(v31 + 8) = v34;
      }
      v35 = (_DWORD *)(*(_DWORD *)(v31 + 12) + 4 * (*(_DWORD *)(v31 + 4) - 1));
      if ( v35 )
        *v35 = v30;
      v65 = 0;
      if ( v58 > 0 )
      {
        v36 = 12 * v7 + v60 + 8;
        LODWORD(v80) = v59 - v75;
        v72 = v60 - v75;
        v71 = v78 - v75;
        v37 = 12 * v7 + v78;
        v38 = (float *)(12 * v7 + v75 + 4);
        LODWORD(v76) = v59 - v60;
        v64 = (char *)(v78 - v60);
        v73 = v59 - v78;
        do
        {
          (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, v82, 36);
          v39 = v82[1];
          v40 = v82[2];
          *(v38 - 1) = v82[0];
          *v38 = v39;
          v41 = v72;
          ++v7;
          v38[1] = v40;
          v42 = v82[4];
          v38 += 3;
          v43 = v82[5];
          *(float *)(v36 - 8) = v82[3];
          v44 = v73;
          *(float *)((char *)v38 + v41 - 12) = v42;
          v36 += 12;
          v37 += 12;
          *(float *)(v36 - 12) = v43;
          *(float *)(v44 + v37 - 12) = *(v38 - 4);
          *(float *)((char *)v38 + LODWORD(v80) - 12) = *(v38 - 3);
          *(float *)(LODWORD(v76) + v36 - 12) = *(v38 - 2);
          v45 = v71;
          *(_DWORD *)(v37 - 12) = *(_DWORD *)(v36 - 20);
          *(float *)((char *)v38 + v45 - 12) = *(float *)((char *)v38 + v41 - 12);
          *(_DWORD *)&v64[v36 - 12] = *(_DWORD *)(v36 - 12);
          v46 = v77;
          *(float *)(LODWORD(v81) + 4 * v7 - 4) = v82[8];
          v47 = v82[7];
          *(float *)(LODWORD(v46) + 8 * v7 - 8) = v82[6];
          *(float *)(LODWORD(v46) + 8 * v7 - 4) = v47;
          ++v65;
        }
        while ( v65 < v58 );
      }
      v48 = 0;
      if ( v57 > 0 )
      {
        v49 = v63;
        do
        {
          (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &v79, 4);
          v62[v49++] = v61 + LODWORD(v79);
          ++v48;
        }
        while ( v48 < v57 );
        v63 = v49;
      }
      v50 = v55 + 1 < v69;
      v61 += v58;
      ++v55;
    }
    while ( v50 );
  }
  v51 = v67;
  if ( a5 )
  {
    if ( v67 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v67 + 12))(v67);
    sub_5C3690();
  }
  v85 = -1;
  if ( v51 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v51 + 4))(v51);
  return 1;
}
