int __fastcall sub_5E06B0(int a1, int *a2)
{
  int result; // eax
  char String[256]; // [esp+4h] [ebp-100h] BYREF

  for ( result = sub_5DF750(a2); result != 1; result = sub_5DF750(a2) )
  {
    result = *a2;
    if ( *a2 == 3 )
      break;
    if ( result != 2 )
    {
      if ( sub_5DF240((int)a2, "INSTANCE", String, 0, 0, 0, 0, 0, 0, 0) )
        sub_5E06B0(String, a2);
      if ( sub_5DF240((int)a2, "MESHFILE", String, 0, 0, 0, 0, 0, 0, 0) )
        ++dword_FB2E8C;
    }
  }
  return result;
}
