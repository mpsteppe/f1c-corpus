_DWORD *__thiscall sub_59C2E0(_DWORD *this)
{
  _DWORD *result; // eax
  int i; // edx

  result = this;
  for ( i = this[2]; !*(_BYTE *)(i + 21); i = *(_DWORD *)(i + 8) )
    result = (_DWORD *)i;
  return result;
}
