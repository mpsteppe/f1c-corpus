int __thiscall sub_473070(_DWORD *this)
{
  int v1; // ebx
  int result; // eax
  int i; // edi
  int v4; // esi
  int *v5; // edx
  int v6; // edx

  v1 = this[74];
  result = 0;
  for ( i = 0; i < v1; ++i )
  {
    v4 = i;
    if ( i >= 0 && i < this[74] )
    {
      v5 = (int *)this[71];
      if ( i <= 0 )
      {
LABEL_7:
        if ( v5 )
        {
          v6 = *v5;
          if ( v6 )
          {
            if ( !*(_DWORD *)(v6 + 84) )
              ++result;
          }
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = (int *)v5[1];
          if ( --v4 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
  return result;
}
