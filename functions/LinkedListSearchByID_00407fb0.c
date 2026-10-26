char __thiscall LinkedListSearchByID(_DWORD *this, int a2)
{
  char result; // al
  int *v3; // edx
  int v4; // edx
  int v5; // edx
  int *v6; // edx

  result = 0;
  if ( a2 != -1 )
  {
    v3 = (int *)this[6];
    this[8] = v3;
    if ( v3 )
    {
      v4 = *v3;
      if ( v4 )
      {
        while ( *(_DWORD *)(v4 + 92) != a2 )
        {
          v5 = this[8];
          if ( v5 )
            this[8] = *(_DWORD *)(v5 + 4);
          v6 = (int *)this[8];
          if ( v6 )
          {
            v4 = *v6;
            if ( v4 )
              continue;
          }
          return result;
        }
        return 1;
      }
    }
  }
  return result;
}
