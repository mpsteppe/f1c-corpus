// f1c  0x00566c30  size=130
bool sub_566C30(int *a1, int a2, ...)
{
  unsigned int v3; // kr04_4
  char v4[2048]; // [esp+Ch] [ebp-800h] BYREF
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, a2);
  if ( !a1[4] )
  {
    sub_58A163(*a1, a2, va);
    return 0;
  }
  sub_58AC95(v4, a2, va);
  v3 = strlen(v4) + 1;
  if ( (int)(v3 - 1) <= 0 )
    return 0;
  return sub_535220(*a1, (int)v4, v3 - 1) == v3 - 1;
}
