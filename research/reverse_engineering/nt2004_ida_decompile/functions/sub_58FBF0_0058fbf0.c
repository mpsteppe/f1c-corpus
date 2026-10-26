int __cdecl sub_58FBF0(__int16 a1, __int16 a2)
{
  int result; // eax

  result = ++dword_7E4CB8;
  if ( dword_7E4CB8 >= 32 )
  {
    result = 0;
    dword_7E4CB8 = 0;
  }
  word_7FF960[2 * result] = a1;
  word_7FF962[2 * result] = a2;
  return result;
}
