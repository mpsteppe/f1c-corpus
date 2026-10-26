int __usercall sub_6B50D0@<eax>(int *a1@<ebx>)
{
  int result; // eax
  unsigned int v2; // esi
  int v3; // eax
  void *v4; // eax
  bool v5; // cc
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  int *v8; // [esp+8h] [ebp-4h]

  result = a1[83];
  v7 = 0;
  if ( result > 0 )
  {
    v8 = a1 + 84;
    do
    {
      v6 = *v8;
      if ( !*(_DWORD *)(*v8 + 76) )
      {
        v2 = *(_DWORD *)(*v8 + 16);
        if ( v2 >= 4 || !a1[v2 + 42] )
        {
          v3 = *a1;
          *(_DWORD *)(v3 + 20) = 52;
          *(_DWORD *)(v3 + 24) = v2;
          (*(void (__stdcall **)(int *))v3)(a1);
        }
        v4 = (void *)(*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 132);
        qmemcpy(v4, (const void *)a1[v2 + 42], 0x84u);
        *(_DWORD *)(v6 + 76) = v4;
      }
      result = v7 + 1;
      v5 = ++v7 < a1[83];
      ++v8;
    }
    while ( v5 );
  }
  return result;
}
