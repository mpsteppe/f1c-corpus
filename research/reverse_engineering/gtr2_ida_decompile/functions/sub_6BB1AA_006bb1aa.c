int __thiscall sub_6BB1AA(_DWORD *this, int *a2, int a3, unsigned int a4, int *a5, _DWORD *a6, int a7, int a8)
{
  int *v8; // ebx
  int v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // esi
  int v14; // edx
  int v15; // edi
  _DWORD *v16; // ecx
  int v17; // eax
  int v18; // eax
  _DWORD *v19; // eax
  int v20; // esi
  unsigned int v21; // ecx
  unsigned int v23; // esi
  int v24; // edi
  unsigned int i; // eax
  int v26; // edx
  int v27; // esi
  int v28; // eax
  int v29; // ecx
  _DWORD v30[4]; // [esp+Ch] [ebp-40h]
  _DWORD v31[4]; // [esp+1Ch] [ebp-30h] BYREF
  int v32; // [esp+2Ch] [ebp-20h]
  int v33; // [esp+30h] [ebp-1Ch]
  int j; // [esp+34h] [ebp-18h]
  int v35; // [esp+38h] [ebp-14h]
  unsigned int v36; // [esp+3Ch] [ebp-10h]
  int v37; // [esp+40h] [ebp-Ch]
  int v38; // [esp+44h] [ebp-8h]
  int *v39; // [esp+48h] [ebp-4h]

  v8 = a2;
  v9 = *a2;
  memset(v31, 0, sizeof(v31));
  v32 = v9;
  if ( (v9 & 0xFFF00000) == 0x50000000 || (v9 & 0xFFF00000) == 0x70800000 )
  {
    v23 = v9 & 0xFFFFF;
    v24 = 0;
    for ( i = 0; i < 4; ++i )
    {
      if ( i >= v23 )
        a6[i] = 255;
      else
        a6[i] = i;
    }
    if ( a4 )
    {
      v26 = this[5];
      v27 = *(_DWORD *)a2[4];
      while ( 1 )
      {
        v28 = *(_DWORD *)(a3 + 4 * v24);
        v29 = *(_DWORD *)(v26 + 4 * v28);
        if ( (v28 != v27 || *(_DWORD *)(v29 + 60) != a7)
          && (*(_DWORD *)(v29 + 56) != v27 || *(_DWORD *)(v29 + 60) != a7) )
        {
          break;
        }
        if ( ++v24 >= a4 )
          return 0;
      }
      return 1;
    }
  }
  else
  {
    v10 = 0;
    v36 = 0;
    if ( a4 )
    {
      v35 = this[5];
      v11 = a3 - (_DWORD)a5;
      v39 = a5;
      v33 = a3 - (_DWORD)a5;
      do
      {
        v12 = *(int *)((char *)v39 + v11);
        v37 = 0;
        v38 = *(_DWORD *)(v35 + 4 * v12);
        if ( !a8 || (v10 = *v39, (unsigned int)*v39 < 4) )
        {
          v13 = 0;
          if ( !v8[3] )
            return 1;
          v14 = v10;
          v15 = v8[4] - (_DWORD)v31;
          for ( j = v15; ; v15 = j )
          {
            v16 = &v31[v13];
            if ( *(_DWORD *)(v14 * 4 + a3) == *(_DWORD *)((char *)v16 + v15) && *(_DWORD *)(v38 + 60) == a7
              || (v17 = v8[4], v8 = a2, *(_DWORD *)(v38 + 56) == *(_DWORD *)(v17 + 4 * v13))
              && *(_DWORD *)(v38 + 60) == a7 )
            {
              v37 = 1;
              v30[v14] = v13;
              *v16 = 1;
            }
            if ( ++v13 >= (unsigned int)v8[3] )
              break;
          }
          if ( !v37 )
            return 1;
          v11 = v33;
          v9 = v32;
        }
        ++v39;
        v10 = ++v36;
      }
      while ( v36 < a4 );
    }
    if ( !a8 )
    {
      v18 = 0;
      if ( (v9 & 0xFFFFF) != 0 )
      {
        while ( v31[v18] )
        {
          if ( ++v18 >= (v9 & 0xFFFFFu) )
            goto LABEL_23;
        }
        return 1;
      }
    }
LABEL_23:
    v19 = a6;
    v20 = 4;
    do
    {
      v21 = *(_DWORD *)((char *)v19 + (char *)a5 - (char *)a6);
      if ( v21 >= 4 )
        *v19 = 255;
      else
        *v19 = v30[v21];
      ++v19;
      --v20;
    }
    while ( v20 );
  }
  return 0;
}
