int __thiscall sub_480B40(int this)
{
  char *v3; // [esp-8h] [ebp-10h]
  int v4; // [esp-4h] [ebp-Ch]

  switch ( *(_DWORD *)(this + 816) )
  {
    case 0x217:
      byte_765440 = 0;
      sub_4A1A90(&byte_765440, 16);
      *(_BYTE *)(this + 271) = 0;
      return 0;
    case 0x218:
    case 0x21B:
      byte_765454 = 0;
      sub_4A1A90(&byte_765454, 16);
      *(_BYTE *)(this + 271) = 0;
      return 0;
    case 0x219:
    case 0x21C:
      byte_765468 = 0;
      sub_4A1A90(&byte_765468, 16);
      *(_BYTE *)(this + 271) = 0;
      return 0;
    case 0x21A:
    case 0x21D:
      byte_76547C = 0;
      sub_4A1A90(&byte_76547C, 16);
      *(_BYTE *)(this + 271) = 0;
      return 0;
    case 0x21E:
      byte_765490 = 0;
      *(_DWORD *)(this + 788) = 0;
      sub_4A1A90(&byte_765490, 23);
      *(_BYTE *)(this + 271) = 0;
      *(_DWORD *)(this + 808) = aWwwwwwwwwwwwww;
      return 0;
    case 0x21F:
      v4 = 15;
      byte_7654A8 = 0;
      v3 = &byte_7654A8;
      goto LABEL_16;
    case 0x220:
      sub_4A1A90(&byte_7654B8, 24);
      sub_4A1B90(24);
      *(_DWORD *)(this + 808) = aWwwwwwwwwwwwww_0;
      return 0;
    case 0x221:
      sub_4A1A90(&unk_7654D8, 63);
      sub_4A1B90(25);
      return 0;
    case 0x222:
      sub_4A1A90(byte_765518, 63);
      *(_DWORD *)(this + 788) = 2;
      sub_4A1B90(31);
      return 0;
    case 0x223:
      *(_DWORD *)(this + 788) = 0;
      sub_4A1B90(127);
      *(_BYTE *)(this + 273) = 1;
      return 0;
    case 0x224:
      byte_765558 = 0;
      sub_4A1A90(&byte_765558, 15);
      *(_BYTE *)(this + 271) = 0;
      return 0;
    case 0x225:
      v4 = 8;
      byte_765578[0] = 0;
      v3 = byte_765578;
      goto LABEL_16;
    case 0x226:
      v4 = 8;
      byte_765584 = 0;
      v3 = &byte_765584;
LABEL_16:
      *(_DWORD *)(this + 788) = 0;
      sub_4A1A90(v3, v4);
      *(_BYTE *)(this + 271) = 0;
      return 0;
    case 0x227:
    case 0x228:
    case 0x229:
    case 0x22A:
    case 0x22B:
    case 0x22C:
    case 0x22D:
    case 0x22E:
    case 0x22F:
    case 0x230:
    case 0x231:
    case 0x232:
      *(_DWORD *)(this + 788) = 0;
      sub_4A1B90(128);
      *(_BYTE *)(this + 271) = 0;
      return 0;
    default:
      return 0;
  }
}
