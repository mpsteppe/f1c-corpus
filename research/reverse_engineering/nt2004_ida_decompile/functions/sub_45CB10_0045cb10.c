void __thiscall sub_45CB10(int this)
{
  int v2; // eax
  int v3; // ebx
  int v4; // ecx
  int v5; // ebp
  int v6; // esi
  double v7; // st7
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  sub_45CE00();
  v2 = *(_DWORD *)(this + 1188);
  v3 = 0;
  v8 = 0;
  *(_BYTE *)(this + 1192) = 0;
  v10 = v2;
  sub_45C910((float *)this);
  sub_506B50(&v11, 0);
  v4 = 0;
  v12 = (__int64)((double)dword_6152EC * 0.035);
  v9 = 0;
  while ( 1 )
  {
    v5 = (v4 + v10) % 8;
    v6 = 140 * v5 + this;
    if ( *(float *)(v6 + 200) > 0.0 )
      break;
LABEL_8:
    v9 = ++v4;
    if ( v4 >= 8 )
      return;
  }
  sub_506D40((char *)(v6 + 68), v11 / 2, v3, *(_DWORD *)(v6 + 196), 2, -1.0, -1.0, 0, 1);
  v7 = *(float *)(v6 + 200) - dbl_7DA9C0;
  *(float *)(v6 + 200) = v7;
  if ( v7 > 0.0 )
    *(_BYTE *)(this + 1192) = 1;
  else
    sub_45C6C0((_DWORD *)this, v5);
  v3 += v12;
  if ( ++v8 < 4 )
  {
    v4 = v9;
    goto LABEL_8;
  }
}
