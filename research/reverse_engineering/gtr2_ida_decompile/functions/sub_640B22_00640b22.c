int __cdecl sub_640B22(int a1, int a2, _DWORD *a3, char *Destination)
{
  unsigned int v4; // kr00_4
  int v5; // eax
  _DWORD *v6; // esi
  char *v7; // edi
  int v8; // ecx
  __int16 v10; // [esp-18h] [ebp-44h]
  __int16 v11; // [esp+0h] [ebp-2Ch] BYREF
  char v12; // [esp+2h] [ebp-2Ah]
  char Source[24]; // [esp+4h] [ebp-28h] BYREF
  _DWORD v14[2]; // [esp+1Ch] [ebp-10h] BYREF
  __int16 v15; // [esp+24h] [ebp-8h]
  int v16; // [esp+28h] [ebp-4h]

  v4 = __readeflags();
  __writeeflags(v4);
  v16 = *(_DWORD *)(dword_16C6D24 - 1609030145);
  __dtold((int)v14, &a1);
  v10 = v15;
  v5 = _I10_OUTPUT(v14[0], v14[1], v10, 17, 0, &v11);
  v6 = a3;
  v7 = Destination;
  a3[2] = v5;
  *v6 = v12;
  v6[1] = v11;
  strcpy(v7, Source);
  v8 = v16;
  v6[3] = v7;
  return sub_6349BB(v8);
}
