unsigned int __stdcall sub_4EDA50(const char *a1, float *a2)
{
  long double v2; // st7
  unsigned int result; // eax
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  v2 = *a2;
  Buffer[0] = 0;
  if ( fabs(v2) >= 0.001 || *a2 == 0.0 )
    sprintf(Buffer, "%.5f", *a2);
  else
    sprintf(Buffer, "%.10f", *a2);
  result = strlen(Buffer) + 1;
  qmemcpy((void *)&a1[strlen(a1)], Buffer, result);
  return result;
}
