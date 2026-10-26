int __cdecl sub_5198B3(int a1, char a2)
{
  _DWORD *v3; // ebx
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  _DWORD *v7; // ebx
  int v8; // [esp+14h] [ebp+8h]
  int v9; // [esp+18h] [ebp+Ch]

  v3 = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 80);
  *(_DWORD *)(a1 + 384) = v3;
  *v3 = sub_51984B;
  if ( a2 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 412) + 8) )
  {
    if ( *(int *)(a1 + 276) < 2 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 46;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    result = sub_519375(a1);
    v5 = *(_DWORD *)(a1 + 276) + 2;
    v9 = v5;
  }
  else
  {
    result = *(_DWORD *)(a1 + 276);
    v9 = result;
    v5 = result;
  }
  v8 = 0;
  if ( *(int *)(a1 + 32) > 0 )
  {
    v6 = (_DWORD *)(*(_DWORD *)(a1 + 196) + 36);
    v7 = v3 + 2;
    while ( 1 )
    {
      ++v8;
      *v7 = (*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)(a1 + 4) + 8))(
              a1,
              1,
              *v6 * *(v6 - 2),
              v5 * (*v6 * *(v6 - 6) / *(_DWORD *)(a1 + 276)));
      result = v8;
      ++v7;
      v6 += 21;
      if ( v8 >= *(_DWORD *)(a1 + 32) )
        break;
      v5 = v9;
    }
  }
  return result;
}
