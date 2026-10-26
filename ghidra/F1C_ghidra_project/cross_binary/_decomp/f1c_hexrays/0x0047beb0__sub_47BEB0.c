// f1c  0x0047beb0  size=118
int __stdcall sub_47BEB0(int a1, const char *a2)
{
  int result; // eax
  const char *v3; // ecx
  char v4[128]; // [esp+4h] [ebp-80h] BYREF

  result = a1;
  if ( a1 )
  {
    if ( a2 )
    {
      *a2 = 0;
      sub_568910(128);
      sub_58815F(a2, "%s", v4);
      result = 0;
      v3 = &a2[strlen(a2)];
      if ( v3 > a2 )
      {
        while ( *v3 != 46 )
        {
          if ( --v3 <= a2 )
            return result;
        }
        *v3 = 0;
      }
    }
  }
  return result;
}
