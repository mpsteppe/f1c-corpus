int __thiscall sub_405D70(_DWORD *this, unsigned int a2, int a3)
{
  unsigned int v3; // ebx
  char *v5; // ebp
  int result; // eax
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // edx
  const char *v10; // [esp+10h] [ebp-8h] BYREF
  int v11; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  v11 = 0;
  if ( a2 < 4 )
  {
    v5 = sub_404FA0(a2);
    if ( v5 )
    {
      if ( AIL_enumerate_filters(&v11, &a2, &v10) )
      {
        while ( strcmp(v10, v5) )
        {
          result = AIL_enumerate_filters(&v11, &a2, &v10);
          if ( !result )
            return result;
        }
        if ( a2 != -1 )
        {
          v7 = this[21];
          if ( v7 )
          {
            AIL_open_filter(a2, *(_DWORD *)(v7 + 144));
            v8 = a2;
            v9 = a3;
            this[24] = v3;
            this[25] = v8;
            this[26] = v9;
          }
        }
      }
    }
  }
  return 0;
}
