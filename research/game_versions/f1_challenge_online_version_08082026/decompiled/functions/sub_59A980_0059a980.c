_DWORD *__thiscall sub_59A980(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  _DWORD *result; // eax
  _DWORD *v5; // edi

  sub_59A8D8(this, 0);
  v2 = (_DWORD *)this[6];
  if ( v2 )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      sub_587BCF(v2);
      v2 = v3;
    }
    while ( v3 );
  }
  result = (_DWORD *)this[7];
  this[6] = 0;
  if ( result )
  {
    do
    {
      v5 = (_DWORD *)*result;
      sub_587BCF(result);
      result = v5;
    }
    while ( v5 );
  }
  this[7] = 0;
  return result;
}
