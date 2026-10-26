LPVOID *__thiscall sub_54FA50(LPVOID *this)
{
  LPVOID *result; // eax

  result = (LPVOID *)this[120];
  if ( result )
  {
    FreeWrapper_7bcf(result[2]);
    result = (LPVOID *)FreeWrapper_7bcf(this[120]);
    this[120] = 0;
  }
  return result;
}
