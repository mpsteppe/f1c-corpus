int __cdecl sub_597F6D(PCNZCH lpString1, PCNZCH lpString2, int cchCount1)
{
  int v4; // eax

  if ( !cchCount1 )
    return 0;
  v4 = sub_59807B(dword_8D48E4, 1u, lpString1, cchCount1, lpString2, cchCount1, dword_8D46BC);
  if ( v4 )
    return v4 - 2;
  else
    return 0x7FFFFFFF;
}
