int __stdcall sub_411BF0(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int result; // eax

  v4 = RandLCGRandomNumberGenerator() % 2;
  switch ( *(_DWORD *)(a2 + 12) )
  {
    case 3:
    case 5:
    case 6:
    case 9:
    case 0xA:
    case 0xD:
    case 0x13:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x26:
    case 0x29:
    case 0x2D:
    case 0x30:
    case 0x32:
    case 0x35:
    case 0x36:
    case 0x37:
      result = SessionStringNameLookup(a4, a1, *(_DWORD *)(a3 + 16), 1, v4 == 0);
      break;
    case 8:
    case 0xF:
    case 0x21:
      result = sub_412490(a4, a1, *(_DWORD *)(a3 + 16), 1, 0);
      break;
    case 0xB:
    case 0xC:
    case 0x33:
      result = sub_412E50(a4, a1, *(_DWORD *)(a3 + 16), 1);
      break;
    case 0x11:
    case 0x1F:
    case 0x20:
    case 0x2A:
    case 0x2B:
    case 0x34:
      result = SessionStringNameLookup(a4, a1, *(_DWORD *)(a3 + 16), 1, 0);
      break;
    case 0x12:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1D:
    case 0x1E:
    case 0x2E:
      result = TextAttributeLookup(a4, a1, *(_DWORD *)(a3 + 16), 1);
      break;
    case 0x15:
    case 0x1C:
      result = SessionStringNameLookup(a4, a1, *(_DWORD *)(a3 + 16), 1, 1);
      break;
    case 0x27:
    case 0x28:
      result = TextAttributeLookup_3710(a4, a1, *(_DWORD *)(a3 + 16), 1);
      break;
    case 0x31:
      result = MapCollisionShapeToBoneIndex(a4, a1, *(_DWORD *)(a3 + 16), 1);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

