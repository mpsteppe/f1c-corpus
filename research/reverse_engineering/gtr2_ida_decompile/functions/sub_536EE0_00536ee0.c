char __usercall sub_536EE0@<al>(int a1@<ecx>, const CHAR *a2@<edi>, int a3@<esi>)
{
  const CHAR *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  char *v8; // eax
  _DWORD *v9; // eax
  char *v10; // eax
  const char *v11; // eax
  char *v12; // esi
  const char *v13; // edi
  const char *v14; // eax
  _DWORD *v15; // eax
  char *v16; // eax
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  int v20; // ecx
  const CHAR *v21; // eax
  int v22; // eax
  char *v23; // eax
  int v24; // eax
  const CHAR *v25; // eax
  const char *v26; // ecx
  const CHAR *v27; // eax
  int v28; // edi
  int v29; // esi
  const CHAR **v30; // ebp
  int v31; // ecx
  int v32; // eax
  int *v33; // eax
  int v34; // eax
  const CHAR *v35; // eax
  char *v36; // ebp
  int v37; // eax
  int v39; // [esp+0h] [ebp-ACh]
  void *v40; // [esp+8h] [ebp-A4h]
  void *Block; // [esp+10h] [ebp-9Ch]
  int v42; // [esp+14h] [ebp-98h]
  void *v43; // [esp+18h] [ebp-94h]
  const char *v44; // [esp+1Ch] [ebp-90h]
  int v45; // [esp+20h] [ebp-8Ch] BYREF
  const CHAR *v46; // [esp+24h] [ebp-88h]
  int v47; // [esp+28h] [ebp-84h]
  int v48; // [esp+2Ch] [ebp-80h]
  char v49[4]; // [esp+30h] [ebp-7Ch] BYREF
  int v50; // [esp+34h] [ebp-78h] BYREF
  unsigned int v51; // [esp+38h] [ebp-74h]
  int v52; // [esp+3Ch] [ebp-70h]
  int v53; // [esp+40h] [ebp-6Ch]
  int v54; // [esp+44h] [ebp-68h]
  int v55; // [esp+48h] [ebp-64h]
  int v56; // [esp+4Ch] [ebp-60h]
  int v57; // [esp+50h] [ebp-5Ch]
  char v58[4]; // [esp+5Ch] [ebp-50h] BYREF
  char v59[4]; // [esp+60h] [ebp-4Ch] BYREF
  _BYTE v60[8]; // [esp+64h] [ebp-48h] BYREF
  _BYTE v61[52]; // [esp+74h] [ebp-38h] BYREF
  int v62; // [esp+A8h] [ebp-4h]

  v50 = dword_B72BF8;
  v52 = 0;
  v53 = -1;
  v62 = 2;
  v56 = 0;
  v57 = -1;
  v54 = 0;
  v55 = -1;
  sub_53C160(v60);
  v4 = (const CHAR *)dword_B73100;
  LOBYTE(v62) = 3;
  if ( !dword_B73100 )
    v4 = WindowName;
  sub_615860(v4);
  sub_615A50(CommandLine);
  v5 = sub_616930("Game Filter");
  sub_615A50(v5);
  sub_615A50(" NOT: NotAI ");
  sub_615860(WindowName);
  v47 = a3;
  v46 = a2;
  sub_615860(WindowName);
  v6 = (_DWORD *)sub_616840("Selection Filter");
  v7 = v6;
  if ( v6 )
  {
    v51 = strlen(sub_48D380(v6));
    if ( v51 )
    {
      v8 = sub_48D380(v7);
      sub_615A50(v8);
    }
  }
  sub_53BDE0(v60, WindowName);
  v9 = (_DWORD *)sub_616840("AI Filter");
  if ( v9 )
  {
    v10 = sub_48D380(v9);
    sub_615A50(v10);
  }
  sub_615A50(" NOT: 2ndCar");
  sub_53BDE0(v59, v53);
  v11 = Str;
  if ( !Str )
    v11 = WindowName;
  if ( strstr(v11, "Custom") )
  {
    v12 = 0;
    v48 = sub_5A6E90(v58);
    if ( v48 > 0 )
    {
      do
      {
        v13 = dword_B6F708;
        if ( !dword_B6F708 )
          v13 = WindowName;
        v43 = v12;
        v14 = *(const char **)((int (__thiscall *)(char *))byte_53A070)(v58);
        if ( !v14 )
          v14 = WindowName;
        if ( !_stricmp(v14, v13) )
          --v47;
        ++v12;
      }
      while ( (int)v12 < v47 );
    }
  }
  v15 = (_DWORD *)sub_616840("Opponents");
  if ( v15 )
  {
    v16 = sub_48D380(v15);
    v17 = atol(v16);
    v47 = v17;
  }
  else
  {
    v17 = v47;
  }
  v18 = 103;
  if ( v17 >= 0 )
  {
    if ( v17 > 103 )
      v47 = 103;
  }
  else
  {
    v47 = 0;
  }
  *(_DWORD *)(a1 + 95732) = 2;
  *(_DWORD *)(a1 + 95736) = 0;
  sub_5303E0(a1 + 94760);
  v19 = a1;
  do
  {
    sub_5303E0(v19);
    v19 = v20 + 920;
    --v18;
  }
  while ( v18 );
  sub_501490(&byte_B6F530, v61, 31);
  sub_615860(v61);
  v21 = dword_B6F708;
  if ( !dword_B6F708 )
    v21 = WindowName;
  sub_615860(v21);
  v22 = v47;
  *(_DWORD *)(a1 + 95572) = v47;
  *(_DWORD *)(a1 + 95576) = v22;
  *(_DWORD *)(a1 + 95580) = v22;
  *(_DWORD *)(a1 + 95584) = 0;
  *(_DWORD *)(a1 + 95596) = 0;
  *(_BYTE *)(a1 + 95600) = 1;
  v23 = *(char **)(a1 + 94768);
  if ( !v23 )
    v23 = (char *)WindowName;
  sub_539600(v23);
  v24 = sub_538790(&unk_BE1CDC);
  if ( v24 )
    *(_DWORD *)(a1 + 95604) = sub_538F10(v24, a1 + 95608, 64, a1 + 95672, 8, 1);
  v25 = v46;
  if ( !v46 )
    v25 = WindowName;
  sub_615860(v25);
  v50 = 0;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v26 = v44;
  v61[20] = 5;
  if ( !v44 )
    v26 = WindowName;
  v27 = dword_B6F708;
  if ( !dword_B6F708 )
    v27 = WindowName;
  sub_5365F0(&v50, v42, (int)v27, v26);
  v28 = 0;
  if ( v42 > 0 )
  {
    v29 = a1 + 812;
    while ( 1 )
    {
      v30 = 0;
      if ( v28 < v53 )
        break;
LABEL_53:
      sub_615860(v30 + 463);
      v35 = *v30;
      if ( !*v30 )
        v35 = WindowName;
      sub_615860(v35);
      sub_615860(WindowName);
      *(_DWORD *)v29 = v28;
      *(_DWORD *)(v29 + 4) = v28;
      *(_DWORD *)(v29 + 8) = v28;
      *(_DWORD *)(v29 + 12) = 0;
      *(_DWORD *)(v29 + 24) = 1;
      *(_BYTE *)(v29 + 28) = 1;
      v36 = *(char **)(v29 - 804);
      if ( !v36 )
        v36 = (char *)WindowName;
      sub_539600(v36);
      v37 = sub_538790(&unk_BE1CDC);
      if ( v37 )
        *(_DWORD *)(v29 + 32) = sub_538F10(v37, v29 + 36, 64, v29 + 100, 8, 0);
      ++v28;
      v29 += 920;
      if ( v28 >= v39 )
        goto LABEL_60;
    }
    v31 = v28;
    if ( v28 < 0 )
    {
      v52 = 0;
      v33 = 0;
    }
    else
    {
      v32 = v50;
      v52 = v50;
      if ( v28 > 0 )
      {
        while ( v32 )
        {
          v32 = *(_DWORD *)(v32 + 4);
          --v31;
          v52 = v32;
          if ( v31 <= 0 )
            goto LABEL_47;
        }
        goto LABEL_48;
      }
LABEL_47:
      if ( !v32 )
      {
LABEL_48:
        v33 = 0;
        goto LABEL_51;
      }
      v33 = *(int **)v32;
    }
LABEL_51:
    v34 = *v33;
    if ( v34 < dword_BE1BD4 )
      v30 = (const CHAR **)(dword_BE1BD8 + 2824 * v34);
    goto LABEL_53;
  }
LABEL_60:
  sub_525140(&v45);
  sub_525140(&v45);
  v61[0] = 2;
  sub_53C1D0(v49);
  if ( Block )
    j_j__free(Block);
  if ( v43 )
    j_j__free(v43);
  if ( v40 )
    j_j__free(v40);
  return 0;
}
