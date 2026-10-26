int __stdcall sub_6CF290(int a1, int a2)
{
  _DWORD *v3; // ebx
  int result; // eax
  int *v5; // edi
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // [esp-8h] [ebp-18h]
  int v11; // [esp-4h] [ebp-14h]
  _DWORD *v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+18h] [ebp+8h]
  _DWORD *v14; // [esp+1Ch] [ebp+Ch]

  v3 = (_DWORD *)(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 116);
  v12 = v3;
  *(_DWORD *)(a1 + 432) = v3;
  *v3 = sub_6CE520;
  v3[2] = sub_6CF230;
  v3[28] = 0;
  if ( a2 )
  {
    result = *(_DWORD *)(a1 + 220);
    v13 = 0;
    if ( *(int *)(a1 + 36) > 0 )
    {
      v5 = (int *)(result + 12);
      v14 = v3 + 18;
      do
      {
        v6 = *v5;
        if ( *(_DWORD *)(a1 + 224) )
          v6 *= 3;
        v7 = *(_DWORD *)(a1 + 4);
        v11 = v6;
        v10 = sub_6B5FD0(v5[5], *v5);
        v8 = sub_6B5FD0(v5[4], *(v5 - 1));
        *v14 = (*(int (__stdcall **)(int, int, int, int, int, int))(v7 + 20))(a1, 1, 1, v8, v10, v11);
        result = v13 + 1;
        ++v14;
        v5 += 21;
        ++v13;
      }
      while ( v13 < *(_DWORD *)(a1 + 36) );
      v3 = v12;
    }
    v3[1] = sub_6CE7C0;
    v3[3] = sub_6CE9E0;
    v3[4] = v3 + 18;
  }
  else
  {
    v9 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, 1280);
    v3[9] = v9 + 128;
    v3[10] = v9 + 256;
    v3[11] = v9 + 384;
    v3[12] = v9 + 512;
    v3[13] = v9 + 640;
    v3[14] = v9 + 768;
    v3[8] = v9;
    v3[15] = v9 + 896;
    v3[16] = v9 + 1024;
    result = v9 + 1152;
    v3[17] = result;
    v3[4] = 0;
    v3[1] = sub_6CE7B0;
    v3[3] = sub_6CE540;
  }
  return result;
}
