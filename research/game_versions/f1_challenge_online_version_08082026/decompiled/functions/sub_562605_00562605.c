char __fastcall sub_562605(char *a1, char *a2)
{
  char result; // al

  result = *a1;
  *a1 = *a2;
  *a2 = result;
  return result;
}
