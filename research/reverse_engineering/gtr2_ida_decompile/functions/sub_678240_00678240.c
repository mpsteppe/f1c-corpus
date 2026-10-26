int __stdcall sub_678240(int *a1)
{
  int *v1; // ecx
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v5; // eax
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebx
  int v9; // eax
  unsigned __int8 *v10; // edi
  bool v11; // zf
  unsigned __int8 v12; // si
  int v13; // eax
  int v14; // ecx
  int v15; // esi
  int v16; // eax
  int *v17; // ecx
  int v18; // eax
  int v19; // esi
  __int16 v20; // dx
  __int16 v21; // dx
  unsigned __int16 *v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v27; // [esp+Ch] [ebp-18h]
  int v28; // [esp+10h] [ebp-14h]
  int *v29; // [esp+14h] [ebp-10h]
  int v30; // [esp+14h] [ebp-10h]
  __int16 v31; // [esp+18h] [ebp-Ch]
  unsigned __int8 **v32; // [esp+1Ch] [ebp-8h]
  int v33; // [esp+20h] [ebp-4h]
  int v34; // [esp+20h] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = v2[1];
  v4 = *v2;
  v32 = v2;
  if ( !v3 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(a1) )
      return 0;
    v4 = *v2;
    v3 = v2[1];
    v1 = a1;
  }
  v5 = 0;
  BYTE1(v5) = *v4;
  v6 = v3 - 1;
  v7 = v4 + 1;
  v33 = (unsigned __int16)v5;
  if ( !v6 )
  {
    if ( ((int (__stdcall *)(int *))v2[3])(v1) )
    {
      v7 = *v2;
      v6 = v2[1];
      v5 = v33;
      v1 = a1;
      goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  v8 = v6 - 1;
  v9 = *v7 + v5 - 2;
  v10 = v7 + 1;
  v11 = v9 == 0;
  v34 = v9;
  if ( v9 > 0 )
  {
    do
    {
      if ( !v8 )
      {
        if ( !((int (__stdcall *)(int *))v2[3])(v1) )
          return 0;
        v10 = *v2;
        v8 = v2[1];
      }
      v12 = *v10;
      v13 = *a1;
      v14 = (int)*v10 >> 4;
      *(_DWORD *)(v13 + 20) = 81;
      v15 = v12 & 0xF;
      *(_DWORD *)(v13 + 24) = v15;
      --v8;
      ++v10;
      v28 = v14;
      *(_DWORD *)(v13 + 28) = v14;
      (*(void (__stdcall **)(int *, int))(v13 + 4))(a1, 1);
      if ( v15 >= 4 )
      {
        v16 = *a1;
        *(_DWORD *)(v16 + 20) = 31;
        *(_DWORD *)(v16 + 24) = v15;
        (*(void (__stdcall **)(int *))v16)(a1);
      }
      v17 = a1;
      if ( !a1[v15 + 42] )
      {
        v18 = sub_6B5F50(a1);
        v17 = a1;
        a1[v15 + 42] = v18;
      }
      v19 = v17[v15 + 42];
      v27 = v19;
      v29 = &dword_744A70;
      do
      {
        if ( v28 )
        {
          if ( !v8 )
          {
            if ( !((int (__stdcall *)(int *))v32[3])(v17) )
              return 0;
            v10 = *v32;
            v8 = v32[1];
            v17 = a1;
          }
          LOBYTE(v20) = 0;
          HIBYTE(v20) = *v10;
          --v8;
          ++v10;
          v31 = v20;
          if ( !v8 )
          {
            if ( !((int (__stdcall *)(int *))v32[3])(v17) )
              return 0;
            v10 = *v32;
            v8 = v32[1];
            v17 = a1;
          }
          v19 = v27;
          v21 = *v10 + v31;
        }
        else
        {
          if ( !v8 )
          {
            if ( !((int (__stdcall *)(int *))v32[3])(v17) )
              return 0;
            v10 = *v32;
            v8 = v32[1];
            v17 = a1;
          }
          v21 = *v10;
        }
        *(_WORD *)(v19 + 2 * *v29) = v21;
        --v8;
        ++v10;
        ++v29;
      }
      while ( (int)v29 < (int)dword_744B70 );
      if ( *(int *)(*v17 + 104) >= 2 )
      {
        v22 = (unsigned __int16 *)(v19 + 4);
        v30 = 8;
        while ( 1 )
        {
          v23 = *v17;
          *(_DWORD *)(v23 + 24) = *(v22 - 2);
          *(_DWORD *)(v23 + 28) = *(v22 - 1);
          *(_DWORD *)(v23 + 32) = *v22;
          *(_DWORD *)(v23 + 36) = v22[1];
          *(_DWORD *)(v23 + 40) = v22[2];
          *(_DWORD *)(v23 + 44) = v22[3];
          *(_DWORD *)(v23 + 48) = v22[4];
          *(_DWORD *)(v23 + 52) = v22[5];
          *(_DWORD *)(v23 + 20) = 93;
          (*(void (__stdcall **)(int *, int))(v23 + 4))(v17, 2);
          v22 += 8;
          if ( !--v30 )
            break;
          v17 = a1;
        }
      }
      v24 = v34 - 65;
      v34 -= 65;
      if ( v28 )
        v34 = v24 - 64;
      v1 = a1;
      v2 = v32;
    }
    while ( v34 > 0 );
    v11 = v34 == 0;
  }
  if ( !v11 )
  {
    v25 = *v1;
    *(_DWORD *)(v25 + 20) = 11;
    (*(void (__stdcall **)(int *))v25)(v1);
  }
  *v2 = v10;
  v2[1] = v8;
  return 1;
}
