int __thiscall sub_4271B0(int this, int a2)
{
  int result; // eax

  result = *(_DWORD *)(this + 24024);
  if ( result != 8 && result != 7 )
  {
    if ( *(_DWORD *)(this + 24244) != 1 || (result = *(_DWORD *)(this + 80), *(_DWORD *)(result + 25300)) )
    {
      if ( dword_7D7540 != 2 && (!(unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80)) || (result = a2) != 0) )
      {
        sub_4C1900(this + 16588);
        *(_BYTE *)(this + 48) = 0;
        ++dword_7663DC;
        result = *(_DWORD *)(this + 24024);
        if ( result != 13 )
        {
          if ( result == 18 || result == 19 || result == 11 )
          {
            *(_DWORD *)(this + 24024) = 11;
            *(_DWORD *)(this + 23756) = 0;
          }
          else
          {
            *(_DWORD *)(this + 24024) = 7;
            *(_DWORD *)(this + 23756) = 0;
          }
        }
      }
    }
  }
  return result;
}
