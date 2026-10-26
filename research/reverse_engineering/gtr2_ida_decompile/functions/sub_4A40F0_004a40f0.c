int __thiscall sub_4A40F0(_DWORD *this)
{
  int result; // eax
  const CHAR *v2; // esi
  const char *v3; // [esp-8h] [ebp-28h]
  char Buffer; // [esp+0h] [ebp-20h] BYREF
  int v5; // [esp+1h] [ebp-1Fh]
  int v6; // [esp+5h] [ebp-1Bh]
  int v7; // [esp+9h] [ebp-17h]
  int v8; // [esp+Dh] [ebp-13h]
  int v9; // [esp+11h] [ebp-Fh]
  int v10; // [esp+15h] [ebp-Bh]
  int v11; // [esp+19h] [ebp-7h]
  __int16 v12; // [esp+1Dh] [ebp-3h]
  char v13; // [esp+1Fh] [ebp-1h]

  result = this[63];
  if ( result )
  {
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    Buffer = 0;
    v13 = 0;
    v2 = *(const CHAR **)(result + 4);
    if ( !v2 )
      v2 = WindowName;
    switch ( *(_DWORD *)dword_B72314 )
    {
      case 1:
      case 3:
      case 4:
        sub_41D810(&Buffer, 0x1Fu, "%s%s", v2, "_SINGLE");
        break;
      case 2:
        sub_41D810(&Buffer, 0x1Fu, "%s%s", v2, "_ARCADE");
        break;
      case 5:
        if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) )
        {
          v3 = "_MPCLIENT";
          goto LABEL_12;
        }
        sub_41D810(&Buffer, 0x1Fu, "%s%s", v2, "_MPHOST");
        break;
      case 7:
        v3 = "_TIMETRIAL";
LABEL_12:
        sub_41D810(&Buffer, 0x1Fu, "%s%s", v2, v3);
        break;
      case 8:
        sub_41D810(&Buffer, 0x1Fu, "%s%s", v2, "_SCHOOL");
        break;
      default:
        break;
    }
    sub_4E1810(&Buffer, 0);
    return -1;
  }
  return result;
}
