_DWORD *sub_635EE8()
{
  _DWORD *result; // eax

  result = (_DWORD *)_getptd();
  if ( (int)result[33] > 0 )
  {
    result = (_DWORD *)(_getptd() + 132);
    --*result;
  }
  return result;
}
