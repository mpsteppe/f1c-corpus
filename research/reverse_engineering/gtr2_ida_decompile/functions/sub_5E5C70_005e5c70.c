_DWORD *__thiscall sub_5E5C70(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  if ( this[12] )
  {
    sub_5EC230(&v5, &v6, &v7);
    if ( a2 )
      *a2 = v5;
    if ( a3 )
      *a3 = v6;
    result = a4;
    if ( a4 )
      *a4 = v7;
  }
  return result;
}
