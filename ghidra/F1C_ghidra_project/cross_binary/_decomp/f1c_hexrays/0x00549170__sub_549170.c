// f1c  0x00549170  size=82
_DWORD *__thiscall sub_549170(_DWORD *this)
{
  int i; // esi
  _DWORD *result; // eax
  _DWORD *v4; // [esp+8h] [ebp-4h] BYREF

  for ( i = this[58]; i; i = *(_DWORD *)(i + 20) )
  {
    v4 = 0;
    sub_54BC60(i, &v4);
    result = v4;
    if ( v4 )
    {
      sub_5452B0((_DWORD *)*this, (int)v4);
      result = (_DWORD *)sub_5490B0(this, v4);
    }
  }
  return result;
}
