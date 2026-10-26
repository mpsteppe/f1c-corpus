char *__stdcall sub_463820(_DWORD *a1)
{
  char *result; // eax
  unsigned int v2; // ecx
  int v3; // [esp+4h] [ebp+4h]

  if ( *a1 )
  {
    if ( *a1 == 1 )
    {
      v2 = a1[1];
      result = (char *)WindowName;
      if ( v2 < 0xC8 )
        return &asc_757CB0[9 * v2];
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v3 = a1[1];
    result = (char *)WindowName;
    if ( v3 < 128 )
    {
      if ( (unsigned int)v3 < 0x5A )
      {
        switch ( v3 )
        {
          case 0:
          case 1:
          case 14:
          case 15:
          case 28:
          case 29:
          case 42:
            goto LABEL_14;
          default:
            if ( v3 >= 54 )
            {
LABEL_14:
              result = &aPause[16 * v3];
            }
            else
            {
              String[4] = sub_45E670();
              result = _strupr(String);
            }
            break;
        }
      }
    }
    else if ( (unsigned int)(v3 - 128) < 0x58 )
    {
      return &asc_758958[16 * v3 - 2048];
    }
  }
  return result;
}
