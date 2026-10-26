int __thiscall sub_45F2B0(int this, int a2)
{
  int v3; // eax
  _BYTE *v4; // esi
  float v6; // [esp+0h] [ebp-1C0h]
  unsigned int v7; // [esp+10h] [ebp-1B0h] BYREF
  char v8; // [esp+18h] [ebp-1A8h]
  char v9; // [esp+19h] [ebp-1A7h]
  _BYTE v10[422]; // [esp+1Ah] [ebp-1A6h] BYREF

  v8 = dword_7C56A4;
  if ( dword_7C56A4 == 7 )
  {
    v9 = *(_BYTE *)(this + 16345);
    qmemcpy(v10, (const void *)(this + 16346), 4 * ((unsigned int)(4 * v9) >> 2));
    v3 = 4 * v9 + 2;
  }
  else
  {
    v9 = 0;
    v3 = 1;
  }
  v6 = dbl_8AFEA0;
  ProgressBarEventEncode(4, 2, v3, 255, LODWORD(v6), 1);
  v4 = (_BYTE *)COMVTableCallVia0x60(*(_DWORD *)(this + 16312));
  if ( a2 == -1 )
    v4[4] = 1;
  else
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v4 + 12))(v4, a2);
  NetworkSendDispatch(&v7, ((v7 >> 8) & 0x3FF) + 8, v4, 1, 1, -1, 0);
  return VirtualMethodDispatch(*(_DWORD *)(this + 16312), v4);
}

