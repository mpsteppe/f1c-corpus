int __usercall sub_5F8040@<eax>(int a1@<ecx>, __int32 a2@<ebp>)
{
  int v4; // [esp+0h] [ebp-8h]

  sub_5F6E20(a2, v4);
  memset((void *)(a1 + 204), 0, 0x3Cu);
  *(_WORD *)(a1 + 264) = 0;
  *(_BYTE *)(a1 + 266) = 0;
  memset((void *)(a1 + 268), 0, 0x3Cu);
  *(_WORD *)(a1 + 328) = 0;
  *(_BYTE *)(a1 + 330) = 0;
  *(_DWORD *)(a1 + 332) = 0;
  *(_DWORD *)(a1 + 336) = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 344) = 0;
  *(_DWORD *)(a1 + 356) = 0;
  *(_DWORD *)(a1 + 360) = 0;
  *(_DWORD *)(a1 + 352) = 0;
  *(_DWORD *)(a1 + 364) = 0;
  *(_DWORD *)(a1 + 368) = 0;
  *(_DWORD *)(a1 + 372) = 0;
  *(_DWORD *)(a1 + 376) = 0;
  *(_DWORD *)(a1 + 348) = 0x7FFFFFFF;
  *(_DWORD *)(a1 + 200) = 3;
  *(_DWORD *)(a1 + 340) = 7;
  return a1;
}
