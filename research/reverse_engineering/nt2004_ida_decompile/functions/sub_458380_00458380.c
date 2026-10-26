HRESULT __thiscall sub_458380(LPVOID *ppvOut)
{
  HRESULT result; // eax
  char v3; // [esp+0h] [ebp-4h]

  if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_4, 5460) )
    sub_500FE0((int)&unk_7D7920, aEnteredHwinput_0, v3);
  result = DirectInput8Create(hinst, 0x800u, &riidltf, ppvOut, 0);
  if ( !result )
  {
    sub_451250(ppvOut + 1, (int)hWndParent, (unsigned __int8)byte_62A154, 2);
    sub_451FF0(ppvOut + 868, (int)hWndParent, (unsigned __int8)byte_62A154);
    sub_451FF0(ppvOut + 1123, (int)hWndParent, (unsigned __int8)byte_62A154);
    sub_452190(ppvOut + 1123);
    sub_452190(ppvOut + 868);
    sub_451FF0(ppvOut + 868, (int)hWndParent, (unsigned __int8)byte_62A154);
    sub_451FF0(ppvOut + 1123, (int)hWndParent, (unsigned __int8)byte_62A154);
    return sub_455960(ppvOut);
  }
  return result;
}
