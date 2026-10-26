char __userpurge sub_48CB41@<al>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>, int a6, int a7)
{
  const char *v7; // edi
  int v9; // eax
  int v10; // esi
  char result; // al
  float v12; // [esp+0h] [ebp-428h]
  _BYTE v13[61]; // [esp+8h] [ebp-420h] BYREF
  __int16 v14; // [esp+45h] [ebp-3E3h]
  char v15; // [esp+47h] [ebp-3E1h]
  char v16[125]; // [esp+48h] [ebp-3E0h] BYREF
  __int16 v17; // [esp+C5h] [ebp-363h]
  char v18; // [esp+C7h] [ebp-361h]
  _BYTE v19[840]; // [esp+E0h] [ebp-348h] BYREF

  *(_DWORD *)&v13[8] = a2;
  *(_DWORD *)&v13[4] = a5;
  *(_DWORD *)v13 = a4;
  v7 = *(const char **)(a3 + 8);
  v9 = strlen(v7);
  v10 = v9;
  if ( v9 >= 0 )
  {
    if ( v9 > 159 )
      v10 = 159;
  }
  else
  {
    v10 = 0;
  }
  v12 = dbl_FB1D18;
  sub_51B2A0(4, 6, v10, 0, LODWORD(v12), 3);
  sub_630FE0(v19, v7, v10);
  v19[v10] = 0;
  sub_4745E0();
  result = *(_BYTE *)(a3 + 12);
  if ( result )
  {
    memset(v16, 0, sizeof(v16));
    v17 = 0;
    v18 = 0;
    memset(v13, 0, sizeof(v13));
    v14 = 0;
    v15 = 0;
    sub_501490(v13, 64);
    sub_472FE0();
    sub_4EA920(v16);
    result = sub_4730C0((int **)&dword_B6CB98, v16, 0, (int)&byte_1020304, 1084227584);
  }
  *(_DWORD *)(a1 + 2128) = 0;
  return result;
}
