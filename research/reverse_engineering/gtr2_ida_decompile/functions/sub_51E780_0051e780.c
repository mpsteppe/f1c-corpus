int __thiscall sub_51E780(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // eax
  _DWORD v7[4]; // [esp+20h] [ebp-98h] BYREF
  _DWORD v8[18]; // [esp+30h] [ebp-88h] BYREF
  _DWORD v9[16]; // [esp+78h] [ebp-40h] BYREF

  memset(&v8[1], 0, 0x40u);
  memset(v9, 0, sizeof(v9));
  v8[16] = 1065353216;
  v8[11] = 1065353216;
  v8[6] = 1065353216;
  v8[1] = 1065353216;
  v8[0] = 1;
  v9[15] = 1065353216;
  v9[10] = 1065353216;
  v9[5] = 1065353216;
  v9[0] = 1065353216;
  v8[17] = 1;
  sub_5F6390(39, 0);
  sub_5FA770(a3, a4, 0);
  sub_5F6390(4096, sub_51E710);
  sub_5D7280(a3 + 628, &unk_BE10BC);
  sub_5D7280(*(_DWORD *)(*(_DWORD *)(dword_BE10B0 + 16) + 4) + 344, v8);
  (*(void (__stdcall **)(int, int, _DWORD *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 16, v9, 4);
  sub_5D7280(a3 + 628, &unk_BE1100);
  sub_5D7280(a3 + 344, v8);
  (*(void (__stdcall **)(int, int, _DWORD *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 20, v9, 4);
  v5 = this[57];
  memset(v7, 0, 12);
  v7[3] = v5;
  (*(void (__stdcall **)(int, int, _DWORD *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 11, v7, 1);
  return 1;
}
