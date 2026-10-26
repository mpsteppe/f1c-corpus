char sub_4A7860()
{
  char result; // al

  result = CGarageOnline::Connect((CGarageOnline *)dword_B6CBB4);
  if ( result )
  {
    CGarageOnline::GetFolderList((CGarageOnline *)dword_B6CBB4);
    return sub_494820();
  }
  return result;
}
