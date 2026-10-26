_DWORD *__thiscall sub_5DA7A0(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  if ( (*(_BYTE *)this & 0x10) != 0 )
  {
    sub_5D75D0(this + 18, &v5, &v6, &v7);
    if ( a2 )
      *a2 = v5;
    if ( a3 )
      *a3 = v6;
    result = a4;
    if ( a4 )
      *a4 = v7;
  }
  else
  {
    result = (_DWORD *)this[133];
    this[135] = result;
    if ( result )
    {
      result = (_DWORD *)*result;
      if ( result )
      {
        if ( a2 )
          *a2 = result[54];
        if ( a3 )
          *a3 = result[55];
        if ( a4 )
        {
          result = (_DWORD *)result[56];
          *a4 = result;
        }
      }
    }
  }
  return result;
}
