// f1c  0x00519375  size=168
int __usercall sub_519375@<eax>(int a1@<esi>)
{
  int v1; // ebx
  int v2; // edi
  int v3; // eax
  int result; // eax
  _DWORD *v5; // ecx
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  _DWORD *i; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 384);
  v2 = *(_DWORD *)(a1 + 276);
  v3 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 8 * *(_DWORD *)(a1 + 32));
  v12 = 0;
  *(_DWORD *)(v1 + 56) = v3;
  *(_DWORD *)(v1 + 60) = v3 + 4 * *(_DWORD *)(a1 + 32);
  result = *(_DWORD *)(a1 + 196);
  if ( *(int *)(a1 + 32) > 0 )
  {
    v5 = (_DWORD *)(result + 12);
    v10 = v2 + 4;
    for ( i = (_DWORD *)(result + 12); ; v5 = i )
    {
      v6 = *v5 * v5[6] / *(_DWORD *)(a1 + 276) * v10;
      v9 = *v5 * v5[6] / *(_DWORD *)(a1 + 276);
      i += 21;
      v7 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 8 * v6) + 4 * v9;
      v8 = 4 * v12;
      *(_DWORD *)(v8 + *(_DWORD *)(v1 + 56)) = v7;
      ++v12;
      *(_DWORD *)(v8 + *(_DWORD *)(v1 + 60)) = v7 + 4 * v6;
      result = v12;
      if ( v12 >= *(_DWORD *)(a1 + 32) )
        break;
    }
  }
  return result;
}
