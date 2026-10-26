int __usercall UIMouseClickHandler@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // eax
  int v5; // eax
  int v7; // [esp+4h] [ebp-8h] BYREF
  int v8; // [esp+8h] [ebp-4h] BYREF

  DualFieldRead(*(_DWORD **)(a1 + 64), &v8, &v7);
  v4 = sub_489F40((_DWORD *)a1, v7, 1);
  if ( v4 >= 0 )
  {
    v5 = ((int (__userpurge *)@<eax>(char@<al>, int@<ebx>, int@<edi>, int, int))(&KeyBindingArrayRemoveShift + 1))(
           *(_BYTE *)(a1 + 372),
           a2,
           a3,
           *(unsigned __int8 *)(a1 + 372),
           v4);
    IndexedArrayInsertWithShift(*(_BYTE *)(a1 + 372) == 0, v5, -1);
  }
  return 0;
}

