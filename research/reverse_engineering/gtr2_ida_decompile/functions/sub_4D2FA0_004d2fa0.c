_DWORD *__thiscall sub_4D2FA0(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // edx
  int v4; // edx
  int v5; // edx

  result = a2;
  if ( a2 )
  {
    this[13] = a2;
    v3 = a2[4] - a2[3];
    if ( v3 <= 0 )
      v4 = 0;
    else
      v4 = v3 + 1;
    this[1] = v4;
    v5 = a2[2] - a2[1];
    if ( v5 <= 0 )
    {
      result = 0;
      this[2] = 0;
    }
    else
    {
      result = (_DWORD *)(v5 + 1);
      this[2] = v5 + 1;
    }
  }
  return result;
}
