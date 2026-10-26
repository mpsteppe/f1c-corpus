int __thiscall sub_4EC740(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // ecx
  int *v4; // eax
  int v5; // eax

  v2 = this[24];
  if ( v2 )
  {
    v3 = a2;
    if ( a2 >= 0 && a2 < *(_DWORD *)(v2 + 64) )
    {
      v4 = *(int **)(v2 + 52);
      if ( a2 <= 0 )
      {
LABEL_7:
        if ( v4 )
        {
          v5 = *v4;
          if ( v5 )
            return *(_DWORD *)(v5 + 20);
        }
      }
      else
      {
        while ( v4 )
        {
          v4 = (int *)v4[1];
          if ( --v3 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
  return -1;
}
