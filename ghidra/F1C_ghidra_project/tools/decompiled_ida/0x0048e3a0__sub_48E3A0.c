// Address: 0x0048e3a0
// Size: 265 bytes
// Name: sub_48E3A0
// Type: int __thiscall(int this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_48E3A0(int this)
{
  int v2; // eax
  int *v3; // edi
  int v4; // ebp
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  int v9; // eax
  int v10; // ecx
  bool v11; // zf
  char *v13; // [esp+10h] [ebp-8h]

  v2 = *(_DWORD *)(this + 228);
  v3 = (int *)(this + 228);
  v4 = 0;
  if ( v2 )
    sub_551F80(v2);
  v5 = *(char **)(this + 176);
  if ( !v5 )
    v5 = &byte_5EA438;
  sub_566650(v5);
  v13 = (char *)sub_587C03(128);
  *v13 = 0;
  v6 = (char *)dword_5EC3F0;
  if ( !dword_5EC3F0 )
    v6 = &byte_5EA438;
  sub_566650(v6);
  v7 = *(char **)(this + 184);
  if ( !v7 )
    v7 = &byte_5EA438;
  sub_5665B0(v7);
  v8 = v13;
  if ( !v13 )
    v8 = &byte_5EA438;
  v9 = sub_551F10(v3, v8, 0, 0);
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 232) = 0;
  if ( v9 )
  {
    *v3 = 0;
    v4 = 1;
  }
  else
  {
    v10 = *v3;
    v11 = *v3 == 0;
    *(_BYTE *)(this + 248) = 0;
    if ( !v11 )
    {
      *(_DWORD *)(this + 240) = *(_DWORD *)(v10 + 12);
      *(_DWORD *)(this + 244) = *(_DWORD *)(v10 + 16);
      sub_551EB0(flt_7CF2CC);
    }
  }
  if ( v13 )
    sub_587BCF(v13);
  return v4;
}
