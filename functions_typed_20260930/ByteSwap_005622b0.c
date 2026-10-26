char __fastcall sub_5622B0(char *a1, char *a2)
{
  char result; // al

  result = *a1;
  *a1 = *a2;
  *a2 = result;
  return result;
}

