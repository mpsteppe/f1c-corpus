char __usercall sub_47E080@<al>(int *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>)
{
  int v5; // eax
  int v6; // ecx
  int i; // esi
  int v8; // ecx
  _DWORD *v9; // ecx
  int v10; // eax
  char *v11; // eax
  int v12; // esi
  int k; // ecx
  int v14; // eax
  char *v15; // eax
  int j; // ecx
  int v17; // eax
  const CHAR **v18; // esi
  int v19; // eax
  const CHAR *v20; // eax
  int v21; // ecx
  int *v22; // eax
  const CHAR **v23; // ebp
  bool v24; // zf
  int v25; // esi
  int v26; // ecx
  int v27; // edx
  const CHAR **v28; // ebx
  char *v30; // [esp+Eh] [ebp-37Ch]
  float v31; // [esp+1Ah] [ebp-370h]
  float v32; // [esp+1Ah] [ebp-370h]
  float v33; // [esp+1Ah] [ebp-370h]
  char v34; // [esp+25h] [ebp-365h]
  int v35; // [esp+26h] [ebp-364h]
  int v36; // [esp+2Ah] [ebp-360h]
  float v37; // [esp+2Eh] [ebp-35Ch]
  float v38; // [esp+32h] [ebp-358h]
  float v39; // [esp+36h] [ebp-354h]

  v5 = *a1;
  v6 = *(_DWORD *)(*a1 + 113328);
  if ( !v6 )
    return v5;
  v36 = a2;
  v35 = a4;
  if ( v6 == 2 || v6 == 1 )
  {
    HIBYTE(v38) = 1;
    if ( *(int *)(v5 + 112884) <= 1 )
      goto LABEL_7;
  }
  else
  {
    HIBYTE(v38) = 0;
  }
  v39 = dbl_FB1D08;
  *(float *)(v5 + 2132) = v39 + *(float *)(v5 + 2132);
LABEL_7:
  if ( !sub_59B670(*(_DWORD *)(*a1 + 113316)) )
  {
    for ( i = 0; i < dword_757C10; ++i )
    {
      v8 = *(&dword_91E088 + i);
      if ( *(_DWORD *)(v8 + 14820) == 2 )
      {
        sub_53F190(v8, 0, v35, v36);
        sub_53F0E0(0);
      }
    }
    v30 = sub_41D840(&byte_91CC38, "Connection lost");
    sub_4730C0((int **)off_16C99A8, v30, 1, (int)&byte_1020304, 1084227584);
    *(float *)(*a1 + 2120) = *(float *)(*a1 + 2120) - v37;
    if ( *(float *)(*a1 + 2120) < 0.0 )
    {
      sub_4EA880(1);
      sub_4EA900(&unk_B6F134);
      byte_B6CBCC = 1;
      sub_4EBCE0(&unk_B6F135);
    }
    goto LABEL_48;
  }
  sub_476000();
  sub_477940();
  v34 = 0;
  sub_479E60();
  sub_47DDB0(*a1, a3, (int)a1, a4);
  sub_479230(*a1);
  sub_473260(*a1 + 292692, v38);
  sub_4743C0(*a1);
  v9 = (_DWORD *)*a1;
  if ( *(_BYTE *)(*a1 + 1184) )
  {
    v10 = v9[28332];
    if ( v10 <= 0 || v10 > 2 )
      sub_476F30();
    else
      sub_479360(v9, -1);
    *(_BYTE *)(*a1 + 1184) = 0;
    if ( HIBYTE(v37) )
    {
      if ( !*(_BYTE *)(*a1 + 1185) )
        sub_474180(*a1);
    }
  }
  if ( *(_DWORD *)dword_B640C8 != 6 )
    goto LABEL_48;
  if ( byte_B6F118 || dword_B640C0 != 5 )
  {
    if ( !*(_BYTE *)(*a1 + 1178) )
      goto LABEL_48;
    if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) )
    {
      *(_BYTE *)(*a1 + 1178) = 0;
      v32 = dbl_FB1D18;
      sub_51B2A0(4, 56, 0, 0, LODWORD(v32), 3);
      goto LABEL_47;
    }
    *(_BYTE *)(*a1 + 1178) = 0;
    v15 = (char *)&unk_9204A0 + 22616 * *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468);
    if ( v15 )
      v15[22588] = 0;
    v12 = 0;
    for ( j = 0; j < dword_757C10; ++j )
    {
      v17 = *(&dword_91E088 + j);
      if ( v17 && *(_BYTE *)(v17 + 22588) )
        ++v12;
    }
LABEL_46:
    v33 = dbl_FB1D18;
    dword_FADE38 = v12;
    sub_51B2A0(4, 57, 4, 255, LODWORD(v33), 3);
    goto LABEL_47;
  }
  if ( *(_BYTE *)(*a1 + 1178) )
    goto LABEL_48;
  if ( (unsigned __int8)sub_4735E0(&dword_B6CBA8) )
  {
    *(_BYTE *)(*a1 + 1178) = 1;
    v11 = (char *)&unk_9204A0 + 22616 * *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468);
    if ( v11 )
      v11[22588] = 1;
    v12 = 0;
    for ( k = 0; k < dword_757C10; ++k )
    {
      v14 = *(&dword_91E088 + k);
      if ( v14 && *(_BYTE *)(v14 + 22588) )
        ++v12;
    }
    goto LABEL_46;
  }
  *(_BYTE *)(*a1 + 1178) = 1;
  v31 = dbl_FB1D18;
  sub_51B2A0(4, 55, 0, 0, LODWORD(v31), 3);
LABEL_47:
  sub_4745E0();
LABEL_48:
  v18 = 0;
  *(float *)(*a1 + 2128) = v37 + *(float *)(*a1 + 2128);
  v19 = *(_DWORD *)(*a1 + 302732);
  if ( v19 )
  {
    v18 = *(const CHAR ***)v19;
    *(_BYTE *)(v19 + 8) = 0;
    if ( !(unsigned __int8)sub_479760() )
      v18 = 0;
  }
  if ( v18 )
  {
    do
    {
      v20 = *v18;
      if ( !*v18 )
        v20 = WindowName;
      sub_4EA920(v20);
      sub_498720(v18);
      j__free(v18);
      v21 = *(_DWORD *)(*a1 + 302732);
      v22 = (int *)(*a1 + 302732);
      v23 = 0;
      if ( v21 )
      {
        v23 = *(const CHAR ***)v21;
        v24 = *(_DWORD *)v21 == 0;
        *(_BYTE *)(v21 + 8) = 0;
        if ( v24 || (v25 = *v22, v26 = 0, !*v22) )
        {
LABEL_59:
          v23 = 0;
        }
        else
        {
          while ( *(const CHAR ***)v25 != v23 )
          {
            v26 = v25;
            v25 = *(_DWORD *)(v25 + 4);
            if ( !v25 )
              goto LABEL_59;
          }
          if ( v25 == v22[2] )
            v22[2] = *(_DWORD *)(v25 + 4);
          v27 = *(_DWORD *)(v25 + 4);
          if ( v26 )
            *(_DWORD *)(v26 + 4) = v27;
          else
            *v22 = v27;
          if ( v22[1] == v25 )
            v22[1] = v26;
          --v22[3];
          if ( *(_BYTE *)(v25 + 8) )
          {
            v28 = *(const CHAR ***)v25;
            if ( *(_DWORD *)v25 )
            {
              sub_498720(*(void **)v25);
              j__free(v28);
            }
          }
          j__free((void *)v25);
        }
      }
      v18 = v23;
    }
    while ( v23 );
  }
  if ( v34 )
    nullsub_7((void *)(*a1 + 302748));
  sub_4767A0((float *)*a1);
  LOBYTE(v5) = sub_4769D0(*a1);
  return v5;
}
