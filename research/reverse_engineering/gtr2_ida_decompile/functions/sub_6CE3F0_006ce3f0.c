int __stdcall sub_6CE3F0(int a1, int a2)
{
  _DWORD *v3; // ebx
  int v4; // eax
  int v5; // eax
  int result; // eax
  _DWORD *v7; // edi
  int *v8; // ebx
  int v9; // eax
  int v10; // ecx
  int v11; // [esp+10h] [ebp+8h]
  int v12; // [esp+14h] [ebp+Ch]

  v3 = (_DWORD *)(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 80);
  *(_DWORD *)(a1 + 428) = v3;
  *v3 = sub_6CE380;
  if ( a2 )
  {
    v4 = *(_DWORD *)a1;
    *(_DWORD *)(v4 + 20) = 4;
    (*(void (__stdcall **)(int))v4)(a1);
  }
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 456) + 8) )
  {
    if ( *(int *)(a1 + 320) < 2 )
    {
      v5 = *(_DWORD *)a1;
      *(_DWORD *)(v5 + 20) = 47;
      (*(void (__stdcall **)(int))v5)(a1);
    }
    sub_6CDE50(a1);
    v11 = *(_DWORD *)(a1 + 320) + 2;
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 320);
  }
  result = *(_DWORD *)(a1 + 220);
  v12 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v7 = (_DWORD *)(result + 36);
    v8 = v3 + 2;
    do
    {
      v9 = (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)(a1 + 4) + 8))(
             a1,
             1,
             *v7 * *(v7 - 2),
             v11 * (*v7 * *(v7 - 6) / *(_DWORD *)(a1 + 320)));
      v10 = *(_DWORD *)(a1 + 36);
      *v8 = v9;
      result = v12 + 1;
      ++v8;
      v7 += 21;
      ++v12;
    }
    while ( v12 < v10 );
  }
  return result;
}
