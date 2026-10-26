char __thiscall sub_57AC50(_DWORD *this, char *Source, int a3)
{
  char v4; // bl
  int v6[7]; // [esp+8h] [ebp-1Ch] BYREF

  v4 = 0;
  sub_57A080(v6);
  sub_57A2F0(v6, Source, 0);
  if ( v6[0] )
  {
    sub_57AB20(this, (int)v6);
    v4 = sub_57A8C0(v6, a3);
    sub_57A360((int)v6);
  }
  sub_57A0A0(v6);
  return v4;
}
