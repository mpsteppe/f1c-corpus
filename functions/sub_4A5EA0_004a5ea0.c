char __thiscall sub_4A5EA0(_BYTE *this)
{
  char result; // al
  int v3; // [esp-4h] [ebp-8h]

  result = this[384];
  if ( !result )
  {
    StateChangeNotify((int)this, 2);
    v3 = *(_DWORD *)this;
    this[384] = 1;
    AISessionPhaseChange(dword_5EB978, v3);
    sub_4BC240(*(_DWORD *)this + 16436);
    result = dword_8ACFC8 - 2;
    if ( dword_8ACFC8 == 2 )
    {
      result = dword_7CEF84;
      if ( dword_7CEF84 )
      {
        if ( dword_7C56A4 == 7 )
          return DisqualificationHandler(aEnteringPitsUn);
        else
          return sub_4BBA90((int)aEnteringPitsUn, 1000.0);
      }
    }
  }
  return result;
}
