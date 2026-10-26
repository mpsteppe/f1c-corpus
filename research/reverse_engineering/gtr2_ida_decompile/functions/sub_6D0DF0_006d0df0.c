int (__stdcall **__stdcall sub_6D0DF0(int a1))(int *a1)
{
  int (__stdcall **result)(int *); // eax
  int v3; // edx
  int v4; // ecx
  int v5; // ebx
  void *v6; // eax
  _DWORD *v7; // [esp+8h] [ebp-4h]
  _DWORD *v8; // [esp+14h] [ebp+8h]

  result = (int (__stdcall **)(int *))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 84);
  v3 = *(_DWORD *)(a1 + 36);
  v4 = *(_DWORD *)(a1 + 220);
  v5 = 0;
  *(_DWORD *)(a1 + 452) = result;
  *result = sub_6D0A90;
  if ( v3 > 0 )
  {
    v7 = (_DWORD *)(v4 + 80);
    v8 = result + 11;
    do
    {
      v6 = (void *)(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 256);
      *v7 = v6;
      memset(v6, 0, 0x100u);
      *v8++ = -1;
      result = *(int (__stdcall ***)(int *))(a1 + 36);
      ++v5;
      v7 += 21;
    }
    while ( v5 < (int)result );
  }
  return result;
}
