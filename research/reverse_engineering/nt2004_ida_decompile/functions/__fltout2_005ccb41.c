_DWORD *__cdecl _fltout2(char a1, int a2, _DWORD *a3, char *Destination)
{
  int v4; // eax
  _DWORD *v5; // esi
  char *v6; // edi
  __int16 v8; // [esp-10h] [ebp-40h]
  __int16 v9; // [esp+8h] [ebp-28h] BYREF
  char v10; // [esp+Ah] [ebp-26h]
  char Source[24]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v12[2]; // [esp+24h] [ebp-Ch] BYREF
  __int16 v13; // [esp+2Ch] [ebp-4h]

  __dtold(v12, &a1);
  v8 = v13;
  v4 = _I10_OUTPUT(v12[0], v12[1], v8, 17, 0, &v9);
  v5 = a3;
  v6 = Destination;
  a3[2] = v4;
  *v5 = v10;
  v5[1] = v9;
  strcpy(v6, Source);
  v5[3] = v6;
  return v5;
}
