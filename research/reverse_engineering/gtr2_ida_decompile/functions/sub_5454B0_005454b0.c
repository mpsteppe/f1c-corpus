int __userpurge sub_5454B0@<eax>(int a1@<ecx>, int a2@<edi>, int a3, int a4)
{
  unsigned int v4; // kr00_4
  unsigned int v5; // ecx
  _DWORD *v7; // edi
  int v8; // ecx
  int (**v9)[512]; // edi
  float *v10; // esi
  bool v11; // zf
  const char *v12; // edi
  float *v13; // esi
  bool v14; // zf
  const char *v15; // edi
  float *v16; // esi
  bool v17; // zf
  const char *v18; // edi
  float *v19; // esi
  bool v20; // zf
  const char *v21; // edi
  float *v22; // esi
  bool v23; // zf
  const char *v24; // edi
  float *v25; // esi
  bool v26; // zf
  const char *v27; // edi
  float *v28; // esi
  bool v29; // zf
  int v30; // eax
  const char *v31; // edi
  float *v32; // esi
  bool v33; // zf
  const char *v34; // edi
  float *v35; // esi
  bool v36; // zf
  int result; // eax
  char *v38; // edx
  char v39; // al
  char *v40; // eax
  char v41; // cl
  char *v42; // eax
  char v43; // cl
  char *v44; // [esp+8Ch] [ebp-11Ch] BYREF
  float *p_String1; // [esp+90h] [ebp-118h]
  int v46; // [esp+94h] [ebp-114h]
  int v47; // [esp+A4h] [ebp-104h]
  float String1; // [esp+A8h] [ebp-100h] BYREF
  char v49; // [esp+ACh] [ebp-FCh] BYREF

  v46 = 0;
  p_String1 = &String1;
  v44 = "LEGAL";
  if ( sub_6137E0(a3) && !_stricmp((const char *)&String1, "TRUE") )
    *(_BYTE *)(a1 + 92) = 1;
  v46 = a2;
  p_String1 = (float *)a4;
  v7 = (_DWORD *)(a1 + 8);
  v44 = (char *)(a1 + 8);
  v47 = 0;
  if ( sub_5429C0(a3) )
    *(_DWORD *)(a1 + 12) = *v7;
  v46 = a4;
  p_String1 = &String1;
  v44 = "WET";
  if ( sub_5429C0(a3) )
    *(float *)(a1 + 12) = *(float *)v7 - String1;
  sub_5429C0(a3);
  v46 = a4;
  p_String1 = (float *)(a1 + 20);
  v44 = "BUMPAMP";
  if ( sub_5429C0(a3) )
    *(float *)(a1 + 20) = *(float *)(a1 + 20) * 0.25;
  v46 = a4;
  p_String1 = &String1;
  v44 = "BUMPWAVELEN";
  if ( sub_5429C0(a3) )
  {
    if ( String1 < 2.0 && String1 < 0.40000001 )
      String1 = 0.40000001;
    *(float *)(a1 + 24) = 6.283185307179586 / String1;
  }
  sub_5429C0(a3);
  sub_5429C0(a3);
  sub_5429C0(a3);
  sub_613240("SPARKS", a1 + 40, 0, 0, 0);
  sub_613240("SCRAPING", a1 + 41, 0, 0, 0);
  sub_613240("WALLSKIDS", a1 + 42, 0, 0, 0);
  v46 = a4;
  p_String1 = &String1;
  v44 = "SINK";
  if ( sub_5429C0(a3) )
    *(double *)(a1 + 96) = String1;
  v46 = 0;
  p_String1 = (float *)&v49;
  v44 = "SOUND";
  if ( sub_6137E0(a3) )
  {
    v9 = &off_71E920;
    v10 = &String1;
    v8 = 4;
    v11 = 1;
    do
    {
      if ( !v8 )
        break;
      v11 = *(_BYTE *)v10 == *(_BYTE *)v9;
      v10 = (float *)((char *)v10 + 1);
      v9 = (int (**)[512])((char *)v9 + 1);
      --v8;
    }
    while ( v11 );
    if ( v11 )
    {
      *(_DWORD *)(a1 + 44) = 18;
      *(_DWORD *)(a1 + 48) = 35;
      *(_DWORD *)(a1 + 52) = 41;
      goto LABEL_63;
    }
    v12 = "WET";
    v13 = &String1;
    v8 = 4;
    v14 = 1;
    do
    {
      if ( !v8 )
        break;
      v14 = *(_BYTE *)v13 == *v12;
      v13 = (float *)((char *)v13 + 1);
      ++v12;
      --v8;
    }
    while ( v14 );
    if ( v14 )
    {
      *(_DWORD *)(a1 + 44) = 19;
      *(_DWORD *)(a1 + 48) = 36;
      *(_DWORD *)(a1 + 52) = 41;
      goto LABEL_63;
    }
    v15 = "DIRT";
    v16 = &String1;
    v8 = 5;
    v17 = 1;
    do
    {
      if ( !v8 )
        break;
      v17 = *(_BYTE *)v16 == *v15;
      v16 = (float *)((char *)v16 + 1);
      ++v15;
      --v8;
    }
    while ( v17 );
    if ( v17 )
    {
      *(_DWORD *)(a1 + 44) = 21;
      *(_DWORD *)(a1 + 48) = 38;
      *(_DWORD *)(a1 + 52) = 46;
      goto LABEL_63;
    }
    v18 = "GRASS";
    v19 = &String1;
    v8 = 6;
    v20 = 1;
    do
    {
      if ( !v8 )
        break;
      v20 = *(_BYTE *)v19 == *v18;
      v19 = (float *)((char *)v19 + 1);
      ++v18;
      --v8;
    }
    while ( v20 );
    if ( v20 )
    {
      *(_DWORD *)(a1 + 44) = 20;
      *(_DWORD *)(a1 + 48) = 37;
      *(_DWORD *)(a1 + 52) = 46;
      goto LABEL_63;
    }
    v21 = "GRAVEL";
    v22 = &String1;
    v8 = 7;
    v23 = 1;
    do
    {
      if ( !v8 )
        break;
      v23 = *(_BYTE *)v22 == *v21;
      v22 = (float *)((char *)v22 + 1);
      ++v21;
      --v8;
    }
    while ( v23 );
    if ( v23 )
    {
      *(_DWORD *)(a1 + 44) = 22;
      *(_DWORD *)(a1 + 48) = 39;
      *(_DWORD *)(a1 + 52) = 46;
      goto LABEL_63;
    }
    v24 = "RUMBLE";
    v25 = &String1;
    v8 = 7;
    v26 = 1;
    do
    {
      if ( !v8 )
        break;
      v26 = *(_BYTE *)v25 == *v24;
      v25 = (float *)((char *)v25 + 1);
      ++v24;
      --v8;
    }
    while ( v26 );
    if ( v26 )
    {
      *(_DWORD *)(a1 + 44) = 23;
      *(_DWORD *)(a1 + 48) = 35;
      *(_DWORD *)(a1 + 52) = 41;
      goto LABEL_63;
    }
    v27 = "TIREWALL";
    v28 = &String1;
    v8 = 9;
    v29 = 1;
    do
    {
      if ( !v8 )
        break;
      v29 = *(_BYTE *)v28 == *v27;
      v28 = (float *)((char *)v28 + 1);
      ++v27;
      --v8;
    }
    while ( v29 );
    if ( v29 )
    {
      v30 = 46;
LABEL_62:
      *(_DWORD *)(a1 + 44) = v30;
      *(_DWORD *)(a1 + 48) = v30;
      *(_DWORD *)(a1 + 52) = v30;
      goto LABEL_63;
    }
    v31 = "SOLIDWALL";
    v32 = &String1;
    v8 = 10;
    v33 = 1;
    do
    {
      if ( !v8 )
        break;
      v33 = *(_BYTE *)v32 == *v31;
      v32 = (float *)((char *)v32 + 1);
      ++v31;
      --v8;
    }
    while ( v33 );
    if ( v33 )
      goto LABEL_61;
    v34 = "GUARDRAIL";
    v35 = &String1;
    v8 = 10;
    v36 = 1;
    do
    {
      if ( !v8 )
        break;
      v36 = *(_BYTE *)v35 == *v34;
      v35 = (float *)((char *)v35 + 1);
      ++v34;
      --v8;
    }
    while ( v36 );
    if ( v36 )
    {
LABEL_61:
      v30 = 41;
      goto LABEL_62;
    }
  }
LABEL_63:
  p_String1 = &String1;
  v44 = (char *)v8;
  v4 = __readeflags();
  v5 = (unsigned int)off_16DDD83 ^ (unsigned int)off_16C6EC4;
  __writeeflags(v4);
  _InterlockedExchange((volatile __int32 *)&v44, v5);
  result = sub_6131C0(v44, (int)p_String1);
  if ( result )
  {
    _strupr((char *)&String1);
    if ( LOBYTE(String1) )
    {
      v38 = (char *)&String1 + 1;
      do
      {
        v39 = *(v38 - 1);
        if ( v39 == 32 )
        {
          v40 = v38;
          do
          {
            v41 = *v40;
            *(v40 - 1) = *v40;
            ++v40;
          }
          while ( v41 );
        }
        else if ( v39 == 44 && (*v38 == 44 || !*v38) )
        {
          v42 = v38;
          do
          {
            v43 = *v42;
            *(v42 - 1) = *v42;
            ++v42;
          }
          while ( v43 );
        }
        else
        {
          ++v38;
        }
      }
      while ( *(v38 - 1) );
    }
    return sub_615860(&String1);
  }
  return result;
}
