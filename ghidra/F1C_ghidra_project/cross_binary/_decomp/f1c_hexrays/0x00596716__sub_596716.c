// f1c  0x00596716  size=93
int __cdecl sub_596716(LPWSTR lpWideCharStr, LPCCH lpMultiByteStr, int a3)
{
  int v3; // ebx
  int v5; // [esp+1Ch] [ebp+10h]

  InterlockedIncrement(&dword_8D5A5C);
  v3 = 0;
  if ( dword_8D5A58 )
  {
    InterlockedDecrement(&dword_8D5A5C);
    sub_58DFEA(19);
    v3 = 1;
  }
  v5 = sub_596773(lpWideCharStr, lpMultiByteStr, a3);
  if ( v3 )
    sub_58E04B(19);
  else
    InterlockedDecrement(&dword_8D5A5C);
  return v5;
}
