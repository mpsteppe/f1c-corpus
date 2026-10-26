int __thiscall sub_47BF30(_BYTE *this)
{
  int v2; // eax
  char *v3; // eax
  int i; // edx
  _BYTE v6[61]; // [esp+8h] [ebp-C0h] BYREF
  __int16 v7; // [esp+45h] [ebp-83h]
  char v8; // [esp+47h] [ebp-81h]
  char v9[125]; // [esp+48h] [ebp-80h] BYREF
  __int16 v10; // [esp+C5h] [ebp-3h]
  char v11; // [esp+C7h] [ebp-1h]

  v6[0] = byte_5EA438[0];
  memset(&v6[1], 0, 0x3Cu);
  v7 = 0;
  v8 = 0;
  v2 = UIScreenTextAccessor(this);
  this[305] = 0;
  if ( v2 )
  {
    sub_587DD0(v6, v2, 63);
    v8 = 0;
  }
  StateCleanupNotification(this);
  sub_565EB0(&dword_8AD3B0);
  v3 = (char *)lpPathName;
  if ( !lpPathName )
    v3 = byte_5EA438;
  sub_565F80(aVcr_0, 1, (int)v3, 0);
  sub_566380(0);
  LinkedListPopFront_5f50(&dword_8AD3B0);
  for ( i = LinkedListNodeDataPeek(&dword_8AD3B0); i; i = LinkedListNodeDataPeek(&dword_8AD3B0) )
  {
    v9[0] = byte_5EA438[0];
    memset(&v9[1], 0, 0x7Cu);
    v10 = 0;
    v11 = 0;
    FileExtensionStripper(i, v9);
    if ( strlen(v9) )
      UIMenuItemCreator(v9, 0, 0, 0, 0);
    LinkedListNodePeek(&dword_8AD3B0);
  }
  UIListSearchAndSelect(v6, 0);
  return sub_565EB0(&dword_8AD3B0);
}

