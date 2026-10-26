BOOL __cdecl sub_58DA40(int a1)
{
  BOOL result; // eax

  result = (unsigned int)dword_7FFA60[a1] < 0x10;
  if ( (unsigned int)dword_7FFA80[a1] >= 0x10 )
    return 0;
  return result;
}
