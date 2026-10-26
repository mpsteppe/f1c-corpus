void __thiscall sub_5E53E0(int this, float a2, float a3, float a4, float a5, __int16 a6)
{
  unsigned int v6; // kr00_4
  int v7; // eax
  double v8; // st7
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  int v13; // [esp-Ch] [ebp-10h]
  float v14; // [esp-8h] [ebp-Ch]
  int v15; // [esp+10h] [ebp+Ch]
  float v16; // [esp+18h] [ebp+14h]
  int v17; // [esp+18h] [ebp+14h]

  if ( (a6 & 0x4000) != 0 )
  {
    v6 = __readeflags();
    v7 = *(_DWORD *)(dword_16C6EC8 - 1823105062);
    __writeeflags(v6);
    v8 = (double)*(int *)(v7 + 9408);
    v16 = (float)*(int *)(v7 + 9412);
  }
  else
  {
    v8 = 1.0;
    v16 = 1.0;
  }
  v9 = (unsigned __int64)(a4 * v8);
  *(_DWORD *)(this + 100) = v9;
  if ( (v9 & 0x80000000) != 0LL )
    *(_DWORD *)(this + 100) = *(_DWORD *)(dword_FB27A4 + 9408);
  v10 = (unsigned __int64)(v16 * a5);
  *(_DWORD *)(this + 104) = v10;
  if ( (v10 & 0x80000000) != 0LL )
    *(_DWORD *)(this + 104) = *(_DWORD *)(dword_FB27A4 + 9412);
  v11 = (unsigned __int64)(v8 * a2);
  *(_DWORD *)(this + 120) = v11;
  if ( (v11 & 0x80000000) != 0LL )
    *(_DWORD *)(this + 120) = 0;
  v12 = (unsigned __int64)(v16 * a3);
  *(_DWORD *)(this + 116) = v12;
  if ( (v12 & 0x80000000) != 0LL )
    *(_DWORD *)(this + 116) = 0;
  v17 = *(_DWORD *)(this + 100);
  *(_DWORD *)(this + 108) = *(_DWORD *)(this + 120) + (v17 >> 1);
  v15 = *(_DWORD *)(this + 104);
  v14 = *(float *)(this + 128);
  v13 = *(_DWORD *)(this + 124);
  *(_DWORD *)(this + 112) = *(_DWORD *)(this + 116) + (v15 >> 1);
  *(float *)(this + 132) = (double)v17 / (double)v15;
  sub_5E5240(this, v13, v14, 512);
}
