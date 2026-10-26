int __userpurge sub_53A410@<eax>(char *a1@<ebp>, int a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // ebp
  _DWORD *v5; // eax
  char *v6; // eax
  char *v8; // [esp+0h] [ebp-8h] BYREF

  v8 = a1;
  v3 = __readeflags();
  v4 = dword_16C6DF4 + 1422907904;
  __writeeflags(v3);
  _InterlockedExchange((volatile __int32 *)&v8, v4);
  if ( !sub_616840(v8) )
    return 1;
  if ( !dword_BE1CD8 )
    return 1;
  if ( !sub_616630((char *)(dword_BE1CD8 + 396 * dword_BE1CD4 + 260)) )
    return 1;
  v5 = (_DWORD *)sub_616630("VenueName");
  if ( !v5 )
    return 1;
  v6 = sub_48D380(v5);
  sub_630FE0(a2, v6, a3 - 1);
  *(_BYTE *)(a3 - 1 + a2) = 0;
  return 0;
}
