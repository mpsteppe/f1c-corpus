// f1c  0x00590440  size=31
int __cdecl sub_590440(__int16 a1)
{
  _WORD *v1; // eax

  v1 = &unk_5E7204;
  while ( a1 != *v1 )
  {
    if ( (int)++v1 >= (int)&off_5E7218 )
      return 1;
  }
  return 0;
}
