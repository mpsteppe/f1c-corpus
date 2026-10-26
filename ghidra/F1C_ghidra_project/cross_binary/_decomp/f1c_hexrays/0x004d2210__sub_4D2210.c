// f1c  0x004d2210  size=65
int sub_4D2210()
{
  int result; // eax
  int i; // esi
  int v2; // eax

  result = dword_5C329C;
  for ( i = 0; i < dword_5C329C; ++i )
  {
    v2 = dword_7C54F0[i];
    if ( *(_DWORD *)(v2 + 13000) <= 1u )
      sub_4BC9B0((int *)(v2 + 16436), 1, 0);
    result = dword_5C329C;
  }
  return result;
}
