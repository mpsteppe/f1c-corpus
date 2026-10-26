int __fastcall sub_68688F(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // ebx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  _DWORD *v19; // ecx
  int v20; // esi
  unsigned int v21; // ebx
  unsigned int v22; // edi
  unsigned int v23; // edi
  unsigned int v24; // edx
  unsigned int v26; // edx
  int v27; // ebx
  _DWORD *v28; // eax
  int v29; // esi
  unsigned int v30; // ecx
  unsigned int v31; // edi
  unsigned int v32; // [esp+Ch] [ebp-14h]
  unsigned int v33; // [esp+10h] [ebp-10h]
  unsigned int v34; // [esp+14h] [ebp-Ch]
  unsigned int v35; // [esp+18h] [ebp-8h]
  unsigned int v36; // [esp+1Ch] [ebp-4h]
  _DWORD *v37; // [esp+1Ch] [ebp-4h]
  _DWORD *v38; // [esp+28h] [ebp+8h]
  unsigned int v39; // [esp+28h] [ebp+8h]
  unsigned int v40; // [esp+2Ch] [ebp+Ch]
  unsigned int v41; // [esp+2Ch] [ebp+Ch]

  v4 = a4;
  v5 = *(_DWORD *)(a4 + 24);
  v6 = *(_DWORD **)(v5 + 4 * a1);
  v7 = *(_DWORD **)(v5 + 4 * a3);
  if ( *v6 < *v7 )
    return -1;
  if ( *v6 <= *v7 )
  {
    v36 = 0;
    if ( v6[3] )
    {
      v8 = v6[4] - v7[4];
      v38 = (_DWORD *)v7[4];
      while ( 1 )
      {
        v9 = *(_DWORD *)(v4 + 20);
        v10 = *(_DWORD **)(v9 + 4 * *(_DWORD *)((char *)v38 + v8));
        v11 = *(_DWORD **)(v9 + 4 * *v38);
        v12 = v10[1];
        v13 = v11[1];
        if ( v12 < v13 )
          return -1;
        if ( v12 > v13 )
          return 1;
        v14 = v10[5];
        v15 = v11[5];
        if ( v14 < v15 )
          return -1;
        if ( v14 > v15 )
          return 1;
        v16 = v10[6];
        v17 = v11[6];
        if ( v16 < v17 )
          return -1;
        if ( v16 > v17 )
          return 1;
        ++v36;
        ++v38;
        v4 = a4;
        if ( v36 >= v6[3] )
          break;
        v8 = v6[4] - v7[4];
      }
    }
    if ( sub_680DDB(v6) )
    {
      v32 = *v6 & 0xFFFFF;
      v35 = 0;
      if ( v32 )
      {
        v18 = *(_DWORD *)(v4 + 20);
        v37 = (_DWORD *)v7[2];
        v19 = &v37[*v6 & 0xFFFFF];
        v20 = v6[2] - (_DWORD)v37;
        while ( 1 )
        {
          v21 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v37 + v20)) + 48);
          v22 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v19 + v20)) + 48);
          v34 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v37) + 48);
          v33 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v19) + 48);
          v40 = v21;
          if ( v21 < v22
            || (v40 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v19 + v20)) + 48),
                v39 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v37 + v20)) + 48),
                v21 <= v22) )
          {
            v39 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v19 + v20)) + 48);
          }
          v23 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v37) + 48);
          v24 = v23;
          if ( v34 < v33 || (v24 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v19) + 48), v34 <= v33) )
            v23 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v19) + 48);
          if ( v40 < v24 )
            break;
          if ( v40 > v24 )
            return 1;
          if ( v39 < v23 )
            break;
          if ( v39 > v23 )
            return 1;
          ++v35;
          ++v37;
          ++v19;
          if ( v35 >= v32 )
            return 0;
        }
        return -1;
      }
    }
    else
    {
      v26 = v6[1];
      v41 = 0;
      if ( v26 )
      {
        v27 = *(_DWORD *)(v4 + 20);
        v28 = (_DWORD *)v7[2];
        v29 = v6[2] - (_DWORD)v28;
        while ( 1 )
        {
          v30 = *(_DWORD *)(*(_DWORD *)(v27 + 4 * *(_DWORD *)((char *)v28 + v29)) + 48);
          v31 = *(_DWORD *)(*(_DWORD *)(v27 + 4 * *v28) + 48);
          if ( v30 < v31 )
            break;
          if ( v30 > v31 )
            return 1;
          ++v41;
          ++v28;
          if ( v41 >= v26 )
            return 0;
        }
        return -1;
      }
    }
    return 0;
  }
  return 1;
}
