_DWORD *__stdcall sub_525900(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = a1;
  switch ( (unsigned int)a1 )
  {
    case 1u:
    case 4u:
    case 7u:
    case 0x16u:
    case 0x19u:
    case 0x2Bu:
      result = a3;
      *a2 = 1;
      *a3 = 0;
      break;
    case 2u:
    case 5u:
    case 8u:
    case 0x17u:
    case 0x1Au:
    case 0x2Cu:
      *a2 = 1;
      *a3 = 0;
      break;
    case 0xAu:
    case 0x27u:
      result = a3;
      *a2 = 1;
      *a3 = 0;
      break;
    case 0xBu:
      *a2 = 1;
      *a3 = 0;
      break;
    case 0xCu:
    case 0xFu:
    case 0x12u:
    case 0x1Eu:
    case 0x21u:
    case 0x24u:
    case 0x28u:
    case 0x2Au:
      result = a2;
      *a2 = 0;
      *a3 = 0;
      break;
    case 0xDu:
    case 0x10u:
    case 0x1Cu:
    case 0x1Fu:
    case 0x22u:
    case 0x25u:
      result = a3;
      *a2 = 0;
      *a3 = 0;
      break;
    case 0xEu:
    case 0x11u:
    case 0x1Du:
    case 0x20u:
    case 0x23u:
    case 0x26u:
    case 0x29u:
      *a2 = 0;
      *a3 = 0;
      break;
    case 0x13u:
      result = a3;
      *a2 = 0;
      *a3 = 0;
      break;
    case 0x14u:
      *a2 = 0;
      *a3 = 0;
      break;
    default:
      result = a2;
      *a2 = 1;
      *a3 = 0;
      break;
  }
  return result;
}
