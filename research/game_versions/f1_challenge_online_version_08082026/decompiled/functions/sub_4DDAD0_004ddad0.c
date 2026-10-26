void __fastcall sub_4DDAD0(int a1, _BYTE *a2, int a3, int a4)
{
  char *v5; // eax
  const char *v6; // edx
  unsigned int v7; // kr08_4
  const char *i; // eax
  char *v9; // eax
  int v10; // esi
  char *v11; // eax
  _DWORD *v12; // eax
  int v13; // ecx
  const char *v14; // ebp
  int v15; // eax
  int v16; // ebx
  const char **v17; // esi
  char *v18; // eax
  const char *v19; // edx
  unsigned int v20; // kr0C_4
  const char *j; // eax
  int v22; // ebp
  const char *v23; // edx
  const char *v24; // ecx
  int v25; // eax
  _DWORD *v26; // esi
  int v27; // edi
  const char *v28; // edx
  const char *v29; // ecx
  const char *v30; // eax
  unsigned int v31; // eax
  int v32; // ebx
  const char *v33; // edx
  const char *v34; // ecx
  _BYTE *v35; // esi
  int v36; // edi
  void *v37; // eax
  const char *v38; // [esp+8h] [ebp-D4h]
  char *v39; // [esp+Ch] [ebp-D0h]
  int v40; // [esp+10h] [ebp-CCh]
  int v41; // [esp+14h] [ebp-C8h]
  char *v42; // [esp+18h] [ebp-C4h]
  char *v43; // [esp+1Ch] [ebp-C0h]
  char *v44; // [esp+24h] [ebp-B8h]
  char *v45; // [esp+28h] [ebp-B4h]
  int v46; // [esp+2Ch] [ebp-B0h] BYREF
  char **v47; // [esp+30h] [ebp-ACh]
  _BYTE *v48; // [esp+34h] [ebp-A8h]
  _DWORD v49[3]; // [esp+38h] [ebp-A4h]
  _DWORD v50[2]; // [esp+44h] [ebp-98h] BYREF
  const char *v51; // [esp+4Ch] [ebp-90h]
  const char *v52; // [esp+54h] [ebp-88h]
  _BYTE v53[128]; // [esp+5Ch] [ebp-80h] BYREF

  v48 = a2;
  v47 = (char **)a1;
  if ( !a1 )
    return;
  v43 = (char *)sub_587C03(256);
  *v43 = 0;
  v5 = *(char **)a1;
  if ( !*(_DWORD *)a1 )
    v5 = byte_5EA438;
  sub_566650(v5);
  v6 = v43;
  if ( !v43 )
    v6 = byte_5EA438;
  v7 = strlen(v6) + 1;
  if ( (int)(v7 - 1) > 0 )
  {
    for ( i = &v6[v7 - 2]; i >= v6; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  sub_5665B0(aTeamMas);
  v9 = v43;
  v46 = 0;
  if ( !v43 )
    v9 = byte_5EA438;
  sub_53CBC0(&v46, v9);
  v44 = *(char **)(a1 + 972);
  if ( !v44 )
    v44 = byte_5EA438;
  v45 = *(char **)(a1 + 984);
  if ( !v45 )
    v45 = byte_5EA438;
  if ( sub_4C58A0((int)v53, 128, (int)aTrackname, 0) )
    v53[0] = 0;
  v10 = *(_DWORD *)(a1 + 980);
  v42 = 0;
  if ( v10 )
  {
    while ( 1 )
    {
      v11 = *(char **)v10;
      if ( !*(_DWORD *)v10 )
        v11 = byte_5EA438;
      if ( !sub_588410(v11, v53) )
        break;
      v10 = *(_DWORD *)(v10 + 16);
      if ( !v10 )
        goto LABEL_26;
    }
    v42 = *(char **)(v10 + 8);
    if ( !v42 )
      v42 = byte_5EA438;
  }
LABEL_26:
  v12 = v50;
  v13 = 3;
  do
  {
    *v12 = 0;
    v12[1] = -1;
    v12 += 2;
    --v13;
  }
  while ( v13 );
  v14 = v38;
  v41 = 0;
  do
  {
    switch ( v41 )
    {
      case 0:
        v14 = aWccarbody;
        v39 = byte_5EA438;
        goto LABEL_39;
      case 1:
        v14 = aWcdriver;
        v39 = aDriver;
        goto LABEL_39;
      case 2:
        v14 = aWcarms;
        v39 = aArms_0;
        goto LABEL_39;
      case 3:
        v14 = aWcwing;
        v39 = aWing;
        goto LABEL_39;
      case 4:
        v14 = aWchelmet;
        v39 = aHelmet_0;
        goto LABEL_39;
      case 5:
        v14 = aWcpitbody;
        v39 = aPitbody;
        goto LABEL_39;
      case 6:
        v14 = aWcpithelmet;
        v39 = aPithelmet;
        goto LABEL_39;
      case 7:
        v14 = aWclollipop;
        v39 = aLollipop_0;
        goto LABEL_39;
      case 8:
        v14 = aWcrefueler;
        v39 = aRefueler;
LABEL_39:
        v38 = v14;
        break;
      default:
        break;
    }
    v15 = 0;
    v40 = 0;
    if ( v48 && *v48 )
    {
      v15 = 1;
      v49[0] = v48;
      v40 = 1;
    }
    if ( v42 && *v42 )
    {
      v49[v15++] = v42;
      v40 = v15;
    }
    if ( v41 != 5 && v41 != 6 && v41 != 7 && v41 != 8 )
      goto LABEL_54;
    if ( v15 < 3 )
    {
      if ( v45 && *v45 )
      {
        v49[v15++] = v45;
        v40 = v15;
      }
LABEL_54:
      if ( v15 < 3 && v44 && *v44 )
      {
        v49[v15++] = v44;
        v40 = v15;
      }
    }
    v16 = 0;
    if ( v15 <= 0 )
      goto LABEL_80;
    v17 = (const char **)v50;
    do
    {
      v18 = *v47;
      if ( !*v47 )
        v18 = byte_5EA438;
      sub_566650(v18);
      v19 = *v17;
      if ( !*v17 )
        v19 = byte_5EA438;
      v20 = strlen(v19) + 1;
      if ( (int)(v20 - 1) > 0 )
      {
        for ( j = &v19[v20 - 2]; j >= v19; *j-- = 0 )
        {
          if ( *j == 92 )
            break;
        }
      }
      v22 = v49[v16];
      sub_5665B0(v22);
      v23 = *v17;
      if ( !*v17 )
        v23 = byte_5EA438;
      v24 = &v23[strlen(v23)];
      if ( v24 > v23 )
      {
        while ( *v24 != 46 )
        {
          if ( --v24 <= v23 )
            goto LABEL_75;
        }
        *v24 = 0;
      }
LABEL_75:
      sub_5665B0(v39);
      v25 = sub_589DB0(v22, 46);
      if ( v25 )
        sub_5665B0(v25);
      else
        sub_5665B0(aBmp);
      ++v16;
      v17 += 2;
    }
    while ( v16 < v40 );
    v14 = v38;
    if ( v16 < 3 )
    {
LABEL_80:
      v26 = &v50[2 * v16];
      v27 = 3 - v16;
      do
      {
        sub_566650(v14);
        sub_5665B0(aBmp);
        v26 += 2;
        --v27;
      }
      while ( v27 );
    }
    v28 = v52;
    if ( !v52 )
      v28 = byte_5EA438;
    v29 = v51;
    if ( !v51 )
      v29 = byte_5EA438;
    v30 = (const char *)v50[0];
    if ( !v50[0] )
      v30 = byte_5EA438;
    v31 = sub_4DC770(v14, 1, v30, v29, v28, 1, a4);
    v32 = v41;
    if ( !v41 && a3 )
    {
      if ( v31 > 2 )
      {
        sub_566650(byte_5EA438);
      }
      else
      {
        v33 = (const char *)v50[2 * v31];
        if ( !v33 )
          v33 = byte_5EA438;
        v34 = &v33[strlen(v33)];
        if ( v34 > v33 )
        {
          while ( *v34 != 92 )
          {
            if ( --v34 <= v33 )
              goto LABEL_96;
          }
          ++v34;
        }
LABEL_96:
        sub_566650(v34);
      }
    }
    ++v41;
  }
  while ( v32 + 1 < 9 );
  if ( v46 )
    sub_53CE40(v46);
  v35 = v53;
  v36 = 3;
  do
  {
    v37 = (void *)*((_DWORD *)v35 - 2);
    v35 -= 8;
    if ( v37 )
      sub_587BCF(v37);
    --v36;
  }
  while ( v36 );
  if ( v43 )
    sub_587BCF(v43);
}
