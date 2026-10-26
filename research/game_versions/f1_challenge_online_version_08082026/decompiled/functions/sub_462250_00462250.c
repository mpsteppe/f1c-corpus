char __thiscall sub_462250(void *this, _DWORD *a2, int a3, int a4, int a5)
{
  char v7; // bl
  _BYTE *v8; // esi
  int v9; // eax
  int v11; // [esp+10h] [ebp-4h]
  char v12; // [esp+18h] [ebp+4h]

  v7 = 0;
  LOBYTE(v11) = (*a2 & 0x8000000) != 0;
  v8 = (_BYTE *)sub_57A680(*(_DWORD *)(*(_DWORD *)this + 16312));
  if ( a4 == -1 )
    v8[4] = 1;
  else
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v8 + 12))(v8, a4);
  if ( a3 == 1 )
  {
    v9 = 1;
    goto LABEL_7;
  }
  if ( a3 != 2 )
  {
    v9 = 0;
LABEL_7:
    v12 = 0;
    goto LABEL_8;
  }
  v9 = 2;
  v12 = 1;
LABEL_8:
  if ( !sub_57A6A0(a2, ((*a2 >> 8) & 0x3FF) + 8, v8, v11, v9, a5, v12) )
    v7 = 1;
  sub_57A690(*(_DWORD *)(*(_DWORD *)this + 16312), v8);
  return v7;
}
