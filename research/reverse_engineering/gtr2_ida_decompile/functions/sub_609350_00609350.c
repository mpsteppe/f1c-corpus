int __thiscall sub_609350(_DWORD *this, int a2)
{
  int result; // eax
  int i; // esi

  result = *(_DWORD *)(a2 + 16);
  if ( result < this[2] )
  {
    sub_608C60(a2, 0);
    for ( i = 0; i < 1168; i += 292 )
      result = sub_609350(i + *(_DWORD *)(a2 + 288));
  }
  return result;
}
