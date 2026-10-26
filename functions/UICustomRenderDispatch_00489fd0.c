int __userpurge UICustomRenderDispatch@<eax>(int a1@<ecx>, int *a2@<ebp>, int *a3, int *a4, int *a5, int *a6)
{
  int v7; // eax
  int v8; // ebx
  int v9; // edi
  int v10; // ebp
  int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edi
  int v19; // ebp
  int v20; // ecx
  int v21; // eax
  int v24; // [esp+10h] [ebp-24h]
  int v25; // [esp+14h] [ebp-20h]
  int v26; // [esp+18h] [ebp-1Ch]
  int v27; // [esp+1Ch] [ebp-18h]
  int v28; // [esp+20h] [ebp-14h]
  int v29; // [esp+24h] [ebp-10h]
  int v30; // [esp+28h] [ebp-Ch] BYREF
  int v31; // [esp+2Ch] [ebp-8h] BYREF
  int v32; // [esp+30h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+34h] [ebp+0h] BYREF

  v7 = *(_DWORD *)(a1 + 332);
  v8 = *(_DWORD *)(a1 + 144);
  v9 = 0;
  v24 = 0;
  if ( v7 > 0 )
  {
    do
    {
      if ( !v8 )
        break;
      v8 = *(_DWORD *)(v8 + 140);
      --v7;
      ++v9;
    }
    while ( v7 > 0 );
    v24 = v9;
  }
  sub_489D00((int *)a1);
  v25 = 0;
  if ( *(int *)(a1 + 344) < 1 || *(int *)(a1 + 364) < 1 )
    return -1;
  v27 = *(_DWORD *)(a1 + 356);
  if ( v8 )
  {
    while ( 1 )
    {
      if ( v27 <= 0 )
        return 0;
      v10 = *(_DWORD *)(a1 + 4) + *(_DWORD *)(a1 + 308) + *(_DWORD *)(a1 + 316) + v25 * *(_DWORD *)(a1 + 344);
      v26 = v10;
      if ( (*(int (__thiscall **)(int, int *))(*(_DWORD *)a1 + 24))(a1, a2) <= 0 )
        v29 = *(_DWORD *)(a1 + 16);
      else
        v29 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 24))(a1);
      if ( v9 == *(_DWORD *)(a1 + 360) )
      {
        v11 = *(_DWORD *)(a1 + 200);
        if ( !v11 )
          goto LABEL_31;
        v12 = *(const char **)(v11 + 72);
      }
      else
      {
        v13 = *(const char **)(v8 + 160);
        if ( !v13 )
          v13 = byte_5EA438;
        if ( !strlen(v13) )
          goto LABEL_26;
        v14 = *(const char **)(v8 + 160);
        if ( !v14 )
          v14 = byte_5EA438;
        DriverNameStringHandler(*(_DWORD **)(a1 + 64), v14);
        v15 = *(const char **)(v8 + 160);
        if ( !v15 )
          v15 = byte_5EA438;
        if ( StringArrayMatchSearch(*(_DWORD **)(a1 + 64), v15) )
        {
          v12 = *(const char **)(v8 + 160);
        }
        else
        {
LABEL_26:
          v16 = *(_DWORD *)(a1 + 200);
          if ( !v16 )
            goto LABEL_31;
          v12 = *(const char **)(v16 + 64);
        }
      }
      if ( !v12 )
        v12 = byte_5EA438;
      sub_498560(*(char **)(a1 + 64), v12);
LABEL_31:
      v17 = *(_DWORD *)(a1 + 320);
      v18 = v10 + *(_DWORD *)(a1 + 344);
      v19 = v17 + *(_DWORD *)(a1 + 12);
      *(_BYTE *)(v8 + 228) = *(_BYTE *)(a1 + 305);
      ShortComputation_a9c0((_DWORD *)v8, v27, v18, v19, v29 - v17);
      a2 = &v30;
      (*(void (__thiscall **)(int, _UNKNOWN **, int *, int *))(*(_DWORD *)v8 + 52))(v8, &retaddr, &v32, &v31);
      if ( v25 )
      {
        v20 = *a3;
        if ( v26 < *a3 )
          v20 = v26;
      }
      else
      {
        v20 = v26;
      }
      *a3 = v20;
      if ( v25 && v18 <= *a4 )
        v18 = *a4;
      *a4 = v18;
      if ( v25 && v19 >= *a5 )
        v19 = *a5;
      *a5 = v19;
      if ( v25 )
      {
        v21 = *a6;
        if ( v28 > *a6 )
          v21 = v28;
      }
      else
      {
        v21 = v28;
      }
      *a6 = v21;
      v8 = *(_DWORD *)(v8 + 140);
      --v27;
      ++v24;
      ++v25;
      if ( !v8 )
        return 0;
      v9 = v24;
    }
  }
  return 0;
}
