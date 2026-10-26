// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_406494@<eax>(
        char a1@<al>,
        char a2@<dh>,
        _DWORD *a3@<ecx>,
        _BYTE *a4@<ebx>,
        int a5,
        int a6,
        int a7,
        int a8)
{
  _DWORD *v8; // esi
  _DWORD *v9; // ecx
  CHAR *v10; // eax

  *a4 += a2;
  LOBYTE(a3) = BYTE1(a3);
  MEMORY[0x53FFFFFC] = a1;
  v8 = a3;
  v9 = a3 + 1;
  *v9 = 0;
  v9[1] = -1;
  *v8 = &off_5D5534;
  v10 = *(CHAR **)a5;
  if ( !*(_DWORD *)a5 )
    v10 = &byte_629120;
  sub_578600(v10);
  v8[3] = *(_DWORD *)(a5 + 8);
  v8[4] = *(_DWORD *)(a5 + 12);
  v8[6] = a7;
  v8[19] = 0;
  v8[22] = 0;
  v8[23] = 0;
  v8[25] = 0;
  v8[26] = 0;
  v8[5] = a6;
  v8[7] = 1008981770;
  v8[8] = 1064933786;
  v8[9] = 1056964608;
  v8[17] = 1185694720;
  v8[21] = a8;
  v8[24] = -1;
  return v8;
}
