int sub_54CCC2()
{
  _DWORD v11[7]; // [esp-Ch] [ebp-48h] BYREF
  int v12; // [esp+10h] [ebp-2Ch]
  int v13; // [esp+14h] [ebp-28h]
  char v14[16]; // [esp+18h] [ebp-24h] BYREF
  int v15; // [esp+28h] [ebp-14h]
  _DWORD *v16; // [esp+2Ch] [ebp-10h]
  int v17; // [esp+38h] [ebp-4h]

  v16 = v11;
  v15 = 0;
  strcpy(v14, "GenuineIntel");
  _EAX = 0;
  __asm { cpuid }
  v12 = _EAX;
  v11[4] = _EBX;
  v11[5] = _EDX;
  v11[6] = _ECX;
  v17 = -1;
  if ( !_EAX )
    return v15;
  _EAX = 1;
  __asm { cpuid }
  v12 = _EAX;
  v13 = _EDX;
  if ( (_EDX & 0x2000000) != 0 )
    v15 |= 4u;
  if ( (v13 & 0x4000000) != 0 )
    return v15 | 8;
  return v15;
}
