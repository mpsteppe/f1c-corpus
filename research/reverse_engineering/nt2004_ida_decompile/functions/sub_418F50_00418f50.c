char __thiscall sub_418F50(int this, int *a2)
{
  CHAR *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // eax
  int v7; // edi
  int v8; // ebx
  int v10; // [esp-4h] [ebp-114h]
  char Buffer[2]; // [esp+10h] [ebp-100h] BYREF
  _BYTE v12[252]; // [esp+12h] [ebp-FEh] BYREF
  __int16 v13; // [esp+10Eh] [ebp-2h]

  *(_WORD *)Buffer = *(_WORD *)String1;
  memset(v12, 0, sizeof(v12));
  v10 = *a2;
  v13 = 0;
  v3 = sub_418A30((__int16 **)&unk_629248, v10);
  sprintf(Buffer, "%s%s", byte_629250, v3);
  LOBYTE(v4) = *(_BYTE *)(this + 16);
  if ( (_BYTE)v4 )
  {
    v4 = operator new(8u);
    v5 = v4;
    if ( v4 )
    {
      *v4 = 0;
      v4[1] = -1;
      sub_578600(Buffer);
      v6 = operator new(0xCu);
      if ( v6 )
      {
        *v6 = v5;
        v6[1] = 0;
        *((_BYTE *)v6 + 8) = 1;
      }
      else
      {
        v6 = 0;
      }
      if ( *(_DWORD *)(this + 20) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 24) + 4) = v6;
      }
      else
      {
        *(_DWORD *)(this + 20) = v6;
        *(_DWORD *)(this + 28) = v6;
      }
      *(_DWORD *)(this + 24) = v6;
      v4 = (_DWORD *)(*(_DWORD *)(this + 32) + 1);
      *(_DWORD *)(this + 32) = v4;
    }
  }
  else if ( *(_DWORD *)(this + 12) )
  {
    if ( (byte_6292FC & 1) == 0 )
    {
      byte_6292FC |= 1u;
      dword_629300 = 0;
      dword_629304 = -1;
      sub_578600(&byte_629120);
      dword_629308 = -1;
      dword_62930C = -1;
      byte_629310 = 0;
      atexit(loc_4190F0);
    }
    sub_578600(&byte_629120);
    dword_629308 = -1;
    dword_62930C = -1;
    byte_629310 = 0;
    v7 = a2[2];
    v8 = a2[1];
    sub_578600(Buffer);
    dword_629308 = v8;
    dword_62930C = v7;
    byte_629310 = 1;
    LOBYTE(v4) = (*(int (__thiscall **)(_DWORD, int *, int, int))(**(_DWORD **)(this + 12) + 4))(
                   *(_DWORD *)(this + 12),
                   &dword_629300,
                   1,
                   1);
  }
  return (char)v4;
}
