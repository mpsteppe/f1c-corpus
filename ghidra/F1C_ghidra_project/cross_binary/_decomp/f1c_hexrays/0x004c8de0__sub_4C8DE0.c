// f1c  0x004c8de0  size=251
LPVOID __stdcall sub_4C8DE0(unsigned int a1, int a2)
{
  LPVOID result; // eax
  const char *v3; // eax
  LPVOID v4[2]; // [esp+10h] [ebp-118h] BYREF
  int v5; // [esp+18h] [ebp-110h]
  int v6; // [esp+1Ch] [ebp-10Ch]
  char v7; // [esp+20h] [ebp-108h]
  _BYTE v8[260]; // [esp+24h] [ebp-104h] BYREF

  if ( !dword_8AC4C4 )
  {
LABEL_4:
    result = (LPVOID)dword_8AC4D0;
    if ( !dword_8AC4D0 )
      return result;
    goto LABEL_5;
  }
  result = (LPVOID)dword_8AC4D0;
  if ( !dword_8AC4D0 )
  {
    dword_8AC4D0 = (*(int (**)(void))(*(_DWORD *)dword_8AC4C4 + 96))();
    goto LABEL_4;
  }
LABEL_5:
  if ( a1 < 8 )
  {
    v4[0] = 0;
    v4[1] = (LPVOID)-1;
    sub_566650(byte_5EA438);
    v3 = (const char *)dword_5EC3E0;
    v5 = -1;
    v6 = -1;
    v7 = 0;
    if ( !dword_5EC3E0 )
      v3 = byte_5EA438;
    sub_58815F(v8, "%s%s", v3, off_5D3234[a1]);
    sub_566650(v8);
    v5 = -1;
    v6 = -1;
    v7 = 0;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_8AC4D0 + 28))(dword_8AC4D0, a2);
    (*(void (__thiscall **)(int, LPVOID *, int, _DWORD))(*(_DWORD *)dword_8AC4D0 + 4))(dword_8AC4D0, v4, 1, 0);
    result = v4[0];
    if ( v4[0] )
      return (LPVOID)sub_587BCF(v4[0]);
  }
  return result;
}
