int __cdecl sub_58E5B0(float a1)
{
  float *v1; // ecx
  float *v2; // esi
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  int v10; // [esp+18h] [ebp-20h]

  v2 = v1;
  if ( v1[52] <= 0.0 )
  {
    if ( v1[51] < (double)*(float *)(LODWORD(a1) + 192) )
    {
      sub_58C630(v1, 12);
      return off_16C9728(LODWORD(a1));
    }
    if ( v7 | v8 )
    {
      a1 = (v1[51] - *(float *)(LODWORD(a1) + 192)) * *(float *)(LODWORD(a1) + 200);
      sub_58C630(v1, 12);
    }
    v10 = 13;
    goto LABEL_12;
  }
  if ( v1[51] >= (double)*(float *)(LODWORD(a1) + 180) )
  {
    if ( !(v4 | v5) )
    {
      sub_58C630(v1, 11);
      return off_16C9728(LODWORD(a1));
    }
    a1 = (v1[51] - *(float *)(LODWORD(a1) + 180)) * *(float *)(LODWORD(a1) + 188);
    sub_58C630(v1, 10);
LABEL_12:
    sub_58C630(v2, v10);
    return off_16C9728(LODWORD(a1));
  }
  sub_58C630(v1, 10);
  return off_16C9728(LODWORD(a1));
}
