int __stdcall sub_5F7560(int a1, int a2)
{
  int v2; // ebp
  int v3; // ebx
  float *v4; // esi
  _DWORD *v5; // edi
  double v6; // st7
  float v8; // [esp+Ch] [ebp-10h]
  float v9; // [esp+10h] [ebp-Ch] BYREF
  float v10; // [esp+14h] [ebp-8h] BYREF
  float v11; // [esp+18h] [ebp-4h] BYREF
  _DWORD **v12; // [esp+24h] [ebp+8h]

  v2 = *(_DWORD *)(*(_DWORD *)(a2 + 104) + 392);
  memset(&unk_FB3338, 0, 0x180u);
  v3 = 0;
  if ( *(int *)(v2 + 568) > 0 )
  {
    v4 = (float *)&unk_FB333C;
    v12 = (_DWORD **)(v2 + 572);
    do
    {
      v5 = *v12;
      sub_6007A0(v4 - 1, v4, v4 + 1);
      v8 = sub_6007E0(v5);
      v4[2] = sub_6007E0(v5) * v8;
      sub_5DCE20(v5, (_DWORD *)v4 + 63, (_DWORD *)v4 + 64, (_DWORD *)v4 + 65);
      v4[66] = cos(sub_6007F0(v5) * 0.5);
      v4[34] = 1.0 / sub_6007E0(v5);
      sub_6006C0(2, &v9, &v10, &v11);
      v6 = sub_600770(2);
      ++v3;
      v4[31] = v9 * v6;
      v4 += 4;
      ++v12;
      v4[28] = v10 * v6;
      v4[29] = v6 * v11;
    }
    while ( v3 < *(_DWORD *)(v2 + 568) );
  }
  return (*(int (__stdcall **)(int, int, void *, int))(*(_DWORD *)dword_FB40C8 + 376))(
           dword_FB40C8,
           72,
           &unk_FB3338,
           24);
}
