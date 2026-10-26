int __thiscall sub_418D00(int this)
{
  int v2; // ebx
  int v3; // eax
  const char *v4; // eax
  char Destination[125]; // [esp+8h] [ebp-80h] BYREF
  __int16 v7; // [esp+85h] [ebp-3h]
  char v8; // [esp+87h] [ebp-1h]

  v2 = 1;
  if ( *(_BYTE *)(this + 8) )
    goto LABEL_9;
  if ( !*(_DWORD *)(this + 12) )
  {
    if ( dword_7D6BB0 )
    {
      v3 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_7D6BB0 + 100))(dword_7D6BB0);
      *(_DWORD *)(this + 12) = v3;
      if ( v3 )
      {
        sub_419190(flt_7678BC);
        Destination[0] = byte_629120;
        memset(&Destination[1], 0, 0x7Cu);
        v7 = 0;
        v8 = 0;
        v4 = dword_62A108;
        if ( !dword_62A108 )
          v4 = &byte_629120;
        strncpy(Destination, v4, 0x7Fu);
        v8 = 0;
        if ( sub_418B00(Destination) )
        {
          *(_BYTE *)(this + 8) = 1;
LABEL_9:
          v2 = 0;
        }
      }
    }
  }
  if ( !*(_BYTE *)(this + 8) )
    sub_419130(this);
  return v2;
}
