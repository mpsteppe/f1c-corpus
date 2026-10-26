void *__stdcall sub_6B7269(int a1, size_t Size)
{
  void *result; // eax

  if ( !a1 || !Size )
    return 0;
  result = malloc(Size);
  if ( !result )
    sub_679F05(a1, (int)"Out of Memory");
  return result;
}
