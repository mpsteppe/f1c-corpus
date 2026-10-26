int __stdcall sub_423070(int a1)
{
  int result; // eax
  char v2[80]; // [esp+4h] [ebp-50h] BYREF

  result = a1;
  if ( a1 )
  {
    result = sub_587C20(a1, aConfig);
    if ( result )
    {
      result = sub_5887ED(result, "config=%s", v2);
      if ( result == 1 )
        return sub_566650(v2);
    }
  }
  return result;
}
