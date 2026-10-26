int __stdcall sub_5E2B30(int *a1, int *a2, int *a3, int a4)
{
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // ebp
  int result; // eax

  v4 = *(_DWORD *)dword_FB27A4;
  v5 = 0;
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 192))(dword_FB27A4);
  v7 = (*(int (__thiscall **)(int, int))(v4 + 196))(dword_FB27A4, v6);
  if ( !v7 )
    goto LABEL_9;
  while ( 1 )
  {
    v8 = *a1;
    if ( *a1 <= *(_DWORD *)(v7 + 288) && *a2 <= *(_DWORD *)(v7 + 292) )
      break;
    if ( v8 <= 16 || *a2 <= 16 )
      break;
    *a1 = v8 >> 1;
    *a2 >>= 1;
    ++v5;
    if ( *a3 > 1 )
      --*a3;
  }
  if ( v5 )
    return 0;
LABEL_9:
  v9 = a4;
  if ( a4 == -1 )
    v9 = dword_FB272C;
  v10 = 0;
  result = v9;
  if ( v9 )
  {
    while ( *a1 > 16 && *a2 > 16 )
    {
      *a1 >>= 1;
      *a2 >>= 1;
      --v9;
      ++v10;
      if ( *a3 > 1 )
        --*a3;
      if ( !v9 )
        return result;
    }
    return v10;
  }
  return result;
}
