int *sub_58DAB0()
{
  char *v0; // eax
  int *v1; // eax

  v0 = byte_7FFAAA;
  do
  {
    if ( *v0 )
    {
      *v0 = 0;
      --dword_7FFA40[(unsigned __int8)v0[1]];
    }
    v0 += 96;
  }
  while ( (int)v0 < (int)&unk_8000AA );
  v1 = dword_7FFA40;
  do
  {
    if ( *v1 )
      *v1 = 0;
    ++v1;
  }
  while ( (int)v1 < (int)dword_7FFA60 );
  return sub_58D340();
}
