int __thiscall sub_49A2F0(_DWORD *this)
{
  int i; // ebx
  _DWORD *j; // esi
  void *v4; // edi
  int result; // eax

  for ( i = 0; i < 26; ++i )
  {
    for ( j = (_DWORD *)this[i]; j; result = sub_587BCF(v4) )
    {
      v4 = j;
      j = (_DWORD *)j[6];
      sub_49A270((LPVOID *)v4);
    }
    this[i] = 0;
  }
  return result;
}
