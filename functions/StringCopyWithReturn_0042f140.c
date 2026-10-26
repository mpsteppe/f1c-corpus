char *__thiscall sub_42F140(int this, const char *a2)
{
  char *v2; // edi

  v2 = (char *)(this + 12);
  if ( BinarySearchInStringTable((_DWORD *)this, a2, (char *)(this + 12)) )
  {
    if ( a2 )
    {
      strcpy(v2, a2);
      return v2;
    }
    *v2 = 0;
  }
  return v2;
}
