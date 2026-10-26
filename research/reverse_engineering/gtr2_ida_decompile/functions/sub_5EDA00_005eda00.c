int *__thiscall sub_5EDA00(_DWORD *this, char a2, int a3)
{
  int v3; // edx
  int *result; // eax
  int v5; // eax
  int v6; // ecx

  v3 = a3;
  result = (int *)this[136];
  if ( a3 < (int)result )
  {
    if ( a3 >= 0 && a3 < (int)result )
    {
      v5 = this[133];
      if ( a3 <= 0 )
      {
LABEL_7:
        if ( v5 )
        {
          result = *(int **)v5;
LABEL_10:
          v6 = *result;
          if ( a2 )
            *result = v6 | 0x100000;
          else
            *result = v6 & 0xFFEFFFFF;
          return result;
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = *(_DWORD *)(v5 + 4);
          if ( --v3 <= 0 )
            goto LABEL_7;
        }
      }
    }
    result = 0;
    goto LABEL_10;
  }
  return result;
}
