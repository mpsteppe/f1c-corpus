int __thiscall LinkedListDestructorWithConditionalCleanup(_DWORD *this)
{
  int result; // eax
  int i; // esi
  LPVOID *v4; // edi
  bool v5; // zf

  result = sub_4190C0(this);
  for ( i = this[104]; i; result = FreeWrapper_7bcf(v4) )
  {
    v4 = (LPVOID *)i;
    v5 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v5 && *v4 )
      FreeWrapper_7bcf(*v4);
  }
  this[104] = 0;
  this[105] = 0;
  this[106] = 0;
  this[107] = 0;
  return result;
}
