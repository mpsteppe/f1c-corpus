int __cdecl sub_58CDC0(int a1, void *a2)
{
  int result; // eax

  dword_7E4840 = a1;
  dword_7E483C = (int)a2;
  if ( a2 )
  {
    if ( a1 > 0 )
    {
      result = 0;
      memset(a2, 0, 4 * a1);
    }
  }
  return result;
}
