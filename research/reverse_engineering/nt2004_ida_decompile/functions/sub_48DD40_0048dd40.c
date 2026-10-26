int __stdcall sub_48DD40(int a1, char *Buffer)
{
  int result; // eax
  char *v3; // ecx
  char v4[128]; // [esp+4h] [ebp-80h] BYREF

  result = a1;
  if ( a1 )
  {
    if ( Buffer )
    {
      *Buffer = 0;
      sub_57B340(128);
      sprintf(Buffer, "%s", v4);
      result = 0;
      v3 = &Buffer[strlen(Buffer)];
      if ( v3 > Buffer )
      {
        while ( *v3 != 46 )
        {
          if ( --v3 <= Buffer )
            return result;
        }
        *v3 = 0;
      }
    }
  }
  return result;
}
