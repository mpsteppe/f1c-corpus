CHAR *__stdcall sub_46C2E0(int a1)
{
  if ( a1 >= (dword_764F14 + dword_764ECC) / 2 )
  {
    if ( a1 >= (dword_764F0C + dword_764F14) / 2 )
    {
      if ( a1 >= 10000 )
      {
        if ( sub_41F230(dword_62A170, off_600E2C, Destination) )
        {
          strncpy(Destination, off_600E2C, 0x1FFu);
          goto LABEL_12;
        }
      }
      else if ( sub_41F230(dword_62A170, aBroadband, Destination) )
      {
        strncpy(Destination, aBroadband, 0x1FFu);
        goto LABEL_12;
      }
    }
    else if ( sub_41F230(dword_62A170, aIsdn, Destination) )
    {
      strncpy(Destination, aIsdn, 0x1FFu);
      goto LABEL_12;
    }
  }
  else if ( sub_41F230(dword_62A170, aModem, Destination) )
  {
    strncpy(Destination, aModem, 0x1FFu);
LABEL_12:
    byte_62A37B = 0;
  }
  return Destination;
}
