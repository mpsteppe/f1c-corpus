size_t __thiscall sub_6C9E19(_DWORD *this)
{
  int v2; // esi
  void *v3; // edi
  char *v4; // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  char *v12; // eax
  unsigned int v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  size_t v18; // edx
  _DWORD *v19; // esi
  _DWORD *v20; // eax
  _DWORD *v21; // edi
  char *v22; // ecx
  char *v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // eax
  int v30; // eax
  size_t v31; // ecx
  _WORD *v32; // edx
  _DWORD *v33; // edi
  unsigned int j; // eax
  _DWORD *v35; // ecx
  int v36; // eax
  int v37; // ecx
  unsigned int v38; // eax
  char *v39; // eax
  char *v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // edi
  unsigned int v43; // ecx
  _DWORD *v44; // eax
  int v45; // eax
  _DWORD v47[10]; // [esp+Ch] [ebp-6Ch] BYREF
  int v48[4]; // [esp+34h] [ebp-44h] BYREF
  size_t v49; // [esp+44h] [ebp-34h]
  size_t Size; // [esp+48h] [ebp-30h]
  int v51; // [esp+4Ch] [ebp-2Ch] BYREF
  unsigned int i; // [esp+50h] [ebp-28h]
  int v53; // [esp+54h] [ebp-24h]
  void *v54; // [esp+58h] [ebp-20h]
  void *Block; // [esp+5Ch] [ebp-1Ch]
  void *v56; // [esp+60h] [ebp-18h]
  void *v57; // [esp+64h] [ebp-14h]
  void *v58; // [esp+68h] [ebp-10h]
  size_t v59; // [esp+6Ch] [ebp-Ch]
  unsigned int v60; // [esp+70h] [ebp-8h]
  unsigned int v61; // [esp+74h] [ebp-4h]

  sub_6801F7(v48, 1196769860);
  v2 = 0;
  memset(v47, 0, sizeof(v47));
  v47[0] = 40;
  Block = 0;
  v57 = 0;
  v54 = 0;
  v56 = 0;
  v58 = 0;
  v61 = 0;
  v59 = sub_68024C(v48, (char *)v47, 0x28u, 1, 0);
  if ( (v59 & 0x80000000) != 0 )
    goto LABEL_82;
  v47[5] = this[74];
  if ( !v47[5] )
    goto LABEL_66;
  v3 = operator new(4 * v47[5]);
  Block = v3;
  if ( !v3
    || (memset(v3, 0, 4 * v47[5]), (v57 = operator new(8 * v47[5])) == 0)
    || (Size = 8 * v47[5], memset(v57, 0, 8 * v47[5]), (v58 = operator new(16 * v47[5])) == 0) )
  {
LABEL_79:
    v59 = -2147024882;
    goto LABEL_82;
  }
  memset(v58, 0, 16 * v47[5]);
  v60 = 0;
  if ( v47[5] )
  {
    v4 = (char *)v57 + 2;
    do
    {
      *(_WORD *)v4 = -1;
      *((_WORD *)v4 - 1) = 0;
      v5 = v2 + 8;
      *(_DWORD *)(v4 + 2) = *(_DWORD *)(this[73] + v2 + 4);
      i = v2 + 8;
      v53 = 4;
      do
      {
        v6 = *(_DWORD *)(v5 + this[73]);
        if ( v6 != -1 )
        {
          v7 = *(_DWORD *)(this[5] + 4 * v6);
          v8 = *(_DWORD *)(v7 + 96) == 0;
          *(_DWORD *)(v7 + 116) = v60;
          if ( !v8 )
          {
            v9 = *(_DWORD *)(v5 + this[73]);
            v10 = v61++;
            *((_DWORD *)v58 + v10) = v9;
            v5 = i;
          }
        }
        v5 += 4;
        v8 = v53-- == 1;
        i = v5;
      }
      while ( !v8 );
      v11 = *(_DWORD *)(v2 + this[73]);
      if ( v11 )
      {
        *((_WORD *)v4 - 1) = *(_WORD *)(v11 + 20);
        v12 = *(char **)(*(_DWORD *)(this[73] + v2) + 16);
        if ( v12 )
        {
          if ( sub_68024C(v48, v12, 0xFFFFFFFF, 7, &v51) < 0 )
            goto LABEL_82;
          v13 = 0;
          for ( i = 0; v13 < v47[3]; i = ++v13 )
          {
            if ( *((_DWORD *)Block + v13) == v51 )
              break;
          }
          if ( v13 == v47[3] )
          {
            *((_DWORD *)Block + v47[3]++) = v51;
            LOWORD(v13) = i;
          }
          *(_WORD *)v4 = v13;
        }
      }
      ++v60;
      v2 += 24;
      v4 += 8;
    }
    while ( v60 < v47[5] );
  }
  if ( !v47[3] || (v59 = sub_68024C(v48, (char *)Block, 4 * v47[3], 1, &v47[4]), (v59 & 0x80000000) == 0) )
  {
    v59 = sub_68024C(v48, (char *)v57, Size, 1, &v47[6]);
    if ( (v59 & 0x80000000) == 0 )
    {
      if ( !v61 )
        goto LABEL_66;
      v14 = v58;
      sub_682274(sub_6BB080, (int *)v58, v61, (int)this);
      v15 = 1;
      v47[7] = 1;
      v16 = 1;
      if ( v61 > 1 )
      {
        v17 = this[5];
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(v17 + 4 * v14[v16 - 1]) + 96) != *(_DWORD *)(*(_DWORD *)(v17 + 4 * v14[v16]) + 96) )
            ++v47[7];
          ++v16;
        }
        while ( v16 < v61 );
        v15 = v47[7];
      }
      v54 = operator new(20 * v15);
      if ( v54 )
      {
        v18 = 20 * v47[7];
        memset(v54, 0, 20 * v47[7]);
        v49 = v18;
        v60 = 0;
        i = 0;
        if ( v47[7] )
        {
          v19 = (char *)v54 + 12;
          while ( 1 )
          {
            v20 = (char *)v58 + 4 * v60;
            v21 = *(_DWORD **)(*(_DWORD *)(this[5] + 4 * *v20) + 96);
            v22 = (char *)v21[8];
            v53 = (int)v20;
            v51 = (int)v21;
            if ( v22 )
            {
              v59 = sub_68024C(v48, v22, 0xFFFFFFFF, 7, v19 - 3);
              if ( (v59 & 0x80000000) != 0 )
                goto LABEL_82;
              v20 = (_DWORD *)v53;
            }
            v23 = *(char **)(v21[5] + 24);
            if ( v23 )
            {
              v59 = sub_68024C(v48, v23, 0xFFFFFFFF, 7, v19 - 2);
              if ( (v59 & 0x80000000) != 0 )
                goto LABEL_82;
              v20 = (_DWORD *)v53;
            }
            v24 = v21[4];
            if ( v24 == 1 || v24 == 2 )
            {
              v59 = sub_6C5628(
                      v48,
                      *(_DWORD *)(v21[6] + 32),
                      (void *)1,
                      (unsigned int)&unk_E00000 & *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v20) + 60),
                      v19 - 1);
              if ( (v59 & 0x80000000) != 0 )
                goto LABEL_82;
            }
            v53 = v60;
            if ( v60 < v61 )
            {
              do
              {
                v25 = this[5];
                v26 = *(_DWORD *)(v25 + 4 * *((_DWORD *)v58 + v60));
                if ( v21 != *(_DWORD **)(v26 + 96) )
                  break;
                Size = *(_DWORD *)(v26 + 116);
                while ( v60 < v61 )
                {
                  v27 = *(_DWORD *)(v25 + 4 * *((_DWORD *)v58 + v60));
                  if ( v21 != *(_DWORD **)(v27 + 96) || Size != *(_DWORD *)(v27 + 116) )
                    break;
                  ++v60;
                }
                v28 = v61;
                ++*v19;
              }
              while ( v60 < v28 );
            }
            v56 = operator new(12 * *v19);
            if ( !v56 )
              goto LABEL_79;
            v59 = 12 * *v19;
            memset(v56, 0, v59);
            v29 = v53;
            *v19 = 0;
            v60 = v29;
            if ( v29 < v61 )
            {
              do
              {
                v30 = *(_DWORD *)(this[5] + 4 * *((_DWORD *)v58 + v60));
                if ( v51 != *(_DWORD *)(v30 + 96) )
                  break;
                v31 = *(_DWORD *)(v30 + 116);
                v32 = v56;
                *((_DWORD *)v56 + 3 * *v19) = v31;
                Size = v31;
                v33 = &v32[6 * *v19 + 2];
                *v33 = -1;
                v33[1] = -1;
                for ( j = v60; j < v61; j = ++v60 )
                {
                  v35 = (char *)v58 + 4 * j;
                  v36 = this[5];
                  v53 = (int)v35;
                  v37 = *(_DWORD *)(v36 + 4 * *v35);
                  if ( v51 != *(_DWORD *)(v37 + 96) || Size != *(_DWORD *)(v37 + 116) )
                    break;
                  v32[6 * *v19 + 2 + *(_DWORD *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)v53) + 16)] = *(_WORD *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)v53) + 100);
                }
                v38 = v61;
                ++*v19;
              }
              while ( v60 < v38 );
            }
            v59 = sub_68024C(v48, (char *)v56, v59, 11, v19 + 1);
            if ( (v59 & 0x80000000) != 0 )
              goto LABEL_82;
            v56 = 0;
            ++i;
            v19 += 5;
            if ( i >= v47[7] )
            {
              v18 = v49;
              break;
            }
          }
        }
        v59 = sub_68024C(v48, (char *)v54, v18, 1, &v47[8]);
        if ( (v59 & 0x80000000) != 0 )
          goto LABEL_82;
LABEL_66:
        v39 = (char *)this[52];
        if ( v39 )
        {
          v59 = sub_68024C(v48, v39, 0xFFFFFFFF, 7, &v47[9]);
          if ( (v59 & 0x80000000) != 0 )
            goto LABEL_82;
        }
        v40 = (char *)this[76];
        if ( v40 )
        {
          if ( sub_68024C(v48, v40, this[77], 5, &v47[2]) < 0 || sub_68024C(v48, (char *)WindowName, 1u, 5, 0) < 0 )
            goto LABEL_82;
        }
        if ( sub_68024C(v48, "Microsoft (R) D3DX9 Shader Compiler 5.04.00.2904", 0xFFFFFFFF, 5, &v47[1]) < 0 )
          goto LABEL_82;
        v41 = sub_680385(v48);
        v42 = v41;
        if ( v41 > 0x8000 )
        {
          sub_686816(
            (int)this,
            0,
            (const char *)0x11C3,
            "debug info exceeds maximum comment size; no debug info emitted");
        }
        else
        {
          v59 = sub_6C5921((int)this, v41);
          if ( (v59 & 0x80000000) != 0 )
            goto LABEL_82;
          memcpy((void *)(this[67] + 4 * v42 + 4), (const void *)(this[67] + 4), 4 * this[68] - 4);
          v43 = 0;
          if ( v47[5] )
          {
            v44 = (char *)v57 + 4;
            do
            {
              *v44 += 4 * (v42 + this[72]);
              ++v43;
              v44 += 2;
            }
            while ( v43 < v47[5] );
          }
          v59 = sub_680391(v48, (int *)(this[67] + 4), v42);
          if ( (v59 & 0x80000000) != 0 )
            goto LABEL_82;
          this[68] += v42;
          v45 = this[68];
          this[72] += v42;
          this[71] = v45;
        }
        v59 = 0;
        goto LABEL_82;
      }
      goto LABEL_79;
    }
  }
LABEL_82:
  j__free(Block);
  j__free(v57);
  j__free(v54);
  j__free(v56);
  j__free(v58);
  sub_680214(v48);
  return v59;
}
