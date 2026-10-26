char *__stdcall sub_4972A0(char *a1, char *Buffer)
{
  char *result; // eax
  char v3[128]; // [esp+0h] [ebp-80h] BYREF

  result = a1;
  if ( a1 )
  {
    if ( Buffer )
    {
      *Buffer = 0;
      sub_617A70(128);
      sprintf(Buffer, "%s", v3);
      result = &Buffer[strlen(Buffer)];
      if ( result > Buffer )
      {
        while ( *result != 46 )
        {
          if ( --result <= Buffer )
            return result;
        }
        *result = 0;
      }
    }
  }
  return result;
}
