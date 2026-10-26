int *sub_4D3440()
{
  int *result; // eax
  int *v1; // esi
  int *v2; // ebp
  int i; // edi
  int v4; // esi

  dword_7D5DB0 = 0;
  dword_7D5DB4 = 0;
  dword_7D5DB8 = 0;
  dword_7D5DBC = 0;
  dword_7D5DC0 = 0;
  dword_7D5DC4 = 0;
  dword_7D5DC8 = 0;
  dword_7D5DCC = 0;
  result = (int *)operator new(4u);
  v1 = result;
  if ( result )
  {
    *result = (int)operator new(0x1A00u);
    v2 = v1;
    result = (int *)operator new(0xCu);
    if ( result )
    {
      *result = (int)v1;
      result[1] = 0;
      *((_BYTE *)result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( dword_7D5DB0 )
    {
      *(_DWORD *)(dword_7D5DB4 + 4) = result;
    }
    else
    {
      dword_7D5DB0 = (int)result;
      dword_7D5DB8 = (int)result;
    }
    dword_7D5DB4 = (int)result;
    ++dword_7D5DBC;
  }
  else
  {
    v2 = 0;
  }
  for ( i = 0; i < 6656; i += 208 )
  {
    v4 = i + *v2;
    if ( v4 )
    {
      result = (int *)operator new(0xCu);
      if ( result )
      {
        *result = v4;
        result[1] = 0;
        *((_BYTE *)result + 8) = 0;
      }
      else
      {
        result = 0;
      }
      if ( dword_7D5DC0 )
      {
        result[1] = dword_7D5DC0;
      }
      else
      {
        dword_7D5DC4 = (int)result;
        dword_7D5DC8 = (int)result;
      }
      dword_7D5DC0 = (int)result;
      ++dword_7D5DCC;
    }
  }
  return result;
}
