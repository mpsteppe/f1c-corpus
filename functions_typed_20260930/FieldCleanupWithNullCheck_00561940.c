LPVOID __thiscall sub_561940(LPVOID *this)
{
  LPVOID result; // eax

  result = this[123];
  if ( result )
  {
    result = (LPVOID)FreeWrapper_7bcf(this[123]);
    this[123] = 0;
  }
  return result;
}

