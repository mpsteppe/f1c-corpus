_DWORD *__stdcall sub_5B43F0(_DWORD *a1, _DWORD *a2, int a3)
{
  _DWORD *result; // eax

  result = a2;
  switch ( a3 )
  {
    case 0:
      if ( a2 == (_DWORD *)8 )
        goto LABEL_3;
      if ( a2 == (_DWORD *)7 )
        goto LABEL_6;
      if ( a2 == (_DWORD *)6 )
        goto LABEL_9;
      if ( a2 == (_DWORD *)5 )
      {
LABEL_12:
        result = a1;
        if ( a1 )
          *a1 = 25;
        return result;
      }
      if ( a2 == (_DWORD *)3 )
        goto LABEL_15;
LABEL_31:
      if ( a2 == (_DWORD *)4 )
      {
        result = a1;
        if ( a1 )
          *a1 = 41;
        return result;
      }
      break;
    case 32:
      if ( a2 == (_DWORD *)8 )
      {
LABEL_3:
        result = a1;
        if ( a1 )
          *a1 = 21;
        return result;
      }
      break;
    case 24:
      if ( a2 == (_DWORD *)7 )
      {
LABEL_6:
        result = a1;
        if ( a1 )
          *a1 = 20;
        return result;
      }
      break;
    case 16:
      if ( a2 == (_DWORD *)6 )
      {
LABEL_9:
        result = a1;
        if ( a1 )
          *a1 = 23;
        return result;
      }
      if ( a2 == (_DWORD *)5 )
        goto LABEL_12;
      if ( a2 == (_DWORD *)3 )
      {
LABEL_15:
        result = a1;
        if ( a1 )
          *a1 = 26;
        return result;
      }
      break;
    case 8:
      goto LABEL_31;
  }
  if ( a2 == (_DWORD *)9 )
  {
    result = a1;
    if ( a1 )
      *a1 = 827611204;
  }
  else if ( a2 == (_DWORD *)10 )
  {
    result = a1;
    if ( a1 )
      *a1 = 844388420;
  }
  else if ( a2 == (_DWORD *)11 )
  {
    result = a1;
    if ( a1 )
      *a1 = 861165636;
  }
  else if ( a2 == (_DWORD *)12 )
  {
    result = a1;
    if ( a1 )
      *a1 = 877942852;
  }
  else if ( a2 == (_DWORD *)13 )
  {
    result = a1;
    if ( a1 )
      *a1 = 894720068;
  }
  return result;
}
