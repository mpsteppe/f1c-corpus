int __thiscall sub_4EC790(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // ecx
  int *v4; // eax
  int v5; // eax

  v2 = this[24];
  if ( v2 )
  {
    if ( *(int *)(v2 + 96) > 0 )
    {
      v3 = a2;
      if ( a2 >= 0 && a2 < *(_DWORD *)(v2 + 96) )
      {
        v4 = *(int **)(v2 + 84);
        if ( a2 <= 0 )
        {
LABEL_8:
          if ( v4 )
          {
            v5 = *v4;
            if ( v5 )
              return *(_DWORD *)(v5 + 28);
          }
        }
        else
        {
          while ( v4 )
          {
            v4 = (int *)v4[1];
            if ( --v3 <= 0 )
              goto LABEL_8;
          }
        }
      }
    }
  }
  return -1;
}
