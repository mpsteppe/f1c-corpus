int __thiscall sub_473010(_DWORD *this)
{
  int result; // eax
  int i; // esi
  int v4; // ecx
  int *v5; // eax
  int v6; // eax

  result = this[74];
  for ( i = 0; i < result; ++i )
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
            sub_472F40(this, v6, 6);
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
    result = this[74];
  }
  return result;
}
