int __thiscall sub_4F6A50(int *this)
{
  int result; // eax
  int v3; // ebx
  int i; // esi
  int v5; // eax
  int v6; // eax
  char v7[64]; // [esp+Ch] [ebp-40h] BYREF

  result = sub_598170(dword_7DA9B8);
  v3 = result;
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    for ( i = 0; i < result; ++i )
    {
      sub_59A620(i);
      sub_599750(v7);
      v5 = sub_4F6360(this, v7);
      v6 = sub_4F63D0(this, v5);
      sub_599660(v6, 4096);
      result = *(_DWORD *)(v3 + 16);
    }
  }
  return result;
}
