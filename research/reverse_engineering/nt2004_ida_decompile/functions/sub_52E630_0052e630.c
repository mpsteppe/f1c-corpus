char __thiscall sub_52E630(float *this, int a2, int *a3)
{
  unsigned int v4; // ebp
  int v6; // ebp
  char v7; // al
  float *v8; // esi
  float v9; // edx
  float v10; // eax
  char *v11; // ecx
  int v13; // [esp+0h] [ebp-1Ch]
  float v14[3]; // [esp+10h] [ebp-Ch] BYREF
  float v15; // [esp+24h] [ebp+8h]

  v4 = *a3;
  v15 = *((float *)a3 + 1);
  v6 = (v4 >> 22) & 0xF;
  if ( v15 <= (double)*this && *this - 5.0 <= v15 && (unsigned __int8)sub_52E850(this) && v6 == *((_DWORD *)this + 1) )
    return 0;
  *this = v15;
  *((_DWORD *)this + 1) = v6;
  if ( (*((_BYTE *)a3 + 2) & 0x3F) != 0 )
  {
    v7 = sub_52E850(this);
    v13 = a3[1];
    if ( v7 )
      sub_4D08E0((int)(a3 + 2), (int)(this + 2), v13);
    else
      sub_4D0C80(a3 + 2, (_DWORD *)this + 2, *a3 & 0x3F, v13);
  }
  else
  {
    sub_4D1850((_DWORD *)this + 2, a3);
  }
  v8 = this + 11;
  v9 = v8[1];
  v10 = v8[2];
  v14[0] = *v8;
  v11 = (char *)&unk_62BFBC + 25304 * (*a3 & 0x3F);
  v14[1] = v9;
  v14[2] = v10;
  sub_51D650((int)v11, v14);
  return 1;
}
