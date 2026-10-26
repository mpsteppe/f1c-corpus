int __thiscall sub_668FA5(int this, _DWORD *a2, unsigned int a3, _DWORD *a4, int a5, char *a6)
{
  char *v7; // esi
  size_t v8; // esi
  bool v9; // zf
  int v10; // esi
  unsigned int v11; // edi
  int v12; // esi
  int v13; // eax
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // eax
  _DWORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // eax
  int *v22; // esi
  char *v23; // edi
  double v24; // st7
  double *v25; // ecx
  BOOL v26; // eax
  _DWORD *v27; // esi
  double *v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  double v33; // st7
  void *v34; // eax
  void *v35; // eax
  _DWORD *v36; // edx
  double *v37; // ecx
  int v38; // esi
  int v39; // eax
  void *v40; // edi
  void *v41; // esi
  size_t v42; // kr00_4
  _DWORD *v44; // [esp-10h] [ebp-98h]
  int v45; // [esp-Ch] [ebp-94h]
  int v46; // [esp-Ch] [ebp-94h]
  __int64 v47; // [esp-8h] [ebp-90h]
  __int64 v48; // [esp-8h] [ebp-90h]
  unsigned int v49; // [esp-8h] [ebp-90h]
  int v50; // [esp-8h] [ebp-90h]
  void *v51; // [esp-4h] [ebp-8Ch]
  void *v52; // [esp-4h] [ebp-8Ch]
  double v53; // [esp+Ch] [ebp-7Ch] BYREF
  double v54; // [esp+14h] [ebp-74h]
  double v55; // [esp+1Ch] [ebp-6Ch] BYREF
  double v56; // [esp+24h] [ebp-64h]
  int v57; // [esp+2Ch] [ebp-5Ch]
  unsigned int v58; // [esp+30h] [ebp-58h]
  unsigned int v59; // [esp+34h] [ebp-54h]
  size_t v60; // [esp+38h] [ebp-50h]
  void *v61; // [esp+3Ch] [ebp-4Ch]
  int v62; // [esp+40h] [ebp-48h] BYREF
  unsigned int v63; // [esp+44h] [ebp-44h] BYREF
  char *v64; // [esp+48h] [ebp-40h]
  int v65; // [esp+4Ch] [ebp-3Ch] BYREF
  int v66; // [esp+50h] [ebp-38h]
  int v67; // [esp+54h] [ebp-34h]
  int v68; // [esp+58h] [ebp-30h]
  int v69; // [esp+5Ch] [ebp-2Ch] BYREF
  double *v70; // [esp+60h] [ebp-28h]
  void *v71; // [esp+64h] [ebp-24h]
  void *v72; // [esp+68h] [ebp-20h]
  void *v73; // [esp+6Ch] [ebp-1Ch]
  unsigned int v74; // [esp+70h] [ebp-18h]
  char *v75; // [esp+74h] [ebp-14h]
  void *v76; // [esp+78h] [ebp-10h]
  size_t Size; // [esp+7Ch] [ebp-Ch]
  void *v78; // [esp+80h] [ebp-8h]
  void *Block; // [esp+84h] [ebp-4h]

  v57 = *(_DWORD *)(this + 88);
  v66 = *(_DWORD *)(this + 92);
  v61 = *(void **)(this + 24);
  v7 = *(char **)(*(_DWORD *)(this + 4) + 24);
  v73 = 0;
  v76 = 0;
  v72 = 0;
  v78 = 0;
  v71 = 0;
  v75 = v7;
  Size = 4 * (_DWORD)v7;
  Block = operator new(4 * (_DWORD)v7);
  if ( !Block
    || (v73 = operator new(Size)) == 0
    || (v8 = 16 * (_DWORD)v7, v60 = v8, (v76 = operator new(v8)) == 0)
    || (v72 = operator new(v8)) == 0
    || (v78 = operator new(Size)) == 0
    || (v71 = operator new(Size)) == 0 )
  {
    v10 = -2147024882;
    goto LABEL_94;
  }
  v9 = a3 == 0;
  *(_DWORD *)(this + 92) = 0;
  if ( v9 )
    goto LABEL_13;
  v10 = sub_67051D(a3, 0);
  if ( v10 >= 0 )
  {
    v10 = 0;
    if ( *(_DWORD *)(this + 92) )
      v66 = 1;
    if ( !*(_DWORD *)(this + 80) && !*(_DWORD *)(this + 84) )
    {
LABEL_13:
      qmemcpy(Block, *(const void **)(this + 24), Size);
      qmemcpy(a6, *(const void **)(this + 24), Size);
      v11 = 0;
      if ( v75 )
      {
        a3 = (unsigned int)v76;
        do
        {
          v12 = 4 * v11;
          v13 = *(_DWORD *)(4 * v11 + *(_DWORD *)(this + 24));
          if ( v13 == -1 || sub_662830(this, v13, (double *)a3) < 0 )
          {
            v14 = a3;
            *(double *)a3 = *(double *)(this + 160);
            *(double *)(v14 + 8) = *(double *)(this + 168);
          }
          v15 = *(_DWORD *)(v12 + *(_DWORD *)(this + 24));
          if ( v15 == -1
            || (v16 = *(_DWORD *)(this + 8),
                v17 = *(_DWORD **)(*(_DWORD *)(v16 + 20) + 4 * v15),
                *(_DWORD *)(v16 + 116) == v17[1]) )
          {
            *(_DWORD *)((char *)v78 + v12) = 31;
          }
          else
          {
            *(_DWORD *)((char *)v78 + v12) = *v17 & 0x1F;
          }
          a3 += 16;
          ++v11;
        }
        while ( v11 < (unsigned int)v75 );
      }
      v18 = *(_DWORD *)(this + 32);
      v67 = 0;
      v62 = -1;
      v63 = -1;
      v74 = 0;
      v65 = v18;
      v69 = v18;
      v68 = 1;
      while ( 1 )
      {
        v19 = *(_DWORD *)(this + 8);
        v20 = *(_DWORD *)(v19 + 8);
        v21 = *(_DWORD *)(v19 + 12);
        v58 = v20;
        v59 = v21;
        qmemcpy(v73, Block, Size);
        qmemcpy(v72, v76, v60);
        a3 = -1;
        qmemcpy(v71, v78, Size);
        if ( a4 )
        {
          a3 = -1;
          *(_DWORD *)(this + 24) = Block;
          v45 = (int)a4;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
          v10 = sub_6714D6(v45, (int)&a3, 0);
          if ( v10 < 0 )
            goto LABEL_94;
          HIDWORD(v47) = 23;
          LODWORD(v47) = &a3;
          v10 = sub_6641F3((_DWORD *)this, (unsigned int)a4, 542113793, (int)&v65, &v65, v47);
          if ( v10 < 0 )
            goto LABEL_94;
          a3 = -1;
          *(_DWORD *)(this + 24) = a6;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
          v10 = sub_6714D6((int)a4, (int)&a3, 0);
          if ( v10 < 0 )
            goto LABEL_94;
          HIDWORD(v48) = 23;
          LODWORD(v48) = &a3;
          v10 = sub_6641F3((_DWORD *)this, (unsigned int)a4, 542113793, (int)&v69, &v69, v48);
          if ( v10 < 0 )
            goto LABEL_94;
          if ( !*(_DWORD *)(this + 88) && (*(_DWORD *)(this + 80) || *(_DWORD *)(this + 84)) )
            goto LABEL_79;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
        }
        if ( sub_662830(this, v69, &v55) < 0 )
        {
          v55 = *(double *)(this + 168);
          v56 = *(double *)(this + 160);
        }
        if ( v55 > 0.0 || v56 < 0.0 )
          v67 = 1;
        if ( v75 )
        {
          v22 = (int *)a6;
          v70 = (double *)v76;
          v23 = (char *)((_BYTE *)v78 - a6);
          v64 = v75;
          do
          {
            if ( *v22 == -1 )
            {
              v25 = v70;
            }
            else
            {
              if ( sub_662830(this, *v22, &v53) >= 0 )
              {
                v24 = v54;
              }
              else
              {
                v53 = *(double *)(this + 160);
                v24 = *(double *)(this + 168);
                v54 = v24;
              }
              v25 = v70;
              if ( v67 )
              {
                *v70 = v53;
                v25[1] = v24;
                *(int *)((char *)v22 + (_DWORD)v23) = **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *v22)
                                                    & 0x1F;
              }
              else
              {
                if ( *v70 > v53 )
                  *v70 = v53;
                if ( v24 > v25[1] )
                  v25[1] = v24;
                *(int *)((char *)v22 + (_DWORD)v23) &= **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *v22);
              }
            }
            ++v22;
            v9 = v64-- == (char *)1;
            v70 = v25 + 2;
          }
          while ( !v9 );
        }
        if ( 0.0 == v55 && 0.0 == v56 )
          goto LABEL_79;
        if ( v55 <= 0.0 && v56 >= 0.0 )
          *(_DWORD *)(this + 88) = 1;
        if ( v68 )
        {
          if ( v67 || (v26 = sub_667073((_DWORD *)this, a3, v74, &v62, &v63), v68 = 1, !v26) )
            v68 = 0;
        }
        if ( v75 )
        {
          v27 = a6;
          v28 = (double *)((_BYTE *)Block - a6);
          v70 = (double *)((_BYTE *)Block - a6);
          v64 = v75;
          do
          {
            v29 = *(_DWORD *)((char *)v27 + (_DWORD)v28);
            if ( v29 != *v27 )
            {
              v30 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
              v31 = *(_DWORD *)(v30 + 4 * v29);
              v32 = *(_DWORD *)(v30 + 4 * *v27);
              *(_WORD *)v31 &= 0xFE60u;
              *(_DWORD *)v31 |= *(_DWORD *)v32 & 0x19F;
              *(double *)(v31 + 32) = *(double *)(v32 + 32);
              v33 = *(double *)(v32 + 40);
              v28 = v70;
              *(double *)(v31 + 40) = v33;
            }
            ++v27;
            --v64;
          }
          while ( v64 );
        }
        if ( a5 )
        {
          v49 = a5;
          v46 = v69;
          *(_DWORD *)(this + 24) = Block;
          v44 = a4;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
          v10 = sub_667428(this, v44, v46, v49, 0);
          if ( v10 < 0 )
            goto LABEL_94;
          v50 = a5;
          *(_DWORD *)(this + 24) = a6;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
          v10 = sub_67051D(v50, 0);
          if ( v10 < 0 )
            goto LABEL_94;
          if ( !*(_DWORD *)(this + 88) && (*(_DWORD *)(this + 80) || *(_DWORD *)(this + 84)) )
            goto LABEL_79;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
        }
        if ( *(_DWORD *)(this + 92) )
          break;
        if ( ++v74 >= 0x400 )
          goto LABEL_79;
      }
      v51 = v73;
      v73 = Block;
      v34 = v76;
      v76 = v72;
      v72 = v34;
      v35 = v78;
      Block = v51;
      v78 = v71;
      v71 = v35;
      sub_664155(this, v58, v59, v51);
      v9 = v74 == 0;
      *(_DWORD *)(this + 76) = 0;
      *(_DWORD *)(this + 80) = 0;
      *(_DWORD *)(this + 84) = 0;
      if ( v9 )
        v66 = 1;
LABEL_79:
      if ( v74 == 1024 )
      {
        sub_663C07(
          (_DWORD *)this,
          a2,
          3511,
          "loop does not appear to terminate in a timely manner (%d iterations)",
          1024);
      }
      else
      {
        if ( v75 )
        {
          v36 = Block;
          v37 = (double *)v76;
          v38 = (_BYTE *)v78 - (_BYTE *)Block;
          a6 = v75;
          do
          {
            if ( *v36 != -1 )
            {
              v39 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *v36);
              *(double *)(v39 + 32) = *v37;
              *(double *)(v39 + 40) = v37[1];
              *(_DWORD *)v39 = *(_DWORD *)((char *)v36 + v38) | 0x180;
            }
            v37 += 2;
            ++v36;
            --a6;
          }
          while ( a6 );
        }
        v40 = v61;
        v41 = Block;
        v42 = Size;
        *(_DWORD *)(this + 24) = v61;
        qmemcpy(v40, v41, v42);
        if ( !v74
          || !v68
          || *(_DWORD *)(this + 80)
          || *(_DWORD *)(this + 84)
          || sub_6641F3((_DWORD *)this, (unsigned int)a4, 268435457, *(_DWORD *)(this + 24) + 4 * v62, &v63, 0) >= 0 )
        {
          v10 = 0;
          goto LABEL_94;
        }
      }
      v10 = -2147467259;
    }
  }
LABEL_94:
  v52 = Block;
  *(_DWORD *)(this + 24) = v61;
  j__free(v52);
  j__free(v73);
  j__free(v76);
  j__free(v72);
  j__free(v78);
  j__free(v71);
  *(_DWORD *)(this + 88) = v57;
  *(_DWORD *)(this + 92) = v66;
  return v10;
}
