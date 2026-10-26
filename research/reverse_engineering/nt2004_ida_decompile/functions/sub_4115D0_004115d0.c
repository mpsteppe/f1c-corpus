char __userpurge sub_4115D0@<al>(int a1@<ecx>, char a2@<bpl>, _DWORD *ArgList)
{
  CHAR ***v5; // eax
  CHAR **i; // eax
  CHAR *v7; // eax
  int v8; // eax
  CHAR ***v9; // eax
  int *v10; // eax
  int j; // eax
  int v12; // eax
  int *v13; // eax
  CHAR ***v14; // eax
  CHAR **k; // eax
  CHAR *v16; // eax
  int v17; // eax
  CHAR ***v18; // eax
  char v19; // bl
  int v20; // ebp
  int v21; // eax
  CHAR *v22; // eax
  int *v23; // eax
  int v24; // ebp
  CHAR *v25; // eax
  int v26; // ebx
  int v27; // eax
  int *v28; // eax
  char v30; // [esp-44h] [ebp-4Ch]
  char v31; // [esp-1Ch] [ebp-24h]
  char v32; // [esp-1Ch] [ebp-24h]
  char v33; // [esp-14h] [ebp-1Ch]
  char v34; // [esp-10h] [ebp-18h]
  char v35; // [esp-10h] [ebp-18h]
  char v36; // [esp-Ch] [ebp-14h]
  char v37; // [esp-8h] [ebp-10h]
  char v38; // [esp-8h] [ebp-10h]
  char v39; // [esp+0h] [ebp-8h]
  int ArgLista; // [esp+Ch] [ebp+4h]
  int ArgListb; // [esp+Ch] [ebp+4h]

  if ( !*ArgList )
    return 0;
  sub_57A400((int)ArgList, aS_6, (char)aCareerdata);
  sub_57A400((int)ArgList, asc_5FC484, v36);
  sub_57A400((int)ArgList, aBankD, *(_DWORD *)(a1 + 4));
  sub_57A400((int)ArgList, aReputationD, *(_BYTE *)(a1 + 8));
  sub_57A400((int)ArgList, aCarnumberD, *(_BYTE *)(a1 + 164));
  v5 = *(CHAR ****)(a1 + 132);
  *(_DWORD *)(a1 + 140) = v5;
  if ( v5 )
  {
    for ( i = *v5; i; i = *v9 )
    {
      v7 = *i;
      if ( !v7 )
        v7 = &byte_629120;
      sub_57A400((int)ArgList, aMessageS, (char)v7);
      v8 = *(_DWORD *)(a1 + 140);
      if ( !v8 )
        break;
      v9 = *(CHAR ****)(v8 + 4);
      *(_DWORD *)(a1 + 140) = v9;
      if ( !v9 )
        break;
    }
  }
  sub_57A400((int)ArgList, asc_5FB9D8, v39);
  v10 = *(int **)(a1 + 12);
  *(_DWORD *)(a1 + 20) = v10;
  if ( v10 )
  {
    for ( j = *v10; j; j = *v13 )
    {
      sub_413CE0(j, ArgList);
      v12 = *(_DWORD *)(a1 + 20);
      if ( !v12 )
        break;
      v13 = *(int **)(v12 + 4);
      *(_DWORD *)(a1 + 20) = v13;
      if ( !v13 )
        break;
    }
  }
  v14 = *(CHAR ****)(a1 + 60);
  *(_DWORD *)(a1 + 68) = v14;
  if ( v14 )
  {
    for ( k = *v14; k; k = *v18 )
    {
      v16 = *k;
      if ( !v16 )
        v16 = &byte_629120;
      sub_57A400((int)ArgList, aBootedsponsorS, (char)v16);
      v17 = *(_DWORD *)(a1 + 68);
      if ( !v17 )
        break;
      v18 = *(CHAR ****)(v17 + 4);
      *(_DWORD *)(a1 + 68) = v18;
      if ( !v18 )
        break;
    }
  }
  sub_57A400((int)ArgList, asc_5FC414, a2);
  sub_57A400((int)ArgList, aS_7, (char)aResearchdata);
  sub_57A400((int)ArgList, asc_5FC404, v31);
  v19 = 0;
  v20 = a1 + 76;
  ArgLista = 4;
  do
  {
    sub_57A400((int)ArgList, aResearchlevelD_0, v19++);
    ++v20;
    --ArgLista;
  }
  while ( ArgLista );
  sub_57A400((int)ArgList, aCurrenttypeD, *(_DWORD *)(a1 + 80));
  sub_57A400((int)ArgList, aCurrentlevelD, *(_BYTE *)(a1 + 84));
  sub_57A400((int)ArgList, aCurrentnumrace_1, *(_BYTE *)(a1 + 85));
  sub_57A400((int)ArgList, aCurrentnumrace_2, *(_BYTE *)(a1 + 86));
  sub_57A400((int)ArgList, aCurrentcostD, *(_DWORD *)(a1 + 88));
  sub_57A400((int)ArgList, asc_5FC34C, v30);
  sub_57A400((int)ArgList, asc_5FC414, v37);
  sub_57A400((int)ArgList, aS_7, (char)aCardata);
  sub_57A400((int)ArgList, asc_5FC404, v32);
  v21 = *(_DWORD *)(a1 + 92);
  if ( v21 )
  {
    v22 = *(CHAR **)(v21 + 8);
    if ( !v22 )
      v22 = &byte_629120;
    sub_57A400((int)ArgList, aCurrentcarS, (char)v22);
  }
  v23 = *(int **)(a1 + 96);
  *(_DWORD *)(a1 + 104) = v23;
  if ( v23 )
  {
    v24 = *v23;
    if ( *v23 )
    {
      do
      {
        sub_57A400((int)ArgList, aCar_0, v38);
        sub_57A400((int)ArgList, asc_5FC31C, v34);
        v25 = *(CHAR **)(v24 + 8);
        if ( !v25 )
          v25 = &byte_629120;
        sub_57A400((int)ArgList, aNameS_0, (char)v25);
        v26 = 0;
        ArgListb = 4;
        do
        {
          sub_57A400((int)ArgList, aLevelDD, v26++);
          --ArgListb;
        }
        while ( ArgListb );
        sub_57A400((int)ArgList, aConditionD, *(_BYTE *)(v24 + 4));
        sub_57A400((int)ArgList, asc_5FC2D0, v33);
        v27 = *(_DWORD *)(a1 + 104);
        if ( !v27 )
          break;
        v28 = *(int **)(v27 + 4);
        *(_DWORD *)(a1 + 104) = v28;
        if ( !v28 )
          break;
        v24 = *v28;
      }
      while ( *v28 );
    }
  }
  sub_57A400((int)ArgList, asc_5FC34C, v38);
  sub_57A400((int)ArgList, asc_5FC2C8, v35);
  return 1;
}
