int __stdcall sub_6816E7(int a1)
{
  int result; // eax

  result = dword_FB9E50;
  if ( !dword_FB9E50 )
    return sub_67EB7E((_DWORD *)dword_FB9E54, a1, 0x10u);
  dword_FB9E50 = *(_DWORD *)(dword_FB9E50 + 120);
  return result;
}
