int __thiscall sub_6A9CD5(_DWORD *this, int a2, unsigned int a3, int a4)
{
  int *v5; // edi
  int v6; // ebx
  int v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  int v12; // ebx
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // ecx
  _DWORD *v16; // eax
  int v17; // edi
  unsigned int v18; // ebx
  int v19; // edi
  _DWORD *v20; // eax
  int v21; // eax
  int v22; // ecx
  _DWORD *v23; // eax
  unsigned int i; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // edx
  int v28; // edi
  unsigned int j; // eax
  int v30; // eax
  int v31; // ebx
  unsigned int v32; // eax
  int v33; // ebx
  int v34; // ecx
  int v35; // eax
  int v36; // edi
  int v37; // edx
  int v38; // eax
  char *v39; // eax
  int v40; // edx
  int v41; // eax
  bool v42; // cf
  char *v43; // eax
  int v45; // [esp-Ch] [ebp-6Ch]
  unsigned int v46; // [esp-8h] [ebp-68h]
  _DWORD v47[2]; // [esp+14h] [ebp-4Ch]
  _DWORD v48[2]; // [esp+1Ch] [ebp-44h]
  int v49; // [esp+24h] [ebp-3Ch]
  int v50; // [esp+28h] [ebp-38h]
  int v51; // [esp+2Ch] [ebp-34h]
  int v52; // [esp+30h] [ebp-30h]
  _DWORD *v53; // [esp+34h] [ebp-2Ch]
  int v54; // [esp+38h] [ebp-28h] BYREF
  unsigned int v55; // [esp+3Ch] [ebp-24h] BYREF
  int v56; // [esp+40h] [ebp-20h]
  _DWORD *v57; // [esp+44h] [ebp-1Ch]
  unsigned int v58; // [esp+48h] [ebp-18h]
  int v59; // [esp+4Ch] [ebp-14h] BYREF
  int v60; // [esp+50h] [ebp-10h] BYREF
  unsigned int v61; // [esp+54h] [ebp-Ch]
  int v62; // [esp+58h] [ebp-8h]
  char *v63; // [esp+5Ch] [ebp-4h]

  v63 = 0;
  v61 = 0;
  if ( a3 )
  {
    v62 = a2;
    do
    {
      v5 = *(int **)v62;
      if ( *(_DWORD *)v62 )
      {
        v56 = *v5;
        v6 = v56 & 0xFFFFF;
        v58 = v56 & 0xFFFFF;
        sub_6A9B74(this, a4, 4u, v5, &v59, &v55, &v60, 1, 1);
        if ( v60 )
        {
          if ( v6 == 2 )
            goto LABEL_68;
        }
        else
        {
          if ( v6 != 2 )
            goto LABEL_68;
          v7 = v5[2] + 8;
          v8 = (_DWORD *)sub_6A9A7C(this, this[139], this[136], v7, 1u, 0);
          v46 = this[136];
          v45 = this[139];
          v57 = v8;
          v9 = (_DWORD *)sub_6A9A7C(this, v45, v46, v7 + 4, 1u, 0);
          v53 = v9;
          if ( !v57 )
            goto LABEL_68;
          if ( !v9 )
            goto LABEL_68;
          sub_6A9B74(this, a4, 4u, v57, &v59, &v55, &v54, 1, 1);
          if ( !v54 )
            goto LABEL_68;
          sub_6A9B74(this, a4, 4u, v53, &v59, &v55, &v60, 1, 1);
          if ( v54 != v60 )
            goto LABEL_68;
          v6 = v58;
        }
        if ( v60 )
        {
          v10 = 0;
          v63 = 0;
          if ( v6 == 3 )
          {
            if ( (v56 & 0xFFF00000) != 0x60F00000 && (v56 & 0xFFF00000) != 0x60A00000 )
              goto LABEL_68;
            v11 = v5[2];
            v12 = this[5];
            v55 = 1;
            v13 = (_DWORD *)(v11 + 12);
            do
            {
              v14 = *(_DWORD *)(v12 + 4 * *v13);
              if ( *(_DWORD *)(v14 + 16) != v10 )
                v55 = 0;
              v15 = *(_DWORD *)(v14 + 60);
              if ( v15 && v15 != 393216 )
              {
                sub_686791(
                  (int)this,
                  *(_DWORD *)(*(_DWORD *)(a2 + 4 * v61) + 60),
                  4535,
                  "cannot match to texreg2rgb instruction because can only have input modifier _bx2");
                return -2147467259;
              }
              ++v10;
              ++v13;
            }
            while ( v10 < 3 );
            if ( !v55 )
              goto LABEL_68;
            if ( (unsigned __int16)this[50] < 0x102u )
            {
              sub_686791(
                (int)this,
                *(_DWORD *)(*(_DWORD *)(a2 + 4 * v61) + 60),
                4536,
                "expression can only be map to texreg2rgb, but this instruction is not supported on 1_%i",
                (unsigned __int8)this[50]);
              return -2147467259;
            }
            v16 = (_DWORD *)sub_681186(116);
            if ( v16 )
              v63 = (char *)sub_680CEC(v16);
            else
              v63 = 0;
            if ( !v63 )
              goto LABEL_77;
            v17 = sub_6811D1(v63, 1918894083, 6, 4, 0);
            if ( v17 < 0 )
              goto LABEL_70;
          }
          else
          {
            if ( v6 != 2 || (v56 & 0xFFF00000) != 0x60500000 )
              goto LABEL_68;
            v18 = 0;
            v19 = 1;
            v48[0] = 3;
            v48[1] = 0;
            v47[0] = 1;
            v47[1] = 2;
            v55 = 1;
            do
            {
              v20 = v57;
              if ( v18 )
                v20 = v53;
              v21 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)v20[2]);
              v22 = *(_DWORD *)(v21 + 16);
              if ( v22 != v48[v18] )
                v55 = 0;
              if ( v22 != v47[v18] )
                v19 = 0;
              if ( *(_DWORD *)(v21 + 60) )
              {
                sub_686791(
                  (int)this,
                  *(_DWORD *)(*(_DWORD *)(a2 + 4 * v61) + 60),
                  4535,
                  "cannot match to texreg2ar or texreg2gb instruction because cannot have input modifiers");
                return -2147467259;
              }
              ++v18;
            }
            while ( v18 < 2 );
            if ( !v55 && !v19 )
              goto LABEL_68;
            v23 = (_DWORD *)sub_681186(116);
            if ( v23 )
              v63 = (char *)sub_680CEC(v23);
            else
              v63 = 0;
            if ( !v63 )
              goto LABEL_77;
            v17 = sub_6811D1(v63, v19 != 0 ? 1920991234 : 1919942658, 4, 4, 0);
            if ( v17 < 0 )
              goto LABEL_70;
          }
          for ( i = 0; i < 0x10; i += 4 )
            *(_DWORD *)(i + *((_DWORD *)v63 + 4)) = *(_DWORD *)(i + *(_DWORD *)(*(_DWORD *)v62 + 16));
          v25 = this[5];
          v26 = *(_DWORD *)(v25 + 4 * **(_DWORD **)(*(_DWORD *)v62 + 8));
          v27 = this[4];
          v52 = *(_DWORD *)(v25 + 4 * *(_DWORD *)(*(_DWORD *)(v60 + 8) + 12));
          if ( (*(_BYTE *)(*(_DWORD *)(v27 + 4 * *(_DWORD *)(v26 + 4)) + 5) & 8) != 0 )
          {
            v55 = *(_DWORD *)(v26 + 12);
            v28 = v55;
            if ( v55 > 3 || *(_DWORD *)(a4 + 4 * v55) )
              goto LABEL_53;
          }
          else
          {
            for ( j = v59; j < 4 && *(_DWORD *)(a4 + 4 * j); ++j )
              ;
            if ( j == 4 )
            {
LABEL_53:
              v17 = -2147467259;
              goto LABEL_70;
            }
            v55 = j;
            *(_DWORD *)(v26 + 12) = j;
            v28 = j;
          }
          v30 = sub_681AAA(this, this[32], v28, 0, 0.0);
          v50 = v30;
          if ( v30 == -1 )
            goto LABEL_77;
          v31 = *(_DWORD *)(this[5] + 4 * v30);
          sub_6815D6((double *)v31, v52);
          *(_DWORD *)(v31 + 108) = (v28 << 8) | 3;
          v32 = v58;
          *(_DWORD *)(v31 + 12) = v28;
          v33 = 0;
          if ( v32 )
          {
            v56 = 4 * v32;
            while ( 1 )
            {
              v34 = sub_681AAA(this, this[32], v59, v33, 0.0);
              v49 = v34;
              if ( v34 == -1 )
                break;
              v35 = this[5];
              v36 = *(_DWORD *)(v35 + 4 * v34);
              v51 = *(_DWORD *)(v35 + 4 * *(_DWORD *)(4 * v58 + *(_DWORD *)(*(_DWORD *)v62 + 8)));
              sub_6815D6((double *)v36, v52);
              v37 = v50;
              *(_DWORD *)(v36 + 12) = v59;
              v38 = v51;
              *(_DWORD *)(v36 + 16) = v33;
              *(_DWORD *)(v36 + 60) = *(_DWORD *)(v38 + 60);
              v39 = v63;
              *(_DWORD *)(*((_DWORD *)v63 + 2) + 4 * v33) = v37;
              v40 = v56;
              v41 = *((_DWORD *)v39 + 2);
              v56 += 4;
              v42 = ++v33 < v58;
              *(_DWORD *)(v40 + v41) = v49;
              if ( !v42 )
              {
                v28 = v55;
                goto LABEL_66;
              }
            }
LABEL_77:
            v17 = -2147024882;
            goto LABEL_70;
          }
LABEL_66:
          v43 = v63;
          *(_DWORD *)(a4 + 4 * v28) = v63;
          v17 = sub_681997((int)this, v43);
          if ( v17 < 0 )
            goto LABEL_70;
          *(_DWORD *)v62 = 0;
          v63 = 0;
        }
      }
LABEL_68:
      ++v61;
      v62 += 4;
    }
    while ( v61 < a3 );
  }
  v17 = 0;
LABEL_70:
  if ( v63 )
    sub_66238F(v63, 1);
  return v17;
}
