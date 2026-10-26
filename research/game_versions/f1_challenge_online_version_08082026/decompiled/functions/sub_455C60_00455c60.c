HRESULT __thiscall sub_455C60(LPVOID *ppvOut)
{
  HRESULT result; // eax

  if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(2, aDDevF119992002_13, 5225) )
    sub_4D7AA0(&unk_8AD25C, aEnteredHwinput_0);
  result = DirectInput8Create(hinst, 0x800u, &riidltf, ppvOut, 0);
  if ( !result )
  {
    sub_44EE10(ppvOut + 1, (int)hWnd, (unsigned __int8)byte_5EC4A4, 2);
    sub_44FA60(ppvOut + 866, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    sub_44FA60(ppvOut + 1121, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    sub_44FBE0(ppvOut + 1121);
    sub_44FBE0(ppvOut + 866);
    sub_44FA60(ppvOut + 866, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    sub_44FA60(ppvOut + 1121, (int)hWnd, (unsigned __int8)byte_5EC4A4);
    return sub_4533A0((int *)ppvOut);
  }
  return result;
}
