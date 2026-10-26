char __thiscall sub_4D8670(int this)
{
  double v2; // st7
  int i; // ebx
  char *v4; // esi
  char v5; // al
  char v6; // bl
  int v8; // [esp-4h] [ebp-24h]
  float v9; // [esp+0h] [ebp-20h]
  float v10; // [esp+4h] [ebp-1Ch]
  float v11; // [esp+14h] [ebp-Ch]
  float v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h] BYREF

  *(_BYTE *)(this + 2148) = 1;
  v12 = 0.75 * 1.5;
  if ( flt_767898 > 0.0 )
    sub_4EFD80(v12);
  v11 = 0.0;
  sub_5074D0(v12);
  if ( v12 > 0.0 )
  {
    do
    {
      v13 = 1;
      sub_4D8860(&v13);
      v2 = dbl_7DA9C0 + v11;
      v11 = v2;
    }
    while ( v2 < v12 );
  }
  *(_BYTE *)(this + 2148) = 1;
  v10 = dbl_7DA9D0;
  v13 = 1;
  sub_4D82E0(this, v10);
  sub_4D8860(&v13);
  *(_BYTE *)(this + 2149) = 0;
  sub_4BEB30(dword_766238, 0);
  for ( i = sub_42F2D0(&unk_62BF64); !sub_42F2C0(&unk_62BF64); i = sub_42F310(&unk_62BF64) )
  {
    v4 = (char *)&unk_62BF68 + 25304 * i;
    sub_51BC20(*(_DWORD *)(this + 4 * i + 964), 0);
    sub_50BFA0(v4 + 1892);
    v5 = *(_BYTE *)(i + this + 1160);
    if ( v4[4769] != v5 )
    {
      v4[4769] = v5;
      sub_50B4E0(*((_DWORD *)v4 + 1190), 1);
    }
    v9 = dbl_7DA9D0;
    sub_50EDC0(v9);
    sub_4EEC50(*(_BYTE *)(i + this + 1209));
    v6 = *(_BYTE *)(i + this + 1258);
    if ( v4[4768] != v6 )
    {
      v8 = *((_DWORD *)v4 + 1190);
      v4[4768] = v6;
      sub_50B4E0(v8, 1);
    }
  }
  sub_4181C0(dword_6291D0);
  sub_4F0200(1065353216);
  sub_57A5B0(*(_DWORD *)(this + 2084));
  *(_DWORD *)(this + 2084) = -1;
  return 1;
}
