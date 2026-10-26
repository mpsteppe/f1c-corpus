// f1c  0x004cef30  size=106
int __thiscall sub_4CEF30(int *this)
{
  int result; // eax
  int v3; // ebx
  int i; // esi
  int v5; // eax
  int v6; // eax
  char v7[64]; // [esp+Ch] [ebp-40h] BYREF

  result = sub_545F40(dword_8AFE88);
  v3 = result;
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    for ( i = 0; i < result; ++i )
    {
      sub_548850(i);
      sub_547370(v7);
      v5 = sub_4CE860(this, v7);
      v6 = sub_4CE8D0(this, v5);
      sub_547280(v6, 4096);
      result = *(_DWORD *)(v3 + 16);
    }
  }
  return result;
}
