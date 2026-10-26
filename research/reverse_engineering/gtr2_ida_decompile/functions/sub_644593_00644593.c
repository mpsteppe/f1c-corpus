unsigned int __fastcall sub_644593(int a1, int a2)
{
  unsigned int result; // eax
  unsigned int *v3; // esi
  int v4; // edi
  int v5; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // edx
  int v8; // [esp+4h] [ebp-4h]

  result = 0;
  if ( !dword_736818[5 * *(_DWORD *)(a1 + 4) + *(_DWORD *)(a2 + 4)] )
    return -1;
  v8 = 0;
  v3 = (unsigned int *)(a1 + 12);
  v4 = a2 - a1;
  v5 = 5;
  do
  {
    v6 = *v3;
    if ( *v3 )
      ++v8;
    v7 = *(unsigned int *)((char *)v3 + v4);
    if ( v6 >= v7 )
    {
      if ( v6 > v7 )
      {
        if ( v7 )
          result += (v6 - v7) << 16;
        else
          result += (unsigned int)&dword_1000000;
      }
    }
    else if ( v6 )
    {
      result += v7 - v6;
    }
    else
    {
      result += 256;
    }
    ++v3;
    --v5;
  }
  while ( v5 );
  if ( v8 == HIBYTE(result) )
    return -1;
  return result;
}
