int __stdcall sub_6DA8F7(int a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // ecx
  int v4; // edx
  int result; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  v1 = *(_DWORD *)(a1 + 5812);
  *(_WORD *)(a1 + 5808) |= 2 << v1;
  if ( v1 <= 13 )
  {
    *(_DWORD *)(a1 + 5812) = v1 + 3;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
    *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
    v2 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v2 - 13;
    *(_WORD *)(a1 + 5808) = 2u >> (16 - v2);
  }
  v3 = *(_DWORD *)(a1 + 5812);
  *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
  if ( v3 <= 9 )
  {
    *(_DWORD *)(a1 + 5812) = v3 + 7;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
    *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v4 - 9;
    *(_WORD *)(a1 + 5808) = 0;
  }
  result = sub_6DA419(a1);
  v6 = *(_DWORD *)(result + 5812);
  if ( *(_DWORD *)(result + 5804) - v6 + 11 < 9 )
  {
    *(_WORD *)(result + 5808) |= 2 << v6;
    if ( v6 <= 13 )
    {
      *(_DWORD *)(result + 5812) = v6 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
      *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
      v7 = *(_DWORD *)(result + 5812);
      ++*(_DWORD *)(result + 20);
      *(_DWORD *)(result + 5812) = v7 - 13;
      *(_WORD *)(result + 5808) = 2u >> (16 - v7);
    }
    v8 = *(_DWORD *)(result + 5812);
    *(_WORD *)(result + 5808) = *(_WORD *)(result + 5808);
    if ( v8 <= 9 )
    {
      *(_DWORD *)(result + 5812) = v8 + 7;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
      *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
      v9 = *(_DWORD *)(result + 5812);
      ++*(_DWORD *)(result + 20);
      *(_DWORD *)(result + 5812) = v9 - 9;
      *(_WORD *)(result + 5808) = 0;
    }
    result = sub_6DA419(result);
  }
  *(_DWORD *)(result + 5804) = 7;
  return result;
}
