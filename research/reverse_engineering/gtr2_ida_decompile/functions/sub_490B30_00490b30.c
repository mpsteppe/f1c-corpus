_DWORD *__thiscall sub_490B30(int *this)
{
  _DWORD *result; // eax
  char v3; // bl
  int v4; // edx

  result = (_DWORD *)this[69];
  if ( !result && !this[70] )
    return result;
  v3 = 0;
  if ( result )
  {
    if ( *result )
      goto LABEL_7;
  }
  else if ( *(_BYTE *)this[70] == 1 )
  {
LABEL_7:
    v3 = 1;
  }
  if ( (unsigned __int8)sub_4CD650(this) )
  {
    v4 = *this;
    if ( v3 )
      this[67] = 4;
    else
      this[67] = 5;
  }
  else
  {
    v4 = *this;
    if ( v3 )
      this[67] = 0;
    else
      this[67] = 1;
  }
  return (_DWORD *)(*(int (__thiscall **)(int *, int))(v4 + 44))(this, this[67]);
}
