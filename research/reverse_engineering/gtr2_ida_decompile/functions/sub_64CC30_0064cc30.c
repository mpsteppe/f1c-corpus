int __thiscall sub_64CC30(_DWORD *this)
{
  unsigned int v2; // eax
  int v4; // esi
  float *v5; // eax
  int v6; // edi
  float *v7; // eax
  int v8; // edi
  char *v9; // eax
  char *v10; // edi
  int *v11; // esi
  int v12; // eax
  int v13; // ecx
  char *v14; // eax
  float *v15; // eax
  double v16; // st7
  int v17; // ecx
  double v18; // st7
  double v19; // st6
  int v20; // esi
  float *v21; // edx
  double v22; // st5
  float *v23; // ecx
  float *v24; // esi
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st5
  float *v29; // edi
  double v30; // st5
  int v31; // esi
  float v32; // [esp+4h] [ebp-C0h]
  float v33; // [esp+8h] [ebp-BCh]
  float v34; // [esp+Ch] [ebp-B8h]
  float v35; // [esp+10h] [ebp-B4h]
  float v36; // [esp+14h] [ebp-B0h]
  float v37; // [esp+18h] [ebp-ACh]
  float v38; // [esp+1Ch] [ebp-A8h]
  float v39; // [esp+24h] [ebp-A0h]
  float v40; // [esp+28h] [ebp-9Ch]
  float v41; // [esp+2Ch] [ebp-98h]
  float v42; // [esp+38h] [ebp-8Ch]
  float v43; // [esp+3Ch] [ebp-88h]
  float v44; // [esp+40h] [ebp-84h]
  float v45; // [esp+44h] [ebp-80h]
  float v46; // [esp+48h] [ebp-7Ch]
  float v47; // [esp+4Ch] [ebp-78h]
  float v48; // [esp+54h] [ebp-70h]
  float v49; // [esp+58h] [ebp-6Ch]
  float v50; // [esp+5Ch] [ebp-68h]
  float v51; // [esp+64h] [ebp-60h]
  float v52; // [esp+68h] [ebp-5Ch]
  float v53; // [esp+6Ch] [ebp-58h]
  float v54; // [esp+78h] [ebp-4Ch]
  float v55; // [esp+7Ch] [ebp-48h]
  float v56; // [esp+80h] [ebp-44h]
  float v57; // [esp+84h] [ebp-40h]
  float v58; // [esp+88h] [ebp-3Ch]
  float v59; // [esp+8Ch] [ebp-38h]
  unsigned int v60; // [esp+94h] [ebp-30h]
  int v61; // [esp+98h] [ebp-2Ch]
  float *v62; // [esp+9Ch] [ebp-28h]
  float *Block; // [esp+A0h] [ebp-24h]
  char *v64; // [esp+A4h] [ebp-20h]
  unsigned int v65; // [esp+A8h] [ebp-1Ch]
  int v66; // [esp+ACh] [ebp-18h]
  BOOL v67; // [esp+B0h] [ebp-14h]
  float *v68; // [esp+B0h] [ebp-14h]
  char *v69; // [esp+B4h] [ebp-10h]
  char *v70; // [esp+B8h] [ebp-Ch]
  float *v71; // [esp+BCh] [ebp-8h]
  float *v72; // [esp+C0h] [ebp-4h]
  char *v73; // [esp+C0h] [ebp-4h]
  int *v74; // [esp+C0h] [ebp-4h]

  v71 = 0;
  v69 = 0;
  v2 = this[2];
  if ( (_BYTE)v2 != 3 )
    return -2147467259;
  v4 = this[1];
  if ( *(_DWORD *)(v4 + 112) != 1 || *(_DWORD *)(*this + 112) != 1 )
    return -2147467259;
  v67 = ((v2 >> 17) & 1) == 0;
  Block = sub_64CB44(*(_DWORD *)(v4 + 104), *(_DWORD *)(*this + 104), (v2 & 0x10000) == 0);
  v5 = sub_64CB44(*(_DWORD *)(this[1] + 108), *(_DWORD *)(*this + 108), v67);
  v68 = v5;
  if ( !Block || !v5 )
    goto LABEL_29;
  v6 = *(_DWORD *)(this[1] + 104);
  v7 = (float *)operator new(16 * v6);
  v72 = v7;
  if ( v7 )
  {
    sub_41D1B0((int)v7, 16, v6, (int)sub_681563);
    v71 = v72;
  }
  else
  {
    v71 = 0;
  }
  if ( v71
    && ((v8 = 2 * *(_DWORD *)(*this + 104), v9 = (char *)operator new(32 * *(_DWORD *)(*this + 104)), (v73 = v9) == 0)
      ? (v69 = 0)
      : (sub_41D1B0((int)v9, 16, v8, (int)sub_681563), v69 = v73),
        v69) )
  {
    v65 = 0;
    v61 = -1;
    v66 = -1;
    v10 = &v69[16 * *(_DWORD *)(*this + 104)];
    v64 = v69;
    v70 = v10;
    if ( *(_DWORD *)(this[1] + 108) )
    {
      v11 = (int *)(v68 + 2);
      v74 = (int *)(v68 + 2);
      do
      {
        v12 = *(v11 - 2);
        v60 = 0;
        if ( v12 != v61 )
        {
          v13 = v66;
          if ( v12 == v66 )
          {
            v14 = v64;
            v66 = -1;
            v64 = v10;
            v61 = v13;
            v70 = v14;
            v10 = v14;
          }
          else
          {
            v61 = *(v11 - 2);
            (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*this + 4))(*this, v12, 0, v64);
          }
        }
        if ( *v11 != v66 )
        {
          v66 = *v11;
          (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*this + 4))(*this, *v11, 0, v10);
        }
        if ( *(_DWORD *)(this[1] + 104) )
        {
          v15 = Block + 2;
          v62 = v71;
          do
          {
            v16 = v15[1];
            v17 = 16 * *(_DWORD *)v15;
            v48 = v16 * *(float *)&v10[v17];
            v49 = v16 * *(float *)&v10[v17 + 4];
            v50 = v16 * *(float *)&v10[v17 + 8];
            v18 = v16 * *(float *)&v10[v17 + 12];
            v19 = *(v15 - 1);
            v20 = 16 * *((_DWORD *)v15 - 2);
            v21 = (float *)&v10[v20];
            v22 = v19 * *(float *)&v10[v20];
            v23 = (float *)&v64[v17];
            v24 = (float *)&v64[v20];
            v42 = v19 * v21[1];
            v43 = v19 * v21[2];
            v44 = v19 * v21[3];
            v57 = v22 + v48;
            v58 = v42 + v49;
            v59 = v43 + v50;
            v25 = *((float *)v74 + 1);
            v39 = v57 * v25;
            v40 = v58 * v25;
            v41 = v59 * v25;
            v26 = (v18 + v44) * v25;
            v27 = v15[1];
            v36 = v27 * *v23;
            v37 = v27 * v23[1];
            v38 = v27 * v23[2];
            v28 = *(v15 - 1);
            v54 = v28 * v24[1];
            v55 = v28 * v24[2];
            v56 = v28 * v24[3];
            v51 = v28 * *v24 + v36;
            v29 = v62;
            v62 += 4;
            v15 += 4;
            ++v60;
            v52 = v54 + v37;
            v53 = v55 + v38;
            v30 = *((float *)v74 - 1);
            v45 = v51 * v30;
            v46 = v52 * v30;
            v47 = v53 * v30;
            v32 = v45 + v39;
            v33 = v46 + v40;
            v34 = v47 + v41;
            v35 = (v27 * v23[3] + v56) * v30 + v26;
            *v29++ = v32;
            *v29++ = v33;
            *v29 = v34;
            v29[1] = v35;
            v10 = v70;
          }
          while ( v60 < *(_DWORD *)(this[1] + 104) );
          v11 = v74;
        }
        (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, float *))(*(_DWORD *)this[1] + 8))(this[1], v65, 0, v71);
        v11 += 4;
        ++v65;
        v74 = v11;
      }
      while ( v65 < *(_DWORD *)(this[1] + 108) );
    }
    v31 = 0;
  }
  else
  {
LABEL_29:
    v31 = -2147024882;
  }
  j__free(Block);
  j__free(v68);
  j__free(v71);
  j__free(v69);
  return v31;
}
