char __usercall sub_535D90@<al>(int a1@<ecx>, char *a2@<edi>)
{
  int v3; // eax
  int v4; // eax
  char v5; // cl
  char v6; // dl
  int v7; // edi
  char v8; // cl
  int v9; // eax
  char v10; // dl
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  char v14; // cl
  const char *v15; // ecx
  char *v16; // ebx
  char *v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  char *v21; // eax
  int v22; // edi
  const CHAR *v23; // eax
  const CHAR *v24; // edi
  const CHAR *v25; // eax
  int v26; // ebp
  int v27; // ebx
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  char *v30; // eax
  _DWORD *v31; // eax
  char *v32; // eax
  int v33; // ebx
  int v34; // edi
  char *v35; // eax
  int v36; // eax
  int v37; // ecx
  _DWORD *v38; // ebp
  int v39; // edi
  char v40; // al
  const CHAR **v41; // ebp
  int v42; // eax
  int v43; // edi
  int v44; // ecx
  const CHAR *v45; // eax
  const CHAR *v46; // eax
  const CHAR *v47; // esi
  int v49; // [esp-4h] [ebp-27Ch]
  int v50; // [esp+0h] [ebp-278h]
  int v51; // [esp+0h] [ebp-278h]
  char *v52; // [esp+4h] [ebp-274h]
  const CHAR **v53; // [esp+Ch] [ebp-26Ch]
  int v54; // [esp+Ch] [ebp-26Ch]
  int v55; // [esp+10h] [ebp-268h]
  _DWORD *v56; // [esp+14h] [ebp-264h]
  char *v57; // [esp+18h] [ebp-260h]
  int v58; // [esp+24h] [ebp-254h]
  char v59[68]; // [esp+28h] [ebp-250h] BYREF
  _BYTE v60[12]; // [esp+6Ch] [ebp-20Ch] BYREF
  char v61; // [esp+78h] [ebp-200h] BYREF

  v3 = *(_DWORD *)(a1 + 95736);
  *(_BYTE *)(a1 + 95714) = 0;
  *(_BYTE *)(a1 + 95712) = 0;
  *(_BYTE *)(a1 + 95713) = 0;
  *(_BYTE *)(a1 + 95715) = 0;
  *(_BYTE *)(a1 + 95716) = 0;
  *(_BYTE *)(a1 + 95717) = 0;
  *(_DWORD *)(a1 + 95720) = 2;
  *(_DWORD *)(a1 + 95724) = 1;
  HIWORD(v58) = HIWORD(v3);
  v4 = sub_533F30(a1, a2, v3);
  v5 = *(_BYTE *)(a1 + 95714);
  v6 = *(_BYTE *)(a1 + 95713);
  v7 = v4;
  *(_BYTE *)(a1 + 95745) = *(_BYTE *)(a1 + 95712);
  LOBYTE(v4) = *(_BYTE *)(a1 + 95715);
  *(_BYTE *)(a1 + 95746) = v5;
  v8 = *(_BYTE *)(a1 + 95716);
  *(_BYTE *)(a1 + 95748) = v4;
  v9 = *(_DWORD *)(a1 + 95720);
  *(_BYTE *)(a1 + 95747) = v6;
  v10 = *(_BYTE *)(a1 + 95717);
  *(_BYTE *)(a1 + 95749) = v8;
  v11 = *(_DWORD *)(a1 + 95724);
  *(_BYTE *)(a1 + 95750) = v10;
  *(_DWORD *)(a1 + 95752) = v9;
  *(_DWORD *)(a1 + 95756) = v11;
  if ( v9 > -1 )
  {
    v12 = dword_B70620;
    dword_B70618[0] = v9;
    if ( v9 < dword_B70620 || (v12 = dword_B70624, v9 > dword_B70624) )
      dword_B70618[0] = v12;
    v13 = dword_B706B0;
    dword_B706A8 = *(_DWORD *)(a1 + 95720);
    if ( dword_B706A8 < dword_B706B0 || (v13 = dword_B706B4, dword_B706A8 > dword_B706B4) )
      dword_B706A8 = v13;
  }
  v14 = byte_B722E6;
  byte_B722E4 = *(_BYTE *)(a1 + 95750);
  if ( (unsigned __int8)byte_B722E4 < (unsigned __int8)byte_B722E6
    || (v14 = byte_B722E7, (unsigned __int8)byte_B722E4 > (unsigned __int8)byte_B722E7) )
  {
    byte_B722E4 = v14;
  }
  v52 = &v61;
  sub_501CC0(&byte_B6F530, 1);
  sub_53BDE0(&unk_BE1CE0, v60);
  v15 = *(const char **)(v7 + 8);
  if ( !v15 )
    v15 = WindowName;
  strcpy(v59, v15);
  v16 = &v59[strlen(v59)];
  if ( v16 > v59 )
  {
    while ( *v16 != 92 )
    {
      if ( --v16 <= v59 )
        goto LABEL_18;
    }
    ++v16;
  }
LABEL_18:
  v17 = &v16[strlen(v16)];
  if ( v17 > v16 )
  {
    while ( *v17 != 46 )
    {
      if ( --v17 <= v16 )
        goto LABEL_23;
    }
    *v17 = 0;
  }
LABEL_23:
  v18 = 0;
  v55 = 0;
  v19 = 0;
  do
  {
    if ( v19 )
      v20 = a1 + 94760;
    else
      v20 = a1 + 920 * v18;
    v21 = *(char **)(v20 + 8);
    if ( !v21 )
      v21 = (char *)WindowName;
    v22 = sub_539670(v21);
    v23 = *(const CHAR **)(v22 + 2708);
    if ( !v23 )
      v23 = WindowName;
    if ( sub_616480(v23, v16) )
    {
      v24 = *(const CHAR **)(v22 + 2716);
      if ( !v24 )
        v24 = WindowName;
      sub_615860(v24);
    }
    v18 = v55 + 1;
    v19 = v55++ == 103;
  }
  while ( v55 <= 104 );
  if ( v53 )
  {
    v25 = *v53;
    if ( !*v53 )
      v25 = WindowName;
    sub_538860(&unk_BE1CFD, v25, v49, v50);
    sub_53A160(0);
    v57 = 0;
    v26 = 20;
    if ( sub_53A250(0) )
    {
      v27 = sub_616840("IgnoreTrackFilter");
      v28 = (_DWORD *)sub_616630("AI Vehicle Filter");
      if ( v28 && !v27 )
        v57 = sub_48D380(v28);
      v29 = (_DWORD *)sub_616630("Max Vehicles");
      if ( v29 )
      {
        v30 = sub_48D380(v29);
        v26 = atol(v30);
      }
    }
    if ( sub_616840("SceneOrder") )
    {
      if ( sub_616610(*(_DWORD *)(a1 + 95736)) )
      {
        v31 = (_DWORD *)sub_616630("Max Vehicles");
        if ( v31 )
        {
          v32 = sub_48D380(v31);
          v26 = atol(v32);
        }
      }
    }
    v33 = 0;
    v54 = v26 - 1;
    v34 = a1 + 8;
    v56 = (_DWORD *)(a1 + 4 * v55 + 20);
    while ( 1 )
    {
      *(_BYTE *)(v34 + 820) = 0;
      if ( v33 < v54 && *(_BYTE *)(v34 + 832) )
      {
        v35 = *(char **)v34;
        if ( !*(_DWORD *)v34 )
          v35 = (char *)WindowName;
        sub_539600(v35);
        v36 = sub_538790(&unk_BE1CDC);
        if ( v36 )
          v37 = v36 + 2172;
        else
          v37 = 0;
        if ( sub_616480(v37, v57) || !v57 )
        {
          *(_DWORD *)(v34 + 828) = 1;
          *(_DWORD *)(v34 + 812) = v33;
          if ( *(_BYTE *)(a1 + 95745) && v55 > 0 )
            *(_DWORD *)(v34 + 808) = *v56 - 1;
          if ( !*(_BYTE *)(a1 + 95748) )
            *(_DWORD *)(v34 + 824) = 0;
          sub_531CD0();
          ++v33;
          goto LABEL_67;
        }
      }
      else
      {
        *(_DWORD *)(v34 + 808) = 0;
        *(_DWORD *)(v34 + 812) = 0;
      }
      *(_DWORD *)(v34 + 828) = -1;
LABEL_67:
      v34 += 920;
      v19 = v52 == (char *)1;
      v55 += 920;
      --v52;
      if ( v19 )
      {
        if ( v33 < 103 )
        {
          v38 = 0;
          v39 = a1 + 836;
          do
          {
            if ( v33 < 103 && *(_BYTE *)(v39 + 4) && !*(_BYTE *)(v39 - 8) && *(_DWORD *)v39 == -1 )
            {
              *(_DWORD *)v39 = 1;
              *(_DWORD *)(v39 - 16) = v33;
              if ( *(_BYTE *)(a1 + 95745) && v54 > 0 )
                *(_DWORD *)(v39 - 20) = *v38 - 1;
              if ( !*(_BYTE *)(a1 + 95748) )
                *(_DWORD *)(v39 - 4) = 0;
              sub_531CD0();
              ++v33;
            }
            else if ( *(_DWORD *)v39 != 1 )
            {
              *(_DWORD *)(v39 - 20) = 0;
              *(_DWORD *)(v39 - 16) = 0;
            }
            v38 += 230;
            v39 += 920;
            --v51;
          }
          while ( v51 );
        }
        v40 = *(_BYTE *)(a1 + 95745);
        *(_BYTE *)(a1 + 95588) = 0;
        if ( v40 )
          *(_DWORD *)(a1 + 95576) = *(_DWORD *)(a1 + 95192) - 1;
        if ( !*(_BYTE *)(a1 + 95748) )
          *(_DWORD *)(a1 + 95592) = 0;
        v41 = (const CHAR **)(a1 + 94760);
        *(_DWORD *)(a1 + 95580) = v33;
        *(_DWORD *)(a1 + 95596) = 0;
        sub_531CD0();
        if ( *(_BYTE *)(a1 + 95745) && *(int *)(a1 + 95740) < 5 )
          *(_DWORD *)(a1 + 95740) = 5;
        v42 = dword_B72C00;
        dword_B72BF8 = v33;
        if ( v33 < dword_B72C00 || (v42 = dword_B72C04, v33 > dword_B72C04) )
          dword_B72BF8 = v42;
        if ( v33 + 1 < 103 )
        {
          v43 = 22616 * (v33 + 1);
          do
          {
            sub_53E6A0(v43 + dword_B763DC, -1);
            v43 += 22616;
          }
          while ( v43 < 2329448 );
        }
        sub_50EC00((int)&byte_B6F530, -1.0);
        v44 = dword_B71F2C;
        dword_B71F24 = *(_DWORD *)(a1 + 95740);
        if ( dword_B71F24 < dword_B71F2C || (v44 = dword_B71F30, dword_B71F24 > dword_B71F30) )
          dword_B71F24 = v44;
        v45 = *v41;
        if ( !*v41 )
          v45 = WindowName;
        sub_615860(v45);
        v46 = *(const CHAR **)(a1 + 94768);
        if ( !v46 )
          v46 = WindowName;
        sub_615860(v46);
        v47 = *(const CHAR **)(a1 + 94768);
        if ( !v47 )
          v47 = WindowName;
        sub_615860(v47);
        return 0;
      }
    }
  }
  return 0;
}
