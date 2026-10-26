int __thiscall sub_4D0610(int this, int a2, int a3, int a4, int a5)
{
  const char *v6; // eax
  unsigned __int16 v7; // bp
  int i; // eax
  const CHAR *v9; // eax
  char v10; // al
  int v11; // edx
  char *v12; // ebx
  int v13; // ecx
  int v14; // ebx
  _BYTE *v15; // ebp
  int v16; // ecx
  _BYTE *v17; // edi
  _BYTE *v19; // edi
  int v20; // ebx
  int v21; // edi
  int v22; // ebp
  int v23; // ecx
  int v24; // edx
  bool v25; // zf
  int v26; // eax
  int *v27; // edx
  int v28; // ecx
  int *v29; // ebx
  char *v30; // ebp
  int v31; // ecx
  int v32; // edi
  int v33; // edi
  int v34; // ebp
  int v35; // ecx
  int v36; // edx
  char *v37; // eax
  char *v38; // edx
  int v39; // ebp
  int v40; // ecx
  int **v41; // ecx
  _DWORD *v42; // eax
  _DWORD *v43; // edx
  int v45; // [esp+4h] [ebp-2B0h]
  int v46; // [esp+8h] [ebp-2ACh]
  int v47; // [esp+Ch] [ebp-2A8h]
  int v48; // [esp+10h] [ebp-2A4h]
  int v49; // [esp+14h] [ebp-2A0h] BYREF
  int *v50; // [esp+18h] [ebp-29Ch] BYREF
  int *v51; // [esp+1Ch] [ebp-298h]
  int v52; // [esp+20h] [ebp-294h]
  int v53; // [esp+24h] [ebp-290h] BYREF
  _BYTE *v54; // [esp+28h] [ebp-28Ch] BYREF
  char *v55; // [esp+2Ch] [ebp-288h]
  int v56; // [esp+30h] [ebp-284h]
  int v57; // [esp+34h] [ebp-280h] BYREF
  int v58; // [esp+38h] [ebp-27Ch] BYREF
  int *v59; // [esp+3Ch] [ebp-278h]
  int v60; // [esp+40h] [ebp-274h]
  int v61; // [esp+44h] [ebp-270h] BYREF
  _DWORD v62[2]; // [esp+48h] [ebp-26Ch] BYREF
  int v63; // [esp+50h] [ebp-264h]
  char *v64; // [esp+54h] [ebp-260h]
  int v65; // [esp+58h] [ebp-25Ch]
  int v66; // [esp+5Ch] [ebp-258h] BYREF
  int v67; // [esp+60h] [ebp-254h]
  int v68; // [esp+64h] [ebp-250h]
  int v69; // [esp+68h] [ebp-24Ch]
  _DWORD v70[2]; // [esp+6Ch] [ebp-248h] BYREF
  _DWORD v71[16]; // [esp+74h] [ebp-240h] BYREF
  _BYTE v72[440]; // [esp+B4h] [ebp-200h] BYREF
  int **v73; // [esp+26Ch] [ebp-48h]
  int **v74; // [esp+270h] [ebp-44h]
  _DWORD *v75; // [esp+274h] [ebp-40h]
  _DWORD *v76; // [esp+278h] [ebp-3Ch]
  char v77; // [esp+2B3h] [ebp-1h]

  v6 = *(const char **)(this + 160);
  if ( *(_BYTE *)(this + 276) )
  {
    if ( !v6 )
      v6 = WindowName;
    v56 = 511;
    v55 = sub_41D840(&byte_91CC38, v6);
    v54 = v72;
  }
  else
  {
    if ( !v6 )
      v6 = WindowName;
    v56 = 511;
    v55 = (char *)v6;
    v54 = v72;
  }
  sub_630FE0(v54, v55, v56);
  memset(v71, 0, sizeof(v71));
  v77 = 0;
  LOWORD(v66) = 124;
  v7 = 0;
  for ( i = sub_6331DF(v72, &v66); i; i = sub_6331DF(v55, v56) )
  {
    if ( v7 >= 0x10u )
      break;
    v56 = (int)&v66;
    v55 = 0;
    v71[v7++] = i;
  }
  v9 = *(const CHAR **)(this + 168);
  if ( !v9 )
    v9 = WindowName;
  v10 = sub_633CD6(*v9);
  switch ( v10 )
  {
    case 'C':
      *(_DWORD *)(this + 268) = 2;
      break;
    case 'L':
      *(_DWORD *)(this + 268) = 1;
      break;
    case 'R':
      *(_DWORD *)(this + 268) = 3;
      break;
  }
  v11 = *(_DWORD *)(this + 4);
  v12 = *(char **)(this + 16);
  v68 = *(_DWORD *)(this + 8);
  v13 = *(_DWORD *)(this + 12);
  v62[1] = v11;
  v65 = v13;
  v64 = v12;
  if ( v7 )
  {
    if ( *(int *)(this + 272) <= 0 )
    {
      v20 = (int)&v12[-v13];
      v21 = 0;
      v67 = 0;
      v61 = 0;
      v63 = v20;
      v70[1] = v68 - v11;
      v69 = v7;
      v67 = v7;
      v22 = v71[0];
      do
      {
        v23 = *(_DWORD *)(this + 48);
        v62[0] = 0;
        v70[0] = 0;
        sub_4E08C0(v23, v22, v62, v70, 1, v57);
        if ( v21 <= v58 )
          v21 = v58;
        v24 = v66 + v57;
        v25 = v63 == 1;
        v57 += v66;
        --v63;
      }
      while ( !v25 );
      v26 = v24;
      v27 = v59;
      v63 = v21;
      if ( v20 >= v21 && v67 >= v26 )
        goto LABEL_47;
      v28 = *(_DWORD *)(this + 268);
      v29 = v59;
      v30 = (char *)v59 + v26;
      if ( v28 == 2 )
      {
        v31 = v61 - (unsigned __int64)((double)v60 * 0.5 + 0.5) - (unsigned __int64)((double)v63 * 0.5 + 0.5);
        v26 = v57;
        v32 = v31 + v21;
      }
      else if ( v28 == 3 )
      {
        v31 = v61 - v21;
        v32 = v61;
      }
      else
      {
        v31 = v62[0];
        v32 = v62[0] + v21;
      }
      v60 = v26 / 2;
      if ( v67 / 2 > v26 / 2 )
        v29 = (int *)((char *)v59 + v67 / 2 - v26 / 2);
      v62[0] = v31;
      v59 = v29;
      v64 = v30;
      v61 = v32;
      sub_4E2A80(v29, v30, v31, v32);
    }
    else
    {
      v14 = 0;
      v69 = v7;
      do
      {
        v15 = (_BYTE *)v71[v14];
        v16 = *(_DWORD *)(this + 48);
        v61 = 0;
        v62[0] = 0;
        sub_4E08C0(v16, v15, &v61, v62, 1, v57);
        if ( v57 > *(_DWORD *)(this + 272) )
        {
          v17 = v15;
          if ( *v15 )
          {
            while ( *++v17 )
              ;
          }
          v52 = 1;
          v51 = &v58;
          v19 = v17 - 1;
          v50 = &v57;
          *v19 = 0;
          sub_4E08C0(*(_DWORD *)(this + 48), v15, v50, v51, v52, v53);
          if ( v53 > *(_DWORD *)(this + 272) )
          {
            do
            {
              if ( v15 == v19 )
                break;
              *--v19 = 0;
              sub_4E08C0(*(_DWORD *)(this + 48), v15, &v53, &v54, 1, v49);
            }
            while ( v49 > *(_DWORD *)(this + 272) );
          }
        }
        ++v14;
      }
      while ( v14 < v58 );
    }
    v27 = v51;
LABEL_47:
    v33 = 0;
    if ( v58 > 0 )
    {
      v34 = (v57 - (int)v27) / v58;
      v52 = v34;
      while ( 1 )
      {
        if ( (unsigned __int8)sub_4CFDA0(0, (int)&v50) )
        {
          v35 = v49 - *(_DWORD *)(this + 12);
          v36 = v48 - *(_DWORD *)(this + 4);
        }
        else
        {
          v35 = 0;
          v36 = 0;
        }
        v48 = v36;
        v37 = (char *)v50 + v36 + v33 * v34;
        v38 = &v37[v34];
        v39 = v35 + v53;
        v49 = v35;
        v40 = v52 + v35;
        if ( *(_DWORD *)(this + 268) == 2 )
        {
          sub_4E0680(*(_DWORD *)(this + 48), *(&v60 + v33), v37, v38, v39, v40, *(unsigned __int8 *)(this + 276));
        }
        else if ( *(_DWORD *)(this + 268) == 3 )
        {
          sub_4E07F0(*(_DWORD *)(this + 48), *(&v60 + v33), v37, v38, v39, v40, *(unsigned __int8 *)(this + 276));
        }
        else
        {
          sub_4E0730(*(_DWORD *)(this + 48));
        }
        if ( ++v33 >= (int)v51 )
          break;
        v34 = v45;
      }
      v27 = &v49;
    }
    v41 = v74;
    *v73 = v27;
    v42 = v75;
    *v41 = v50;
    v43 = v76;
    *v42 = v47;
    *v43 = v46;
  }
  return 0;
}
