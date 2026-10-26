int __stdcall sub_6B4CF0(_DWORD *a1)
{
  int result; // eax
  int v2; // esi

  result = (int)a1;
  v2 = a1[106];
  if ( a1[21] )
    result = (*(int (__stdcall **)(_DWORD *))(a1[116] + 8))(a1);
  ++*(_DWORD *)(v2 + 12);
  return result;
}
