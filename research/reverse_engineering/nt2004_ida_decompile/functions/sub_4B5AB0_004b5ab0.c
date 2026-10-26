int __stdcall sub_4B5AB0(int a1, int a2)
{
  int result; // eax

  result = dword_75AAC4;
  if ( *(_DWORD *)(dword_75AAC4 + 4448) )
    result = sub_5A2930(a1, a2, 0);
  if ( *(_DWORD *)(dword_75AAC4 + 4412) )
    return sub_5A2930(a1, a2, 0);
  return result;
}
