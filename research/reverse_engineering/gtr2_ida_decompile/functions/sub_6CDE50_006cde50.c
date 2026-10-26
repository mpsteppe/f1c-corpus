int __usercall sub_6CDE50@<eax>(int a1@<esi>)
{
  int v1; // ebx
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int result; // eax
  int v7; // ebx
  _DWORD *v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // [esp+8h] [ebp-10h]
  int v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  _DWORD *i; // [esp+14h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 428);
  v2 = *(_DWORD *)(a1 + 320);
  v12 = v1;
  v3 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 8 * *(_DWORD *)(a1 + 36));
  v4 = *(_DWORD *)(a1 + 36);
  v5 = v3 + 4 * v4;
  *(_DWORD *)(v1 + 56) = v3;
  result = *(_DWORD *)(a1 + 220);
  *(_DWORD *)(v1 + 60) = v5;
  v7 = 0;
  if ( v4 > 0 )
  {
    v8 = (_DWORD *)(result + 12);
    v14 = v2 + 4;
    for ( i = (_DWORD *)(result + 12); ; v8 = i )
    {
      v9 = *v8 * v8[6] / *(_DWORD *)(a1 + 320) * v14;
      v13 = *v8 * v8[6] / *(_DWORD *)(a1 + 320);
      v10 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 8 * v9) + 4 * v13;
      v11 = *(_DWORD *)(v12 + 60);
      *(_DWORD *)(*(_DWORD *)(v12 + 56) + 4 * v7) = v10;
      *(_DWORD *)(v11 + 4 * v7) = v10 + 4 * v9;
      result = *(_DWORD *)(a1 + 36);
      ++v7;
      i += 21;
      if ( v7 >= result )
        break;
    }
  }
  return result;
}
