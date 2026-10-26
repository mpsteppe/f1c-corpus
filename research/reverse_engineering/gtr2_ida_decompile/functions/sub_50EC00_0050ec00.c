char __thiscall sub_50EC00(int this, float a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  char *v12; // eax
  _DWORD *v13; // eax
  char *v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  _DWORD *v19; // eax
  char *v20; // eax
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  unsigned __int64 v25; // rax
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  _DWORD *v29; // eax
  char *v30; // eax
  int v31; // eax
  int v32; // edx
  int v33; // eax
  int v34; // ecx
  unsigned __int64 v35; // rax
  int v36; // edx
  int v37; // eax
  int v38; // ecx
  int v39; // edx
  _DWORD *v40; // eax
  char *v41; // eax
  int v42; // eax
  unsigned __int64 v43; // rax
  int v44; // edx
  int v45; // eax
  int v46; // ecx
  int v47; // edx
  int v48; // ecx
  int v50; // [esp+4h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(this + 12208);
  v4 = *(_DWORD *)(this + 12212);
  *(_DWORD *)(this + 12200) = 12;
  v5 = *(_DWORD *)(this + 12200);
  if ( v5 >= v3 )
  {
    if ( v5 > v4 )
      *(_DWORD *)(this + 12200) = v4;
  }
  else
  {
    *(_DWORD *)(this + 12200) = v3;
  }
  v6 = *(_DWORD *)(this + 12532);
  v7 = *(_DWORD *)(this + 12536);
  *(_DWORD *)(this + 12524) = 15;
  v8 = *(_DWORD *)(this + 12524);
  if ( v8 >= v6 )
  {
    if ( v8 > v7 )
      *(_DWORD *)(this + 12524) = v7;
  }
  else
  {
    *(_DWORD *)(this + 12524) = v6;
  }
  v9 = *(_DWORD *)(this + 12856);
  v10 = *(_DWORD *)(this + 12860);
  *(_DWORD *)(this + 12848) = 30;
  v11 = *(_DWORD *)(this + 12848);
  if ( v11 >= v9 )
  {
    if ( v11 > v10 )
      *(_DWORD *)(this + 12848) = v10;
  }
  else
  {
    *(_DWORD *)(this + 12848) = v9;
  }
  if ( a2 <= 0.0 )
  {
    if ( *(_BYTE *)(this + 11700) )
      a2 = *(float *)(this + 13520);
    else
      a2 = *(float *)(this + 13172);
  }
  if ( a2 < 0.029999999 )
    a2 = 0.029999999;
  v12 = *(char **)(this + 376);
  if ( !v12 )
    v12 = (char *)WindowName;
  if ( sub_53A250(v12) )
  {
    v13 = (_DWORD *)sub_616630("QualifyLaps");
    if ( v13 )
    {
      v14 = sub_48D380(v13);
      v15 = atol(v14);
      v16 = *(_DWORD *)(this + 12212);
      *(_DWORD *)(this + 12200) = v15;
      v17 = *(_DWORD *)(this + 12208);
      v18 = *(_DWORD *)(this + 12200);
      if ( v18 >= v17 )
      {
        if ( v18 > v16 )
          *(_DWORD *)(this + 12200) = v16;
      }
      else
      {
        *(_DWORD *)(this + 12200) = v17;
      }
    }
    v19 = (_DWORD *)sub_616630("RaceLaps");
    if ( v19 )
    {
      v20 = sub_48D380(v19);
      v21 = atol(v20);
      v22 = *(_DWORD *)(this + 12536);
      *(_DWORD *)(this + 12524) = v21;
      v23 = *(_DWORD *)(this + 12532);
      v24 = *(_DWORD *)(this + 12524);
      if ( v24 >= v23 )
      {
        if ( v24 > v22 )
          *(_DWORD *)(this + 12524) = v22;
      }
      else
      {
        *(_DWORD *)(this + 12524) = v23;
      }
      v25 = (unsigned __int64)((double)*(int *)(this + 12524) * a2);
      if ( (int)v25 < 3 )
        LODWORD(v25) = 3;
      HIDWORD(v25) = *(_DWORD *)(this + 12536);
      *(_DWORD *)(this + 12524) = v25;
      v27 = *(_DWORD *)(this + 12532);
      v28 = *(_DWORD *)(this + 12524);
      if ( v28 >= v27 )
      {
        if ( v28 > v26 )
          *(_DWORD *)(this + 12524) = v26;
      }
      else
      {
        *(_DWORD *)(this + 12524) = v27;
      }
    }
    v29 = (_DWORD *)sub_616630("RaceTime");
    if ( v29 )
    {
      v30 = sub_48D380(v29);
      v31 = atol(v30);
      v32 = *(_DWORD *)(this + 12860);
      *(_DWORD *)(this + 12848) = v31;
      v33 = *(_DWORD *)(this + 12856);
      v34 = *(_DWORD *)(this + 12848);
      if ( v34 >= v33 )
      {
        if ( v34 > v32 )
          *(_DWORD *)(this + 12848) = v32;
      }
      else
      {
        *(_DWORD *)(this + 12848) = v33;
      }
      v35 = (unsigned __int64)((double)*(int *)(this + 12848) * a2 + 0.5);
      v36 = *(_DWORD *)(this + 12860);
      *(_DWORD *)(this + 12848) = v35;
      v37 = *(_DWORD *)(this + 12856);
      v38 = *(_DWORD *)(this + 12848);
      if ( v38 >= v37 )
      {
        if ( v38 > v36 )
          *(_DWORD *)(this + 12848) = v36;
      }
      else
      {
        *(_DWORD *)(this + 12848) = v37;
      }
    }
    if ( sub_616840("SceneOrder") )
    {
      v39 = dword_BE1CD8 + 396 * dword_BE1CD4;
      if ( v39 )
      {
        if ( sub_616630((char *)(v39 + 260)) )
        {
          v40 = (_DWORD *)sub_616630("RaceLaps");
          if ( v40 )
          {
            v41 = sub_48D380(v40);
            v50 = atol(v41);
            sub_4762A0(dword_B72608, &v50);
          }
        }
      }
    }
  }
  LOBYTE(v42) = *(_BYTE *)(this + 11700);
  if ( (_BYTE)v42 )
  {
    v43 = (unsigned __int64)(a2 * 1440.0 + 0.5);
    v44 = *(_DWORD *)(this + 12860);
    *(_DWORD *)(this + 12848) = v43;
    v45 = *(_DWORD *)(this + 12856);
    v46 = *(_DWORD *)(this + 12848);
    if ( v46 >= v45 )
    {
      if ( v46 > v44 )
        *(_DWORD *)(this + 12848) = v44;
    }
    else
    {
      *(_DWORD *)(this + 12848) = v45;
    }
    v42 = *(_DWORD *)(this + 12532);
    v47 = *(_DWORD *)(this + 12536);
    *(_DWORD *)(this + 12524) = 0x7FFFFFFF;
    v48 = *(_DWORD *)(this + 12524);
    if ( v48 >= v42 )
    {
      if ( v48 > v47 )
        *(_DWORD *)(this + 12524) = v47;
    }
    else
    {
      *(_DWORD *)(this + 12524) = v42;
    }
  }
  return v42;
}
