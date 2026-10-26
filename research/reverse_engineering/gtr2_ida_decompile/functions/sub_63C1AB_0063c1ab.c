int *__cdecl sub_63C1AB(double *a1, int a2, double *a3, int a4)
{
  unsigned int v4; // kr00_4
  int *result; // eax
  double *v6; // esi
  double v7; // [esp+18h] [ebp-Ch]

  v4 = __readeflags();
  __writeeflags(v4);
  if ( a4 <= 161 )
  {
    if ( a4 == 161 )
      goto LABEL_39;
    if ( a4 <= 24 )
    {
      if ( a4 == 24 || a4 == 2 )
        goto LABEL_39;
      if ( a4 != 3 )
      {
        if ( a4 == 8 )
          goto LABEL_39;
        if ( a4 != 9 )
        {
          if ( a4 != 14 )
          {
            result = (int *)(a4 - 15);
            if ( a4 != 15 )
              return result;
            goto LABEL_26;
          }
          goto LABEL_39;
        }
      }
      goto LABEL_48;
    }
    switch ( a4 )
    {
      case 25:
LABEL_26:
        v6 = a3;
        v7 = *a3;
        result = (int *)off_913310();
LABEL_52:
        *v6 = v7;
        return result;
      case 26:
        result = (int *)a3;
        *a3 = 1.0;
        return result;
      case 27:
LABEL_39:
        v6 = a3;
        v7 = *a3;
        result = (int *)off_913310();
        if ( !result )
        {
          result = _errno();
          *result = 34;
        }
        goto LABEL_52;
      case 28:
        goto LABEL_48;
    }
    result = (int *)(a4 - 29);
    if ( a4 != 29 )
      return result;
LABEL_49:
    v6 = a3;
    *a3 = *a1;
LABEL_50:
    v7 = *v6;
    result = (int *)off_913310();
    if ( !result )
    {
      result = _errno();
      *result = 33;
    }
    goto LABEL_52;
  }
  if ( a4 > 1002 )
  {
    if ( a4 == 1003 || a4 == 1004 || a4 == 1005 )
      goto LABEL_49;
    if ( a4 != 1006 )
    {
      result = (int *)(a4 - 1007);
      if ( a4 != 1007 )
        return result;
      goto LABEL_49;
    }
    goto LABEL_48;
  }
  switch ( a4 )
  {
    case 1002:
      goto LABEL_49;
    case 162:
    case 166:
    case 170:
      goto LABEL_39;
    case 171:
LABEL_48:
      v6 = a3;
      goto LABEL_50;
    case 1000:
      goto LABEL_49;
  }
  result = (int *)(a4 - 1001);
  if ( a4 == 1001 )
    goto LABEL_49;
  return result;
}
