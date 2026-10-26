int __thiscall sub_4DBE00(_DWORD **this, char *String1)
{
  int v2; // esi
  int v3; // edi
  _BYTE *v5; // eax
  _BYTE *v6; // eax
  void *v7; // eax
  void *v8; // eax

  if ( !String1 )
    return 0;
  v2 = (*(int (__thiscall **)(_DWORD *, char *))(*this[194] + 24))(this[194], String1);
  if ( !v2 )
  {
    v3 = 0;
    while ( _stricmp(String1, (&off_75AD00)[v3]) )
    {
      if ( ++v3 >= 21 )
        return v2;
    }
    switch ( v3 )
    {
      case 0:
        v5 = operator new(0x114u);
        if ( !v5 )
          goto LABEL_48;
        v6 = sub_4D8C10(v5, 0);
        break;
      case 1:
        if ( !operator new(0x11Cu) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4DB5B0();
        break;
      case 2:
        if ( !operator new(0x120u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9F40();
        break;
      case 3:
        if ( !operator new(0x118u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D8D20(1, -1);
        break;
      case 4:
        if ( !operator new(0x118u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D8D20(2, -1);
        break;
      case 5:
        if ( !operator new(0x118u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D8D20(3, -1);
        break;
      case 6:
        if ( !operator new(0x13Cu) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9820();
        break;
      case 7:
        if ( !operator new(0x330u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D98D0();
        break;
      case 8:
        v7 = operator new(0x254u);
        if ( !v7 )
          goto LABEL_48;
        v6 = (_BYTE *)((int (__thiscall *)(void *))dword_4D9300)(v7);
        break;
      case 9:
        if ( !operator new(0x118u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4DB620();
        break;
      case 10:
        if ( !operator new(0x138u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D8CA0();
        break;
      case 11:
        if ( !operator new(0x10Cu) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D8C60();
        break;
      case 13:
        if ( !operator new(0x198u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9B00();
        break;
      case 14:
        if ( !operator new(0x12Cu) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9BD0();
        break;
      case 15:
        if ( !operator new(0x134u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9C70();
        break;
      case 16:
        if ( !operator new(0x110u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9D10();
        break;
      case 17:
        if ( !operator new(0x1B4u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9D50();
        break;
      case 18:
        v8 = operator new(0x114u);
        if ( !v8 )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9E90(v8);
        break;
      case 19:
        if ( !operator new(0x120u) )
          goto LABEL_48;
        v6 = (_BYTE *)sub_4D9EE0();
        break;
      case 20:
        if ( operator new(0x158u) )
          v6 = (_BYTE *)sub_4DA4E0();
        else
LABEL_48:
          v6 = 0;
        break;
      default:
        return v2;
    }
    v2 = (int)v6;
    if ( !v6 )
      return v2;
  }
  return off_16C92F8(String1);
}
