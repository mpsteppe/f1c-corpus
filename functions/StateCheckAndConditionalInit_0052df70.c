int sub_52DF70()
{
  int result; // eax

  result = (unsigned __int8)CPUIDFeatureCheck();
  dword_8B0108 = result;
  if ( result )
    return LargeTableCopyFromROMData();
  return result;
}
