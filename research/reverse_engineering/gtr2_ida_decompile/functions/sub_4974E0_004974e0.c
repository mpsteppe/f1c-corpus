char *__thiscall sub_4974E0(_DWORD *this)
{
  char *result; // eax
  char *v3; // edx
  char v4; // cl

  result = (char *)sub_4CE170(this);
  if ( result )
  {
    result = (char *)sub_4CE170(this);
    v3 = &byte_B6DC90;
    do
    {
      v4 = *result++;
      *v3++ = v4;
    }
    while ( v4 );
  }
  this[149] = 0;
  return result;
}
