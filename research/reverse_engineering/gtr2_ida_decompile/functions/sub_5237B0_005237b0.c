char __thiscall sub_5237B0(char **this, int a2, int a3, float a4)
{
  int v4; // eax
  int v5; // edi
  int v6; // esi
  char v7; // bl
  char v8; // al

  if ( a4 == -9.9999997e37 )
    a4 = *((float *)*this + 723213);
  v4 = sub_5223B0(*this, a2, a4, 0);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = v4 + 212;
  v7 = sub_599CD0(v4 + 212);
  v8 = sub_599CF0(v5 + 212);
  if ( v7 )
  {
    if ( v8 )
      return sub_59AA00(a4, a3, 0.0);
    else
      return sub_59A9A0(v6, LODWORD(a4), v5 + 1068, a3);
  }
  else if ( v8 )
  {
    return sub_59A9A0(v6, LODWORD(a4), v5 + 220, a3);
  }
  else
  {
    return 0;
  }
}
