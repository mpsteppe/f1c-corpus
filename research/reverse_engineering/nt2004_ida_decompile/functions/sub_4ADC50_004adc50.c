char __thiscall sub_4ADC50(_DWORD *this, char *String2)
{
  int v2; // esi
  CHAR *v3; // eax
  int v4; // eax
  void (__thiscall ***v5)(_DWORD, int); // esi
  char *v7; // eax
  char *v8; // ebp
  int v9; // ecx
  int i; // eax
  void *v11; // eax
  bool v12; // zf
  LPVOID v14[4]; // [esp+14h] [ebp-14h] BYREF
  char v15; // [esp+24h] [ebp-4h]

  if ( !String2 )
    return 0;
  if ( !sub_4ADDB0(String2) )
  {
    v2 = dword_7D6BB0;
    if ( !dword_7D6BB0 )
      return 0;
    v3 = (CHAR *)dword_62A090;
    if ( !dword_62A090 )
      v3 = &byte_629120;
    (*(void (__thiscall **)(int, CHAR *))(*(_DWORD *)dword_7D6BB0 + 72))(dword_7D6BB0, v3);
    v14[0] = 0;
    v14[1] = (LPVOID)-1;
    sub_578600(&byte_629120);
    sub_578600(String2);
    v14[2] = 0;
    v14[3] = 0;
    v15 = 0;
    v4 = (*(int (__thiscall **)(int, LPVOID *, _DWORD, int))(*(_DWORD *)v2 + 96))(v2, v14, 0, 15);
    v5 = (void (__thiscall ***)(_DWORD, int))v4;
    if ( !v4 )
    {
LABEL_9:
      if ( v14[0] )
        sub_5BE8AE(v14[0]);
      return 0;
    }
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4) )
    {
      (**v5)(v5, 1);
      goto LABEL_9;
    }
    v7 = (char *)operator new(0x58u);
    if ( v7 )
    {
      *((_DWORD *)v7 + 20) = 0;
      *((_DWORD *)v7 + 21) = 0;
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    strcpy(v8, String2);
    *((_DWORD *)v8 + 20) = v5;
    v9 = this[85];
    if ( v9 )
    {
      for ( i = *(_DWORD *)(v9 + 84); i; i = *(_DWORD *)(i + 84) )
        v9 = i;
      *(_DWORD *)(v9 + 84) = v8;
    }
    else
    {
      this[85] = v8;
    }
    v11 = v14[0];
    v12 = v14[0] == 0;
    ++this[86];
    if ( !v12 )
      sub_5BE8AE(v11);
  }
  return 1;
}
