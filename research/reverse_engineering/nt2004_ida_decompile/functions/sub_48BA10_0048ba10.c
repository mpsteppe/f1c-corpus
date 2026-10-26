int __stdcall sub_48BA10(_DWORD *a1, _DWORD *a2)
{
  int result; // eax

  result = sub_4AB570(&unk_765B00);
  if ( result )
    return sub_4AB110(*a1, a1[1], *a2, a2[1], 16711680, result);
  return result;
}
