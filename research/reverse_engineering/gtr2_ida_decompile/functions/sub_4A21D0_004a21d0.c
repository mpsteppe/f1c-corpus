int __thiscall sub_4A21D0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  float v5; // [esp+0h] [ebp-44h]
  float v6; // [esp+4h] [ebp-40h]
  float v7; // [esp+8h] [ebp-3Ch]
  float v8; // [esp+Ch] [ebp-38h]
  int v9; // [esp+2Ch] [ebp-18h]
  int v10; // [esp+30h] [ebp-14h]
  _BYTE v11[4]; // [esp+34h] [ebp-10h] BYREF
  _BYTE v12[4]; // [esp+38h] [ebp-Ch] BYREF
  _BYTE v13[4]; // [esp+3Ch] [ebp-8h] BYREF
  _BYTE v14[4]; // [esp+40h] [ebp-4h] BYREF

  if ( *((_DWORD *)dword_91E07C + 3705) != -1 && !byte_FADD28 && dword_FB1D04 && sub_5E5670("MAINVIEW", 0) )
  {
    if ( *(_DWORD *)dword_B72314 != 6
      && *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) != *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468)
      && dword_91E07C )
    {
      sub_48D800();
    }
    sub_4EA810(&unk_B6E7A8);
    nullsub_7(&unk_FB20EC);
    v2 = this[4];
    v3 = this[2];
    v10 = this[3];
    v9 = this[1];
    sub_5E5550(v14, v13, v12, v11, 0);
    v8 = (double)(v3 - v9) * 0.0016666667;
    v7 = (double)(v2 - v10) * 0.00125;
    v6 = (double)v9 * 0.0016666667;
    v5 = (double)v10 * 0.00125;
    sub_5E53E0(v5, v6, v7, v8, 0x4000);
    sub_58F290(&unk_FB1E98);
    sub_51E980(&dword_BE10B0);
    sub_54AB10(&unk_BE2728);
    sub_5206C0(&unk_BE1198);
    sub_58F2C0(&unk_FB1E98);
    sub_5E53E0(0.0, 0.0, 1.0, 1.0, 0x4000);
    sub_5E5050(286);
  }
  return 0;
}
