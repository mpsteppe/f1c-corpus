int (__stdcall **__stdcall sub_6D7520(int a1, int a2))(int *a1, int a2)
{
  int v2; // eax
  int (__stdcall **result)(int *, int); // eax
  int v4; // edx
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // edi
  int *v8; // ebx
  int v9; // eax
  int v10; // ecx
  int v11; // [esp+10h] [ebp+Ch]

  if ( a2 )
  {
    v2 = *(_DWORD *)a1;
    *(_DWORD *)(v2 + 20) = 4;
    (*(void (__stdcall **)(int))v2)(a1);
  }
  result = (int (__stdcall **)(int *, int))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 64);
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 364) + 8);
  *(_DWORD *)(a1 + 348) = result;
  *result = sub_6D6FC0;
  if ( v4 )
  {
    result[1] = (int (__stdcall *)(int *, int))sub_6D71F0;
    return (int (__stdcall **)(int *, int))sub_6D7400(a1);
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 60);
    v6 = *(_DWORD *)(a1 + 68);
    result[1] = (int (__stdcall *)(int *, int))sub_6D7010;
    v11 = 0;
    if ( v5 > 0 )
    {
      v7 = (_DWORD *)(v6 + 8);
      v8 = (int *)(result + 2);
      do
      {
        v9 = (*(int (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)(a1 + 4) + 8))(
               a1,
               1,
               8 * *(_DWORD *)(a1 + 240) * v7[5] / *v7,
               *(_DWORD *)(a1 + 244));
        v10 = *(_DWORD *)(a1 + 60);
        *v8 = v9;
        result = (int (__stdcall **)(int *, int))(v11 + 1);
        ++v8;
        v7 += 21;
        ++v11;
      }
      while ( v11 < v10 );
    }
  }
  return result;
}
