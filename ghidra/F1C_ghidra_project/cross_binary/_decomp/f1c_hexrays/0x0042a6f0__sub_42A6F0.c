// f1c  0x0042a6f0  size=69
char __thiscall sub_42A6F0(int this)
{
  char result; // al

  sub_4BD760(this + 16436);
  result = *(_BYTE *)(this + 17796);
  if ( !result )
    ++*(_DWORD *)(this + 17888);
  if ( dword_7C56A4 == 7 )
    *(_DWORD *)(this + 17716) = 0;
  *(float *)(this + 17532) = dbl_8AFEA0 + 4.0;
  return result;
}
