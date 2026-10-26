// positive sp value has been detected, the output may be wrong!
char __userpurge sub_4745E6@<al>(int a1@<ecx>, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edi
  int v7; // eax
  char v9; // bl
  _BYTE *v10; // esi
  int v11; // eax
  int v13; // [esp-344h] [ebp-354h]
  int v14; // [esp-340h] [ebp-350h]
  _BYTE v15[844]; // [esp-33Ch] [ebp-34Ch] BYREF

  v6 = a3;
  v7 = *a3;
  v9 = 0;
  if ( (*a3 & 0xE0000000) == 0x20000000 && (v7 & 0xFC0000) == 0 && (v7 & 0x3FF00) == 0x3400 )
  {
    sub_51BFA0(a3);
    v6 = v15;
    ((void (__thiscall *)(_BYTE *))sub_51C6B0)(v15);
  }
  LOBYTE(v14) = (*v6 & 0x18000000) == 402653184;
  v10 = (_BYTE *)sub_59B480(*(_DWORD *)(*(_DWORD *)a1 + 113316));
  if ( a5 == -1 )
    v10[4] = 1;
  else
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v10 + 12))(v10, a5);
  if ( a4 == 1 )
  {
    v11 = 1;
    goto LABEL_11;
  }
  if ( a4 != 2 )
  {
    v11 = 0;
LABEL_11:
    LOBYTE(v13) = 0;
    goto LABEL_12;
  }
  v11 = 2;
  LOBYTE(v13) = 1;
LABEL_12:
  if ( !sub_59B7F0((char)v6, ((*v6 >> 8) & 0x3FF) + 8, (char)v10, v14, v11, a6, v13) )
    v9 = 1;
  sub_59B490(*(_DWORD *)(*(_DWORD *)a1 + 113316), v10);
  return v9;
}
