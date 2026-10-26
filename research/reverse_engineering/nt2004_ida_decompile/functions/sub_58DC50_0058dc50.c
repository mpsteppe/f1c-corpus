int __cdecl sub_58DC50(int a1)
{
  int result; // eax

  if ( !dword_7E4834 && ((dword_7E4834 = 1, sub_58E190(a1)) || sub_58DCD0(a1)) )
  {
    result = sub_58E1B0(a1);
    dword_7E4834 = 0;
  }
  else
  {
    dword_7E4834 = 0;
    return 0;
  }
  return result;
}
