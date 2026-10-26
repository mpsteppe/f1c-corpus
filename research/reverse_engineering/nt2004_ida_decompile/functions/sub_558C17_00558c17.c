_DWORD *__cdecl sub_558C17(int a1)
{
  _DWORD *result; // eax
  _DWORD *v3; // ebx
  void *v4; // edi
  _DWORD *v5; // eax
  int v6; // [esp+4h] [ebp-4h]
  int v7; // [esp+10h] [ebp+8h]

  result = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 84);
  v6 = 0;
  *(_DWORD *)(a1 + 408) = result;
  *result = sub_558A60;
  if ( *(int *)(a1 + 32) > 0 )
  {
    v7 = *(_DWORD *)(a1 + 196) + 80;
    v3 = result + 11;
    do
    {
      v4 = (void *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 256);
      v5 = (_DWORD *)v7;
      v7 += 84;
      *v5 = v4;
      memset(v4, 0, 0x100u);
      *v3 = -1;
      result = (_DWORD *)++v6;
      ++v3;
    }
    while ( v6 < *(_DWORD *)(a1 + 32) );
  }
  return result;
}
