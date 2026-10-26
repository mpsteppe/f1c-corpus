char __thiscall sub_500010(float *this, int a2, int a3, int a4)
{
  char v5; // al
  int v7; // ebp
  char v9; // al
  char *v10; // ecx
  int v11; // [esp-4h] [ebp-14h]
  int v12; // [esp+0h] [ebp-10h]
  float v13; // [esp+18h] [ebp+8h]

  v5 = *(_BYTE *)(a3 + 3);
  v13 = *(float *)(a3 + 4);
  v7 = v5 & 7;
  if ( v13 <= (double)*this && *this - 5.0 <= v13 && (unsigned __int8)sub_5001F0(this) && v7 == *((_DWORD *)this + 1) )
    return 0;
  *this = v13;
  *((_DWORD *)this + 1) = v7;
  if ( (*(_DWORD *)a3 & 0xFC0000) != 0 )
  {
    v9 = sub_5001F0(this);
    v12 = *(int *)(a3 + 4);
    v10 = (char *)(a3 + 8);
    v11 = (int)(this + 2);
    if ( v9 )
      sub_4B2DD0(v10, v11, v12);
    else
      sub_4B32A0(v10, v11, v12);
    return 1;
  }
  else
  {
    sub_4B3A90((_DWORD *)this + 2, (_DWORD *)a3);
    return 1;
  }
}
