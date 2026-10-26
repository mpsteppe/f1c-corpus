int __thiscall sub_4CE420(int this, float a2)
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
  int result; // eax
  char *v13; // edx
  int v14; // eax
  const char *v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  const char *v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  __int64 v26; // rax
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  const char *v30; // eax
  int v31; // eax
  int v32; // edx
  int v33; // eax
  int v34; // ecx
  __int64 v35; // rax
  int v36; // edx
  int v37; // ecx

  v3 = *(_DWORD *)(this + 9812);
  v4 = *(_DWORD *)(this + 9816);
  *(_DWORD *)(this + 9804) = 2;
  v5 = *(_DWORD *)(this + 9804);
  if ( v5 >= v3 )
  {
    if ( v5 > v4 )
      *(_DWORD *)(this + 9804) = v4;
  }
  else
  {
    *(_DWORD *)(this + 9804) = v3;
  }
  v6 = *(_DWORD *)(this + 10136);
  v7 = *(_DWORD *)(this + 10140);
  *(_DWORD *)(this + 10128) = 5;
  v8 = *(_DWORD *)(this + 10128);
  if ( v8 >= v6 )
  {
    if ( v8 > v7 )
      *(_DWORD *)(this + 10128) = v7;
  }
  else
  {
    *(_DWORD *)(this + 10128) = v6;
  }
  v9 = *(_DWORD *)(this + 10460);
  v10 = *(_DWORD *)(this + 10464);
  *(_DWORD *)(this + 10452) = 15;
  v11 = *(_DWORD *)(this + 10452);
  if ( v11 >= v9 )
  {
    if ( v11 > v10 )
      *(_DWORD *)(this + 10452) = v10;
  }
  else
  {
    *(_DWORD *)(this + 10452) = v9;
  }
  if ( a2 <= 0.0 )
    a2 = *(float *)(this + 10776);
  result = sub_57AE50(aSeasonraces);
  if ( result )
  {
    v13 = *(char **)(this + 436);
    if ( !v13 )
      v13 = &byte_629120;
    result = sub_57A720(v13);
    if ( result )
    {
      v14 = sub_57A720(aQualifylaps);
      if ( v14 )
      {
        v15 = (const char *)sub_57A6D0(v14);
        v16 = atol(v15);
        v17 = *(_DWORD *)(this + 9816);
        *(_DWORD *)(this + 9804) = v16;
        v18 = *(_DWORD *)(this + 9812);
        v19 = *(_DWORD *)(this + 9804);
        if ( v19 >= v18 )
        {
          if ( v19 > v17 )
            *(_DWORD *)(this + 9804) = v17;
        }
        else
        {
          *(_DWORD *)(this + 9804) = v18;
        }
      }
      v20 = sub_57A720(aRacelaps);
      if ( v20 )
      {
        v21 = (const char *)sub_57A6D0(v20);
        v22 = atol(v21);
        v23 = *(_DWORD *)(this + 10140);
        *(_DWORD *)(this + 10128) = v22;
        v24 = *(_DWORD *)(this + 10136);
        v25 = *(_DWORD *)(this + 10128);
        if ( v25 >= v24 )
        {
          if ( v25 > v23 )
            *(_DWORD *)(this + 10128) = v23;
        }
        else
        {
          *(_DWORD *)(this + 10128) = v24;
        }
        v26 = (__int64)((double)*(int *)(this + 10128) * a2 + 0.5);
        if ( (int)v26 < 3 )
          LODWORD(v26) = 3;
        HIDWORD(v26) = *(_DWORD *)(this + 10140);
        *(_DWORD *)(this + 10128) = v26;
        v28 = *(_DWORD *)(this + 10136);
        v29 = *(_DWORD *)(this + 10128);
        if ( v29 >= v28 )
        {
          if ( v29 > v27 )
            *(_DWORD *)(this + 10128) = v27;
        }
        else
        {
          *(_DWORD *)(this + 10128) = v28;
        }
      }
      result = sub_57A720(aRacetime);
      if ( result )
      {
        v30 = (const char *)sub_57A6D0(result);
        v31 = atol(v30);
        v32 = *(_DWORD *)(this + 10464);
        *(_DWORD *)(this + 10452) = v31;
        v33 = *(_DWORD *)(this + 10460);
        v34 = *(_DWORD *)(this + 10452);
        if ( v34 >= v33 )
        {
          if ( v34 > v32 )
            *(_DWORD *)(this + 10452) = v32;
        }
        else
        {
          *(_DWORD *)(this + 10452) = v33;
        }
        v35 = (__int64)((double)*(int *)(this + 10452) * a2 + 0.5);
        v36 = *(_DWORD *)(this + 10464);
        *(_DWORD *)(this + 10452) = v35;
        result = *(_DWORD *)(this + 10460);
        v37 = *(_DWORD *)(this + 10452);
        if ( v37 >= result )
        {
          if ( v37 > v36 )
            *(_DWORD *)(this + 10452) = v36;
        }
        else
        {
          *(_DWORD *)(this + 10452) = result;
        }
      }
    }
  }
  return result;
}
