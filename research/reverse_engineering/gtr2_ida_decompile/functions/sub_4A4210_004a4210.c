int __thiscall sub_4A4210(_DWORD *this)
{
  int v1; // edx
  int result; // eax
  const char *v3; // esi
  const char *v4; // [esp-Ch] [ebp-4Ch]
  char Buffer[61]; // [esp+0h] [ebp-40h] BYREF
  __int16 v6; // [esp+3Dh] [ebp-3h]
  char v7; // [esp+3Fh] [ebp-1h]

  v1 = this[63];
  result = 0;
  if ( v1 )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v6 = 0;
    v7 = 0;
    v3 = *(const char **)(v1 + 4);
    if ( !v3 )
      v3 = WindowName;
    switch ( *(_DWORD *)dword_B72314 )
    {
      case 1:
        sub_41D810(Buffer, 0x3Fu, "%s%s", v3, "_PRACTICE");
        break;
      case 2:
        sub_41D810(Buffer, 0x3Fu, "%s%s", v3, "_QUICKRACE");
        goto LABEL_7;
      case 3:
LABEL_7:
        if ( byte_B722E4 )
        {
          v4 = "_ENDURANCE";
          goto LABEL_16;
        }
        sub_41D810(Buffer, 0x3Fu, "%s%s", v3, "_GRANDPRIX");
        break;
      case 4:
        sub_41D810(Buffer, 0x3Fu, "%s%s", v3, "_CHAMP");
        break;
      case 5:
        if ( (unsigned __int8)sub_4735E0(&dword_B6CBA8) )
        {
          sub_41D810(Buffer, 0x3Fu, "%s%s", v3, "_MPHOST");
        }
        else
        {
          v4 = "_MPCLIENT";
LABEL_16:
          sub_41D810(Buffer, 0x3Fu, "%s%s", v3, v4);
        }
        break;
      case 7:
        v4 = "_GHOST";
        goto LABEL_16;
      case 8:
        sub_41D810(Buffer, 0x3Fu, "%s%s", v3, "_SCHOOL");
        break;
      default:
        break;
    }
    sub_4E1810(Buffer, 0);
    return -1;
  }
  return result;
}
