char __thiscall StateResetAndConditionalInit(int this)
{
  char result; // al

  byte_7CD850 = 0;
  sub_475150((_DWORD *)this);
  result = dword_7D0E74;
  if ( !dword_7D0E74 )
  {
    result = byte_7D0FAC;
    if ( byte_7D0FAC )
    {
      result = *(_BYTE *)(this + 380);
      if ( !result )
      {
        result = StartNetworkUpdate(dword_7CD25C);
        *(_BYTE *)(this + 380) = 1;
      }
    }
  }
  return result;
}

