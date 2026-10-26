LPVOID __thiscall sub_560B30(LPVOID *this)
{
  LPVOID result; // eax

  result = this[107];
  if ( result )
  {
    result = (LPVOID)FreeWrapper_7bcf(this[107]);
    this[107] = 0;
  }
  return result;
}

