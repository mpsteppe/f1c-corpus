_DWORD *__thiscall sub_4584C0(int this)
{
  unsigned int v2; // ecx
  _DWORD *result; // eax
  char v4; // [esp+0h] [ebp-4h]

  if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_4, 5504) )
    sub_500FE0((int)&unk_7D7920, aEnteredHwinput_2, v4);
  sub_451B90((float *)(this + 3264), 0, 0, dword_6152E8, dword_6152EC);
  sub_4514D0((_DWORD *)(this + 4));
  if ( dword_76AD4C )
    sub_452530((int *)(this + 5512));
  *(_BYTE *)(this + 10148) = 0;
  v2 = 33;
  result = (_DWORD *)(this + 8404);
  while ( !*result && result[1] == 89 )
  {
    ++v2;
    result += 11;
    if ( v2 > 0x28 )
      return result;
  }
  *(_BYTE *)(this + 10148) = 1;
  return result;
}
