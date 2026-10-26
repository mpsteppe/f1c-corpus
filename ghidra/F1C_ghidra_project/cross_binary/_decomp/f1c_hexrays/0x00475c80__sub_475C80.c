// f1c  0x00475c80  size=55
int __stdcall sub_475C80(_DWORD *a1, _DWORD *a2)
{
  int result; // eax

  result = sub_495150(&unk_7CDE00);
  if ( result )
    return sub_494C20(*a1, a1[1], *a2, a2[1], 16711680, result);
  return result;
}
