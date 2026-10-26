int __stdcall sub_411E90(int a1, int a2, _DWORD *a3, int a4)
{
  int v4; // esi
  int result; // eax
  char v6; // [esp+8h] [ebp-4h]

  v4 = -1;
  v6 = RandLCGRandomNumberGenerator() % 2 == 0;
  RandLCGRandomNumberGenerator();
  switch ( *(_DWORD *)(a2 + 12) )
  {
    case 1:
      result = TextAttributeLookup_3600(a4, a1, a3[4], 0);
      break;
    case 2:
      result = TextAttributeLookup_3710(a4, a1, a3[4], 0);
      break;
    case 4:
    case 0x2F:
      result = SessionStringNameLookup(a4, a1, a3[4], 0, v6);
      break;
    case 5:
    case 0xA:
    case 0x17:
      result = sub_412490(a4, a1, a3[5], 0, 1);
      break;
    case 6:
    case 0x1B:
    case 0x1D:
    case 0x26:
    case 0x35:
    case 0x36:
      result = sub_412490(a4, a1, a3[5], 0, 0);
      break;
    case 8:
    case 9:
    case 0xC:
    case 0x33:
      result = SessionStringNameLookup(a4, a1, a3[5], 0, v6);
      break;
    case 0xD:
    case 0x1C:
      result = SessionStringNameLookup(a4, a1, a3[5], 0, 0);
      break;
    case 0xE:
      result = sub_412E50(a4, a1, a3[4], 0);
      break;
    case 0x10:
      result = sub_412490(a4, a1, a3[4], 0, 0);
      break;
    case 0x11:
    case 0x34:
      result = EnumValueTranslation(a4, a3[5]);
      break;
    case 0x13:
    case 0x29:
      result = sub_412E50(a4, a1, a3[5], 0);
      break;
    case 0x14:
      result = SeasonSpecificTeamIDLookup(a4, a1, a3[4], 0);
      break;
    case 0x16:
    case 0x1A:
      result = TextAttributeLookup_3710(a4, a1, a3[5], 0);
      break;
    case 0x18:
    case 0x19:
      result = TextAttributeLookup_3600(a4, a1, a3[5], 0);
      break;
    case 0x1E:
      result = TextAttributeLookup(a4, a1, a3[5], 0);
      break;
    case 0x1F:
      result = sub_413820(a4, a1, a3[5], 0);
      break;
    case 0x20:
      result = CollisionShapeSizeClassify(a4, a1, a3[5], 0);
      break;
    case 0x22:
    case 0x23:
      result = sub_412490(a4, a1, a3[4], 0, 1);
      break;
    case 0x25:
      result = SessionStringNameLookup(a4, a1, a3[4], 0, 0);
      break;
    case 0x2A:
      result = sub_413820(a4, a1, a3[6], 0);
      break;
    case 0x2B:
      result = CollisionShapeSizeClassify(a4, a1, a3[6], 0);
      break;
    case 0x2C:
      goto LABEL_26;
    case 0x30:
      result = SeasonSpecificTeamIDLookup(a4, a1, a3[5], 0);
      break;
    case 0x32:
      result = MapCollisionShapeToBoneIndex(a4, a1, a3[5], 0);
      break;
    default:
      v4 = 0;
LABEL_26:
      result = v4;
      break;
  }
  return result;
}
