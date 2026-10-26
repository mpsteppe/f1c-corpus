int __stdcall sub_50FEA7(int Data)
{
  if ( Data )
  {
    if ( dword_5D7998 == 0xFFFF )
    {
      dword_5D7998 = 0;
      qmemcpy(&off_5D77C8, off_5D78B0, 0xE4u);
      FunctionTableInit(&off_5D77C8);
      if ( !sub_50FBFC(4, "DisableD3DXPSGP", (LPBYTE)&Data, 4u) )
        Data = 0;
      if ( Data != 1 )
      {
        if ( OSVersionDetection(7u) )
        {
          sub_5172A5(&off_5D77C8);
          dword_5D7998 = 1;
        }
        else if ( OSVersionDetection(0xAu) )
        {
          sub_5170C0(&off_5D77C8);
          dword_5D7998 = 2;
        }
        else if ( OSVersionDetection(6u) )
        {
          UnidentifiedLogicFunctionTable(&off_5D77C8);
          dword_5D7998 = 3;
        }
      }
    }
  }
  else
  {
    dword_5D7998 = 0xFFFF;
    qmemcpy(&off_5D77C8, off_5D78B0, 0xE4u);
  }
  return dword_5D7998;
}

