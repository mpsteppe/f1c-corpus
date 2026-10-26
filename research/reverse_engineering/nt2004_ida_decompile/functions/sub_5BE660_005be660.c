char __fastcall sub_5BE660(_BYTE *a1, char a2)
{
  unsigned __int8 v2; // al
  char v3; // bl
  unsigned __int8 *v4; // eax
  unsigned __int8 v5; // dl
  int v6; // edx
  unsigned __int8 v7; // bl
  char v8; // bl
  unsigned __int8 v11; // [esp+8h] [ebp-4h]

  v2 = a1[256];
  v3 = a1[v2] + a1[257];
  a1[256] = v2 + 1;
  a1[257] = v3;
  v4 = &a1[(unsigned __int8)a1[260]];
  v5 = *v4;
  *v4 = a1[(unsigned __int8)a1[257]];
  v11 = v5;
  a1[(unsigned __int8)a1[257]] = a1[(unsigned __int8)a1[259]];
  a1[(unsigned __int8)a1[259]] = a1[(unsigned __int8)a1[256]];
  a1[(unsigned __int8)a1[256]] = v5;
  v6 = (unsigned __int8)a1[259];
  v7 = a1[v11] + a1[258];
  a1[258] = v7;
  LOBYTE(v6) = a1[(unsigned __int8)a1[(unsigned __int8)(a1[(unsigned __int8)a1[260]]
                                                      + a1[(unsigned __int8)a1[257]]
                                                      + a1[v6])]];
  v8 = a1[(unsigned __int8)(a1[(unsigned __int8)a1[256]] + a1[v7])];
  a1[260] = a2;
  LOBYTE(v6) = a2 ^ v8 ^ v6;
  a1[259] = v6;
  return v6;
}
