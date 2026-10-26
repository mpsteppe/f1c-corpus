int __stdcall sub_54CE1B(int Data)
{
  BYTE v2[4]; // [esp+8h] [ebp-4h] BYREF

  if ( Data )
  {
    if ( dword_617618 == 0xFFFF )
    {
      dword_617618 = 0;
      qmemcpy(&off_617448, off_617530, 0xE4u);
      sub_5548B5(&off_617448);
      if ( !sub_54CB70(4, "DisablePSGP", (LPBYTE)&Data, 4u) )
        Data = 0;
      if ( sub_54CB70(4, "DisableD3DXPSGP", v2, 4u) )
        Data = *(_DWORD *)v2;
      if ( Data != 1 )
      {
        if ( sub_54CD67(7u) )
        {
          sub_554233(&off_617448);
          dword_617618 = 1;
        }
        else if ( sub_54CD67(0xAu) )
        {
          sub_554050(&off_617448);
          dword_617618 = 2;
        }
        else if ( sub_54CD67(6u) )
        {
          sub_553F40(&off_617448);
          dword_617618 = 3;
        }
      }
    }
  }
  else
  {
    dword_617618 = 0xFFFF;
    qmemcpy(&off_617448, off_617530, 0xE4u);
  }
  return dword_617618;
}
