_DWORD *__thiscall sub_5943E0(_DWORD *this)
{
  int i; // esi
  _DWORD *result; // eax
  _DWORD *v4; // [esp+8h] [ebp-4h] BYREF

  for ( i = this[58]; i; i = *(_DWORD *)(i + 20) )
  {
    v4 = 0;
    sub_59E8F0(i, &v4);
    result = v4;
    if ( v4 )
    {
      sub_597500(v4);
      result = (_DWORD *)sub_594320(this, v4);
    }
  }
  return result;
}
