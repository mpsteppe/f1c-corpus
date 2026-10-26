_DWORD *__thiscall sub_67FAE0(int this)
{
  _DWORD *v2; // eax
  _DWORD *result; // eax

  v2 = (_DWORD *)sub_65B229(48);
  if ( v2 )
    result = sub_67EF10(v2);
  else
    result = 0;
  if ( result )
    qmemcpy(result + 4, (const void *)(this + 16), 0x20u);
  return result;
}
