char __thiscall sub_463A40(void *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // esi
  char v7; // bl
  _BYTE *v8; // edi
  int v9; // eax
  int v10; // eax
  int v12; // [esp+14h] [ebp-D4h]
  _BYTE v13[208]; // [esp+18h] [ebp-D0h] BYREF

  v5 = (_DWORD *)a2;
  v7 = 0;
  if ( (*(_DWORD *)a2 & 0xF0000000) == 0x10000000
    && (*(_BYTE *)(a2 + 2) & 0x3F) == 0
    && (*(_DWORD *)a2 & 0xFFC0) == 0xD00 )
  {
    sub_4D1850(a2);
    v5 = v13;
    sub_4D1890(v13);
  }
  LOBYTE(v12) = (*v5 & 0xC000000) == 201326592;
  v8 = (_BYTE *)sub_56A3B0(*(_DWORD *)(*(_DWORD *)this + 6708));
  if ( a4 == -1 )
    v8[4] = 1;
  else
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v8 + 12))(v8, a4);
  if ( a3 == 1 )
  {
    v9 = 1;
    goto LABEL_11;
  }
  if ( a3 != 2 )
  {
    v9 = 0;
LABEL_11:
    v10 = sub_56A3D0(v5, ((unsigned __int16)*v5 >> 6) + 8, v8, v12, v9, a5, 0);
    goto LABEL_12;
  }
  v10 = sub_56A3D0(v5, ((unsigned __int16)*v5 >> 6) + 8, v8, v12, 2, a5, 1);
LABEL_12:
  if ( !v10 )
    v7 = 1;
  sub_56A3C0(*(_DWORD *)(*(_DWORD *)this + 6708), v8);
  return v7;
}
