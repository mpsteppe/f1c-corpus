_DWORD *__thiscall sub_680164(int this)
{
  _DWORD *v2; // eax
  _DWORD *result; // eax

  v2 = (_DWORD *)sub_65B229(56);
  if ( v2 )
    result = sub_67F8DA(v2);
  else
    result = 0;
  if ( result )
    qmemcpy(result + 4, (const void *)(this + 16), 0x28u);
  return result;
}
