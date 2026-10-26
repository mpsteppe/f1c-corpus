void *__cdecl sub_554E20(jmp_buf Buf, size_t Size)
{
  void *result; // eax

  if ( !Buf || !Size )
    return 0;
  result = malloc(Size);
  if ( !result )
    sub_54E7FC(Buf, (int)"Out of Memory");
  return result;
}
