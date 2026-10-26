_DWORD *__thiscall sub_59A980(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  _DWORD *result; // eax
  _DWORD *v5; // edi

  CallbackChainIteration(this, 0);
  v2 = (_DWORD *)this[6];
  if ( v2 )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      FreeWrapper_7bcf(v2);
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
      FreeWrapper_7bcf(result);
      result = v5;
    }
    while ( v5 );
  }
  this[7] = 0;
  return result;
}
