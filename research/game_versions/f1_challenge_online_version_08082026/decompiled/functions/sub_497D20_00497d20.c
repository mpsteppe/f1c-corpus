char __thiscall sub_497D20(_DWORD *this, const char *a2)
{
  int v2; // esi
  char *v3; // eax
  int v4; // eax
  void (__thiscall ***v5)(_DWORD, int); // esi
  int v7; // eax
  int v8; // ebp
  int v9; // ecx
  int i; // eax
  void *v11; // eax
  bool v12; // zf
  LPVOID v14[4]; // [esp+14h] [ebp-14h] BYREF
  char v15; // [esp+24h] [ebp-4h]

  if ( !a2 )
    return 0;
  if ( !sub_497E80(a2) )
  {
    v2 = dword_8AC4C4;
    if ( !dword_8AC4C4 )
      return 0;
    v3 = (char *)dword_5EC400;
    if ( !dword_5EC400 )
      v3 = byte_5EA438;
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)dword_8AC4C4 + 68))(dword_8AC4C4, v3);
    v14[0] = 0;
    v14[1] = (LPVOID)-1;
    sub_566650(byte_5EA438);
    sub_566650(a2);
    v14[2] = 0;
    v14[3] = 0;
    v15 = 0;
    v4 = (*(int (__thiscall **)(int, LPVOID *, _DWORD, int))(*(_DWORD *)v2 + 92))(v2, v14, 0, 15);
    v5 = (void (__thiscall ***)(_DWORD, int))v4;
    if ( !v4 )
    {
LABEL_9:
      if ( v14[0] )
        sub_587BCF(v14[0]);
      return 0;
    }
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4) )
    {
      (**v5)(v5, 1);
      goto LABEL_9;
    }
    v7 = sub_587C03(88);
    if ( v7 )
    {
      *(_DWORD *)(v7 + 80) = 0;
      *(_DWORD *)(v7 + 84) = 0;
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    strcpy((char *)v8, a2);
    *(_DWORD *)(v8 + 80) = v5;
    v9 = this[67];
    if ( v9 )
    {
      for ( i = *(_DWORD *)(v9 + 84); i; i = *(_DWORD *)(i + 84) )
        v9 = i;
      *(_DWORD *)(v9 + 84) = v8;
    }
    else
    {
      this[67] = v8;
    }
    v11 = v14[0];
    v12 = v14[0] == 0;
    ++this[68];
    if ( !v12 )
      sub_587BCF(v11);
  }
  return 1;
}
