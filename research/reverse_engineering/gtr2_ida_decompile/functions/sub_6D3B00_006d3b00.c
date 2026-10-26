char *__stdcall sub_6D3B00(int a1, int a2)
{
  char *result; // eax
  char v3; // cl

  result = (char *)malloc(a2 + 16);
  v3 = (char)result;
  if ( result )
  {
    result = (char *)((unsigned int)(result + 16) & 0xFFFFFFF0);
    *(result - 1) = ((v3 + 16) & 0xF0) - v3;
  }
  return result;
}
