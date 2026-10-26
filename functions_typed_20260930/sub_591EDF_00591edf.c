int __cdecl sub_591EDF(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // ebx
  int v8; // esi
  int v9; // ecx
  int v10; // eax
  char v12[8]; // [esp+4h] [ebp-24h] BYREF
  int v13; // [esp+Ch] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-14h]
  int v15; // [esp+18h] [ebp-10h]
  int v16; // [esp+20h] [ebp-8h]
  int v17; // [esp+30h] [ebp+8h]

  v7 = a1 - 1900;
  if ( a1 - 1900 < 70 || v7 > 138 )
    return -1;
  v8 = a3 + dword_5E9B04[a2];
  if ( (v7 & 3) == 0 && a2 > 2 )
    ++v8;
  LazyInitSingletonWithFlagGuard();
  v16 = v8;
  v15 = a1 - 1900;
  v13 = a4;
  v14 = a2 - 1;
  v9 = dword_5E7758 + 60 * (a5 + 60 * (a4 + 24 * (((a1 - 1901) >> 2) + v8 + 365 * (a1 - 1900)))) + a6 + 2085978496;
  v17 = v9;
  if ( a7 == 1 || a7 == -1 && dword_5E775C && (v10 = CriticalSectionGuardedCall(v12), v9 = v17, v10) )
    v9 += dword_5E7760;
  return v9;
}

