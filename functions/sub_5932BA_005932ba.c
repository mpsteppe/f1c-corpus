int sub_5932BA()
{
  int result; // eax

  result = dword_8D3EBC;
  if ( dword_8D3EBC == 1 || !dword_8D3EBC && dword_5E65B4 == 1 )
  {
    sub_5932F3(0xFCu);
    if ( dword_8D41AC )
      dword_8D41AC();
    return sub_5932F3(0xFFu);
  }
  return result;
}
