void __thiscall sub_658A3E(int this, int a2, int a3, int a4)
{
  void *v5; // edi
  unsigned int v6; // esi
  bool v7; // zf
  int v8; // edi
  void *v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // edi
  bool v16; // cf
  unsigned int v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int i; // ecx
  unsigned int v22; // ecx
  int v23; // edx
  _DWORD *v24; // edi
  _DWORD *v25; // esi
  int v26; // edi
  unsigned int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // edx
  _DWORD *v30; // esi
  _DWORD *v31; // edi
  unsigned int v32; // eax
  int v33; // edx
  _DWORD *v34; // edi
  _DWORD *v35; // esi
  int v36; // eax
  _DWORD v37[4]; // [esp+8h] [ebp-20h] BYREF
  unsigned int v38; // [esp+18h] [ebp-10h]
  unsigned int v39; // [esp+1Ch] [ebp-Ch]
  unsigned int v40; // [esp+20h] [ebp-8h]
  unsigned int v41; // [esp+24h] [ebp-4h]
  unsigned int v42; // [esp+30h] [ebp+8h]
  unsigned int j; // [esp+30h] [ebp+8h]
  int v44; // [esp+34h] [ebp+Ch]
  int v45; // [esp+34h] [ebp+Ch]
  int v46; // [esp+38h] [ebp+10h]

  v42 = *(_DWORD *)(this + 64) + a2;
  v44 = *(_DWORD *)(this + 76) + a3;
  if ( !*(_DWORD *)(this + 248) )
  {
    v5 = operator new(8 * *(_DWORD *)(this + 228) * *(_DWORD *)(this + 224));
    *(_DWORD *)(this + 248) = v5;
    if ( !v5 )
      return;
    memset(v5, 0, 8 * *(_DWORD *)(this + 228) * *(_DWORD *)(this + 224));
  }
  v6 = *(_DWORD *)(this + 248)
     + 8 * (((v42 - *(_DWORD *)(this + 200)) >> 2) + *(_DWORD *)(this + 224) * (v44 - *(_DWORD *)(this + 212)));
  v7 = *(_DWORD *)(v6 + 4) == 0;
  v41 = v6;
  if ( v7 )
  {
    v8 = 16 * *(_DWORD *)(this + 220);
    v9 = operator new(*(_DWORD *)(this + 220) << 8);
    v38 = (unsigned int)v9;
    if ( v9 )
    {
      sub_41D1B0((int)v9, 16, v8, (int)sub_681563);
      v10 = v38;
    }
    else
    {
      v10 = 0;
    }
    *(_DWORD *)(v6 + 4) = v10;
    if ( !v10 )
      return;
    *(_DWORD *)v6 = 0;
    ++*(_DWORD *)(this + 244);
  }
  if ( !*(_DWORD *)v6 )
  {
    v11 = *(_DWORD *)(this + 64);
    v12 = v42 & 0xFFFFFFFC;
    v38 = v42 & 0xFFFFFFFC;
    if ( ((v42 & 0xFFFFFFFC) >= v11 || v11 <= *(_DWORD *)(this + 152))
      && ((v13 = *(_DWORD *)(this + 72), (v42 & 0xFFFFFFFC) + 4 <= v13) || v13 >= *(_DWORD *)(this + 160)) )
    {
      v17 = *(_DWORD *)(this + 196);
      v18 = *(_DWORD *)(this + 60);
      if ( v17 < v18 && v18 > *(_DWORD *)(this + 148) )
      {
        (*(void (__stdcall **)(_DWORD, unsigned int))(this + 140))(
          *(_DWORD *)(v6 + 4),
          *(_DWORD *)(this + 32)
        + v44 * *(_DWORD *)(this + 100)
        + *(_DWORD *)(this + 96) * (v42 >> 2)
        + *(_DWORD *)(this + 136) * (v17 >> 2));
        v12 = v38;
      }
      v19 = *(_DWORD *)(this + 204);
      v20 = *(_DWORD *)(this + 68);
      if ( v19 <= v20 || v20 >= *(_DWORD *)(this + 156) )
        goto LABEL_25;
      (*(void (__stdcall **)(_DWORD, unsigned int))(this + 140))(
        *(_DWORD *)(v6 + 4),
        *(_DWORD *)(this + 32)
      + v44 * *(_DWORD *)(this + 100)
      + *(_DWORD *)(this + 96) * (v42 >> 2)
      + *(_DWORD *)(this + 136) * ((v19 - 4) >> 2));
    }
    else
    {
      v14 = *(_DWORD *)(this + 196);
      v15 = *(_DWORD *)(this + 32)
          + v44 * *(_DWORD *)(this + 100)
          + *(_DWORD *)(this + 136) * (v14 >> 2)
          + *(_DWORD *)(this + 96) * (v42 >> 2);
      v16 = v14 < *(_DWORD *)(this + 204);
      v40 = *(_DWORD *)(v6 + 4);
      v39 = v14;
      if ( !v16 )
        goto LABEL_25;
      do
      {
        (*(void (__stdcall **)(unsigned int, int))(this + 140))(v40, v15);
        v39 += 4;
        v15 += *(_DWORD *)(this + 136);
        v40 += 256;
      }
      while ( v39 < *(_DWORD *)(this + 204) );
    }
    v12 = v38;
LABEL_25:
    for ( i = 0; i < 4; ++i )
    {
      if ( i + v12 < *(_DWORD *)(this + 64) || i + v12 >= *(_DWORD *)(this + 72) )
        *(_DWORD *)v6 |= 1 << i;
    }
  }
  if ( *(_DWORD *)(this + 84) )
    a4 = sub_64EB2A((_DWORD *)this, a4);
  if ( *(_DWORD *)(this + 16) )
    a4 = sub_650093((_DWORD *)this, a4);
  v22 = *(_DWORD *)(this + 60) - *(_DWORD *)(this + 196);
  v23 = (v42 - *(_DWORD *)(this + 200)) & 3;
  v38 = v22 + *(_DWORD *)(this + 104);
  if ( v22 < v38 )
  {
    do
    {
      v24 = (_DWORD *)(*(_DWORD *)(v6 + 4) + 16 * (v22 & 3 | (4 * (v23 | v22 & 0xFFFFFFFC))));
      v25 = (_DWORD *)a4;
      a4 += 16;
      *v24 = *v25++;
      *++v24 = *v25++;
      *++v24 = *v25;
      v16 = ++v22 < v38;
      v24[1] = v25[1];
      v6 = v41;
    }
    while ( v16 );
  }
  *(_DWORD *)v6 |= 1 << (v42 & 3);
  if ( *(_DWORD *)v6 == 15 )
  {
    v26 = *(_DWORD *)(this + 32)
        + v44 * *(_DWORD *)(this + 100)
        + *(_DWORD *)(this + 136) * (*(_DWORD *)(this + 196) >> 2)
        + *(_DWORD *)(this + 96) * (v42 >> 2);
    v16 = *(_DWORD *)(this + 196) < *(_DWORD *)(this + 204);
    v45 = v26;
    v46 = *(_DWORD *)(v6 + 4);
    v40 = *(_DWORD *)(this + 196);
    if ( v16 )
    {
      memset(v37, 0, 12);
      v37[3] = 1;
      v38 = v42 & 0xFFFFFFFC;
      do
      {
        v27 = *(_DWORD *)(this + 156) - v40;
        v28 = *(_DWORD *)(this + 160) - v38;
        if ( v27 < 4 )
        {
          for ( j = 0; j < v28; v26 = v45 )
          {
            if ( j >= 4 )
              break;
            v29 = v27;
            do
            {
              v30 = (_DWORD *)(v46 + 16 * ((4 * j) | v37[v29]));
              v31 = (_DWORD *)(v46 + 16 * (v29++ | (4 * j)));
              *v31 = *v30++;
              *++v31 = *v30++;
              *++v31 = *v30;
              v31[1] = v30[1];
            }
            while ( v29 < 4 );
            ++j;
            v6 = v41;
          }
        }
        if ( v28 < 4 )
        {
          do
          {
            v32 = 0;
            v33 = 4 * v37[v28];
            do
            {
              v34 = (_DWORD *)(v46 + 16 * (v32 | (4 * v28)));
              v35 = (_DWORD *)(v46 + 16 * (v32++ | v33));
              *v34 = *v35++;
              *++v34 = *v35++;
              *++v34 = *v35;
              v34[1] = v35[1];
            }
            while ( v32 < 4 );
            ++v28;
          }
          while ( v28 < 4 );
          v26 = v45;
          v6 = v41;
        }
        v36 = 0;
        if ( *(_DWORD *)(this + 252) || *(_DWORD *)(this + 92) )
          v36 = 1;
        (*(void (__stdcall **)(int, int, int))(this + 144))(v26, v46, v36);
        v40 += 4;
        v26 += *(_DWORD *)(this + 136);
        v46 += 256;
        v45 = v26;
      }
      while ( v40 < *(_DWORD *)(this + 204) );
    }
    if ( v6 + 8 >= *(_DWORD *)(this + 248) + 8 * *(_DWORD *)(this + 224) * *(_DWORD *)(this + 228)
      || *(_DWORD *)(v6 + 8)
      || *(_DWORD *)(v6 + 12) )
    {
      j__free(*(void **)(v6 + 4));
      --*(_DWORD *)(this + 244);
    }
    else
    {
      *(_DWORD *)(v6 + 12) = *(_DWORD *)(v6 + 4);
      *(_DWORD *)(v6 + 4) = 0;
    }
    *(_DWORD *)(v6 + 4) = 0;
  }
}
