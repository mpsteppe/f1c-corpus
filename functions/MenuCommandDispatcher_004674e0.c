int __thiscall MenuCommandDispatcher(int *this)
{
  int result; // eax
  _BYTE v3[64]; // [esp+4h] [ebp-40h] BYREF

  StateCleanupNotification(this);
  result = this[93] - 446;
  switch ( this[93] )
  {
    case 446:
      SetupIntegerFormatDS(&byte_7C56C0, *(float *)&dword_7C737C, v3);
      byte_7C7378 = 0;
      return UIMenuItemCreator(this, (int)v3, 0, 0, 0, 0);
    case 447:
    case 448:
    case 449:
    case 450:
      if ( byte_7D048C )
      {
        SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], (int)v3, 3);
        return UIMenuItemCreator(this, (int)v3, 0, 0, 0, 0);
      }
      else
      {
        if ( this[94] == 1 )
        {
          MessageStringFormatter(&byte_7C56C0, (int)v3);
          UIMenuItemCreator(this, (int)v3, 0, 0, 0, 0);
        }
        SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], (int)v3, 2);
        UIMenuItemCreator(this, (int)v3, 0, 0, 0, 0);
        SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], (int)v3, 1);
        UIMenuItemCreator(this, (int)v3, 0, 0, 0, 0);
        SetupDateAngleDisplayFormat(&byte_7C56C0, this[94], (int)v3, 0);
        return UIMenuItemCreator(this, (int)v3, 0, 0, 0, 0);
      }
    case 451:
    case 452:
    case 453:
    case 454:
      JUMPOUT(0x4675E5);
    case 455:
    case 456:
    case 457:
    case 458:
      ((void (__thiscall *)(char *, int, _BYTE *))((char *)&loc_4319DF + 1))(&byte_7C56C0, this[94], v3);
      return UIMenuItemCreator(this, (int)v3, 0, 0, 0, 0);
    default:
      return result;
  }
}
