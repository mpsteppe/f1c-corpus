// f1c  0x004ba180  size=81
void __thiscall sub_4BA180(float **this)
{
  float **v1; // esi
  int v2; // ecx
  double v3; // st7
  float **v4; // esi
  int v5; // eax
  float **v6; // ecx
  float v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+0h] [ebp-8h]

  if ( *this != (float *)2 )
    return;
  v4 = this + 2;
  if ( sub_4B9A00(this + 2) )
    goto LABEL_6;
  v5 = sub_4B8BD0();
  if ( v5 == 2 )
  {
    sub_4C8DC0(1065353216);
    sub_4B9E40(v4);
LABEL_6:
    v6 = v4;
    goto LABEL_8;
  }
  sub_4B8C40(*v4, *(float *)&v5, 1);
  v6 = v4;
LABEL_8:
  v1 = v6;
  v3 = sub_4B8790(*v6);
  if ( *(float *)(v2 + 3900) != v3 || *(_BYTE *)(v2 + 3968) )
  {
    sub_4B8DA0((float ***)v2);
    sub_4B9CE0(v1);
    v7 = v3;
    sub_4B9000((char *)*v1, v7);
    v8 = sub_4B8790(*v1);
    sub_4B9B80(v1, v8);
    *((_BYTE *)*v1 + 3968) = 0;
  }
}
