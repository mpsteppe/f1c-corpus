_DWORD *__stdcall sub_58BED0(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = a1;
  switch ( (unsigned int)a1 )
  {
    case 0u:
    case 3u:
    case 6u:
    case 9u:
    case 0xCu:
    case 0xFu:
    case 0x12u:
    case 0x15u:
    case 0x21u:
    case 0x24u:
    case 0x39u:
      result = a2;
      *a2 = 1;
      *a3 = 0;
      break;
    case 1u:
    case 4u:
    case 7u:
    case 0xAu:
    case 0xDu:
    case 0x10u:
    case 0x13u:
    case 0x16u:
    case 0x22u:
    case 0x25u:
    case 0x28u:
    case 0x3Au:
      result = a3;
      *a2 = 1;
      *a3 = 0;
      break;
    case 0x18u:
    case 0x1Bu:
    case 0x1Eu:
    case 0x2Au:
    case 0x2Du:
    case 0x30u:
    case 0x33u:
    case 0x36u:
      result = a2;
      *a2 = 0;
      *a3 = 0;
      break;
    case 0x19u:
    case 0x1Cu:
    case 0x1Fu:
    case 0x2Bu:
    case 0x2Eu:
    case 0x31u:
      result = a3;
      *a2 = 0;
      *a3 = 0;
      break;
    case 0x1Au:
    case 0x1Du:
    case 0x20u:
    case 0x29u:
    case 0x2Cu:
    case 0x2Fu:
    case 0x32u:
      *a2 = 0;
      *a3 = 0;
      break;
    case 0x27u:
      result = a2;
      *a2 = 1;
      *a3 = 0;
      break;
    case 0x35u:
    case 0x37u:
      result = a3;
      *a2 = 0;
      *a3 = 0;
      break;
    default:
      *a2 = 1;
      *a3 = 0;
      break;
  }
  return result;
}
