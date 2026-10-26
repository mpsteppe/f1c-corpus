int __stdcall sub_6D5FB0(int a1, int a2)
{
  int v3; // edx
  int v4; // ecx
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // eax
  unsigned int v8; // esi
  int v9; // eax
  bool v10; // cc
  int result; // eax
  _DWORD *v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  BOOL v14; // [esp+14h] [ebp-8h]
  _DWORD *v15; // [esp+18h] [ebp-4h]
  int *v16; // [esp+24h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 324);
  v4 = *(_DWORD *)(a1 + 332);
  v5 = *(_DWORD **)(a1 + 372);
  v12 = v5;
  v5[8] = a1;
  v5[3] = a2;
  v14 = v3 == 0;
  if ( v4 )
  {
    if ( v3 )
    {
      v6 = v5[16];
      v5[1] = sub_6D5C00;
      if ( !v6 )
        v5[16] = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1000);
    }
    else
    {
      v5[1] = sub_6D5B40;
    }
  }
  else if ( v3 )
  {
    v5[1] = sub_6D5950;
  }
  else
  {
    v5[1] = sub_6D57E0;
  }
  if ( a2 )
    v5[2] = sub_6D5ED0;
  else
    v5[2] = sub_6D5E80;
  v13 = 0;
  if ( *(int *)(a1 + 252) > 0 )
  {
    v15 = v5 + 9;
    v16 = (int *)(a1 + 256);
    while ( 1 )
    {
      v7 = *v16;
      *v15 = 0;
      if ( !v14 )
        break;
      if ( !*(_DWORD *)(a1 + 332) )
      {
        v8 = *(_DWORD *)(v7 + 20);
        goto LABEL_18;
      }
LABEL_25:
      v10 = ++v13 < *(_DWORD *)(a1 + 252);
      ++v16;
      ++v15;
      if ( !v10 )
        goto LABEL_26;
    }
    v8 = *(_DWORD *)(v7 + 24);
    v5[13] = v8;
LABEL_18:
    if ( a2 )
    {
      if ( v8 >= 4 )
      {
        v9 = *(_DWORD *)a1;
        *(_DWORD *)(v9 + 20) = 50;
        *(_DWORD *)(v9 + 24) = v8;
        (*(void (__stdcall **)(int))v9)(a1);
      }
      if ( !v5[v8 + 23] )
        v5[v8 + 23] = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1028);
      memset((void *)v5[v8 + 23], 0, 0x404u);
      v5 = v12;
    }
    else
    {
      sub_6D4710((int *)a1, v14, v8, &v5[v8 + 19]);
    }
    goto LABEL_25;
  }
LABEL_26:
  result = *(_DWORD *)(a1 + 200);
  v5[14] = 0;
  v5[15] = 0;
  v5[6] = 0;
  v5[7] = 0;
  v5[17] = result;
  v5[18] = 0;
  return result;
}
