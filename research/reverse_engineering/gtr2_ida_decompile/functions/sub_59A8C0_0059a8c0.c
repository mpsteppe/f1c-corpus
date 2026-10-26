char __thiscall sub_59A8C0(float *this, int a2, int a3)
{
  double v4; // st7
  int v5; // ecx
  float *v6; // esi
  float v7; // edx
  float v8; // eax
  char *v9; // ecx
  float v11[3]; // [esp+Ch] [ebp-Ch] BYREF

  v4 = *(float *)(a3 + 4);
  v5 = *(_BYTE *)(a3 + 3) & 7;
  if ( v4 <= *this && v4 >= *this - 5.0 && *((_DWORD *)this + 3) != 2123789977 && v5 == *((_DWORD *)this + 1) )
    return 0;
  *this = *(float *)(a3 + 4);
  *((_DWORD *)this + 1) = v5;
  if ( (*(_DWORD *)a3 & 0xFC0000) != 0 )
  {
    if ( *((_DWORD *)this + 3) == 2123789977 )
      ((void (__thiscall *)(int, float *, _DWORD, _DWORD))byte_51C620)(
        a3 + 8,
        this + 2,
        (unsigned __int8)*(_DWORD *)a3,
        *(_DWORD *)(a3 + 4));
    else
      sub_51C210((_DWORD *)(a3 + 8), (int)(this + 2), *(_DWORD *)(a3 + 4));
  }
  else
  {
    sub_51BFA0((_DWORD *)this + 2, (_DWORD *)a3);
  }
  v6 = this + 11;
  v7 = v6[1];
  v8 = v6[2];
  v11[0] = *v6;
  v9 = (char *)&unk_9204B0 + 22616 * (unsigned __int8)*(_DWORD *)a3;
  v11[1] = v7;
  v11[2] = v8;
  sub_5782A0((int)v9, v11);
  return 1;
}
