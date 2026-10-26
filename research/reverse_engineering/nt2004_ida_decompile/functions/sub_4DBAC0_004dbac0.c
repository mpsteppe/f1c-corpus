int *__thiscall sub_4DBAC0(int **this)
{
  int *result; // eax
  int *v3; // ebp
  char *v4; // eax
  char *v5; // esi
  int v6; // ebx
  int v7; // eax
  int i; // ebp
  int v9; // esi
  int v10; // ecx
  int v11; // [esp+10h] [ebp-4h]
  int *v12; // [esp+10h] [ebp-4h]

  result = (int *)operator new(4u);
  v3 = result;
  if ( result )
  {
    v4 = (char *)operator new(0x180u);
    v11 = (int)v4;
    if ( v4 )
    {
      v5 = v4;
      v6 = 32;
      do
      {
        sub_4D33B0(v5);
        v5 += 12;
        --v6;
      }
      while ( v6 );
      v7 = v11;
    }
    else
    {
      v7 = 0;
    }
    *v3 = v7;
    v12 = v3;
    result = (int *)operator new(0xCu);
    if ( result )
    {
      *result = (int)v3;
      result[1] = 0;
      *((_BYTE *)result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( *this )
    {
      this[1][1] = (int)result;
    }
    else
    {
      *this = result;
      this[2] = result;
    }
    this[1] = result;
    this[3] = (int *)((char *)this[3] + 1);
  }
  else
  {
    v12 = 0;
  }
  for ( i = 0; i < 384; i += 12 )
  {
    v9 = i + *v12;
    if ( v9 )
    {
      result = (int *)operator new(0xCu);
      if ( result )
      {
        *result = v9;
        result[1] = 0;
        *((_BYTE *)result + 8) = 0;
      }
      else
      {
        result = 0;
      }
      v10 = (int)this[4];
      if ( v10 )
      {
        result[1] = v10;
      }
      else
      {
        this[5] = result;
        this[6] = result;
      }
      this[4] = result;
      this[7] = (int *)((char *)this[7] + 1);
    }
  }
  return result;
}
