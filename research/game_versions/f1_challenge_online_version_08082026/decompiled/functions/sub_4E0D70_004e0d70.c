int __stdcall sub_4E0D70(int *a1)
{
  int result; // eax

  result = *a1;
  if ( *a1 )
  {
    if ( *((_BYTE *)a1 + 64) )
    {
      sub_54BAA0(*a1);
      *((_BYTE *)a1 + 64) = 0;
      return sub_54C030(1, 1, 1, 0);
    }
  }
  return result;
}
