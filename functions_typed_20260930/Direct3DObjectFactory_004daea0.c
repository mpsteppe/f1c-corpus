_DWORD *__thiscall sub_4DAEA0(void *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // esi
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // esi

  result = 0;
  switch ( (unsigned int)this )
  {
    case 0u:
      result = (_DWORD *)OperatorNewNhMallocWrapper(24);
      if ( !result )
        goto LABEL_20;
      result[1] = 2;
      *((_BYTE *)result + 8) = 1;
      *result = &off_5AD050;
      result[3] = 0;
      break;
    case 1u:
      result = (_DWORD *)OperatorNewNhMallocWrapper(20);
      if ( !result )
        goto LABEL_20;
      *result = &off_5AD034;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      break;
    case 2u:
      result = (_DWORD *)OperatorNewNhMallocWrapper(20);
      if ( !result )
        goto LABEL_20;
      *result = &off_5AD018;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      break;
    case 6u:
      result = (_DWORD *)OperatorNewNhMallocWrapper(20);
      if ( !result )
        goto LABEL_20;
      *result = &off_5ACFFC;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      break;
    case 7u:
      v2 = (_DWORD *)OperatorNewNhMallocWrapper(20);
      if ( !v2 )
        goto LABEL_20;
      ConstructorVTable3Fields(1, 1);
      *v2 = &off_5ACFE0;
      result = v2;
      break;
    case 8u:
      v3 = (_DWORD *)OperatorNewNhMallocWrapper(20);
      v4 = v3;
      if ( !v3 )
        goto LABEL_20;
      SmallStructConstructor_b0e0(v3);
      *v4 = &off_5ACFC4;
      result = v4;
      break;
    case 0xDu:
      result = (_DWORD *)OperatorNewNhMallocWrapper(32);
      if ( !result )
        goto LABEL_20;
      *result = &off_5ACFA8;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      result[3] = 0;
      break;
    case 0x11u:
      v5 = (_DWORD *)OperatorNewNhMallocWrapper(24);
      if ( !v5 )
        goto LABEL_20;
      ConstructorVTable3Fields(1, 1);
      *v5 = &off_5ACF8C;
      result = v5;
      break;
    case 0x13u:
      result = (_DWORD *)OperatorNewNhMallocWrapper(44);
      if ( result )
      {
        *result = &off_5ACF70;
        result[1] = 1;
        *((_BYTE *)result + 8) = 1;
        result[3] = 0;
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

