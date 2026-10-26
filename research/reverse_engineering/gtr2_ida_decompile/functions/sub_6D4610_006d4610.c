int __stdcall sub_6D4610(int a1, int a2)
{
  int (__stdcall **v3)(int *, int); // ebx
  int result; // eax
  int *v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // [esp-8h] [ebp-14h]
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+14h] [ebp+8h]
  _DWORD *v14; // [esp+18h] [ebp+Ch]

  v3 = (int (__stdcall **)(int *, int))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 104);
  *(_DWORD *)(a1 + 352) = v3;
  *v3 = sub_6D4540;
  if ( a2 )
  {
    result = *(_DWORD *)(a1 + 68);
    v13 = 0;
    if ( *(int *)(a1 + 60) > 0 )
    {
      v5 = (int *)(result + 12);
      v14 = v3 + 16;
      do
      {
        v6 = *(_DWORD *)(a1 + 4);
        v12 = *v5;
        v11 = sub_6B5FD0(v5[5], *v5);
        v7 = sub_6B5FD0(v5[4], *(v5 - 1));
        *v14 = (*(int (__stdcall **)(int, int, _DWORD, int, int, int))(v6 + 20))(a1, 1, 0, v7, v11, v12);
        result = v13 + 1;
        ++v14;
        v5 += 21;
        ++v13;
      }
      while ( v13 < *(_DWORD *)(a1 + 60) );
    }
  }
  else
  {
    v8 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, 1280);
    v3[7] = (int (__stdcall *)(int *, int))(v8 + 128);
    v3[8] = (int (__stdcall *)(int *, int))(v8 + 256);
    v3[9] = (int (__stdcall *)(int *, int))(v8 + 384);
    v3[10] = (int (__stdcall *)(int *, int))(v8 + 512);
    v3[11] = (int (__stdcall *)(int *, int))(v8 + 640);
    v3[12] = (int (__stdcall *)(int *, int))(v8 + 768);
    v3[6] = (int (__stdcall *)(int *, int))v8;
    v9 = v8 + 896;
    v10 = v8 + 1024;
    result = v8 + 1152;
    v3[13] = (int (__stdcall *)(int *, int))v9;
    v3[14] = (int (__stdcall *)(int *, int))v10;
    v3[15] = (int (__stdcall *)(int *, int))result;
    v3[16] = 0;
  }
  return result;
}
