int __userpurge sub_4D0F70@<eax>(int a1@<ecx>, const CHAR ***a2@<ebx>, int a3@<edi>, int a4, int a5, int a6, int a7)
{
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  const CHAR **v13; // esi
  const CHAR *v14; // eax
  const CHAR *v15; // eax
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // ebx
  char v22; // al
  int v23; // eax
  int v24; // edi
  char v25; // al
  int v26; // eax
  int v27; // edi
  char v28; // al
  int v29; // eax
  int v30; // eax
  int v31; // edi
  char v32; // al
  int v33; // eax
  int v34; // eax
  const char *v35; // eax
  const CHAR *v36; // eax
  const char *v37; // eax
  const CHAR *v38; // eax
  int v39; // eax
  const CHAR ***v40; // eax
  _DWORD *v41; // edx
  _DWORD *v42; // ecx
  _DWORD *v43; // eax
  const CHAR **v45; // [esp+0h] [ebp-98h]
  __int16 v46; // [esp+8h] [ebp-90h]
  char v47[4]; // [esp+Ch] [ebp-8Ch] BYREF
  int v48; // [esp+10h] [ebp-88h]
  char *v49; // [esp+14h] [ebp-84h] BYREF
  const CHAR **v50; // [esp+18h] [ebp-80h]
  int v51; // [esp+1Ch] [ebp-7Ch] BYREF
  int v52; // [esp+20h] [ebp-78h] BYREF
  int v53; // [esp+24h] [ebp-74h] BYREF
  __int16 v54; // [esp+28h] [ebp-70h] BYREF
  int v55; // [esp+2Ch] [ebp-6Ch] BYREF
  const CHAR ***v56; // [esp+30h] [ebp-68h] BYREF
  int v57; // [esp+34h] [ebp-64h]
  _DWORD v58[2]; // [esp+38h] [ebp-60h] BYREF
  char v59; // [esp+40h] [ebp-58h] BYREF
  int v60; // [esp+44h] [ebp-54h]
  int v61; // [esp+54h] [ebp-44h]
  int v62; // [esp+58h] [ebp-40h]
  int v63; // [esp+5Ch] [ebp-3Ch]
  const CHAR **v64; // [esp+68h] [ebp-30h]
  _DWORD v65[5]; // [esp+78h] [ebp-20h] BYREF
  _DWORD v66[3]; // [esp+8Ch] [ebp-Ch] BYREF

  v8 = *(_DWORD *)(a1 + 12);
  v9 = *(_DWORD *)(a1 + 4);
  v10 = *(_DWORD *)(a1 + 8);
  v66[0] = v8;
  v11 = *(_DWORD *)(a1 + 296);
  v65[3] = v9;
  v12 = *(_DWORD *)(a1 + 16);
  v65[4] = v10;
  v65[1] = 0;
  v66[1] = v12;
  v13 = (const CHAR **)sub_47F6E0((void *)(a1 + 280), v11);
  v14 = *(const CHAR **)(*(_DWORD *)(a1 + 244) + 64);
  v64 = v13;
  if ( !v14 )
    v14 = WindowName;
  sub_4DF1B0(*(_DWORD *)(a1 + 48), v14);
  if ( v13 )
  {
    v56 = a2;
    v55 = a3;
    while ( 1 )
    {
      v15 = *v13;
      if ( !*v13 )
        v15 = WindowName;
      sub_4E08C0(*(_DWORD *)(a1 + 48), v15, v66, v65, 1, v55);
      v16 = *(_DWORD *)(a1 + 4);
      if ( sub_4E3D00(a1 + 112) <= 0 )
      {
        v18 = *(_DWORD *)(a1 + 244);
        if ( !v18 )
          goto LABEL_14;
        v50 = (const CHAR **)&v55;
        v49 = &v59;
        v17 = v18 + 108;
      }
      else
      {
        v50 = (const CHAR **)&v55;
        v49 = &v59;
        v17 = a1 + 112;
      }
      if ( (unsigned __int8)sub_4E3D10(v17, 0, v49, v50) )
      {
        v19 = v16 + (__int16)v52;
        goto LABEL_15;
      }
LABEL_14:
      v19 = -1;
LABEL_15:
      v20 = *(_DWORD *)(a1 + 12);
      v21 = v19 + v62 * v63;
      v61 = v21 + v63;
      if ( sub_4E3D00(a1 + 112) <= 0 )
      {
        v23 = *(_DWORD *)(a1 + 244);
        if ( !v23 )
          goto LABEL_21;
        v22 = sub_4E3D10(v23 + 108, 0, &v53, v58);
      }
      else
      {
        v22 = sub_4E3D10(a1 + 112, 0, &v53, v58);
      }
      if ( v22 )
      {
        v60 = v20 + (__int16)v50;
        goto LABEL_22;
      }
LABEL_21:
      v60 = -1;
LABEL_22:
      v24 = *(_DWORD *)(a1 + 12);
      if ( sub_4E3D00(a1 + 112) <= 1 )
      {
        v26 = *(_DWORD *)(a1 + 244);
        if ( !v26 )
          goto LABEL_28;
        v25 = sub_4E3D10(v26 + 108, 1, &v51, &v56);
      }
      else
      {
        v25 = sub_4E3D10(a1 + 112, 1, &v51, &v56);
      }
      if ( v25 )
      {
        v57 = v24 + (__int16)v48;
        goto LABEL_29;
      }
LABEL_28:
      v57 = -1;
LABEL_29:
      v27 = *(_DWORD *)(a1 + 4);
      if ( sub_4E3D00(a1 + 112) <= 1 )
      {
        v29 = *(_DWORD *)(a1 + 244);
        if ( !v29 )
          goto LABEL_35;
        v28 = sub_4E3D10(v29 + 108, 1, &v54, &v49);
      }
      else
      {
        v28 = sub_4E3D10(a1 + 112, 1, &v54, &v49);
      }
      if ( v28 )
      {
        v30 = v27 + v46;
        goto LABEL_36;
      }
LABEL_35:
      v30 = -1;
LABEL_36:
      if ( (int)v56 > v30 )
        goto LABEL_58;
      v31 = *(_DWORD *)(a1 + 4);
      if ( sub_4E3D00(a1 + 112) <= 0 )
      {
        v33 = *(_DWORD *)(a1 + 244);
        if ( !v33 )
          goto LABEL_43;
        v32 = sub_4E3D10(v33 + 108, 0, &v52, v47);
      }
      else
      {
        v32 = sub_4E3D10(a1 + 112, 0, &v52, v47);
      }
      if ( v32 )
      {
        v34 = v31 + (__int16)v45;
        goto LABEL_44;
      }
LABEL_43:
      v34 = -1;
LABEL_44:
      if ( v21 < v34 )
      {
LABEL_58:
        *(_BYTE *)(a1 + 313) = 1;
        goto LABEL_59;
      }
      v35 = *(const char **)(a1 + 168);
      if ( !v35 )
        v35 = WindowName;
      if ( !strcmp("c", v35) )
      {
        v36 = *v50;
        if ( !*v50 )
          v36 = WindowName;
        sub_4E0680(*(_DWORD *)(a1 + 48), v36, v21, v53, v52, v51, 1);
      }
      else
      {
        v37 = *(const char **)(a1 + 168);
        if ( !v37 )
          v37 = WindowName;
        if ( !strcmp("r", v37) )
        {
          v38 = *v50;
          if ( !*v50 )
            v38 = WindowName;
          sub_4E07F0(*(_DWORD *)(a1 + 48), v38, v21, v53, v52, v51, 1);
        }
        else
        {
          sub_4E0730(*(_DWORD *)(a1 + 48));
        }
      }
LABEL_59:
      v39 = *(_DWORD *)(a1 + 288);
      if ( v39 && (v40 = *(const CHAR ****)(v39 + 4), (*(_DWORD *)(a1 + 288) = v40) != 0) )
        v45 = *v40;
      else
        v45 = 0;
      ++v48;
      if ( !v45 )
        break;
      v13 = v45;
    }
  }
  v41 = (_DWORD *)v57;
  *v56 = v50;
  v42 = (_DWORD *)v58[0];
  *v41 = v51;
  v43 = (_DWORD *)v58[1];
  *v42 = v52;
  *v43 = v53;
  return 0;
}
