int __thiscall sub_4D9CA0(float **this, float a2)
{
  int *v2; // edx
  int v3; // esi
  __int64 v4; // rax
  int v5; // esi
  float v7; // [esp+Ch] [ebp-Ch]
  float v8; // [esp+10h] [ebp-8h]
  char v9; // [esp+14h] [ebp-4h]

  v2 = (int *)this;
  if ( a2 == -9.9999997e37 )
    a2 = sub_4D83C0(*this);
  v7 = *(float *)(*v2 + 2080);
  v8 = a2;
  v9 = 1;
  if ( a2 < (double)v7 )
  {
    v8 = *(float *)(*v2 + 2080);
    v7 = a2;
    v9 = 0;
  }
  sub_4D92D0(*v2, v7, v8, v9);
  sub_4D1940((char **)&dword_79FC40);
  v3 = (__int64)floor(v7 * 40.0);
  v4 = (__int64)floor(v8 * 40.0);
  if ( v3 != (_DWORD)v4 )
  {
    v5 = sub_42F2D0(&unk_62BF64);
    for ( LODWORD(v4) = sub_42F2C0(&unk_62BF64); !(_BYTE)v4; LODWORD(v4) = sub_42F2C0(&unk_62BF64) )
    {
      sub_51A8C0((char *)&unk_62BFBC + 25304 * v5);
      sub_50EDC0(a2);
      v5 = sub_42F310(&unk_62BF64);
    }
  }
  return v4;
}
