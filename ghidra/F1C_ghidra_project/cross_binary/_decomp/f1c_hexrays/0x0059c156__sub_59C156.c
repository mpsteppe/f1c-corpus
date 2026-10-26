// f1c  0x0059c156  size=145
int __cdecl sub_59C156(_DWORD *a1, __int64 a2, unsigned int a3)
{
  int v3; // eax
  DWORD v4; // edi
  __int64 v5; // rax
  int v6; // eax
  int v7; // eax
  int v8; // edx

  v3 = a1[3];
  if ( (v3 & 0x83) != 0 && (v4 = a3, a3 <= 2) )
  {
    LOBYTE(v3) = v3 & 0xEF;
    a1[3] = v3;
    if ( a3 == 1 )
    {
      LODWORD(v5) = sub_58C824((int)a1);
      a2 += v5;
      v4 = 0;
    }
    sub_58A05A(a1);
    v6 = a1[3];
    if ( (v6 & 0x80u) == 0 )
    {
      if ( (v6 & 1) != 0 && (v6 & 8) != 0 && (v6 & 0x400) == 0 )
        a1[6] = 512;
    }
    else
    {
      LOBYTE(v6) = v6 & 0xFC;
      a1[3] = v6;
    }
    v7 = sub_595F11(a1[4], a2, SHIDWORD(a2), v4);
    if ( (v8 & v7) != 0xFFFFFFFF )
      return 0;
  }
  else
  {
    *(_DWORD *)sub_58AFCF() = 22;
  }
  return -1;
}
