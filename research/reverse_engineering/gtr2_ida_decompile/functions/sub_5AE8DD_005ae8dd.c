int __stdcall sub_5AE8DD(DWORD Type)
{
  DWORD v2; // [esp+Ch] [ebp-4h] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  sub_5AF608();
  if ( Type )
  {
    if ( dword_904D4C == 0xFFFF )
    {
      dword_904D4C = 0;
      qmemcpy(&off_904AF8, off_904C20, 0x128u);
      sub_5AF4E9(&off_904AF8);
      if ( !sub_5AE703((BYTE *)4, "DisablePSGP", (BYTE *)&Type, 4u) )
        Type = 0;
      if ( sub_5AE703((BYTE *)4, "DisableD3DXPSGP", (BYTE *)&v2, 4u) )
        Type = v2;
      if ( Type != 1 )
      {
        if ( Type == 2 || !IsProcessorFeaturePresent(7u) )
        {
          if ( (sub_5AE83C((int)&savedregs) & 8) != 0 )
          {
            sub_5AEB53(&off_904AF8);
            dword_904D4C = 2;
          }
          else if ( IsProcessorFeaturePresent(6u) )
          {
            sub_5AE9E0(&off_904AF8);
            dword_904D4C = 3;
          }
        }
        else
        {
          sub_5AEDA2(&off_904AF8);
          dword_904D4C = 1;
        }
      }
    }
  }
  else
  {
    dword_904D4C = 0xFFFF;
    qmemcpy(&off_904AF8, off_904C20, 0x128u);
  }
  return dword_904D4C;
}
