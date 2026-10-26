int __userpurge sub_501730@<eax>(int a1@<ecx>, char *a2@<edi>, char *a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // edi
  char *v7; // [esp+0h] [ebp-Ch] BYREF

  v7 = a2;
  v3 = __readeflags();
  v4 = __ROR4__(dword_16C6DDC, *(&loc_41E52C + 1));
  __writeeflags(v3);
  _InterlockedExchange((volatile __int32 *)&v7, v4);
  if ( sub_616840(v7) && sub_616610(*(_DWORD *)(a1 + 11784)) )
    return sub_616630(a3);
  else
    return 0;
}
