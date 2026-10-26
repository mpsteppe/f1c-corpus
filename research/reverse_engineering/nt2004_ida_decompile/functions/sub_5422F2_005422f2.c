int __thiscall sub_5422F2(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // eax
  int *v4; // eax
  int v5; // ebx
  void *v6; // eax
  void *v7; // eax
  int v8; // ebx
  char *v9; // eax
  char *v10; // eax
  char *v11; // ebx
  int *v12; // edi
  int v13; // eax
  int v14; // ecx
  char *v15; // eax
  int *v16; // eax
  double v17; // st7
  int v18; // ecx
  double v19; // st7
  double v20; // st6
  int v21; // edx
  float *v22; // ecx
  double v23; // st6
  double v24; // st7
  double v25; // st6
  double v26; // st5
  double v27; // st5
  float *v28; // edi
  int v29; // esi
  float v30; // [esp+4h] [ebp-D0h]
  float v31; // [esp+8h] [ebp-CCh]
  float v32; // [esp+Ch] [ebp-C8h]
  float v33; // [esp+10h] [ebp-C4h]
  float v34; // [esp+14h] [ebp-C0h]
  float v35; // [esp+18h] [ebp-BCh]
  float v36; // [esp+1Ch] [ebp-B8h]
  float v37; // [esp+24h] [ebp-B0h]
  float v38; // [esp+28h] [ebp-ACh]
  float v39; // [esp+2Ch] [ebp-A8h]
  float v40; // [esp+38h] [ebp-9Ch]
  float v41; // [esp+3Ch] [ebp-98h]
  float v42; // [esp+40h] [ebp-94h]
  float v43; // [esp+44h] [ebp-90h]
  float v44; // [esp+48h] [ebp-8Ch]
  float v45; // [esp+4Ch] [ebp-88h]
  float v46; // [esp+54h] [ebp-80h]
  float v47; // [esp+58h] [ebp-7Ch]
  float v48; // [esp+5Ch] [ebp-78h]
  float v49; // [esp+64h] [ebp-70h]
  float v50; // [esp+68h] [ebp-6Ch]
  float v51; // [esp+6Ch] [ebp-68h]
  float v52; // [esp+78h] [ebp-5Ch]
  float v53; // [esp+7Ch] [ebp-58h]
  float v54; // [esp+80h] [ebp-54h]
  float v55; // [esp+84h] [ebp-50h]
  float v56; // [esp+88h] [ebp-4Ch]
  float v57; // [esp+8Ch] [ebp-48h]
  float *v59; // [esp+98h] [ebp-3Ch]
  int *v60; // [esp+9Ch] [ebp-38h]
  unsigned int v61; // [esp+A0h] [ebp-34h]
  int *v62; // [esp+A4h] [ebp-30h]
  char *v63; // [esp+A8h] [ebp-2Ch]
  unsigned int v64; // [esp+ACh] [ebp-28h]
  int v65; // [esp+B0h] [ebp-24h]
  float *v66; // [esp+B4h] [ebp-20h]
  char *v67; // [esp+B8h] [ebp-1Ch]
  int v68; // [esp+BCh] [ebp-18h]
  void *v69; // [esp+C0h] [ebp-14h]
  BOOL v70; // [esp+C4h] [ebp-10h]
  int *v71; // [esp+C4h] [ebp-10h]

  v1 = this;
  v2 = this[2];
  if ( (_BYTE)v2 != 3 )
    return -2147467259;
  v70 = (v2 & 0x20000) == 0;
  v62 = sub_5421F2(*(_DWORD *)(this[1] + 4184), *(_DWORD *)(*this + 4184), (v2 & 0x10000) == 0);
  v4 = sub_5421F2(*(_DWORD *)(v1[1] + 4188), *(_DWORD *)(*v1 + 4188), v70);
  v71 = v4;
  if ( !v62 || !v4 )
    goto LABEL_27;
  v5 = *(_DWORD *)(v1[1] + 4184);
  v6 = operator new(16 * v5);
  v69 = v6;
  if ( v6 )
  {
    sub_53D688((int)v6, 16, v5, (int (__thiscall *)(int))sub_53D5B2);
    v7 = v69;
    v66 = (float *)v69;
  }
  else
  {
    v66 = 0;
    v7 = 0;
  }
  if ( v7
    && ((v8 = 2 * *(_DWORD *)(*v1 + 4184), v9 = (char *)operator new(32 * *(_DWORD *)(*v1 + 4184)), (v67 = v9) == 0)
      ? (v10 = 0)
      : (sub_53D688((int)v9, 16, v8, (int (__thiscall *)(int))sub_53D5B2), v10 = v67),
        v10) )
  {
    v64 = 0;
    v65 = -1;
    v68 = -1;
    v11 = &v10[16 * *(_DWORD *)(*v1 + 4184)];
    v63 = v10;
    if ( *(_DWORD *)(v1[1] + 4188) )
    {
      v12 = v71 + 2;
      v60 = v71 + 2;
      do
      {
        v13 = *(v12 - 2);
        v61 = 0;
        if ( v13 != v65 )
        {
          v14 = v68;
          if ( v13 == v68 )
          {
            v15 = v63;
            v68 = -1;
            v63 = v11;
            v65 = v14;
            v11 = v15;
          }
          else
          {
            v65 = *(v12 - 2);
            (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*v1 + 4))(*v1, v13, 0, v63);
          }
        }
        if ( *v12 != v68 )
        {
          v68 = *v12;
          (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*v1 + 4))(*v1, *v12, 0, v11);
        }
        if ( *(_DWORD *)(v1[1] + 4184) )
        {
          v16 = v62 + 2;
          v59 = v66;
          do
          {
            v17 = *((float *)v16 + 1);
            v18 = 16 * *v16;
            v55 = v17 * *(float *)&v11[v18];
            v56 = v17 * *(float *)&v11[v18 + 4];
            v57 = v17 * *(float *)&v11[v18 + 8];
            v19 = v17 * *(float *)&v11[v18 + 12];
            v20 = *((float *)v16 - 1);
            v21 = 16 * *(v16 - 2);
            v40 = v20 * *(float *)&v11[v21 + 4];
            v41 = v20 * *(float *)&v11[v21 + 8];
            v22 = (float *)&v63[v18];
            v42 = v20 * *(float *)&v11[v21 + 12];
            v46 = v20 * *(float *)&v11[v21] + v55;
            v47 = v40 + v56;
            v48 = v41 + v57;
            v23 = *((float *)v12 + 1);
            v37 = v46 * v23;
            v38 = v47 * v23;
            v39 = v48 * v23;
            v24 = (v42 + v19) * v23;
            v25 = *((float *)v16 + 1);
            v34 = v25 * *v22;
            v35 = v25 * v22[1];
            v36 = v25 * v22[2];
            v26 = *((float *)v16 - 1);
            v16 += 4;
            ++v61;
            v52 = v26 * *(float *)&v63[v21 + 4];
            v53 = v26 * *(float *)&v63[v21 + 8];
            v54 = v26 * *(float *)&v63[v21 + 12];
            v49 = v26 * *(float *)&v63[v21] + v34;
            v50 = v52 + v35;
            v51 = v53 + v36;
            v27 = *((float *)v12 - 1);
            v28 = v59;
            v59 += 4;
            v43 = v49 * v27;
            v44 = v50 * v27;
            v45 = v51 * v27;
            v30 = v43 + v37;
            v31 = v44 + v38;
            v32 = v45 + v39;
            v33 = (v54 + v25 * v22[3]) * v27 + v24;
            *v28++ = v30;
            *v28++ = v31;
            *v28 = v32;
            v28[1] = v33;
            v12 = v60;
          }
          while ( v61 < *(_DWORD *)(this[1] + 4184) );
          v1 = this;
        }
        (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, float *))(*(_DWORD *)v1[1] + 8))(v1[1], v64, 0, v66);
        v12 += 4;
        ++v64;
        v60 = v12;
      }
      while ( v64 < *(_DWORD *)(v1[1] + 4188) );
    }
    v29 = 0;
  }
  else
  {
LABEL_27:
    v29 = -2147024882;
  }
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  return v29;
}
