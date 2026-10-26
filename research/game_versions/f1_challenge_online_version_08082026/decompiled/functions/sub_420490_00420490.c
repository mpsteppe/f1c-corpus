char __fastcall sub_420490(char a1)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  char *v16; // ecx
  const char *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // esi
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // esi
  int v27; // eax
  int v28; // esi
  int v29; // eax
  int v30; // edi
  int v31; // eax
  char *v32; // ecx
  const char *v33; // eax
  int v34; // eax
  char result; // al
  char v36; // [esp+12h] [ebp-26h]
  char v37; // [esp+13h] [ebp-25h]
  float v39[8]; // [esp+18h] [ebp-20h] BYREF

  v1 = 0;
  v2 = 0;
  v36 = 0;
  v37 = 0;
  v3 = sub_4C2850(&unk_7D2DB0);
  if ( *(_DWORD *)(sub_4C1390(v3) + 412) == 1 )
  {
    v4 = sub_4C2850(&unk_7D2DB0);
    v5 = sub_4C1390(v4);
  }
  else
  {
    v6 = 0;
    v7 = sub_4C2850(&unk_7D2DB0);
    if ( sub_4C1370(v7) <= 0 )
      goto LABEL_24;
    while ( 1 )
    {
      sub_4C2850(&unk_7D2DB0);
      if ( *(_DWORD *)(sub_4C13A0(v6) + 412) == 1 )
        break;
      ++v6;
      v8 = sub_4C2850(&unk_7D2DB0);
      if ( v6 >= sub_4C1370(v8) )
        goto LABEL_24;
    }
    sub_4C2850(&unk_7D2DB0);
    v5 = sub_4C13A0(v6);
  }
  v2 = v5;
  if ( v5 )
  {
    v9 = sub_4C2850(&unk_7D2DB0);
    if ( v2 != sub_4C1390(v9) )
    {
      v10 = *(_DWORD *)(v2 + 408);
      v11 = sub_4C2850(&unk_7D2DB0);
      if ( v10 == *(_DWORD *)(sub_4C1390(v11) + 408) )
        v36 = 1;
    }
    v12 = 0;
    v13 = sub_4C2850(&unk_7D2DB0);
    if ( sub_4C1370(v13) > 0 )
    {
      do
      {
        sub_4C2850(&unk_7D2DB0);
        if ( v2 != sub_4C13A0(v12) )
        {
          v14 = *(_DWORD *)(v2 + 408);
          sub_4C2850(&unk_7D2DB0);
          if ( v14 == *(_DWORD *)(sub_4C13A0(v12) + 408) )
            v36 = 1;
        }
        ++v12;
        v15 = sub_4C2850(&unk_7D2DB0);
      }
      while ( v12 < sub_4C1370(v15) );
    }
    if ( !v36 && a1 )
    {
      sub_4144D0(v39);
      v16 = *(char **)(v2 + 8);
      if ( !v16 )
        v16 = &byte_5EA438;
      v17 = *(const char **)v2;
      if ( !*(_DWORD *)v2 )
        v17 = &byte_5EA438;
      v18 = sub_415230((char ****)&dword_5EA5E8, v17, (int)v16);
      sub_4144F0(v39, 397, v18, 2, -1, -1, -2.0, -2.0);
      sub_418560(flt_5EA618, v39);
    }
  }
LABEL_24:
  v19 = sub_4C2850(&unk_7D2DB0);
  if ( *(_DWORD *)(sub_4C1390(v19) + 412) == 2 )
  {
    v20 = sub_4C2850(&unk_7D2DB0);
    v21 = sub_4C1390(v20);
  }
  else
  {
    v22 = 0;
    v23 = sub_4C2850(&unk_7D2DB0);
    if ( sub_4C1370(v23) <= 0 )
      goto LABEL_47;
    while ( 1 )
    {
      sub_4C2850(&unk_7D2DB0);
      if ( *(_DWORD *)(sub_4C13A0(v22) + 412) == 2 )
        break;
      ++v22;
      v24 = sub_4C2850(&unk_7D2DB0);
      if ( v22 >= sub_4C1370(v24) )
        goto LABEL_47;
    }
    sub_4C2850(&unk_7D2DB0);
    v21 = sub_4C13A0(v22);
  }
  v1 = v21;
  if ( !v21 )
    goto LABEL_47;
  v25 = sub_4C2850(&unk_7D2DB0);
  if ( v1 != sub_4C1390(v25) )
  {
    v26 = *(_DWORD *)(v1 + 408);
    v27 = sub_4C2850(&unk_7D2DB0);
    if ( v26 == *(_DWORD *)(sub_4C1390(v27) + 408) )
      v37 = 1;
  }
  v28 = 0;
  v29 = sub_4C2850(&unk_7D2DB0);
  if ( sub_4C1370(v29) > 0 )
  {
    do
    {
      sub_4C2850(&unk_7D2DB0);
      if ( v1 != sub_4C13A0(v28) )
      {
        v30 = *(_DWORD *)(v1 + 408);
        sub_4C2850(&unk_7D2DB0);
        if ( v30 == *(_DWORD *)(sub_4C13A0(v28) + 408) )
          v37 = 1;
      }
      ++v28;
      v31 = sub_4C2850(&unk_7D2DB0);
    }
    while ( v28 < sub_4C1370(v31) );
  }
  if ( v37 )
  {
LABEL_47:
    result = a1;
    if ( a1 )
      return result;
    goto LABEL_48;
  }
  if ( a1 )
  {
    sub_4144D0(v39);
    v32 = *(char **)(v1 + 8);
    if ( !v32 )
      v32 = &byte_5EA438;
    v33 = *(const char **)v1;
    if ( !*(_DWORD *)v1 )
      v33 = &byte_5EA438;
    v34 = sub_415230((char ****)&dword_5EA5E8, v33, (int)v32);
    sub_4144F0(v39, 397, v34, 3, -1, -1, -2.0, -2.0);
    sub_418560(flt_5EA618, v39);
    goto LABEL_47;
  }
LABEL_48:
  result = v36;
  if ( !v36 )
  {
    result = v37;
    if ( !v37 )
    {
      if ( v2 )
      {
        if ( v1 )
          return sub_4144D0(v39);
      }
    }
  }
  return result;
}
