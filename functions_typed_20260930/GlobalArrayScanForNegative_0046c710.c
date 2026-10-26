int __thiscall GlobalArrayScanForNegative(_BYTE *this)
{
  int result; // eax
  int *v2; // ecx
  int *v3; // ecx

  result = 0;
  if ( this[372] )
  {
    v2 = &dword_7CD2B8;
    do
    {
      if ( *v2 < 0 )
        break;
      ++v2;
      ++result;
    }
    while ( (int)v2 < (int)&flt_7CD458 );
  }
  else
  {
    v3 = &dword_7CD470;
    do
    {
      if ( *v3 < 0 )
        break;
      ++v3;
      ++result;
    }
    while ( (int)v3 < (int)&flt_7CD610 );
  }
  return result;
}

