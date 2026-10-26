int __thiscall sub_4AE4C0(_DWORD **this, int a2, char *Source)
{
  char *v3; // ebp
  int result; // eax
  char *v6; // esi
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v3 = Source;
  result = 0;
  if ( Source )
  {
    Source = 0;
    v7 = 0;
    result = sub_4AE230(this, v3, &Source, &v7);
    if ( (int)Source > a2 )
    {
      result = 0;
      v6 = &v3[strlen(v3) + 1];
      do
      {
        if ( v3 == v6 )
          break;
        *--v6 = 0;
        result = sub_4AE230(this, v3, &Source, &v7);
      }
      while ( (int)Source > a2 );
    }
  }
  return result;
}
