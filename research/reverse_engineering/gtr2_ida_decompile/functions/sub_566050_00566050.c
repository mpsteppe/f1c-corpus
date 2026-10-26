_DWORD *__thiscall sub_566050(void *this)
{
  _DWORD *result; // eax

  result = 0;
  switch ( (unsigned int)this )
  {
    case 0u:
      result = operator new(0x18u);
      if ( !result )
        goto LABEL_20;
      result[1] = 2;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_72111C;
      break;
    case 1u:
      result = operator new(0x14u);
      if ( !result )
        goto LABEL_20;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_721144;
      break;
    case 2u:
      result = operator new(0x14u);
      if ( !result )
        goto LABEL_20;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_721160;
      break;
    case 6u:
      result = operator new(0x14u);
      if ( !result )
        goto LABEL_20;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_72117C;
      break;
    case 7u:
      result = operator new(0x14u);
      if ( !result )
        goto LABEL_20;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_721198;
      break;
    case 8u:
      result = operator new(0x14u);
      if ( !result )
        goto LABEL_20;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_7211B4;
      break;
    case 0xDu:
      result = operator new(0x20u);
      if ( !result )
        goto LABEL_20;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_7211E4;
      break;
    case 0x11u:
      result = operator new(0x18u);
      if ( !result )
        goto LABEL_20;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      *result = &off_721208;
      break;
    case 0x13u:
      result = operator new(0x2Cu);
      if ( result )
      {
        result[1] = 1;
        *((_BYTE *)result + 8) = 1;
        result[3] = 0;
        *result = &off_721244;
      }
      else
      {
LABEL_20:
        result = 0;
      }
      break;
    default:
      return result;
  }
  return result;
}
