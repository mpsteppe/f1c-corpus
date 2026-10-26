int __stdcall sub_6D49D0(int a1, __int16 *a2, int a3, int a4, int a5)
{
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  int v9; // ecx
  int *v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // edi
  int v14; // esi
  int v15; // edi
  int v16; // ecx
  int v18; // [esp-4h] [ebp-14h]
  int v19; // [esp-4h] [ebp-14h]
  int *v20; // [esp+Ch] [ebp-4h]
  int v21; // [esp+20h] [ebp+10h]
  int v22; // [esp+24h] [ebp+14h]

  v5 = *a2 - a3;
  v6 = v5;
  if ( v5 < 0 )
  {
    v6 = a3 - *a2;
    --v5;
  }
  v7 = 0;
  if ( !v6 )
    goto LABEL_7;
  do
  {
    v6 >>= 1;
    ++v7;
  }
  while ( v6 );
  if ( v7 > 11 )
  {
    v8 = a1;
    v9 = **(_DWORD **)(a1 + 32);
    v18 = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(v9 + 20) = 6;
    (*(void (__stdcall **)(int))v9)(v18);
  }
  else
  {
LABEL_7:
    v8 = a1;
  }
  if ( sub_6D48F0(v8, *(_DWORD *)(a4 + 4 * v7), *(char *)(v7 + a4 + 1024)) && (!v7 || sub_6D48F0(v8, v5, v7)) )
  {
    v10 = (int *)&unk_744A74;
    v11 = 0;
    v20 = (int *)&unk_744A74;
    do
    {
      v12 = a2[*v10];
      if ( a2[*v10] )
      {
        if ( v11 > 15 )
        {
          while ( sub_6D48F0(a1, *(_DWORD *)(a5 + 960), *(char *)(a5 + 1264)) )
          {
            v11 -= 16;
            if ( v11 <= 15 )
              goto LABEL_17;
          }
          return 0;
        }
LABEL_17:
        v21 = v12;
        if ( v12 < 0 )
        {
          v12 = -v12;
          --v21;
        }
        v13 = v12 >> 1;
        v14 = 1;
        v22 = 1;
        if ( !v13 )
          goto LABEL_23;
        do
        {
          v13 >>= 1;
          ++v14;
        }
        while ( v13 );
        v22 = v14;
        if ( v14 > 10 )
        {
          v15 = a1;
          v16 = **(_DWORD **)(a1 + 32);
          v19 = *(_DWORD *)(a1 + 32);
          *(_DWORD *)(v16 + 20) = 6;
          (*(void (__stdcall **)(int))v16)(v19);
        }
        else
        {
LABEL_23:
          v15 = a1;
        }
        if ( !sub_6D48F0(v15, *(_DWORD *)(a5 + 4 * (v14 + 16 * v11)), *(char *)(v14 + 16 * v11 + a5 + 1024))
          || !sub_6D48F0(v15, v21, v22) )
        {
          return 0;
        }
        v10 = v20;
        v11 = 0;
      }
      else
      {
        ++v11;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)dword_744B70 );
    if ( v11 <= 0 || sub_6D48F0(a1, *(_DWORD *)a5, *(char *)(a5 + 1024)) )
      return 1;
  }
  return 0;
}
