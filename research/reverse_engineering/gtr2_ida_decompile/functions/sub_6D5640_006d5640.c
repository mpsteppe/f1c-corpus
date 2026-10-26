signed int __usercall sub_6D5640@<eax>(int a1@<eax>)
{
  signed int result; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // ecx
  _DWORD *v7; // eax
  int v8; // ebx
  char *v9; // edi
  int v10; // [esp-Ch] [ebp-10h]

  result = *(_DWORD *)(a1 + 56);
  if ( result )
  {
    v3 = result >> 1;
    v4 = 0;
    if ( v3 )
    {
      do
      {
        v3 >>= 1;
        ++v4;
      }
      while ( v3 );
      if ( v4 > 14 )
      {
        v5 = **(_DWORD **)(a1 + 32);
        v10 = *(_DWORD *)(a1 + 32);
        *(_DWORD *)(v5 + 20) = 40;
        (*(void (__stdcall **)(int))v5)(v10);
      }
    }
    v6 = *(_DWORD *)(a1 + 52);
    if ( *(_DWORD *)(a1 + 12) )
    {
      v7 = (_DWORD *)(*(_DWORD *)(a1 + 4 * v6 + 92) + (v4 << 6));
      ++*v7;
    }
    else
    {
      sub_6D5530(
        a1,
        *(_DWORD *)(*(_DWORD *)(a1 + 4 * v6 + 76) + (v4 << 6)),
        *(char *)(*(_DWORD *)(a1 + 4 * v6 + 76) + 16 * v4 + 1024));
    }
    if ( v4 )
      sub_6D5530(a1, *(_DWORD *)(a1 + 56), v4);
    result = *(_DWORD *)(a1 + 12);
    v8 = *(_DWORD *)(a1 + 60);
    v9 = *(char **)(a1 + 64);
    *(_DWORD *)(a1 + 56) = 0;
    if ( !result && v8 )
    {
      do
      {
        result = sub_6D5530(a1, *v9++, 1);
        --v8;
      }
      while ( v8 );
    }
    *(_DWORD *)(a1 + 60) = 0;
  }
  return result;
}
