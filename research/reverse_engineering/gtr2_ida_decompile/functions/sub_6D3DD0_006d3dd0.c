_DWORD *__stdcall sub_6D3DD0(int *a1, int a2)
{
  _DWORD *result; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // edi
  int *v8; // ebx
  int v9; // eax
  int v10; // ecx
  int v11; // [esp+Ch] [ebp+8h]

  result = (_DWORD *)(*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 64);
  v4 = a1[44];
  a1[86] = (int)result;
  *result = sub_6D3D70;
  if ( !v4 )
  {
    if ( a2 )
    {
      v5 = *a1;
      *(_DWORD *)(v5 + 20) = 4;
      return (_DWORD *)(*(int (__stdcall **)(int *))v5)(a1);
    }
    else
    {
      v6 = a1[17];
      v11 = 0;
      if ( a1[15] > 0 )
      {
        v7 = (_DWORD *)(v6 + 28);
        v8 = result + 6;
        do
        {
          v9 = (*(int (__stdcall **)(int *, int, int, int))(a1[1] + 8))(a1, 1, 8 * *v7, 8 * *(v7 - 4));
          v10 = a1[15];
          *v8 = v9;
          result = (_DWORD *)(v11 + 1);
          ++v8;
          v7 += 21;
          ++v11;
        }
        while ( v11 < v10 );
      }
    }
  }
  return result;
}
