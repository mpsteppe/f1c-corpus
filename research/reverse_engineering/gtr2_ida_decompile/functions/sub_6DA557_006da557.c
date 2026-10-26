int __stdcall sub_6DA557(int a1)
{
  *(_WORD *)(a1 + 5808) = 0;
  *(_DWORD *)(a1 + 5812) = 0;
  *(_DWORD *)(a1 + 2832) = a1 + 140;
  *(_DWORD *)(a1 + 2844) = a1 + 2432;
  *(_DWORD *)(a1 + 2840) = &off_91AA50;
  *(_DWORD *)(a1 + 2852) = &off_91AA64;
  *(_DWORD *)(a1 + 2856) = a1 + 2676;
  *(_DWORD *)(a1 + 2864) = &unk_91AA78;
  *(_DWORD *)(a1 + 5804) = 8;
  return sub_6D95B2(a1);
}
