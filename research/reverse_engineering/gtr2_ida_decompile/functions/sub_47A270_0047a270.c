int __thiscall sub_47A270(int *this)
{
  int *v1; // esi
  int v2; // eax
  bool v3; // zf
  int v4; // ecx
  bool v5; // dl
  int v6; // edi
  int v7; // ebx
  int v8; // ebp
  int *v9; // eax
  int *v10; // esi
  int **v11; // eax
  bool v12; // cf
  int v13; // eax
  int v14; // edx
  int i; // ecx
  int v16; // edx
  unsigned int j; // ecx
  int *v18; // eax
  int v19; // ecx
  int v20; // eax
  int v22; // [esp+Ch] [ebp-2Ch]
  int v23; // [esp+10h] [ebp-28h]
  int v25; // [esp+18h] [ebp-20h]
  int v26; // [esp+1Ch] [ebp-1Ch] BYREF
  int **v27; // [esp+20h] [ebp-18h]
  int **v28; // [esp+24h] [ebp-14h]
  int v29; // [esp+28h] [ebp-10h]
  int v30; // [esp+34h] [ebp-4h]

  v1 = this;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v2 = *this;
  v3 = *(_DWORD *)(*this + 112884) == 0;
  v30 = 0;
  v25 = 0;
  if ( !v3 )
  {
    v4 = 0;
    v23 = 0;
    v22 = 112052;
    do
    {
      v5 = (*(_BYTE *)(v4 + v2 + 2752) & 2) != 0 && *(_DWORD *)(v4 + v2 + 2228) == 3;
      if ( *(_DWORD *)(v4 + v2 + 2228) == 3 )
      {
        if ( v5 )
          v6 = *(char *)(v4 + v2 + 2740);
        else
          v6 = -1;
        v7 = *(_DWORD *)(v22 + v2);
        if ( v6 < 0 )
          v8 = -1;
        else
          v8 = dword_925014[5654 * v6];
        v9 = (int *)operator new(0xCu);
        v10 = v9;
        if ( v9 )
        {
          *v9 = v6;
          v9[1] = v7;
          v9[2] = v8;
          v11 = (int **)operator new(0xCu);
          if ( v11 )
          {
            *v11 = v10;
            v11[1] = 0;
            *((_BYTE *)v11 + 8) = 1;
          }
          else
          {
            v11 = 0;
          }
          if ( v26 )
          {
            v27[1] = (int *)v11;
          }
          else
          {
            v26 = (int)v11;
            v28 = v11;
          }
          v27 = v11;
          ++v29;
        }
        v1 = this;
        v4 = v23;
      }
      v22 += 4;
      v2 = *v1;
      v4 += 528;
      v12 = (unsigned int)++v25 < *(_DWORD *)(*v1 + 112884);
      v23 = v4;
    }
    while ( v12 );
  }
  v13 = sub_478DB0(v26);
  v26 = v13;
  v14 = v13;
  if ( v13 )
  {
    for ( i = *(_DWORD *)(v13 + 4); i; i = *(_DWORD *)(i + 4) )
      v14 = i;
  }
  v27 = (int **)v14;
  v16 = 0;
  for ( j = 0; j < 588016; j += 5654 )
    dword_925014[j] = ++v16;
  v28 = (int **)v13;
  if ( v13 )
    v18 = *(int **)v13;
  else
    v18 = 0;
  v19 = 1;
  if ( v18 )
  {
    do
    {
      *(_DWORD *)(*v1 + 4 * v19 + 113346) = v18[1];
      v20 = *v18;
      if ( v20 >= 0 )
        dword_925014[5654 * v20] = v19;
      ++v19;
      if ( !v28 )
        break;
      v28 = (int **)v28[1];
      if ( !v28 )
        break;
      v18 = *v28;
    }
    while ( *v28 );
  }
  *(_BYTE *)(*v1 + 113349) = v19 - 1;
  return sub_525140(&v26);
}
