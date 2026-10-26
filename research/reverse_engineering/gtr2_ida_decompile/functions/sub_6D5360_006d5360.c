int __stdcall sub_6D5360(int a1, int a2)
{
  _DWORD *v3; // ebx
  unsigned int v4; // edx
  unsigned int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int result; // eax
  _DWORD *v12; // [esp+8h] [ebp-Ch]
  int v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]
  unsigned int v15; // [esp+1Ch] [ebp+8h]

  v3 = *(_DWORD **)(a1 + 372);
  if ( a2 )
  {
    v3[1] = sub_6D4F30;
    v3[2] = sub_6D5260;
  }
  else
  {
    v3[1] = sub_6D4C30;
    v3[2] = sub_6D4DA0;
  }
  v13 = 0;
  if ( *(int *)(a1 + 252) > 0 )
  {
    v12 = v3 + 5;
    v14 = a1 + 256;
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)v14 + 24);
      v5 = *(_DWORD *)(*(_DWORD *)v14 + 20);
      v15 = v4;
      if ( a2 )
      {
        if ( v5 >= 4 )
        {
          v6 = *(_DWORD *)a1;
          *(_DWORD *)(v6 + 20) = 50;
          *(_DWORD *)(v6 + 24) = v5;
          (*(void (__stdcall **)(int))v6)(a1);
          v4 = v15;
        }
        if ( v4 >= 4 )
        {
          v7 = *(_DWORD *)a1;
          *(_DWORD *)(v7 + 20) = 50;
          *(_DWORD *)(v7 + 24) = v4;
          (*(void (__stdcall **)(int))v7)(a1);
          v4 = v15;
        }
        if ( !v3[v5 + 19] )
        {
          v8 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1028);
          v4 = v15;
          v3[v5 + 19] = v8;
        }
        memset((void *)v3[v5 + 19], 0, 0x404u);
        if ( !v3[v4 + 23] )
        {
          v9 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1028);
          v4 = v15;
          v3[v15 + 23] = v9;
        }
        memset((void *)v3[v4 + 23], 0, 0x404u);
      }
      else
      {
        sub_6D4710((int *)a1, 1, v5, &v3[v5 + 11]);
        sub_6D4710((int *)a1, 0, v15, &v3[v15 + 15]);
      }
      *v12++ = 0;
      ++v13;
      v14 += 4;
    }
    while ( v13 < *(_DWORD *)(a1 + 252) );
  }
  v10 = *(_DWORD *)(a1 + 200);
  result = 0;
  v3[3] = 0;
  v3[4] = 0;
  v3[9] = v10;
  v3[10] = 0;
  return result;
}
