int *__thiscall sub_4BEE40(_DWORD *this)
{
  int v2; // esi
  int *result; // eax
  int v4; // edx
  int v5; // ecx
  bool v6; // zf

  sub_4BECA0(this, 2);
  v2 = 3;
  switch ( this[50] )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 0xB:
    case 0xC:
    case 0xD:
      v2 = 3;
      break;
    case 5:
    case 6:
    case 7:
      v2 = 2;
      break;
    case 8:
    case 9:
    case 0xA:
      v2 = 1;
      break;
    default:
      break;
  }
  result = (int *)this[46];
  this[48] = result;
  if ( result )
  {
    result = (int *)*result;
    if ( result )
    {
      while ( 1 )
      {
        v4 = result[18];
        if ( v4 == -1 )
          goto LABEL_18;
        v5 = result[25];
        if ( !v5 || *((_BYTE *)result + 2) )
          goto LABEL_18;
        if ( v2 != 3 )
        {
          if ( v2 == 2 )
          {
            if ( v4 != 1 )
            {
              v6 = v4 == 3;
              goto LABEL_16;
            }
          }
          else if ( v4 )
          {
            v6 = v4 == 2;
LABEL_16:
            if ( !v6 )
              goto LABEL_18;
          }
        }
        sub_59EF60(v5);
LABEL_18:
        result = (int *)this[48];
        if ( result )
        {
          result = (int *)result[1];
          this[48] = result;
          if ( result )
          {
            result = (int *)*result;
            if ( result )
              continue;
          }
        }
        return result;
      }
    }
  }
  return result;
}
