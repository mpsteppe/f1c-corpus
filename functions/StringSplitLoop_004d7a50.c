char __thiscall sub_4D7A50(_DWORD *this, int a2, int a3, int a4)
{
  if ( *this < a2 )
    return 0;
  do
    a3 = sub_587C20(a3 + 1, &word_5C2AAC);
  while ( a3 );
  DebugLogWrite(this, a1212s5d);
  return 1;
}
