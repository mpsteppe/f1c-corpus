int __cdecl sub_58B465(int CharType)
{
  int v1; // ebx
  int result; // eax
  int CharTypea; // [esp+8h] [ebp+4h]

  v1 = 0;
  if ( dword_8D3F38 )
  {
    InterlockedIncrement(&dword_8D5A5C);
    if ( dword_8D5A58 )
    {
      InterlockedDecrement(&dword_8D5A5C);
      CriticalSectionLazyInitEnter(19);
      v1 = 1;
    }
    CharTypea = sub_58B4D4(CharType);
    if ( v1 )
      CritSectLeave(19);
    else
      InterlockedDecrement(&dword_8D5A5C);
    return CharTypea;
  }
  else
  {
    result = CharType;
    if ( CharType >= 65 && CharType <= 90 )
      return CharType + 32;
  }
  return result;
}
