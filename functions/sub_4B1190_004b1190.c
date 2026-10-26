int __thiscall sub_4B1190(int this, float a2)
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
  int result; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // eax
  int v32; // edx
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // edx
  int v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax

  v3 = *(_DWORD *)(this + 8212);
  v4 = *(_DWORD *)(this + 8216);
  *(_DWORD *)(this + 8204) = 12;
  v5 = *(_DWORD *)(this + 8204);
  if ( v5 >= v3 )
  {
    if ( v5 > v4 )
      *(_DWORD *)(this + 8204) = v4;
  }
  else
  {
    *(_DWORD *)(this + 8204) = v3;
  }
  v6 = *(_DWORD *)(this + 8464);
  v7 = *(_DWORD *)(this + 8468);
  *(_DWORD *)(this + 8456) = 5;
  v8 = *(_DWORD *)(this + 8456);
  if ( v8 >= v6 )
  {
    if ( v8 > v7 )
      *(_DWORD *)(this + 8456) = v7;
  }
  else
  {
    *(_DWORD *)(this + 8456) = v6;
  }
  v9 = *(_DWORD *)(this + 8716);
  v10 = *(_DWORD *)(this + 8720);
  *(_DWORD *)(this + 8708) = 15;
  v11 = *(_DWORD *)(this + 8708);
  if ( v11 >= v9 )
  {
    if ( v11 > v10 )
      *(_DWORD *)(this + 8708) = v10;
  }
  else
  {
    *(_DWORD *)(this + 8708) = v9;
  }
  if ( a2 <= 0.0 )
    a2 = *(float *)(this + 8960);
  if ( a2 < 0.050000001 )
    a2 = 0.050000001;
  v12 = *(char **)(this + 340);
  if ( !v12 )
    v12 = byte_5EA438;
  result = SeasonRacesSectionFinder(v12);
  if ( result )
  {
    v14 = StringKeyedLinkedListSearch(aQualifylaps);
    if ( v14 )
    {
      v15 = DataEntryAccessor(v14);
      v16 = sub_587ECE(v15);
      v17 = *(_DWORD *)(this + 8216);
      *(_DWORD *)(this + 8204) = v16;
      v18 = *(_DWORD *)(this + 8212);
      v19 = *(_DWORD *)(this + 8204);
      if ( v19 >= v18 )
      {
        if ( v19 > v17 )
          *(_DWORD *)(this + 8204) = v17;
      }
      else
      {
        *(_DWORD *)(this + 8204) = v18;
      }
    }
    v20 = StringKeyedLinkedListSearch(aRacelaps);
    if ( v20 )
    {
      v21 = DataEntryAccessor(v20);
      v22 = sub_587ECE(v21);
      v23 = *(_DWORD *)(this + 8468);
      *(_DWORD *)(this + 8456) = v22;
      v24 = *(_DWORD *)(this + 8464);
      v25 = *(_DWORD *)(this + 8456);
      if ( v25 >= v24 )
      {
        if ( v25 > v23 )
          *(_DWORD *)(this + 8456) = v23;
      }
      else
      {
        *(_DWORD *)(this + 8456) = v24;
      }
      v26 = CRTFtol((double)*(int *)(this + 8456) * a2);
      if ( v26 < 1 )
        v26 = 1;
      v27 = *(_DWORD *)(this + 8468);
      *(_DWORD *)(this + 8456) = v26;
      v28 = *(_DWORD *)(this + 8464);
      v29 = *(_DWORD *)(this + 8456);
      if ( v29 >= v28 )
      {
        if ( v29 > v27 )
          *(_DWORD *)(this + 8456) = v27;
      }
      else
      {
        *(_DWORD *)(this + 8456) = v28;
      }
    }
    v38 = StringKeyedLinkedListSearch(aReconPitOpen);
    if ( v38 )
    {
      v39 = DataEntryAccessor(v38);
      dword_7CEC30 = sub_587ECE(v39);
    }
    v40 = StringKeyedLinkedListSearch(aReconPitClosed);
    if ( v40 )
    {
      v41 = DataEntryAccessor(v40);
      dword_7CEC54 = sub_587ECE(v41);
    }
    result = StringKeyedLinkedListSearch(aRacetime);
    if ( result )
    {
      v30 = DataEntryAccessor(result);
      v31 = sub_587ECE(v30);
      v32 = *(_DWORD *)(this + 8720);
      *(_DWORD *)(this + 8708) = v31;
      v33 = *(_DWORD *)(this + 8716);
      v34 = *(_DWORD *)(this + 8708);
      if ( v34 >= v33 )
      {
        if ( v34 > v32 )
          *(_DWORD *)(this + 8708) = v32;
      }
      else
      {
        *(_DWORD *)(this + 8708) = v33;
      }
      v35 = CRTFtol((double)*(int *)(this + 8708) * a2 + 0.5);
      v36 = *(_DWORD *)(this + 8720);
      *(_DWORD *)(this + 8708) = v35;
      result = *(_DWORD *)(this + 8716);
      v37 = *(_DWORD *)(this + 8708);
      if ( v37 >= result )
      {
        if ( v37 > v36 )
          *(_DWORD *)(this + 8708) = v36;
      }
      else
      {
        *(_DWORD *)(this + 8708) = result;
      }
    }
  }
  return result;
}
