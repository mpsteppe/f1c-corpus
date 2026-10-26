char __thiscall sub_4D8450(int this)
{
  int i; // edi
  char *v4; // esi
  const char *v5; // eax
  double v6; // st7
  int v7; // [esp-8h] [ebp-A0h]
  float v8; // [esp+0h] [ebp-98h]
  float v9; // [esp+10h] [ebp-88h]
  int v10; // [esp+14h] [ebp-84h] BYREF
  char Buffer[125]; // [esp+18h] [ebp-80h] BYREF
  __int16 v12; // [esp+95h] [ebp-3h]
  char v13; // [esp+97h] [ebp-1h]

  sub_4D7520((int *)this);
  if ( *(float *)(this + 2064) - *(float *)(this + 2060) <= 0.0 )
    return 0;
  *(_DWORD *)(this + 2084) = sub_57A620(this + 884);
  *(_BYTE *)(this + 2149) = 1;
  for ( i = sub_42F2D0(&unk_62BF64); !sub_42F2C0(&unk_62BF64); i = sub_42F310(&unk_62BF64) )
  {
    v4 = (char *)&unk_62BF68 + 25304 * i;
    sub_50EDC0(*(float *)(this + 2060));
    sub_50BF70(v4 + 1892);
    *(_DWORD *)(this + 4 * i + 964) = *((_DWORD *)v4 + 4146);
    *(_BYTE *)(i + this + 1160) = v4[4769];
    *(_BYTE *)(i + this + 1209) = (*((_DWORD *)v4 + 6324) & 2) != 0;
    *(_BYTE *)(i + this + 1258) = v4[4768];
    if ( v4[4768] != 1 )
    {
      v7 = *((_DWORD *)v4 + 1190);
      v4[4768] = 1;
      sub_50B4E0(v7, 1);
    }
    sub_51BC20(3, 0);
  }
  sub_4BEB30(dword_766238, 1);
  v8 = dbl_7DA9D0;
  sub_4D82E0(this, v8);
  sub_502040(0);
  *(_BYTE *)(this + 2148) = 1;
  if ( flt_767898 > 0.0 )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x7Cu);
    v12 = 0;
    v13 = 0;
    v5 = *(const char **)dword_62A070;
    if ( !*(_DWORD *)dword_62A070 )
      v5 = &byte_629120;
    sub_405480(Buffer, 0x7Fu, "%s%s", v5, aAmbientIrMp3);
    sub_4EFCF0(0.75, Buffer);
  }
  v9 = 0.0;
  sub_5074A0(0.75);
  if ( 0.0 < 0.75 )
  {
    do
    {
      v10 = 1;
      sub_4D8860(&v10);
      v6 = dbl_7DA9C0 + v9;
      v9 = v6;
    }
    while ( v6 < 0.75 );
  }
  return 1;
}
