_DWORD *__stdcall sub_644568(int a1)
{
  _DWORD *result; // eax

  result = &unk_736010;
  if ( off_913B0C <= &unk_736010 )
    return &unk_735FE8;
  while ( a1 != *result )
  {
    result += 9;
    if ( result >= (_DWORD *)off_913B0C )
      return &unk_735FE8;
  }
  return result;
}
