void __thiscall sub_4DA510(float **this)
{
  float **v1; // esi
  int v2; // ecx
  double v3; // st7
  float **v4; // esi
  int v5; // eax
  int v6; // edx
  float **v7; // ecx
  float v8; // [esp+0h] [ebp-8h]
  float v9; // [esp+0h] [ebp-8h]

  if ( *this != (float *)2 )
    return;
  v4 = this + 2;
  if ( sub_4D9AE0(this + 2) )
    goto LABEL_7;
  if ( !dword_768948 || (v5 = sub_4D8960(), v5 == 2) )
  {
    sub_4F0200(1065353216);
    sub_4DA130(v4);
LABEL_7:
    v7 = v4;
    goto LABEL_9;
  }
  sub_4D89D0(v6, v5, 1);
  v7 = v4;
LABEL_9:
  v1 = v7;
  v3 = sub_4D83C0(*v7);
  if ( *(float *)(v2 + 2080) != v3 || *(_BYTE *)(v2 + 2148) )
  {
    sub_4D8B50((float ***)v2);
    v8 = sub_4D9E20(v1);
    sub_4D8DD0((char *)*v1, v8);
    v9 = sub_4D83C0(*v1);
    sub_4D9CA0(v1, v9);
    *((_BYTE *)*v1 + 2148) = 0;
  }
}
