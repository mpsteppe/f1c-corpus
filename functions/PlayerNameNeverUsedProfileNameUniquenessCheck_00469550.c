bool __thiscall sub_469550(_DWORD *this, const char *a2)
{
  int v3; // ebx
  int v5; // [esp+10h] [ebp-204h]
  _BYTE v6[509]; // [esp+14h] [ebp-200h] BYREF
  __int16 v7; // [esp+211h] [ebp-3h]
  char v8; // [esp+213h] [ebp-1h]

  if ( !a2 || !strlen(a2) )
    return 0;
  v3 = 0;
  v5 = this[276];
  if ( v5 <= 0 )
    return 1;
  while ( 1 )
  {
    FilenameFromLinkedList((int)this, v3);
    v6[0] = byte_5EA438[0];
    memset(&v6[1], 0, 0x1FCu);
    v7 = 0;
    v8 = 0;
    sub_568910(512);
    if ( !sub_588410(v6, a2) )
      break;
    if ( ++v3 >= v5 )
      return 1;
  }
  return byte_7D2E41 && !sub_588410(aPlayernameneve, a2);
}
