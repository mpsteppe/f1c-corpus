char __userpurge sub_4EC8E0@<al>(int a1@<edi>, int a2, int a3, int a4)
{
  int v4; // eax
  void *v5; // esi
  int v6; // eax
  int *v8; // [esp+4h] [ebp-11Ch] BYREF
  _DWORD v9[2]; // [esp+8h] [ebp-118h] BYREF
  char Buffer[8]; // [esp+10h] [ebp-110h] BYREF
  int v11; // [esp+18h] [ebp-108h] BYREF
  char v12; // [esp+110h] [ebp-10h]
  char v13; // [esp+114h] [ebp-Ch]
  const char *retaddr; // [esp+120h] [ebp+0h]

  v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 35);
  v5 = (void *)v4;
  v11 = 0;
  if ( v4 )
  {
    v9[0] = a1;
    v8 = &v11;
    LOBYTE(v9[0]) = 0;
    if ( (unsigned __int8)sub_4CE380() )
    {
      *(_WORD *)((char *)v9 + 1) = 0;
      HIBYTE(v9[0]) = 0;
      sub_4CE140(v5, (int)v9);
      sprintf(Buffer, "%s%s", retaddr, (const char *)&v8);
      LOBYTE(v4) = sub_4D3F60();
    }
    else
    {
      *(_WORD *)((char *)v9 + 1) = 0;
      HIBYTE(v9[0]) = 0;
      sub_4CE140(v5, (int)v9);
      v6 = sprintf(Buffer, "%s%s", retaddr, (const char *)&v8);
      v9[0] = sub_4D93B0(v6, (int)Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      LOBYTE(v4) = sub_4CE380();
      if ( (_BYTE)v4 )
      {
        if ( v13 || (LOBYTE(v4) = v12) != 0 )
          LOBYTE(v4) = sub_4CE460(v5);
      }
    }
  }
  return v4;
}
