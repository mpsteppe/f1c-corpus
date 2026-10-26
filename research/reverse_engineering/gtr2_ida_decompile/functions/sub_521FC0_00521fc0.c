char __thiscall sub_521FC0(int this, int *a2, float a3, float a4)
{
  int *v4; // esi
  const char *v6; // edi
  const char *v7; // edi
  unsigned int v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  unsigned int v15; // ecx
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // edx
  void ***v19; // edi
  int v20; // ebx
  void **v21; // eax
  void *v22; // ecx
  void **v23; // eax
  bool v24; // zf
  void **v25; // eax
  int v26; // eax
  int *v27; // eax
  int v28; // edi
  const char *v29; // eax
  const CHAR *v30; // edi
  int v31; // eax
  int *v32; // eax
  int *v33; // eax
  int v34; // edi
  int v35; // edx
  int v36; // ecx
  double v37; // st7
  int v38; // eax
  int *v39; // eax
  int v40; // edx
  _DWORD *v41; // ebx
  int v42; // edi
  int i; // ebp
  int v45; // [esp+84h] [ebp-2Ch]
  char v46; // [esp+94h] [ebp-1Ch]
  char v47; // [esp+95h] [ebp-1Bh] BYREF
  char v48; // [esp+96h] [ebp-1Ah] BYREF
  char v49; // [esp+97h] [ebp-19h] BYREF
  unsigned int v50; // [esp+98h] [ebp-18h] BYREF
  int v51; // [esp+9Ch] [ebp-14h] BYREF
  int v52; // [esp+A0h] [ebp-10h] BYREF
  int v53; // [esp+A4h] [ebp-Ch] BYREF
  int v54; // [esp+A8h] [ebp-8h] BYREF
  float v55; // [esp+ACh] [ebp-4h] BYREF

  v4 = a2;
  v46 = 1;
  (*(void (__stdcall **)(int))(*a2 + 44))(v45);
  if ( *(_DWORD *)(this + 2892916) == 1 )
  {
    (*(void (__thiscall **)(int *, char *, int))(*v4 + 24))(v4, off_9034C4, 4);
    (*(void (__thiscall **)(int *, float *, int))(*v4 + 24))(v4, &flt_9034C8, 4);
  }
  else
  {
    (*(void (__thiscall **)(int *, char *, int))(*v4 + 24))(v4, off_9034B0, 4);
    (*(void (__thiscall **)(int *, int *, int))(*v4 + 24))(v4, &dword_BE1230, 4);
  }
  v6 = *(const char **)(this + 1900);
  if ( !v6 )
    v6 = WindowName;
  v50 = strlen(v6);
  (*(void (__thiscall **)(int *, unsigned int *, int))(*v4 + 24))(v4, &v50, 4);
  (*(void (__thiscall **)(int *, const char *, unsigned int))(*v4 + 24))(v4, v6, v50);
  v7 = *(const char **)(this + 1908);
  if ( !v7 )
    v7 = WindowName;
  v8 = strlen(v7);
  v9 = *v4;
  v50 = v8;
  (*(void (__thiscall **)(int *, unsigned int *, int))(v9 + 24))(v4, &v50, 4);
  (*(void (__thiscall **)(int *, const char *, unsigned int))(*v4 + 24))(v4, v7, v50);
  v10 = *v4;
  v47 = *(_BYTE *)(this + 2892816);
  (*(void (__thiscall **)(int *, char *, int))(v10 + 24))(v4, &v47, 1);
  v11 = *v4;
  v48 = *(_BYTE *)(this + 2892820);
  (*(void (__thiscall **)(int *, char *, int))(v11 + 24))(v4, &v48, 1);
  v12 = *v4;
  v54 = *(_DWORD *)(this + 2892824);
  (*(void (__thiscall **)(int *, int *, int))(v12 + 24))(v4, &v54, 4);
  if ( !*(_DWORD *)(this + 2892916) )
  {
    v13 = *v4;
    LOBYTE(a2) = *(_BYTE *)(this + 2892828);
    (*(void (__thiscall **)(int *, int **, int))(v13 + 24))(v4, &a2, 1);
    v14 = *v4;
    v51 = dword_B70618[0];
    (*(void (__thiscall **)(int *, int *, int))(v14 + 24))(v4, &v51, 4);
  }
  v15 = 0;
  v16 = (_DWORD *)(this + 124);
  v17 = 21;
  do
  {
    v15 += *v16 + v16[4] + *(v16 - 4) + *(v16 - 8) + *(v16 - 12);
    v16 += 20;
    --v17;
  }
  while ( v17 );
  v18 = *v4;
  v50 = v15;
  (*(void (__thiscall **)(int *, unsigned int *, int))(v18 + 24))(v4, &v50, 4);
  v51 = 0;
  v19 = (void ***)(this + 72);
  v20 = 105;
  do
  {
    v21 = *(v19 - 2);
    *v19 = v21;
    if ( v21 )
    {
      v22 = *v21;
      if ( *v21 )
      {
        do
        {
          sub_5208E0(v22, v4);
          v23 = *v19;
          v24 = *v19 == 0;
          ++v51;
          if ( !v24 )
            *v19 = (void **)v23[1];
          v25 = *v19;
          if ( !*v19 )
            break;
          v22 = *v25;
        }
        while ( *v25 );
      }
    }
    v19 += 4;
    --v20;
  }
  while ( v20 );
  v26 = *v4;
  v49 = *(_BYTE *)(this + 1756);
  (*(void (__thiscall **)(int *, char *, int))(v26 + 24))(v4, &v49, 1);
  v27 = *(int **)(this + 1744);
  *(_DWORD *)(this + 1752) = v27;
  if ( v27 )
  {
    v28 = *v27;
    if ( *v27 )
    {
      do
      {
        (*(void (__thiscall **)(int *, int, int))(*v4 + 24))(v4, v28, 4);
        v29 = *(const char **)(v28 + 4);
        if ( !v29 )
          v29 = WindowName;
        LOBYTE(a2) = strlen(v29);
        (*(void (__thiscall **)(int *, int **, int))(*v4 + 24))(v4, &a2, 1);
        if ( (_BYTE)a2 )
        {
          v30 = *(const CHAR **)(v28 + 4);
          if ( !v30 )
            v30 = WindowName;
          (*(void (__thiscall **)(int *, const CHAR *, _DWORD))(*v4 + 24))(v4, v30, (unsigned __int8)a2);
        }
        v31 = *(_DWORD *)(this + 1752);
        if ( !v31 )
          break;
        v32 = *(int **)(v31 + 4);
        *(_DWORD *)(this + 1752) = v32;
        if ( !v32 )
          break;
        v28 = *v32;
      }
      while ( *v32 );
    }
  }
  if ( v50 != v51 )
    v46 = 0;
  v33 = *(int **)(this + 1884);
  v34 = 0;
  v35 = 0;
  v52 = 0;
  v53 = 0;
  *(_DWORD *)(this + 1892) = v33;
  if ( !v33 )
    return 0;
  v36 = *v33;
  if ( !*v33 )
    return 0;
  do
  {
    v37 = *(float *)v36;
    if ( v37 > a4 )
      break;
    if ( v37 >= a3 )
    {
      if ( !v34 )
        v34 = v36;
      ++v52;
      v35 = v36;
      v53 += *(unsigned __int16 *)(v36 + 8);
    }
    v38 = *(_DWORD *)(this + 1892);
    if ( v38 )
      *(_DWORD *)(this + 1892) = *(_DWORD *)(v38 + 4);
    v39 = *(int **)(this + 1892);
    if ( !v39 )
      break;
    v36 = *v39;
  }
  while ( *v39 );
  if ( !v34 || !v35 )
    return 0;
  (*(void (__thiscall **)(int *, int *, int))(*v4 + 24))(v4, &v52, 4);
  (*(void (__thiscall **)(int *, int *, int))(*v4 + 24))(v4, &v53, 4);
  v40 = *v4;
  v55 = a4 - a3;
  (*(void (__thiscall **)(int *, float *, int))(v40 + 24))(v4, &v55, 4);
  if ( *(_DWORD *)(this + 2892916) == 1 )
  {
    sub_520A90((char *)(this + 2892996), (int)v4);
    v41 = (_DWORD *)(this + 2892928);
    (*(void (__thiscall **)(int *, int, int))(*v4 + 24))(v4, this + 2892928, 4);
    v42 = *(_DWORD *)(this + 2892936);
    for ( i = 0; i < *v41; v42 += 24 )
    {
      (*(void (__thiscall **)(int *, int, int))(*v4 + 24))(v4, v42, 12);
      (*(void (__thiscall **)(int *, int, int))(*v4 + 24))(v4, v42 + 12, 4);
      (*(void (__thiscall **)(int *, int, int))(*v4 + 24))(v4, v42 + 16, 4);
      (*(void (__thiscall **)(int *, int, int))(*v4 + 24))(v4, v42 + 20, 4);
      ++i;
    }
  }
  return v46;
}
