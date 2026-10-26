char *sub_4EA010()
{
  if ( dword_8ADAF8 >= 32 )
    return (char *)&unk_8ADAC0;
  return (char *)&unk_8AD3F8 + 56 * dword_8ADAF8++;
}
