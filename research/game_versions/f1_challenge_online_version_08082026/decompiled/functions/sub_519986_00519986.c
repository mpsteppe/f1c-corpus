_DWORD *__thiscall sub_519986(_DWORD *this)
{
  _DWORD *result; // eax
  bool v2; // cf
  int v3; // ecx
  int v4; // ecx

  result = (_DWORD *)this[97];
  if ( (int)this[72] <= 1 )
  {
    v2 = this[32] < (unsigned int)(this[70] - 1);
    v3 = this[73];
    if ( v2 )
      v4 = *(_DWORD *)(v3 + 12);
    else
      v4 = *(_DWORD *)(v3 + 72);
    result[7] = v4;
  }
  else
  {
    result[7] = 1;
  }
  result[5] = 0;
  result[6] = 0;
  return result;
}
