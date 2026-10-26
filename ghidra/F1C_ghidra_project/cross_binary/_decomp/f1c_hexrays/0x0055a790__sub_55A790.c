// f1c  0x0055a790  size=374
int __thiscall sub_55A790(_DWORD *this, char *a2, _DWORD *a3)
{
  int v4; // eax
  CHAR *v5; // ebx
  int v7; // [esp+8h] [ebp-114h]
  char v8[16]; // [esp+Ch] [ebp-110h] BYREF
  char v9[256]; // [esp+1Ch] [ebp-100h] BYREF

  v7 = 0;
  v4 = sub_587C03(264);
  if ( v4 )
    v5 = (CHAR *)sub_548E20(v4);
  else
    v5 = 0;
  *(_DWORD *)v5 = this;
  while ( sub_559A70(a3) != 1 )
  {
    if ( *a3 == 3 )
      break;
    if ( *a3 != 2 )
    {
      sub_559E20((int)a3, (int)aType, v8, 0);
      if ( sub_559E20((int)a3, (int)aInstance, v9, 0) )
        sub_549020(v5, v9);
      if ( sub_559E20((int)a3, (int)aLight, v9, 0) )
        sub_5491D0(v5, (int)v9);
      if ( sub_559E20((int)a3, (int)aLink, v9, 0) )
        sub_5492F0(v5, v9);
      if ( sub_559E20((int)a3, (int)aAdjacent, v9, 0) )
        sub_5493B0(v5, v9);
    }
  }
  if ( !strcmp(v8, aStorage) )
    v7 = 64;
  if ( !strcmp(v8, aInstance) )
    v7 = 128;
  sub_548E80(v5, a2, v7);
  sub_54A270(this, (int)v5);
  return 0;
}
